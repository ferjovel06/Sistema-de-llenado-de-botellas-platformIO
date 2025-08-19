#include "DjangoData.h"
#include <WiFi.h>

void enviarDatosDjango(float caudal, int rpm)
{
    WiFiClient client;
    const char *host = "192.168.1.95";
    const int port = 8000;

    if (client.connect(host, port))
    {
        String postData = "caudal=" + String(caudal) + "&velocidad_motor=" + String(rpm);
        client.println("POST /api/data/ HTTP/1.1");
        client.println("Host: 192.168.1.95");
        client.println("Content-Type: application/x-www-form-urlencoded");
        client.print("Content-Length: ");
        client.println(postData.length());
        client.println();
        client.print(postData); // Usar print para evitar salto de línea extra
        Serial.println("Datos enviados a Django: " + postData);
        delay(1000); // Esperar respuesta (opcional)
        client.stop();
    }
    else
    {
        Serial.println("Conexión fallida con el servidor Django");
    }
}