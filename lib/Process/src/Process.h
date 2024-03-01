#include "dev_config.h"

#include <ArduinoJson.h>
#include <Output.h>
#include <ArduinoQueue.h>
#include <timeController.h>
#include <Status.h>
#include <Input.h>

// Queue creation:
typedef struct
{
    int id;
    int duration = 0;
    int tipe;
    int seconds = 0;
    bool isPemupukan = false;

} LandsConfig;

typedef struct
{
    String Tanggal;
    String Waktu;
    String durasi;
    String Tipe;
    uint32_t unixTime;
} Jadwal;

class Process
{
public:
    Process();

    void processAutoMode(JsonDocument doc);
    void processManualMode(JsonDocument doc);
    void processData(String type, JsonDocument doc);
    void pumpHandler(String type);
    void buzzerBeep(unsigned long ms);
    bool getIsSecondsBeat();
    bool getIsSeconds(int seconds);
    bool getIsSeconds2(int seconds);
    bool getIsSeconds3(int seconds);
    void resetCounter();
    void jadwalTerdekat(JsonDocument doc);
    void resetQueue();

    void setStateJadwalTerdekat(bool state);
    bool getStateJadwalTerdekat();

private:
    int stateJadwalTerdekat = 0;
    bool stateAfterJadwal = false;
    int counterDetik = 999;
    int counterDetik2 = 999;
    int counterDetik3 = 999;
    LandsConfig current_land;
    bool isOperate;
    bool isDelay;
    bool state_water_pump;
    bool state_nutrient_pump;
    bool isBuzzer;
    String delay_over_lands;
    String *lands;
    String time;
    String today;
    unsigned long timerBuzzer;
    unsigned long lastTime;
    unsigned long timerDelay;
    unsigned long lastSecond;
    unsigned long second;
    DateTime nearest;
    bool flag = false;
    bool flag_near = false;

    bool isDetik;
    // day_t days;
};
