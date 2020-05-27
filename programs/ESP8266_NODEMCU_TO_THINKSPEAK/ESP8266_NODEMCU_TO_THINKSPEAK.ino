#include <ESP8266WiFi.h>;
 
#include <WiFiClient.h>;
 
#include <ThingSpeak.h>;
 
const char* ssid = "Server001"; //Your Network SSID
 
const char* password = "8589838398"; //Your Network Password
 
int val;
 
int LDRpin = A0; //LDR Pin Connected at A0 Pin
 
 
 
WiFiClient client;
 
unsigned long myChannelNumber = 1023033; //Your Channel Number (Without Brackets)
 
const char * myWriteAPIKey = "LKKJ2MUZWFL5ZUL9"; //Your Write API Key
 
void setup()
 
{
 
Serial.begin(115200);
 
delay(10);
 
// Connect to WiFi network
 
WiFi.begin(ssid, password);
 
 
 
ThingSpeak.begin(client);
 
}
 
 
 
void loop()
 
{
 
val = analogRead(LDRpin); //Read Analog values and Store in val variable
 
Serial.println(val); //Print on Serial Monitor
 
delay(10);
 
ThingSpeak.writeField(myChannelNumber, 1,val, myWriteAPIKey); //Update in ThingSpeak
ThingSpeak.writeField(myChannelNumber, 2,val, myWriteAPIKey); //Update in ThingSpeak
 
 
 
delay(10);
 
}
