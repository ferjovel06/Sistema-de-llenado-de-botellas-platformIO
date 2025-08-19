#ifndef WIFI_H
#define WIFI_H

#include <WiFi.h>

// WiFi credentials
extern const char *ssid;
extern const char *password;

// Declaración de la función
void connectToWiFi();

#endif