
#include "UbidotsEsp32Mqtt.h"

/****************************************
 * Define Constants
 ****************************************/
const char *UBIDOTS_TOKEN = "BBFF-Cx0am77wZdSklJMToVQNatzvlmzmCp";  // Put here your Ubidots TOKEN
const char *WIFI_SSID = "satyam";      // Put here your Wi-Fi SSID
const char *WIFI_PASS = "00000000";      // Put here your Wi-Fi password
const char *DEVICE_LABEL = "relay-lock";   // Replace with the device label to subscribe to
const char *VARIABLE_LABEL = "relay-lock"; // Replace with your variable label to subscribe to

#define RELAY_1 12
#define RELAY_2 13
#define RELAY_3 14
#define RELAY_4 27
Ubidots ubidots(UBIDOTS_TOKEN);

/****************************************
 * Auxiliar Functions
 ****************************************/

void callback(char *topic, byte *payload, unsigned int length)
{
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++)
  {
    Serial.print((char)payload[i]);
    if((char)payload[0] == '1')//LOCK
  {
    digitalWrite(19, LOW);
    digitalWrite(18, HIGH);  
    digitalWrite(RELAY_1, 0);
    digitalWrite(RELAY_2, 0);
    Serial.print("lock");
    delay(200);
    digitalWrite(18, LOW);
    delay(200);
    digitalWrite(18, HIGH);
    delay(200);
    digitalWrite(18, LOW);
    delay(200);
    digitalWrite(18, LOW);
    digitalWrite(RELAY_1, 1);
    digitalWrite(RELAY_2, 1);
    delay(200);
    digitalWrite(18, HIGH);//GREEN
  }
  else//UNLOCK
  {
    digitalWrite(18, LOW);
    digitalWrite(19, HIGH);
    digitalWrite(RELAY_3, 0);
    digitalWrite(RELAY_4, 0);
    Serial.print("unlock");
    delay(200);
    digitalWrite(19, LOW);
    delay(200);
    digitalWrite(19, HIGH);
    delay(200);
    digitalWrite(19, LOW);
    delay(200);
    digitalWrite(19, LOW);
    digitalWrite(RELAY_3, 1);
    digitalWrite(RELAY_4, 1);
    delay(200);
    digitalWrite(19, HIGH);
  }
  }
  Serial.println();
}

/****************************************
 * Main Functions
 ****************************************/

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(RELAY_1, OUTPUT);
  pinMode(RELAY_2, OUTPUT);
  pinMode(RELAY_3, OUTPUT);
  pinMode(RELAY_4, OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(19, OUTPUT);

  // ubidots.setDebug(true);  // uncomment this to make debug messages available
  ubidots.connectToWifi(WIFI_SSID, WIFI_PASS);
  ubidots.setCallback(callback);
  ubidots.setup();
  ubidots.reconnect();
  ubidots.subscribeLastValue(DEVICE_LABEL, VARIABLE_LABEL); // Insert the device and variable's Labels, respectively
}

void loop()
{
  // put your main code here, to run repeatedly:
  if (!ubidots.connected())
  {
    ubidots.reconnect();
    ubidots.subscribeLastValue(DEVICE_LABEL, VARIABLE_LABEL); // Insert the device and variable's Labels, respectively
  }
  ubidots.loop();
  
}
