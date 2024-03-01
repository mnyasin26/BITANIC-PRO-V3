#include <Arduino.h>
#include "dev_config.h"
#include <Connection.h>
#include <Storage.h>
#include <Process.h>
#include <displayTFT.h>
#define _TASK_SLEEP_ON_IDLE_RUN
#include <TaskScheduler.h>
#include <SPI.h>
#include <OneButton.h>

#include "GUIslice.h"
#include "GUIslice_drv.h"

extern gslc_tsGui m_gui;
void InitGUIslice_gen();

// ------------------------------------------------
// Program Globals
// ------------------------------------------------

int pos = 0;
extern bool isDeleted;

// enum
// {
//     Dashboard,
//     SplashScreen,
//     wifiConnecting,
//     wifiConnected,
//     wifiNotConnected,
//     continueNotWiFi,
//     commandReceived
// };

JsonDocument doc;
Process processor;
Connection con;
Storage storage;
extern TimeController time_h;
extern Status status_h;
extern Input input_h;
DisplayTFT display_h;
Scheduler runner;

TaskHandle_t Task1;
TaskHandle_t Task2;

unsigned long lastTimeWifiManager = 0;

bool stateConBefore = false;

OneButton button(0, true);

void restartWiFiManager();

void setup()
{
    Wire.begin(8, 9);
    Serial.begin(115200);

    DEBUG_PRINTLN("Starting...");

    InitGUIslice_gen();
    gslc_GuiRotate(&m_gui, 3);
    gslc_Update(&m_gui);

    status_h.setID(DEVICE_ID);
    status_h.setFirmwareVersion(DEVICE_FIRMWARE_VERSION);
    status_h.setActivation(true);
    status_h.setTotalOutput(6);
    status_h.setTotalInput(4);

    // display_h.initLCD();
    processor.buzzerBeep(500);
    delay(500);
    processor.buzzerBeep(500);
    // display_h.displayWifiConnecting();

    delay(3000);
    display_h.setSSIDText("\"" + con.getSavedWifiSSID() + "\"");
    display_h.changePage(display_h.wifiConnecting);

    DEBUG_PRINTLN("Connecting to WiFi...");
    DEBUG_PRINTLN(con.getSavedWifiSSID());
    DEBUG_PRINTLN(con.getSavedWifiPassword());
    WiFi.mode(WIFI_STA);
    WiFi.begin(con.getSavedWifiSSID().c_str(), con.getSavedWifiPassword().c_str());

    int tempCounter = 0;
    while (tempCounter < 10 && WiFi.status() != WL_CONNECTED)
    {
        if ((millis() - lastTimeWifiManager) > 1000)
        {
            DEBUG_PRINTLN("Connecting...");
            lastTimeWifiManager = millis();
            tempCounter++;
            // display_h.loading1Text();
        }
    }

    if (WiFi.status() != WL_CONNECTED)
    {
        processor.buzzerBeep(1000);
        DEBUG_PRINTLN("WiFi failed to connect");

        display_h.setAPNameText("Connect \"" + (String)WIFI_AP_NAME  + "\"");
        display_h.setToConfigText();
        display_h.setTimeoutText("60");

        display_h.changePage(display_h.wifiNotConnected);
        // display_h.displayWifiNotConnected();
        // display_h.displayWifiManagerStarted(WIFI_AP_NAME, 60);
        con.startWiFiManagerNonBlocking(WIFI_AP_NAME, WIFI_AP_PASSWORD, 60);
        while (con.portalRunning)
        {
            con.doWiFiManager();
            if ((millis() - lastTimeWifiManager) > 1000)
            {
                // display_h.loading2Text();
                lastTimeWifiManager = millis();
                DEBUG_PRINTLN("Loading...");
            }
        }
    }

    if (WiFi.status() == WL_CONNECTED)
    {
        processor.buzzerBeep(200);
        delay(100);
        processor.buzzerBeep(200);
        delay(100);
        processor.buzzerBeep(200);
        // display_h.reDrawWiFiConnected();
        display_h.changePage(display_h.wifiConnected);
        // display_h.displayWifiConnected();
        DEBUG_PRINTLN("WiFi connected");
        stateConBefore = true;
        con.connectMQTT(MQTT_SERVER, 1883, MQTT_ID);
        con.mqttSubscribe(MQTT_TOPIC);
    }
    else
    {
        stateConBefore = false;
        processor.buzzerBeep(1000);
        display_h.changePage(display_h.continueNotWiFi);
        // display_h.displayContinueWithoutWiFi();
        DEBUG_PRINTLN("WiFi failed to connect");
        DEBUG_PRINTLN("Continue without WiFi...");
        // WiFi.disconnect();
    }

    delay(100);
    time_h.initRTC();
    if (WiFi.status() == WL_CONNECTED)
    {
        time_h.syncTime();
    }

    delay(100);

    // load config
    input_h.initSensor();

    doc = storage.loadConfig();
    status_h.updateFromLoadConfig(doc);

    DEBUG_PRINTLN(getArduinoLoopTaskStackSize());
    DEBUG_PRINTLN(getCpuFrequencyMhz());

    DEBUG_PRINTLN("Config loaded");
    button.attachClick(restartWiFiManager);

    delay(1000);
    display_h.changePage(display_h.Dashboard);
}

unsigned long lastTime = 0;

void loop()
{

    if (millis() - lastTime > 500)
    {
        time_h.getSourceTime();
        lastTime = millis();
    }

    // save config
    String temp = con.getLastMessage();
    if (temp != "")
    {
        deserializeJson(doc, temp);
        // serializeJson(doc, temp);
        // DEBUG_PRINTLN(temp);
        DEBUG_PRINTLN(doc["mode"].as<String>());
        if (doc["mode"].as<String>() == "auto")
        {
            storage.saveConfig(doc);
            delay(100);
            doc.clear();
            doc = storage.loadConfig();
            String temp;
            serializeJson(doc, temp);
            DEBUG_PRINTLN(temp);
            status_h.updateFromLoadConfig(doc);
            status_h.setIsStatusChanged(true);
            processor.resetQueue();

            processor.setStateJadwalTerdekat(false);
            processor.buzzerBeep(500);
        }
        else if (doc["mode"].as<String>() == "manual")
        {
            processor.buzzerBeep(500);
            processor.processManualMode(doc);
            doc.clear();
            doc = storage.loadConfig();
        }
    }

    if (processor.getIsSeconds3(60))
    {
        display_h.addSuhuPoint(random(200, 400) / 10.0);
        display_h.addHumPoint(random(600, 800) / 10.0);
    }

    if (processor.getIsSeconds2(120))
    {
        DEBUG_PRINTLN("Reinit LCD");
        // display_h.reinitLCD();
    }

    if (processor.getIsSeconds(10))
    {
        if (con.isMqttConnected())
        {
            DEBUG_PRINTLN("Sending Data...");
            String temp;

            serializeJson(status_h.getStatusJSON(), temp);
            con.mqttPublish(MQTT_TOPIC_PUBLISH, temp);
            time_h.updateTime();
        }

        if (WiFi.status() != WL_CONNECTED)
        {
            DEBUG_PRINTLN("[ATTENTION] !WiFi, reconnecting");
            con.reconnectWiFi();
        }
    }

    if (status_h.isStatusChanged())
    {
        processor.resetCounter();
        if (con.isMqttConnected())
        {
            DEBUG_PRINTLN("Sending Immedietly...");

            String temp;

            serializeJson(status_h.getStatusJSON(), temp);
            con.mqttPublish(MQTT_TOPIC_PUBLISH, temp);
        }
        else
        {
            DEBUG_PRINTLN("[ATTENTION] !Internet, Waiting Connecion");
        }
    }

    if (processor.getIsSecondsBeat())
    {
        
        con.connectionLoopMQTT();

        if (WiFi.status() == WL_CONNECTED)
        {
            int sig = WiFi.RSSI();
            if (sig <= -80)
            {
                display_h.setWiFiSignalStrength(1);
            }
            else if (sig >= -79 && sig <= -60)
            {
                display_h.setWiFiSignalStrength(2);
            }
            else if (sig >= -59)
            {
                display_h.setWiFiSignalStrength(3);
            }
        }
        else
        {
            display_h.setWiFiSignalStrength(0);
        }

        display_h.setSuhu(random(200, 400) / 10.0);

        display_h.setHum(random(600, 900) / 10.0);
        display_h.setDate(time_h.getDate());
        display_h.setTime(time_h.getTime());
    }

    if (con.isConnected() != stateConBefore)
    {
        stateConBefore = con.isConnected();
        if (stateConBefore)
        {
            processor.buzzerBeep(200);
            delay(100);
            processor.buzzerBeep(200);
            delay(100);
            processor.buzzerBeep(200);
        }
        else
        {
            processor.buzzerBeep(1000);
        }
    }

    display_h.setStateL1(status_h.getLahan1());
    display_h.setStateL2(status_h.getLahan2());
    display_h.setStateL3(status_h.getLahan3());
    display_h.setStateL4(status_h.getLahan4());

    processor.processAutoMode(doc);
    con.connectionLoop();
    button.tick();
}

void restartWiFiManager()
{
    con.startWiFiManager(WIFI_AP_NAME, WIFI_AP_PASSWORD, WIFI_SET_ONDEMAND, 60);
}
