#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "[Your Wifi]";
const char* password = "[Pass]";
const char* hueBridgeIP = "[IP Bridge]";
const char* username = "[Username API Bridge]";
const int lightId1 = 1;
const int lightId2 = 2;
const int potPin = A0;

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  Serial.println("Se conectează la Wi-Fi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("\nConectat la Wi-Fi!");
  Serial.print("Adresa IP: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  int potValue = analogRead(potPin);
  int brightness = map(potValue, 0, 1023, 0, 254);
  
  Serial.print("Valoare potențiometru: ");
  Serial.print(potValue);
  Serial.print(" -> Intensitate: ");
  Serial.println(brightness);

  WiFiClient client;
  HTTPClient http;

  String url1 = String("http://") + hueBridgeIP + "/api/" + username + "/lights/" + String(lightId1) + "/state";
  String payload1 = String("{\"bri\":") + String(brightness) + String("}");
  http.begin(client, url1);
  http.addHeader("Content-Type", "application/json");
  int httpCode1 = http.PUT(payload1);

  if (httpCode1 > 0) {
    Serial.print("Cerere HTTP reușită pentru becul 1, cod: ");
    Serial.println(httpCode1);
  } else {
    Serial.print("Eroare HTTP pentru becul 1, cod: ");
    Serial.println(httpCode1);
  }

  String url2 = String("http://") + hueBridgeIP + "/api/" + username + "/lights/" + String(lightId2) + "/state";
  String payload2 = String("{\"bri\":") + String(brightness) + String("}");
  http.begin(client, url2);
  http.addHeader("Content-Type", "application/json");
  int httpCode2 = http.PUT(payload2);

  if (httpCode2 > 0) {
    Serial.print("Cerere HTTP reușită pentru becul 2, cod: ");
    Serial.println(httpCode2);
  } else {
    Serial.print("Eroare HTTP pentru becul 2, cod: ");
    Serial.println(httpCode2);
  }

  http.end();
  delay(300);
}
