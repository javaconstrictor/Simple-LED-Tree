//Start by adding a few public variables

#include <ESP8266WiFi.h>

//setting wifi for setup
const char* ssid = "wifiName";
const char* password = "passwd";

//this isnt neccesary, was testing what worked best 
int green = 5;


void setup() {
    
    //turns on green led array to show that power is on and set up has started in case of non gui interface
    pinMode(green,OUTPUT);
    digitalWrite(green,LOW);
    
    Serial.begin (74880);
    //setup information printed to serial
    Serial.print ("connecting to network: ");
    
    Serial.println ( ssid );

     WiFi.begin(ssid,password);

     Serial.println ();
    
    Serial.println ("Please hold");

    //this is to show that the device is still setting up and has not frozen
     while(WiFi.status() != WL_CONNECTED ){
    
         delay(500);

         Serial.print("...");
        
     }
    //shut off green led array to show finallization of set up and is ready to be controlled.
   digitalWrite( green,HIGH );
   
    Serial.println();

   Serial.println("WiFi connection successful!");
   //prints out device ip to connect and controll, once you know the ip, add as a shortcut to homescreen which launches the webpage.
    Serial.print( "your ip address is ");
   
    Serial.println(WiFi.localIP() );
}

void loop() {
  // put your main code here, to run repeatedly:

}
