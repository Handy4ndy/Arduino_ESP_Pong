#include <WiFi.h>
#include "wifi_client.h"
#include "wifi_credentials.h" // Include the credentials header
#include "shared_pins.h"      // Include the shared pins header

// Server address
const char* serverIP = "server_IP_address"; // Replace with the server's IP address
const int serverPort = 80;

void setupWiFiClient() {
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
}

void clientLoop() {
  WiFiClient client;
  if (!client.connect(serverIP, serverPort)) {
    Serial.println("Connection to server failed");
    delay(1000);
    return;
  }

  int localPaddleY = analogRead(joystickYPin);
  client.print(localPaddleY);
  client.print('\n');

  if (client.available()) {
    String line = client.readStringUntil('\n');
    int paddle1Y, paddle2Y, ballX, ballY;
    sscanf(line.c_str(), "%d,%d,%d,%d", &paddle1Y, &paddle2Y, &ballX, &ballY);

    // Update displays
    // updateDisplays(paddle1Y, paddle2Y, ballX, ballY); // Implement this function
  }

  client.stop();
}
