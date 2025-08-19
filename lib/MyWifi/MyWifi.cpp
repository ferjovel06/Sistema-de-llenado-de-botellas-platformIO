#include <MyWifi.h>

const char *ssid = "CLARO1_378ED8";
const char *password = "5HZTSSX42M";

void connectToWiFi() {
    Serial.print("Connecting to WiFi");
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print(".");
  }
  Serial.println("Connected to WiFi");
}
