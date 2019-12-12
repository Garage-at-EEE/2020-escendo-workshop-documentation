
#include <WiFi.h> //built in library to connect to WiFi
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include "enterprise.h"
#include <FastLED.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).

// Your WiFi credentials.
// Set password to "" for open networks.
        char auth[] = "auth_token";
        char ssid[] = "NTUSECURE";
        char iden[] = "STUDENT\\username";
        char pass[] = "password";
        
// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.

#define DATA_PIN 23 //data pin 23
#define NUM_LEDS 1 // no. of LED is 1

CRGB leds[NUM_LEDS];

int BRIGHTNESS;

BLYNK_WRITE(V2) //Button Widget is writing to pin V1
{
   BRIGHTNESS = param.asInt();
}

void setup()
{
  // Set first led
  leds[0] = CRGB( 255, 255, 255);

    Serial.begin(9600);
    connectEnterprise(auth, ssid, iden, pass);
    FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);

}

void loop()
{
  Blynk.run();
  FastLED.setBrightness(BRIGHTNESS );
  FastLED.show();
//  delay(1000);
}
