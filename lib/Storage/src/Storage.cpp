#include "Storage.h"
#include "TimeController.h"

extern TimeController time_h;

Storage::Storage()
{
}

void Storage::startEEPROM(int size)
{
    EEPROM.begin(size);
}

void Storage::saveConfig(JsonDocument doc)
{
    EEPROM.begin(4000);

    String date = time_h.getDateWithCalc(doc["jadwal"]["minggu"].as<int>());
    DEBUG_PRINTLN(date);
    doc["date"] = date;

    String test;
    serializeJson(doc, test);
    // DEBUG_PRINTLN(test);

    EEPROM.writeString(500, test);
    // DEBUG_PRINTLN(test);

    EEPROM.commit();
    EEPROM.end();
    // Close the file
}

JsonDocument Storage::loadConfig()
{
    EEPROM.begin(4000);
    // Open file for reading
    JsonDocument doc;
    String test;
    test = EEPROM.readString(500);
    // DEBUG_PRINTLN(test);
    DeserializationError error = deserializeJson(doc, test);
    if (error)
    {
        DEBUG_PRINTLN(F("Failed to read file, using default configuration"));
        doc["status"] = "error";
        return doc;
    }

    // DEBUG_PRINTLN(doc["ssid"].as<String>());
    // EEPROM.end();
    return doc;
    // Extract each characters by one by one
    // while (file.available()) {
    //   DEBUG_PRINT((char)file.read());
    // }
    // DEBUG_PRINTLN();

    // Close the file
    EEPROM.end();
}