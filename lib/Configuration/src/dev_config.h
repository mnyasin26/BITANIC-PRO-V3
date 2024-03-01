#include <Arduino.h>

// MACRO
#define WIFI_SET_AUTOCONNECT 0
#define WIFI_SET_ONDEMAND 1
#define JSON_SIZE 3800
#define DELAY_LCD_UPDATE 50
#define QUEUE_SIZE_ITEMS 10
#define MINUTE 60

// PIN CONFIGURATION
#define DHTPIN1 15
// #define DHTPIN2 32
#define DHTTYPE DHT22
#define MAIN_PUMP_PIN 2
#define WATER_PUMP_PIN 3
#define NUTRIENT_PUMP_PIN 4
#define LAHAN1_PUMP_PIN 5
#define LAHAN2_PUMP_PIN 16
#define LAHAN3_PUMP_PIN 19
#define LAHAN4_PUMP_PIN 20
#define BUZZER_PIN 14
#define LED_PIN_PENYIRAMAN 12
#define LED_PIN_PEMUPUKAN 13

#define DEVICE_ID "BT13"
#define DEVICE_FIRMWARE_VERSION "3.0.0"

#define MQTT_ID "BITANIC_BT13"
#define MQTT_SERVER "bitanic.id"
#define MQTT_TOPIC "bitanic/BT13"
#define MQTT_TOPIC_PUBLISH "bitanic"

#define WIFI_AP_NAME "BT_SETTING"
#define WIFI_AP_PASSWORD "admin1234"

// MQTT broker ferads host
// mqtt://ferads.my.id:1883

#define DEBUG_PROGRAM true

// DEBUG
#define DEBUG_WIFI_MANAGER true
#define DEBUG_MQTT true

#if DEBUG_PROGRAM == true
#define DEBUG_PRINT(x) Serial.print(x)
#define DEBUG_PRINTLN(x) Serial.println(x)
#define DEBUG_PRINTF(x, y) Serial.printf(x, y)
#else
#define DEBUG_PRINT(x)
#define DEBUG_PRINTLN(x)
#define DEBUG_PRINTF(x, y)
#endif

