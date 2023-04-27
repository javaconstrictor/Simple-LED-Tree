#include <ESP8266WiFi.h>

WiFiServer Server(80);
const char* ssid = "ssid";
const char* password = "pW";

int g = 5;                               //initializing led control pins and 
int b = 4;                              // including wifi library
int r = 0;
int brightness = 0;
int revbright = 255-brightness;
int fade = 5;
int clickCounter = 0;

void setup() {
  pinMode(g,OUTPUT);                    // set pins to output, test all
  pinMode(b,OUTPUT);
  pinMode(r,OUTPUT);
  digitalWrite(g,LOW);
  digitalWrite(r,LOW);
  digitalWrite(b,LOW);

  Serial.begin (74880);
  Serial.print ("welcome!");                      //welcome matt for serial mon
  Serial.println ();
  Serial.print ("initializing, please hold.");
  Serial.println ();
  Serial.print ("Connecting to network: ");
  Serial.println ( ssid );

    WiFi.begin(ssid,password);

      Serial.println ();
      Serial.print (" Network found, almost there!");     //connect to wifi

        while(WiFi.status() != WL_CONNECTED ) {
              delay (250);
              Serial.print (".");
        }
    
    digitalWrite (g,HIGH);
    digitalWrite (r,HIGH);
    digitalWrite (b,HIGH);
    Serial.println ();
    Serial.print ("WiFi Connected succesfully!");         //state succesful connection
    Serial.print (" Your Client IP address is: ");        //and ip
    Serial.println (WiFi.localIP() );

  Server.begin();
  Serial.println ();
  Serial.print ("Setup complete! please test client site");
}

void loop() {
  WiFiClient client = Server.available();

    if (client) {
      Serial.print ("Client found");
      String currentLine = "";
      while (client.connected()) {
        if (client.available()) {
          char c = client.read();
          Serial.write(c);
          if (c == '\n') {
            if (currentLine.length() == 0) {
              client.println("HTTP/1.1 200 OK");
              client.println("Content-type:text/html");
              client.println();
              client.print("Click <a href=\"/H\">here</a> to change lighting mode<br>");
              client.println();
              break;
            } else {
              currentLine = "";
            }
          } else if (c != '\r') {
            currentLine += c;
          }

          if (currentLine.endsWith("GET /H")) { clickCounter++;
        }
      }
      if (clickCounter == 1) {
        analogWrite (r, 200);
        delay (1500);
        analogWrite (g, 200);
        analogWrite (r, 0);
        delay(1500);
        analogWrite (b, 200);
        analogWrite (g, 0);
        delay(1500);
      } else if (clickCounter == 0) {
        analogWrite (r, 0);
        analogWrite (g, 0);
        analogWrite (b, 0);
      } else if (clickCounter == 2) {
        digitalWrite (r,LOW);
        digitalWrite (g,LOW);
        digitalWrite (b,LOW);
        delay(1000);
        digitalWrite (r,HIGH);
        delay(1000);
      } else if (clickCounter == 3) {
        digitalWrite (r,LOW);
        digitalWrite (g,LOW);
        digitalWrite (b,LOW);
        delay(1000);
        digitalWrite (g,HIGH);
        delay(1000);
      } else if (clickCounter == 4) {
        digitalWrite (r,LOW);
        digitalWrite (g,LOW);
        digitalWrite (b,LOW);
        delay(1000);
        digitalWrite (b,HIGH);
        delay(1000);
      } else if (clickCounter == 5) {
        digitalWrite (r,LOW);
        digitalWrite (b,LOW);
        digitalWrite (g,HIGH);
        delay(1000);
        digitalWrite (r,HIGH);
        digitalWrite (g,LOW);
        delay(1000);
      } else if (clickCounter ==10) {
        int clickCounter = 0;
        
      } else if (clickCounter == 6) {
        analogWrite (r,brightness);
        brightness = brightness+fade;
        if (brightness == 0 || brightness == 255) {
          fade = -fade;
        }
      }else if (clickCounter == 7) {
        analogWrite (g,brightness);
        brightness = brightness+fade;
        if (brightness == 0 || brightness == 255) {
          fade = -fade;
        }
     }else if (clickCounter == 8) {
        analogWrite (b,brightness);
        brightness = brightness+fade;
        if (brightness == 0 || brightness == 255) {
          fade = -fade;
        }
        }else if (clickCounter == 9) {
        analogWrite (g,brightness);
        analogWrite (r,revbright);
        brightness = brightness+fade;
        if (brightness == 0 || brightness == 255) {
          fade = -fade; 
    }
      }
    client.stop();
    Serial.println("Client has disconnected.");
}
}
}
