#include <FastLED.h>  // Include the library. Must do this every time we use a library.

#define NUM_LEDS 3    // Number of LEDs in the LED strip
#define DATA_PIN 3    // The digital pin the LED signal line is connected to.


// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() {
  // Initialize the LED strip.
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}

void loop() {
  // Turn the first LED on, then wait for 0.5 seconds.
  // The format is CRGB(red, green, blue). Value ranges from 0-255, with 255 being the brightest.
  leds[0] = CRGB(255, 0, 0);   // Full red.
  FastLED.show();              // Do this to implement the color change to the LED!
  delay(500);
  
  // Now turn the LED off, then wait for 0.5 seconds.
  leds[0] = CRGB(0, 0, 0);
  FastLED.show();
  delay(500);
}
