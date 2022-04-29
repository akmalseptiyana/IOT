#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>

String key = "12345";
#define relay1 D2  //D2
#define relay2 D5  //D5
 
void setup() {
  const char* ssid = "Redmi Note 9 Pro"; //Nama WiFi / hotspot
  const char* password = ""; //Password WiFi
  Serial.begin(115200); //Serial Monitor
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  digitalWrite(relay1, LOW);
  digitalWrite(relay2, LOW);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting..");
  }
  Serial.println("Connection OK");
}
 
void loop() {
 
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin("http://192.168.43.244/led/kontrol.php");
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    int httpResponseCode = http.POST("token="+key); //post 2 parameter
    delay(100);
    if (httpResponseCode > 0) {
      String response = http.getString();
      char json[500];
      response.toCharArray(json, 500);
      StaticJsonDocument<200> doc;
      deserializeJson(doc, json);
      int led1 = doc["led1"];
      int led2 = doc["led2"];

      if(led1 == 1){
        digitalWrite(relay1, HIGH);
        Serial.println("LED1 ON");
      }else{
        digitalWrite(relay1, LOW);
        Serial.println("LED1 OFF");
      }

      if(led2 == 1){
        digitalWrite(relay2, HIGH);
        Serial.println("LED2 ON");
      }else{
        digitalWrite(relay2, LOW);
        Serial.println("LED2 OFF");
      }
/*
      Serial.print("led1 = ");
      Serial.println(led1);
      Serial.print("led2 = ");
      Serial.println(led2);
      Serial.println(response); //menampilkan respon dari website
*/
    } else {
      Serial.print("Error on sending POST: ");
      Serial.println(httpResponseCode);
    }
    http.end();  //Free resources
  } else {
    Serial.println("Error in WiFi connection");
  }
//  delay(1000);
}
