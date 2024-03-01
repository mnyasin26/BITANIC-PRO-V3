#include "dev_config.h"
#include "RTClib.h"
#include <NTPClient.h>
#include <WiFi.h>
#include <WiFiUdp.h>

class TimeController
{
private:
    DateTime clock_now;

    unsigned long targetProgress;
    unsigned long initTime;

public:
    TimeController();
    void syncTime();
    void initRTC();
    void updateTime();
    String getTime();
    String getTimeHourMinute();
    String getDay();
    String getDayofThenWeek();
    String getDate();

    bool isDayAfterToday(String day, String today);
    int caclDay(String day, String today, String time, String timeNow);
    String getDateWithCalcDays(int days);
    String getDateWithCalc(int week);
    uint32_t convertToUnixTime(String tanggal, String waktu);
    bool isBefore(String date);
    String getRestOfWeekFrom(String date);
    void getSourceTime();
    String convertDuration(int durationMinute, int durationSecond);

    String getMonth();
    String getYear();
    String getHour();
    String getMinute();
    String getSecond();

    void initProgress(unsigned long durationInSeconds);

    int getUpdateProgress();




    ~TimeController();
};
