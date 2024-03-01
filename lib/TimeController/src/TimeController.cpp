#include "TimeController.h"

// extern TwoWire WireAlt;

const long utcOffsetInSeconds = 25200;
RTC_DS3231 rtc;
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "id.pool.ntp.org", utcOffsetInSeconds);

TimeController::TimeController()
{
}

TimeController::~TimeController()
{
}

void TimeController::initProgress(unsigned long durationInSeconds){
    unsigned long secondStamp = (unsigned long)(millis() * 0.001);
    targetProgress = secondStamp  + durationInSeconds;
    initTime = secondStamp;
}

int TimeController::getUpdateProgress(){
    unsigned long currentTime = (unsigned long)(millis() * 0.001);
    int res = (int)(map(currentTime, initTime, targetProgress, 0, 100));
    Serial.print("[DEBUGGGG] ");
    Serial.println(currentTime);
    Serial.println(initTime);
    Serial.println(targetProgress);
    Serial.println(res);
    return res;
}

int TimeController::caclDay(String day, String today, String time, String timeNow)
{
    int dayInt = 0;
    int todayInt = 0;

    if (day == "senin")
    {
        dayInt = 1;
    }
    else if (day == "selasa")
    {
        dayInt = 2;
    }
    else if (day == "rabu")
    {
        dayInt = 3;
    }
    else if (day == "kamis")
    {
        dayInt = 4;
    }
    else if (day == "jum'at")
    {
        dayInt = 5;
    }
    else if (day == "sabtu")
    {
        dayInt = 6;
    }
    else if (day == "minggu")
    {
        dayInt = 7;
    }

    if (today == "senin")
    {
        todayInt = 1;
    }
    else if (today == "selasa")
    {
        todayInt = 2;
    }
    else if (today == "rabu")
    {
        todayInt = 3;
    }
    else if (today == "kamis")
    {
        todayInt = 4;
    }
    else if (today == "jum'at")
    {
        todayInt = 5;
    }
    else if (today == "sabtu")
    {
        todayInt = 6;
    }
    else if (today == "minggu")
    {
        todayInt = 7;
    }

    if (dayInt < todayInt)
    {
        dayInt += 7;
    }

    // time 10:00:00
    // timeNow 11:00:00

    if (time.length() == 5)
    {
        time = time + ":00";
    }

    if (today == day)
    {
        if (timeNow.substring(0, 2).toInt() > time.substring(0, 2).toInt())
        {
            dayInt += 7;
            DEBUG_PRINTLN("TITIK 1");
        }
        else if (timeNow.substring(0, 2).toInt() == time.substring(0, 2).toInt())
        {
            if (timeNow.substring(3, 5).toInt() > time.substring(3, 5).toInt())
            {
                dayInt += 7;
                DEBUG_PRINTLN("TITIK 2");
            }
            else if (timeNow.substring(3, 5).toInt() == time.substring(3, 5).toInt()){
                if (timeNow.substring(6, 8).toInt() > time.substring(6, 8).toInt())
                {
                    dayInt += 7;
                    DEBUG_PRINTLN("TITIK 3");
                }
            }
        }
    }

    DEBUG_PRINTLN(time);
    DEBUG_PRINTLN(timeNow);

    return dayInt - todayInt;
}

bool TimeController::isDayAfterToday(String day, String today)
{
    int dayInt = 0;
    int todayInt = 0;

    if (day == "senin")
    {
        dayInt = 1;
    }
    else if (day == "selasa")
    {
        dayInt = 2;
    }
    else if (day == "rabu")
    {
        dayInt = 3;
    }
    else if (day == "kamis")
    {
        dayInt = 4;
    }
    else if (day == "jum'at")
    {
        dayInt = 5;
    }
    else if (day == "sabtu")
    {
        dayInt = 6;
    }
    else if (day == "minggu")
    {
        dayInt = 7;
    }

    if (today == "senin")
    {
        todayInt = 1;
    }
    else if (today == "selasa")
    {
        todayInt = 2;
    }
    else if (today == "rabu")
    {
        todayInt = 3;
    }
    else if (today == "kamis")
    {
        todayInt = 4;
    }
    else if (today == "jum'at")
    {
        todayInt = 5;
    }
    else if (today == "sabtu")
    {
        todayInt = 6;
    }
    else if (today == "minggu")
    {
        todayInt = 7;
    }

    if (dayInt >= todayInt)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void TimeController::updateTime()
{
    if (timeClient.update())
    {
        time_t epochTime = timeClient.getEpochTime();
        struct tm *ptm = NULL;
        ptm = gmtime((time_t *)&epochTime);
        int monthDay = ptm->tm_mday;
        DEBUG_PRINT("Month day: ");
        DEBUG_PRINTLN(monthDay);

        int currentMonth = ptm->tm_mon + 1;
        DEBUG_PRINT("Month: ");
        DEBUG_PRINTLN(currentMonth);

        int currentYear = ptm->tm_year + 1900;
        DEBUG_PRINT("Year: ");
        DEBUG_PRINTLN(currentYear);

        // Print complete date:
        String currentDate = String(currentYear) + "-" + String(currentMonth) + "-" + String(monthDay);
        DEBUG_PRINT("Current date: ");
        DEBUG_PRINTLN(currentDate);

        // Kalibrasi Waktu RTC dengan NTP
        // rtc.begin();
        // DateTime now = rtc.now();

        // int64_t rtc_current_time = now.unixtime();
        // int64_t ntp_current_time = epochTime;

        // DEBUG_PRINT("RTC time: " + (String)now.unixtime());
        // DEBUG_PRINT(" NTP time: " + (String)epochTime);

        if (currentYear != 2036)
        {

            if (rtc.lostPower())
            {
                rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
                DEBUG_PRINTLN("RTC lost power, let's set the time!");
            }

            rtc.adjust(DateTime(currentYear, currentMonth, monthDay, timeClient.getHours(), timeClient.getMinutes(), timeClient.getSeconds()));
            DEBUG_PRINTLN("Time synced");
        }
        else
        {
            DEBUG_PRINTLN("Time Not Synced, NTP Error");
        }
    }
    else
    {
        DEBUG_PRINTLN("Time Not Synced, NTP Not Available");
    }
}

String TimeController::getDate()
{
    // DateTime now = rtc.now();
    String day = clock_now.day() < 10 ? "0" + String(clock_now.day()) : String(clock_now.day());
    String month = clock_now.month() < 10 ? "0" + String(clock_now.month()) : String(clock_now.month());
    String year = String(clock_now.year());
    String date = day + "/" + month + "/" + year;
    return date;
}

String TimeController::convertDuration(int durationMinute, int durationSecond)
{
    int hour = durationMinute / 60;
    int minute = durationMinute % 60;
    int second = durationSecond;

    String hourStr = hour < 10 ? "0" + String(hour) : String(hour);
    String minuteStr = minute < 10 ? "0" + String(minute) : String(minute);
    String secondStr = second < 10 ? "0" + String(second) : String(second);

    String duration = hourStr + ":" + minuteStr + ":" + secondStr;
    return duration;
}

String TimeController::getRestOfWeekFrom(String date)
{
    // 01/01/2021
    // DateTime now = rtc.now();
    DateTime target = DateTime(date.substring(6, 10).toInt(), date.substring(3, 5).toInt(), date.substring(0, 2).toInt(), 0, 0, 0);
    TimeSpan rest;
    if (clock_now > target)
    {
        rest = TimeSpan(0, 0, 0, 0);
    }
    else
    {
        rest = target - clock_now;
    }

    String restString = String(rest.days() / 7);
    return restString;
}

bool TimeController::isBefore(String date)
{
    // 01/01/2021
    // DateTime now = rtc.now();
    DateTime target = DateTime(date.substring(6, 10).toInt(), date.substring(3, 5).toInt(), date.substring(0, 2).toInt(), 0, 0, 0);
    if (clock_now <= target)
    {
        return true;
    }
    else
    {
        return false;
    }
}

uint32_t TimeController::convertToUnixTime(String tanggal, String waktu)
{
    // 01/01/2021 00:00:00
    // DateTime now = rtc.now();
    DateTime target = DateTime(tanggal.substring(6, 10).toInt(), tanggal.substring(3, 5).toInt(), tanggal.substring(0, 2).toInt(), waktu.substring(0, 2).toInt(), waktu.substring(3, 5).toInt(), waktu.substring(6, 8).toInt());
    return target.unixtime();
}

String TimeController::getDateWithCalcDays(int days)
{
    // DateTime now = rtc.now();
    DateTime now = clock_now;
    now = now + TimeSpan(days, 0, 0, 0);
    String day = now.day() < 10 ? "0" + String(now.day()) : String(now.day());
    String month = now.month() < 10 ? "0" + String(now.month()) : String(now.month());
    String year = String(now.year());
    String date = day + "/" + month + "/" + year;
    return date;
}

String TimeController::getDateWithCalc(int week)
{
    // DateTime now = rtc.now();
    DateTime now = clock_now;
    now = now + TimeSpan(week * 7, 0, 0, 0);
    String day = now.day() < 10 ? "0" + String(now.day()) : String(now.day());
    String month = now.month() < 10 ? "0" + String(now.month()) : String(now.month());
    String year = String(now.year());
    String date = day + "/" + month + "/" + year;
    return date;
}

void TimeController::initRTC()
{
    if (!rtc.begin(&Wire))
    {
        DEBUG_PRINTLN("Couldn't find RTC");
        Serial.flush();
    }
    else
    {
        clock_now = rtc.now();
    }
}

void TimeController::getSourceTime()
{
    clock_now = rtc.now();
}

void TimeController::syncTime()
{

    if (rtc.lostPower())
    {
        DEBUG_PRINTLN("RTC lost power, let's set the time!");
        // When time needs to be set on a new device, or after a power loss, the
        // following line sets the RTC to the date & time this sketch was compiled
        rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
        // This line sets the RTC with an explicit date & time, for example to set
        // January 21, 2014 at 3am you would call:
        // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
    }

    timeClient.begin();
    time_t epochTime = timeClient.getEpochTime();
    struct tm *ptm = NULL;

    if (timeClient.update())
    {
        epochTime = timeClient.getEpochTime();
        // Get a time structure
        ptm = gmtime((time_t *)&epochTime);

        // DateTime now = timeClient.getEpochTime();
        // DEBUG_PRINTLN(
        //     String(now.year()) + "-" +
        //     String(now.month()) + "-" +
        //     String(now.day()) + " " +
        //     String(now.hour()) + ":" +
        //     String(now.minute()) + ":" +
        //     String(now.second()));
        // rtc.adjust(now);

        // time_t epochTime = timeClient.getEpochTime();
        // Get a time structure
        // ptm = gmtime((time_t *)&epochTime);

        int monthDay = ptm->tm_mday;
        DEBUG_PRINT("Month day: ");
        DEBUG_PRINTLN(monthDay);

        int currentMonth = ptm->tm_mon + 1;
        DEBUG_PRINT("Month: ");
        DEBUG_PRINTLN(currentMonth);

        int currentYear = ptm->tm_year + 1900;
        DEBUG_PRINT("Year: ");
        DEBUG_PRINTLN(currentYear);

        if (currentYear != 2036)
        {
            // Print complete date:
            String currentDate = String(currentYear) + "-" + String(currentMonth) + "-" + String(monthDay);
            DEBUG_PRINT("Current date: ");
            DEBUG_PRINTLN(currentDate);

            // Kalibrasi Waktu RTC dengan NTP
            // rtc.begin();
            // DateTime now = rtc.now();

            // int64_t rtc_current_time = now.unixtime();
            // int64_t ntp_current_time = epochTime;

            // DEBUG_PRINT("RTC time: " + (String)now.unixtime());
            // DEBUG_PRINT(" NTP time: " + (String)epochTime);

            if (rtc.lostPower())
            {
                rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
                DEBUG_PRINTLN("RTC lost power, let's set the time!");
            }

            rtc.adjust(DateTime(currentYear, currentMonth, monthDay, timeClient.getHours(), timeClient.getMinutes(), timeClient.getSeconds()));
            clock_now = rtc.now();
            DEBUG_PRINTLN("Time synced");
        }
    }
    else
    {
        clock_now = rtc.now();
        DEBUG_PRINTLN("Time Not Synced, NTP Not Available");
    }

    // else
    // {
    //     if (!(ntp_current_time - rtc_current_time > 1000) && !(ntp_current_time - rtc_current_time < -1000))
    //     {

    //         DEBUG_PRINTLN("Time synced");
    //         /* code */
    //     }
    //     else
    //     {
    //         // DEBUG_PRINTLN("Time not synced, NTP not available");
    //         /* code */
    //     }
    // }
}

String TimeController::getTime()
{
    // DateTime now = rtc.now();
    String hour = clock_now.hour() < 10 ? "0" + String(clock_now.hour()) : String(clock_now.hour());
    String minute = clock_now.minute() < 10 ? "0" + String(clock_now.minute()) : String(clock_now.minute());
    String second = clock_now.second() < 10 ? "0" + String(clock_now.second()) : String(clock_now.second());
    String time = hour + ":" + minute + ":" + second;
    return time;
}

String TimeController::getTimeHourMinute()
{
    // DateTime now = rtc.now();
    String hour = clock_now.hour() < 10 ? "0" + String(clock_now.hour()) : String(clock_now.hour());
    String minute = clock_now.minute() < 10 ? "0" + String(clock_now.minute()) : String(clock_now.minute());
    String time = hour + ":" + minute;
    return time;
}

String TimeController::getDay()
{
    // DateTime now = rtc.now();
    String day = String(clock_now.day());

    return day;
}

String TimeController::getDayofThenWeek()
{
    // DateTime now = rtc.now();
    String day = String(clock_now.dayOfTheWeek());
    if (day == "1")
    {
        day = "senin";
    }
    else if (day == "2")
    {
        day = "selasa";
    }
    else if (day == "3")
    {
        day = "rabu";
    }
    else if (day == "4")
    {
        day = "kamis";
    }
    else if (day == "5")
    {
        day = "jum'at";
    }
    else if (day == "6")
    {
        day = "sabtu";
    }
    else if (day == "0")
    {
        day = "minggu";
    }

    return day;
}

String TimeController::getMonth()
{
    // DateTime now = rtc.now();
    String month = String(clock_now.month());
    return month;
}

String TimeController::getYear()
{
    // DateTime now = rtc.now();
    String year = String(clock_now.year());
    return year;
}

String TimeController::getHour()
{
    // DateTime now = rtc.now();
    String hour = String(clock_now.hour());
    return hour;
}

String TimeController::getMinute()
{
    // DateTime now = rtc.now();
    String minute = String(clock_now.minute());
    return minute;
}

String TimeController::getSecond()
{
    // DateTime now = rtc.now();
    String second = String(clock_now.second());
    return second;
}
