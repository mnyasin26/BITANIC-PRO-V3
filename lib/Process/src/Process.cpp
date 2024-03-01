#include "Process.h"
#include <displayTFT.h>
#include <vector>
#include <algorithm>

using namespace std;

ArduinoQueue<LandsConfig> landsQueue(QUEUE_SIZE_ITEMS);

ArduinoQueue<String> jadwalSebelumToday(20);
// ArduinoQueue<Jadwal> jadwalSemua(30);

vector<Jadwal> jadwalSemua;

extern DisplayTFT display_h;

Output mainPump(MAIN_PUMP_PIN);
Output waterPump(WATER_PUMP_PIN);
Output nutrientPump(NUTRIENT_PUMP_PIN);
Output lahan1(LAHAN1_PUMP_PIN);
Output lahan2(LAHAN2_PUMP_PIN);
Output lahan3(LAHAN3_PUMP_PIN);
Output lahan4(LAHAN4_PUMP_PIN);
Output buzzer(BUZZER_PIN);
Output ledPenyiraman(LED_PIN_PENYIRAMAN);
Output ledPemupukan(LED_PIN_PEMUPUKAN);

Input input_h;

TimeController time_h;
Status status_h;

Process::Process() : nearest(2080, 1, 1, 0, 0, 0)
{
}

void Process::resetQueue()
{
    while (landsQueue.isEmpty() == false)
    {
        landsQueue.dequeue();
    }
}

void Process::buzzerBeep(unsigned long ms)
{
    buzzer.on();
    timerBuzzer = millis();
    while (millis() - timerBuzzer < ms)
    {
        /* code */
    }
    buzzer.off();
}

void Process::processData(String type, JsonDocument doc)
{
    JsonDocument days;
    days = doc["jadwal"][type]["days"];

    bool isBeyondToday = false;

    int day = 0;

    for (int i = 0; i < days.size(); i++)
    {
        JsonDocument setOnTimes;

        setOnTimes = doc["jadwal"][type]["setontimes"];

        for (int j = 0; j < setOnTimes.size(); j++)
        {
            JsonDocument lands;
            lands = setOnTimes[j]["lands"];

            if (!stateJadwalTerdekat)
            {
                Jadwal temp;

                temp.Tanggal = time_h.getDateWithCalcDays(time_h.caclDay(days[i].as<String>(), today, setOnTimes[j]["time"].as<String>(), time));
                temp.Waktu = setOnTimes[j]["time"].as<String>();

                int totalMinutes = 0;
                int totalSeconds = 0;

                for (int k = 0; k < lands.size(); k++)
                {
                    totalMinutes += lands[k]["duration"].as<int>();
                    totalSeconds += lands[k]["seconds"].as<int>();
                }

                temp.durasi = time_h.convertDuration(totalMinutes, totalSeconds);

                if (type == "air")
                {
                    temp.Tipe = "SIRAM";
                    /* code */
                }
                else if (type == "pemupukan")
                {
                    temp.Tipe = "PUPUK";
                }

                temp.unixTime = time_h.convertToUnixTime(temp.Tanggal, temp.Waktu);
                jadwalSemua.push_back(temp);
            }

            if (days[i].as<String>() == today)
            {
                String time_target = setOnTimes[j]["time"].as<String>();

                DateTime now = DateTime(2020, 1, 1, time.substring(0, 2).toInt(), time.substring(3, 5).toInt(), time.substring(6, 8).toInt());
                DateTime target = DateTime(2020, 1, 1, time_target.substring(0, 2).toInt(), time_target.substring(3, 5).toInt(), time_target.substring(6, 8).toInt());

                DEBUG_PRINTLN("now: " + time + " target: " + time_target);
                if (now <= target)
                {
                    flag = true;
                    if (target <= nearest)
                    {
                        flag_near = true;
                        DEBUG_PRINTLN("Ada Jadwal Terdekat");
                        /* code */
                        nearest = target;
                    }
                }

                // String temp;
                // serializeJson(doc, temp);
                // DEBUG_PRINTLN("Data: " + temp);

                if (flag)
                {
                    if (flag_near)
                    {
                        this->flag_near = false;
                        status_h.setWaktuPendajwalanTerdekatHariIni(time_target.substring(0, 2) + ":" + time_target.substring(3, 5));

                        if (type == "air")
                        {
                            status_h.setTipeTerdekatHariIni("SIRAM");
                            /* code */
                        }
                        else if (type == "pemupukan")
                        {
                            status_h.setTipeTerdekatHariIni("PUPUK");
                        }
                    }
                }

                if (time_target.length() == 5)
                {
                    time_target = time_target + ":00";
                }

                if (time == time_target)
                {
                    int totalMinutes = 0;
                    int totalSeconds = 0;
                    // TODO: set ontypepump
                    if (type == "air")
                    {
                        // DEBUG_PRINTLN("set true");
                        state_water_pump = true;
                        // temp["statusJadwal"]["air"]["setontimes"][j]["status"] = "on";
                        DEBUG_PRINTLN("[ATTENTION] Waktu untuk menyiram");
                        buzzerBeep(1000);
                        // TODO: Handle Error kalau nggak ada land
                    }
                    else if (type == "pemupukan")
                    {
                        state_nutrient_pump = true;
                        buzzerBeep(1000);
                        DEBUG_PRINTLN("[ATTENTION] Waktu untuk pemupukan");
                    }

                    status_h.setCurrentIndexSetOnTimes(j);
                    lastTime = millis();
                    this->delay_over_lands = setOnTimes[j]["delay"].as<String>();
                    for (int k = 0; k < lands.size(); k++)
                    {
                        // DEBUG_PRINTLN("land: " + (String)lands[k]["id"].as<int>());
                        // DEBUG_PRINTLN("duration: " + (String)lands[k]["duration"].as<int>());
                        LandsConfig temp;
                        JsonDocument test;
                        test = lands[k];
                        if (type == "air")
                        {

                            temp.tipe = 0;
                            temp.id = test["id"].as<int>();
                            temp.duration = test["duration"].as<int>();
                            temp.seconds = test["seconds"].as<int>();
                            temp.isPemupukan = false;

                            totalSeconds += temp.seconds;
                            totalMinutes += temp.duration;

                            landsQueue.enqueue(temp);
                        }
                        else if (type == "pemupukan")
                        {
                            temp.tipe = 0;
                            temp.id = test["id"].as<int>();
                            temp.duration = test["first_water"]["minutes"].as<int>();
                            temp.seconds = test["first_water"]["seconds"].as<int>();
                            temp.isPemupukan = true;

                            totalSeconds += temp.seconds;
                            totalMinutes += temp.duration;

                            landsQueue.enqueue(temp);

                            temp.tipe = 1;
                            temp.id = test["id"].as<int>();
                            temp.duration = test["duration"].as<int>();
                            temp.seconds = test["seconds"].as<int>();
                            temp.isPemupukan = true;

                            totalSeconds += temp.seconds;
                            totalMinutes += temp.duration;

                            landsQueue.enqueue(temp);

                            temp.tipe = 0;
                            temp.id = test["id"].as<int>();
                            temp.duration = test["last_water"]["minutes"].as<int>();
                            temp.seconds = test["last_water"]["seconds"].as<int>();
                            temp.isPemupukan = true;

                            totalSeconds += temp.seconds;
                            totalMinutes += temp.duration;

                            landsQueue.enqueue(temp);
                        }
                    }

                    time_h.initProgress((totalMinutes * 60) + totalSeconds + ((int)(lands.size() - 1) * (int)(setOnTimes[j]["delay"].as<int>())) + lands.size() + 1);

                    display_h.setProgress(time_h.getUpdateProgress());
                }
            }
        }
    }
}

String temp;

void Process::pumpHandler(String type)
{
    if (isOperate == false && landsQueue.isEmpty() == true)
    {
        if (type == "air")
        {
            state_water_pump = false;
        }
        else if (type == "pemupukan")
        {
            state_nutrient_pump = false;
        }

        status_h.setPenjadwalanOn(false);

        stateJadwalTerdekat = true;
        stateAfterJadwal = true;

        display_h.setOnShceduleHighlight(false);

        display_h.setProgress(0);

        mainPump.off();
    }

    if (isOperate == false && landsQueue.isEmpty() == false)
    {
        current_land = landsQueue.dequeue();
        lastTime = millis();
        isOperate = true;

        display_h.setOnShceduleHighlight(true);

        status_h.setPenjadwalanOn(true);

        if (current_land.tipe == 0)
        {
            temp = "air";
        }
        else if (current_land.tipe == 1)
        {
            temp = "pemupukan";
        }

        if (current_land.isPemupukan)
        {
            status_h.setOnTimesStatus(true, current_land.id, "pemupukan");
        }
        else
        {
            status_h.setOnTimesStatus(true, current_land.id, temp);
        }

        if (temp == "air")
        {
            status_h.setWaterPump(true);
            DEBUG_PRINTLN("WATER PUMP ON");
            ledPenyiraman.on();
            waterPump.on();
        }
        else if (temp == "pemupukan")
        {
            ledPemupukan.on();
            status_h.setNutrientPump(true);
            DEBUG_PRINTLN("NUTRIENT PUMP ON");
            nutrientPump.on();
        }

        mainPump.on();
        status_h.setMainPump(true);

        DEBUG_PRINTLN("CURRENT LAND: " + (String)current_land.id);
        DEBUG_PRINTLN("DURATION: " + (String)current_land.duration);

        if (current_land.id == 1)
        {
            status_h.setLahan1(true);
            lahan1.on();
        }
        else if (current_land.id == 2)
        {
            status_h.setLahan2(true);
            lahan2.on();
        }
        else if (current_land.id == 3)
        {
            status_h.setLahan3(true);
            lahan3.on();
        }
        else if (current_land.id == 4)
        {
            status_h.setLahan4(true);
            lahan4.on();
        }
    }

    if (isOperate == true && isDelay == false)
    {
        display_h.setProgress(time_h.getUpdateProgress());

        if (millis() - lastTime > (current_land.duration * 1000UL * MINUTE) + 200 + (current_land.seconds * 1000UL))
        {

            if (temp == "air")
            {
                DEBUG_PRINTLN("WATER PUMP OFF");
                status_h.setWaterPump(false);
                ledPenyiraman.off();
                waterPump.off();
            }
            else if (temp == "pemupukan")
            {
                DEBUG_PRINTLN("NUTRIENT PUMP OFF");
                status_h.setNutrientPump(false);
                ledPemupukan.off();
                nutrientPump.off();
            }

            status_h.setMainPump(false);
            mainPump.off();

            if (current_land.id == 1)
            {
                status_h.setLahan1(false);
                lahan1.off();
            }
            else if (current_land.id == 2)
            {
                status_h.setLahan2(false);
                lahan2.off();
            }
            else if (current_land.id == 3)
            {
                status_h.setLahan3(false);
                lahan3.off();
            }
            else if (current_land.id == 4)
            {
                status_h.setLahan4(false);
                lahan4.off();
            }

            if (landsQueue.isEmpty() == false)
            {
                DEBUG_PRINTLN("DELAY ON");
                timerDelay = millis();
                isDelay = true;
            }
            else
            {
                DEBUG_PRINTLN("DELAY OFF");
                isDelay = false;
                isOperate = false;

                // String temp;
                if (current_land.tipe == 0)
                {
                    temp = "air";
                }
                else if (current_land.tipe == 1)
                {
                    temp = "pemupukan";
                }

                status_h.setOnTimesStatus(false, 0, temp);
                DEBUG_PRINTLN("[ATTENTION] OFFFFFFFFFFFFFFFFFF");
            }
        }
    }

    if (isDelay == true)
    {
        display_h.setProgress(time_h.getUpdateProgress());
        if (millis() - timerDelay > delay_over_lands.toInt() * 1000UL)
        {
            DEBUG_PRINTLN("DELAY OFF");
            isDelay = false;
            isOperate = false;
        }
    }
}

void Process::processManualMode(JsonDocument doc)
{
    bool flag = false;

    if (doc["lahan1"].as<String>() == "on")
    {
        status_h.setLahan1(true);
        lahan1.on();
        flag = true;
    }
    else
    {
        status_h.setLahan1(false);
        lahan1.off();
    }

    if (doc["lahan2"].as<String>() == "on")
    {
        status_h.setLahan2(true);
        lahan2.on();
        flag = true;
    }
    else
    {
        status_h.setLahan2(false);
        lahan2.off();
    }

    if (doc["lahan3"].as<String>() == "on")
    {
        status_h.setLahan3(true);
        lahan3.on();
        flag = true;
    }
    else
    {
        status_h.setLahan3(false);
        lahan3.off();
    }

    if (doc["lahan4"].as<String>() == "on")
    {
        status_h.setLahan4(true);
        lahan4.on();
        flag = true;
    }
    else
    {
        status_h.setLahan4(false);
        lahan4.off();
    }

    if (flag == true)
    {
        status_h.setMainPump(true);
        mainPump.on();
        if (doc["tipe"].as<String>() == "penyiraman")
        {
            status_h.setWaterPump(true);
            waterPump.on();
            status_h.setNutrientPump(false);
            nutrientPump.off();
        }
        else
        {
            status_h.setWaterPump(false);
            waterPump.off();
            status_h.setNutrientPump(true);
            nutrientPump.on();
        }
    }
    else
    {
        status_h.setMainPump(false);
        status_h.setWaterPump(false);
        status_h.setNutrientPump(false);
        waterPump.off();
        nutrientPump.off();
        mainPump.off();
    }
}

bool Process::getIsSecondsBeat()
{
    if (isDetik == true)
    {
        isDetik = false;
        return true;
    }
    else
    {
        return false;
    }
}

void Process::resetCounter()
{
    counterDetik = 0;
}

bool Process::getIsSeconds3(int seconds)
{
    if (counterDetik3 >= seconds)
    {
        counterDetik3 = 0;
        return true;
    }
    else
    {
        return false;
    }
}

bool Process::getIsSeconds2(int seconds)
{
    if (counterDetik2 >= seconds)
    {
        counterDetik2 = 0;
        return true;
    }
    else
    {
        return false;
    }
}

bool Process::getIsSeconds(int seconds)
{
    if (counterDetik >= seconds)
    {
        counterDetik = 0;
        return true;
    }
    else
    {
        return false;
    }
}

void Process::setStateJadwalTerdekat(bool state)
{
    stateJadwalTerdekat = state;
}

bool Process::getStateJadwalTerdekat()
{
    return stateJadwalTerdekat;
}

void Process::processAutoMode(JsonDocument doc)
{

    if (millis() - lastSecond > 1000)
    {
        input_h.updateSensor();
        this->today = time_h.getDayofThenWeek();
        this->time = time_h.getTime();
        // this->time = time_h.getTimeHourMinute();
        status_h.setDate(time_h.getDate());
        status_h.setTime(time_h.getTimeHourMinute());
        DEBUG_PRINTLN("Day: " + (String)today + " Time: " + (String)this->time);
        lastSecond = millis();
        // DEBUG_PRINTLN("Waktu: " + (String)((duration.toInt() * 60) - ((lastSecond - lastTime) / 1000) < 0 ? 0 : (duration.toInt() * 60) - ((lastSecond - lastTime) / 1000)));
        // DEBUG_PRINTLN("Waktu: " + (String)((lastSecond - lastTime) / 1000));
        DEBUG_PRINTLN("Sisa minggu: " + time_h.getRestOfWeekFrom(doc["date"].as<String>()));

        status_h.setSisaPekan((time_h.getRestOfWeekFrom(doc["date"].as<String>())).toInt());
        status_h.setCurrentPekan((status_h.getTotalPekan() - status_h.getSisaPekan()));
        status_h.setDHTLahan1Temp(input_h.getDHT1Temp());
        status_h.setDHTLahan1Hum(input_h.getDHT1Hum());
        status_h.setDHTLahan2Temp(input_h.getDHT2Temp());
        status_h.setDHTLahan2Hum(input_h.getDHT2Hum());

        DEBUG_PRINTLN(status_h.getTipeTerdekatHariIni());
        DEBUG_PRINTLN(status_h.getWaktuPendajwalanTerdekatHariIni());
        // status_h.updateJSON();
        // DEBUG_PRINTLN(status_h.getStatusJSON().memoryUsage());
        counterDetik++;
        counterDetik2++;
        counterDetik3++;
        isDetik = true;
        // String temp;
        // serializeJson(status_h.getStatusJSON(), temp);
        // DEBUG_PRINTLN("Data To Be Send: " + temp);
        // DEBUG_PRINTLN("Hari ini ada jadwal");
        this->flag = false;
        this->flag_near = false;

        if (doc["mode"].as<String>() == "auto")
        {

            if (time_h.isBefore(doc["date"].as<String>()))
            {
                if (stateAfterJadwal)
                {
                    stateJadwalTerdekat = false;
                }

                if (!stateJadwalTerdekat)
                {
                    jadwalSemua.clear();
                }

                if (state_water_pump == false && state_nutrient_pump == false)
                {
                    processData("air", doc);
                }

                if (state_water_pump == true)
                {
                    pumpHandler("air");
                }

                if (state_nutrient_pump == false && state_water_pump == false)
                {
                    processData("pemupukan", doc);
                }

                if (state_nutrient_pump == true)
                {
                    pumpHandler("pemupukan");
                }

                if (!stateJadwalTerdekat)
                {
                    sort(jadwalSemua.begin(), jadwalSemua.end(), [](const Jadwal &a, const Jadwal &b)
                         { return a.unixTime < b.unixTime; });

                    while (display_h.getItemNumber() > 1)
                    {
                        display_h.jadwal_Delete(1);
                    }

                    for (int i = 0; i < jadwalSemua.size(); i++)
                    {
                        Serial.println(jadwalSemua.at(i).Tanggal + " " + jadwalSemua.at(i).Waktu + " " + jadwalSemua.at(i).durasi + " " + jadwalSemua.at(i).Tipe);
                    }

                    display_h.jadwal_Add(jadwalSemua.at(0).Tanggal + " " + jadwalSemua.at(0).Waktu + " " + jadwalSemua.at(0).durasi + " " + jadwalSemua.at(0).Tipe);
                    display_h.jadwal_Add(jadwalSemua.at(1).Tanggal + " " + jadwalSemua.at(1).Waktu + " " + jadwalSemua.at(1).durasi + " " + jadwalSemua.at(1).Tipe);
                    display_h.jadwal_Add(jadwalSemua.at(2).Tanggal + " " + jadwalSemua.at(2).Waktu + " " + jadwalSemua.at(2).durasi + " " + jadwalSemua.at(2).Tipe);
                    display_h.jadwal_Add(jadwalSemua.at(3).Tanggal + " " + jadwalSemua.at(3).Waktu + " " + jadwalSemua.at(3).durasi + " " + jadwalSemua.at(3).Tipe);

                    stateJadwalTerdekat = true;
                    stateAfterJadwal = false;

                    jadwalSemua.clear();
                }
            }
            else
            {
                DEBUG_PRINTLN("Sisa minggu sudah habis");
            }
        }

        if (!flag && status_h.getPenjadwalanOn() == false)
        {
            DEBUG_PRINTLN("tidak ada Jadwal Terdekat");
            status_h.setTipeTerdekatHariIni("-----");
            status_h.setWaktuPendajwalanTerdekatHariIni("--:--");
        }

        nearest = DateTime(2080, 1, 1, 0, 0, 0);

        DEBUG_PRINTLN("                     =======================================");
    }
}