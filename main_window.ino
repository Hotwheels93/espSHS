#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <Wire.h>

// Wifi credentials
const char* ssid     = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PW";

// URL and post request 
const char* serverName = "YOUR_PHP_POST_SCRIPT_URL.php";
String apiKeyValue = "123456789087654321";

// Sensor data
String sensorName = "ReedSensor";
String sensorLocation = "AZ_1";

int windowStatus = 0;

 
void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("ESP_HomeSense - Version 0.1");
  Serial.println("espSHS- v 0.1");
  Serial.println("Sensor: " + sensorName);
  Serial.println("Location: " + sensorLocation);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) { 
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connection established, IP adress: "+ WiFi.localIP());
}

void loop() {
  //Check WiFi connection status
  if(WiFi.status()== WL_CONNECTED){
    int sensorValue = analogRead(A0);
    float voltage = sensorValue * (3.2 / 1023.0);
     if (voltage < 1) {
      windowStatus = 0;
      Serial.println("Window Open");
     } else {
      windowStatus = 1;
      Serial.println("Winbdow Closed");
     }
    HTTPClient http;
    http.begin(serverName);
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    String httpRequestData = "api_key=" + apiKeyValue + "&sensor=" + sensorName
                          + "&location=" + sensorLocation + "&value1=" + String(windowStatus) + "";
    Serial.println("httpRequestData: ");
    Serial.println(httpRequestData);
    int httpResponseCode = http.POST(httpRequestData);
    if (httpResponseCode>0) {
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
    }
    else {
      Serial.print("Error code: ");
      Serial.println(httpResponseCode);
    }
    // Free resources
    http.end();
  }
  else {
    Serial.println("WiFi Disconnected");
  }
  delay(10000);  
}
