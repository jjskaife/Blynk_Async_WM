/****************************************************************************************************************************
   defines.h
   For ESP32 boards

   Blynk_Async_WM is a library, using AsyncWebServer instead of (ESP8266)WebServer for the ESP8266/ESP32 to enable easy
   configuration/reconfiguration and autoconnect/autoreconnect of WiFi/Blynk.
   
   Based on and modified from Blynk library v0.6.1 (https://github.com/blynkkk/blynk-library/releases)
   Built by Khoi Hoang (https://github.com/khoih-prog/Blynk_Async_WM)
   Licensed under MIT license
   Version: 1.0.16

   Version    Modified By   Date      Comments
   -------    -----------  ---------- -----------
    1.0.16    K Hoang      25/08/2020 Initial coding to use (ESP)AsyncWebServer instead of (ESP8266)WebServer. 
                                      Bump up to v1.0.16 to sync with Blynk_WM v1.0.16
 *****************************************************************************************************************************/

#ifndef defines_h
#define defines_h

#ifndef ESP32
  #error This code is intended to run on the ESP32 platform! Please check your Tools->Board setting.
#endif

#define BLYNK_PRINT Serial

#define DOUBLERESETDETECTOR_DEBUG     false
#define BLYNK_WM_DEBUG                0

// Not use #define USE_SPIFFS  => using EEPROM for configuration data in WiFiManager
// #define USE_SPIFFS    false => using EEPROM for configuration data in WiFiManager
// #define USE_SPIFFS    true  => using SPIFFS for configuration data in WiFiManager
// Be sure to define USE_SPIFFS before #include <BlynkSimpleEsp8266_WM.h>

#define USE_SPIFFS                  true
//#define USE_SPIFFS                  false

#if (!USE_SPIFFS)
  // EEPROM_SIZE must be <= 2048 and >= CONFIG_DATA_SIZE (currently 172 bytes)
  #define EEPROM_SIZE    (2 * 1024)
  // EEPROM_START + CONFIG_DATA_SIZE must be <= EEPROM_SIZE
  #define EEPROM_START   0
#endif

// Force some params in Blynk, only valid for library version 1.0.1 and later
#define TIMEOUT_RECONNECT_WIFI                    10000L
#define RESET_IF_CONFIG_TIMEOUT                   true
#define CONFIG_TIMEOUT_RETRYTIMES_BEFORE_RESET    5
// Those above #define's must be placed before #include <BlynkSimpleEsp8266_Async_WM.h>

//You have to download Blynk WiFiManager Blynk_Async_WM library at //https://github.com/khoih-prog/Blynk_Async_WM
// In order to enable (USE_BLYNK_WM = true). Otherwise, use (USE_BLYNK_WM = false)
#define USE_BLYNK_WM   true
//#define USE_BLYNK_WM   false


//#define USE_SSL     true
#define USE_SSL     false

#if USE_BLYNK_WM
  #if USE_SSL
    #include <BlynkSimpleEsp32_SSL_Async_WM.h>        //https://github.com/khoih-prog/Blynk_Async_WM
  #else
    #include <BlynkSimpleEsp32_Async_WM.h>            //https://github.com/khoih-prog/Blynk_Async_WM
  #endif

  #include "Credentials.h"
  #include "dynamicParams.h"

#else
  #if USE_SSL
    #include <BlynkSimpleEsp32_SSL.h>
    #define BLYNK_HARDWARE_PORT     9443
  #else
    #include <BlynkSimpleEsp32.h>
    #define BLYNK_HARDWARE_PORT     8080
  #endif
#endif

#if !USE_BLYNK_WM

  #ifndef LED_BUILTIN
    #define LED_BUILTIN       2         // Pin D2 mapped to pin GPIO2/ADC12 of ESP32, control on-board LED
  #endif
  
  #define USE_LOCAL_SERVER    true
  //#define USE_LOCAL_SERVER    false
  
  // If local server
  #if USE_LOCAL_SERVER
    char blynk_server[]   = "yourname.duckdns.org";
  #endif
  
  char auth[]     = "***";
  char ssid[]     = "***";
  char pass[]     = "***";

#endif

#define PIN_D22   22            // Pin D22 mapped to pin GPIO22/SCL of ESP32

#define DHT_PIN     PIN_D22     // pin DATA @ D22 / GPIO22
#define DHT_TYPE    DHT11

#define HOST_NAME   "ESP32-DHT11-Async"

#endif      //defines_h
