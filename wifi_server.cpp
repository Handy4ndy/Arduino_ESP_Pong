#include <WiFi.h>
#include "wifi_server.h"
#include "wifi_credentials.h" // Include the credentials header
#include "shared_pins.h"      // Include the shared pins header

// Server settings
WiFiServer server(80);

void setupWiFiServer() {
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  server.begin();
}

void serverLoop() {
  WiFiClient client = server.available();
  if (client) {
    while (client.connected()) {
      if (client.available()) {
        String line = client.readStringUntil('\n');
        // Handle received data
        // Parse and update game state
        int paddle1Y, paddle2Y, ballX, ballY;
        sscanf(line.c_str(), "%d,%d,%d,%d", &paddle1Y, &paddle2Y, &ballX, &ballY);
        
        // Update displays
        // updateDisplays(paddle1Y, paddle2Y, ballX, ballY); // Implement this function
      }
    }
    client.stop();
  }
}
