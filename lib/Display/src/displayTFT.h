#pragma once

#include <dev_config.h>

#ifndef DISPLAYTFT
#define DISPLAYTFT

class DisplayTFT
{
public:
    void jadwal_Add(String jadwal);
    void jadwal_Delete(int position);
    void setStateL1(bool state);
    void setStateL2(bool state);
    void setStateL3(bool state);
    void setStateL4(bool state);
    void setWiFiSignalStrength(int strength);
    void setDate(String date);
    void setTime(String time);
    void setProgress(int progress);
    void addSuhuPoint(float c);
    void setSuhu(float c);
    void addHumPoint(float h);
    void setHum(float h);
    int getItemNumber();
    void changePage(int page);

    void setSSIDText(String t);
    void setAPNameText(String t);
    void loading1Text();
    void reDrawWiFiConnected();
    void loading2Text();
    void setToConfigText();
    void setTimeoutText(String t);

    void setOnShceduleHighlight(bool isLighten);

    void updateAtChanged();

    enum
    {
        Dashboard,
        SplashScreen,
        wifiConnecting,
        wifiConnected,
        wifiNotConnected,
        continueNotWiFi,
        commandReceived
    };

private:
    bool stateL1;
    bool stateL2;
    bool stateL3;
    bool stateL4;
    int wifiSignalStrength;
    String date;
    String time;
    int progress;
    float suhu;
    float hum;

    int loading1Counter = 0;
    int loading2Counter = 0;

    int pos = 0;

    bool isChanged = false;
};

#endif