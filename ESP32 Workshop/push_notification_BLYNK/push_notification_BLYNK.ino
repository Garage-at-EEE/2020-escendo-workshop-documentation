#include <WiFi.h> //built in library to connect to WiFi
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include "enterprise.h"

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).

// Your WiFi credentials.
// Set password to "" for open networks.
        char auth[] = "auth_token";
        char ssid[] = "NTUSECURE";
        char iden[] = "STUDENT\\username";
        char pass[] = "password";

void setup() {
   Serial.begin(9600);
  connectEnterprise(auth, ssid, iden, pass);

}

void loop() {
  String c=Serial.readString();
  Blynk.notify(c);
 Blynk.run();
}
