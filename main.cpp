#include <WiFi.h>
#include <HTTPClient.h>


const char* ssid = "REPLACE_WITH_YOUR_SSID";
const char* password = "REPLACE_WITH_YOUR_PASSWORD";
String serverName = "https://maker.ifttt.com/trigger/door_status/with/key/pEbV6M8QVTmc9S43r2jfrWmy488E8hi61OqZr4lun4B";

#define sensor 2

const int bulb1 = 12;
const int bulb2 = 14;
const int bulb3 = 26;
const int bulb4 = 27;

void sendemail(){
  
      HTTPClient http;

      String serverPath = serverName;
      
      // Your Domain name with URL path or IP address with path
      http.begin(serverPath.c_str());
      
      // Send HTTP GET request
      int httpResponseCode = http.GET();
      
      if (httpResponseCode>0) {
        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);
        String payload = http.getString();
        Serial.println(payload);
      }
      else {
        Serial.print("Error code: ");
        Serial.println(httpResponseCode);
      }
  }

int ldr(){
  int val = analogRead(sensor);  
  
  }

void control(){
  if(ldr() < 500){
    digitalWrite(bulb1, HIGH);
    delay(700);
    digitalWrite(bulb2, HIGH);
    delay(700);
    digitalWrite(bulb3, HIGH);
    delay(700);
    digitalWrite(bulb4, HIGH);
    delay(700);
    sendemail();
    }
  else{
    digitalWrite(bulb1, LOW);
    delay(700);
    digitalWrite(bulb2, LOW);
    delay(700);
    digitalWrite(bulb3, LOW);
    delay(700);
    digitalWrite(bulb4, LOW);
    delay(700);
    sendemail();
    }
    
  
  }

void setup() {
  pinMode(bulb1, OUTPUT);
  pinMode(bulb2, OUTPUT);
  pinMode(bulb3, OUTPUT);
  pinMode(bulb4, OUTPUT);
  // Serial port for debugging purposes
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
    }
    Serial.println("");
    Serial.println("WiFi connected");  
}

void loop() {
  control();
  }
