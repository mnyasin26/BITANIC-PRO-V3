// // Date and time functions using a DS3231 RTC connected via I2C and Wire lib
// #include "RTClib.h"
// #include <SPI.h>
// #include <FS.h>
// #include <SPIFFS.h>

// RTC_DS3231 rtc;

// /*********
//   Rui Santos
//   Complete project details at https://randomnerdtutorials.com
// *********/

// #include <Wire.h>

// void setup() {
//   Wire.begin(8, 9);
//   Serial.begin(115200);
//   DEBUG_PRINTLN("\nI2C Scanner");
// }

// void loop() {
//   byte error, address;
//   int nDevices;
//   DEBUG_PRINTLN("Scanning...");
//   nDevices = 0;
//   for(address = 1; address < 127; address++ ) {
//     Wire.beginTransmission(address);
//     DEBUG_PRINT("address: ");
//     DEBUG_PRINTLN(address);
//     error = Wire.endTransmission();
//     if (error == 0) {
//       DEBUG_PRINT("I2C device found at address 0x");
//       if (address<16) {
//         DEBUG_PRINT("0");
//       }
//       DEBUG_PRINTLN(address,HEX);
//       nDevices++;
//     }
//     else if (error==4) {
//       DEBUG_PRINT("Unknow error at address 0x");
//       if (address<16) {
//         DEBUG_PRINT("0");
//       }
//       DEBUG_PRINTLN(address,HEX);
//     }
//   }
//   if (nDevices == 0) {
//     DEBUG_PRINTLN("No I2C devices found\n");
//   }
//   else {
//     DEBUG_PRINTLN("done\n");
//   }
//   delay(5000);
// }