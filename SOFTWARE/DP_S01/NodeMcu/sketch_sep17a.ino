/* PROJECT IS FIRST PROJECT FOR DP COMPANY 
 *  BY ENG-MOHAMED HAMDI AND ENG MOHAMED SAMY QASEM 
 *  AND THE PROJECT IS SMART HOME SYSTEM THAT CALLED DP S01  
 *  DATE/7-7-2020 10:43 PM
 */
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "-5zgetw-hN6WhmARqSI8Q6E-7a9wCvkz";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "fathalla";
char pass[] = "hamdi123";
#define DHTPIN 2          // What digital pin we're connected to

// Uncomment whatever type you're using!
#define DHTTYPE DHT11     // DHT 11
//#define DHTTYPE DHT22   // DHT 22, AM2302, AM2321
//#define DHTTYPE DHT21   // DHT 21, AM2301

DHT dht(DHTPIN, DHTTYPE);
//DEFINTIONS OF PINS CONDITIONS FOR BUTTON AND LAMPS.
const int ledPin1 = 3 ;
const int btnPin1 = 0 ;
const int ledPin2 = 9 ;
const int btnPin2 = 1 ;
const int ledPin3 = 10 ;
const int btnPin3 = 4 ;
const int ledPin4 = 12 ;
const int btnPin4 = 5 ;
const int ledPin5 = 13 ;
const int btnPin5 = 14 ;
const int ledPin6 = 15 ;
const int btnPin6 = 16 ;
BlynkTimer timer;
// This function sends Arduino's up time every second to Virtual Pin (5).
// In the app, Widget's reading frequency should be set to PUSH. This means
// that you define how often to send data to Blynk App.
void sendSensor()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V8, h);
  Blynk.virtualWrite(V9, t);}
void checkPhysicalButton();

int ledState1 = LOW;
int btnState1 = HIGH;
int ledState2 = LOW;
int btnState2 = HIGH;
int ledState3 = LOW;
int btnState3 = HIGH;
int ledState4 = LOW;
int btnState4 = HIGH;
int ledState5 = LOW;
int btnState5 = HIGH;
int ledState6 = LOW;
int btnState6 = HIGH;

// Every time we connect to the cloud...
BLYNK_CONNECTED() {
// Request the latest state from the server
  Blynk.syncVirtual(V2);
  Blynk.syncVirtual(V3); 
  Blynk.syncVirtual(V4);  
  Blynk.syncVirtual(V5);
  Blynk.syncVirtual(V6);
  Blynk.syncVirtual(V7);

  // Alternatively, you could override server state using:
  //Blynk.virtualWrite(V2, ledState);
}

// When App buttons is pushed - switches the state
  BLYNK_WRITE(V2) {
  ledState1 = param.asInt();
  digitalWrite(ledPin1, ledState1);}
  BLYNK_WRITE(V3) {
  ledState2 = param.asInt();
  digitalWrite(ledPin2, ledState2);}
  BLYNK_WRITE(V4) {
  ledState3 = param.asInt();
  digitalWrite(ledPin3, ledState3);}
  BLYNK_WRITE(V5) {
  ledState4 = param.asInt();
  digitalWrite(ledPin4, ledState4);}
  BLYNK_WRITE(V6) {
  ledState5 = param.asInt();
  digitalWrite(ledPin5, ledState5);}
  BLYNK_WRITE(V7) {
  ledState6 = param.asInt();
  digitalWrite(ledPin6, ledState6);}


void checkPhysicalButton()
{
  if (digitalRead(btnPin1) == LOW) {
    // btnState1 is used to avoid sequential toggles
    if (btnState1 != LOW) {

      // Toggle LED1 state
      ledState1 = !ledState1;
      digitalWrite(ledPin1, ledState1);

      // Update Button1 Widget
      Blynk.virtualWrite(V2, ledState1);
    }
    btnState1 = LOW;
  } else {
    btnState1 = HIGH;}
      if (digitalRead(btnPin2) == LOW) {
    // btnState2 is used to avoid sequential toggles
    if (btnState2 != LOW) {

      // Toggle LED2 state
      ledState2 = !ledState2;
      digitalWrite(ledPin2, ledState2);

      // Update Button2 Widget
      Blynk.virtualWrite(V3, ledState2);
    }
    btnState2 = LOW;
  } else {
    btnState2 = HIGH;}
  if (digitalRead(btnPin3) == LOW) {
    // btnState3 is used to avoid sequential toggles
    if (btnState3 != LOW) {

      // Toggle LED3 state
      ledState3 = !ledState3;
      digitalWrite(ledPin3, ledState3);

      // Update Button3 Widget
      Blynk.virtualWrite(V4, ledState3);
    }
    btnState3 = LOW;
  } else {
    btnState3 = HIGH;}
      if (digitalRead(btnPin4) == LOW) {
    // btnState is used to avoid sequential toggles
    if (btnState4 != LOW) {

      // Toggle LED4 state
      ledState4 = !ledState4;
      digitalWrite(ledPin4, ledState4);

      // Update Button4 Widget
      Blynk.virtualWrite(V5, ledState4);
    }
    btnState4 = LOW;
  } else {
    btnState4 = HIGH;}
      if (digitalRead(btnPin5) == LOW) {
    // btnState5 is used to avoid sequential toggles
    if (btnState5 != LOW) {

      // Toggle LED5 state
      ledState5 = !ledState5;
      digitalWrite(ledPin5, ledState5);

      // Update Button5 Widget
      Blynk.virtualWrite(V6, ledState5);
    }
    btnState5 = LOW;
  } else {
    btnState5 = HIGH;}
      if (digitalRead(btnPin6) == LOW) {
    // btnState6 is used to avoid sequential toggles
    if (btnState6 != LOW) {

      // Toggle LED6 state
      ledState6 = !ledState6;
      digitalWrite(ledPin6, ledState6);

      // Update Button6 Widget
      Blynk.virtualWrite(V7, ledState6);
    }
    btnState6 = LOW;
  } else {
    btnState6 = HIGH;
    }
    }
    void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);

  pinMode(ledPin1, OUTPUT);
  pinMode(btnPin1, INPUT_PULLUP);
  digitalWrite(ledPin1, ledState1);
  pinMode(ledPin2, OUTPUT);
  pinMode(btnPin2, INPUT_PULLUP);
  digitalWrite(ledPin2, ledState2);
  pinMode(ledPin3, OUTPUT);
  pinMode(btnPin3, INPUT_PULLUP);
  digitalWrite(ledPin3, ledState3);
  pinMode(ledPin4, OUTPUT);
  pinMode(btnPin4, INPUT_PULLUP);
  digitalWrite(ledPin4, ledState4);
  pinMode(ledPin5, OUTPUT);
  pinMode(btnPin5, INPUT_PULLUP);
  digitalWrite(ledPin5, ledState5);
  pinMode(ledPin6, OUTPUT);
  pinMode(btnPin6, INPUT_PULLUP);
  digitalWrite(ledPin6, ledState6);
  // Setup a function to be called every 100 ms
  timer.setInterval(100L, checkPhysicalButton);

  dht.begin();

  // Setup a function to be called every second
  timer.setInterval(1000L, sendSensor);
}


void loop()
{
  Blynk.run();
  timer.run();
}
    
