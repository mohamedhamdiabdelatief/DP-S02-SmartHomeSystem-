/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************

  This example shows how to synchronize Button widget
  and physical button state.

  App project setup:
    Button widget attached to V2 (Switch mode)
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "-5zgetw-hN6WhmARqSI8Q6E-7a9wCvkz";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "fathalla";
char pass[] = "hamdi123";

// Set your LED and physical button pins here
const int ledPin1 = 1;
const int btnPin1 = 2;
const int ledPin2 = 3;
const int btnPin2 = 0;

BlynkTimer timer;
void checkPhysicalButton();

int ledState1 = LOW;
int btnState1 = HIGH;
int ledState2 = LOW;
int btnState2 = HIGH;

// Every time we connect to the cloud...
BLYNK_CONNECTED() {
  // Request the latest state from the server
  Blynk.syncVirtual(V2);
    // Request the latest state from the server
  Blynk.syncVirtual(V3);

  // Alternatively, you could override server state using:
  //Blynk.virtualWrite(V2, ledState);
}

// When App button is pushed - switch the state
BLYNK_WRITE(V2) {
  ledState1 = param.asInt();
  digitalWrite(ledPin1, ledState1);}
  BLYNK_WRITE(V3) {
  ledState2 = param.asInt();
  digitalWrite(ledPin2, ledState2);
}
void checkPhysicalButton(){

  if (digitalRead(btnPin1) == LOW) {
    // btnState is used to avoid sequential toggles
    if (btnState1 != LOW) {

      // Toggle LED state
      ledState1 = !ledState1;
      digitalWrite(ledPin1, ledState1);

      // Update Button Widget
      Blynk.virtualWrite(V2, ledState1);
    }
    btnState1 = LOW;
  } else {
    btnState1 = HIGH;
  }
    if (digitalRead(btnPin2) == LOW) {
    // btnState is used to avoid sequential toggles
    if (btnState2 != LOW) {

      // Toggle LED state
      ledState2 = !ledState2;
      digitalWrite(ledPin2, ledState2);

      // Update Button Widget
      Blynk.virtualWrite(V3, ledState2);
    }
    btnState2 = LOW;
  } else {
    btnState2 = HIGH;
  }
   
}

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);

  pinMode(ledPin1, OUTPUT);
  pinMode(btnPin1, INPUT_PULLUP);
    digitalWrite(ledPin1, ledState1);
  pinMode(ledPin2, OUTPUT);
  pinMode(btnPin2, INPUT_PULLUP);
    digitalWrite(ledPin2, ledState2);
  

  // Setup a function to be called every 100 ms
  timer.setInterval(100L, checkPhysicalButton);
}

void loop()
{
  Blynk.run();
  timer.run();
}
