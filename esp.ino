// This is to make the node mcu work with cayenne api.
// for some reason it does not work without the blynk header file.
#include <ESP8266WiFi.h>
#include "CayenneDefines.h"
#include "BlynkSimpleEsp8266.h"
#include "CayenneWiFiClient.h"


#define CAYANNE_DEBUG
#define VIRTUAL_PIN V1
#define VIRTUAL_PIN V2
#define RELAY_DIGITAL_PIN1 5
#define RELAY_DIGITAL_PIN2 12


// Cayenne authentication token. This should be obtained from the Cayenne Dashboard.
char token[] = "g88nznkh8y"; // Insert your token here
char ssid[] = "Panchal2"; // Insert your SSID here
char pwd[] = "omkaar2011"; // Insert your SSID password here

void setup() {
  // put your setup code here, to run once:
  pinMode(RELAY_DIGITAL_PIN1, OUTPUT);
  pinMode(RELAY_DIGITAL_PIN2, OUTPUT);

  Serial.begin(115200);
  Cayenne.begin(token, ssid, pwd);
}

CAYENNE_IN(V1)
{
  // get value sent from dashboard
  int currentValue = getValue.asInt(); // 0 to 1

  // assuming you wire your relay as normally open
  if (currentValue == 0) {
    digitalWrite(RELAY_DIGITAL_PIN1, HIGH);
  } else {
    digitalWrite(RELAY_DIGITAL_PIN1, LOW);
  }
}
CAYENNE_IN(V2)
{
  // get value sent from dashboard
  int currentValue = getValue.asInt(); // 0 to 1

  // assuming you wire your relay as normally open
  if (currentValue == 0) {
    digitalWrite(RELAY_DIGITAL_PIN2, HIGH);
  } else {
    digitalWrite(RELAY_DIGITAL_PIN2, LOW);
  }
}
void loop() {
  // put your main code here, to run repeatedly:
  Cayenne.run();
}

