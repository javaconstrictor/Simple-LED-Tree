#include <ESP8266WiFi.h>

const char* ssid = "BroncosRule";
const char* password = "hollyjo39";

int green = 5;


void setup() {
    pinMode(green,OUTPUT);
    digitalWrite(green,LOW);
    
    Serial.begin (74880);
    Serial.print ("hello World!");
    Serial.println ();
    Serial.print ("connecting to network: ");
    Serial.println ( ssid );

     WiFi.begin(ssid,password);

     Serial.println ();
     Serial.println ("Please hold :D");

     while(WiFi.status() != WL_CONNECTED ){
        delay(500);
        Serial.print("...");
        
     }
   digitalWrite( green,HIGH );
   Serial.println();

   Serial.println("WiFi connection successful!");
   Serial.print( "your ip address is ");
   Serial.println(WiFi.localIP() );
}

void loop() {
  // put your main code here, to run repeatedly:

}
