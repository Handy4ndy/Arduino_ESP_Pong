#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <WiFi.h>
#include <esp_now.h>


//Madlabs Logo
const unsigned char myLogo[] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0xFF, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0xE0, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3E, 0x00, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0xC0, 0x00, 0x3E, 0x00, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0xF0, 0x00, 0x3F, 0x00, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0xF8, 0x00, 0x3F, 0x00, 0x7E, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0xFC, 0x00, 0x3F, 0x00, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0xFE, 0x00, 0x3F, 0x01, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x3E, 0x7F, 0x00, 0x3F, 0x03, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x3E, 0x3F, 0x80, 0x3F, 0x07, 0xF0, 0x00, 0x00, 0xFF, 0x80, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x1F, 0xC0, 0x3F, 0x0F, 0xE0, 0x00, 0x7F, 0xFF, 0xFC, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x1F, 0xE0, 0x3F, 0x3F, 0xC0, 0x00, 0xFF, 0xFF, 0xFE, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x1F, 0xF0, 0x3F, 0xFF, 0x00, 0x00, 0x7F, 0xC0, 0xFE, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0xFF, 0xF8, 0x3F, 0xFE, 0x00, 0x00, 0x1F, 0x83, 0xFC, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0xFF, 0xFC, 0x3F, 0xFC, 0x00, 0x00, 0x1F, 0x8F, 0xF8, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0xF9, 0xFE, 0x3F, 0xF0, 0x00, 0x00, 0x3F, 0xFF, 0xE0, 0x00,
  0x00, 0x00, 0x00, 0x01, 0xC0, 0x7F, 0xC0, 0xFF, 0x3F, 0xC0, 0x00, 0x00, 0x3F, 0xFF, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x07, 0xF0, 0x7F, 0x00, 0x3E, 0x00, 0x00, 0x07, 0x00, 0x3F, 0xFF, 0xE0, 0x00,
  0x00, 0x00, 0x00, 0x07, 0xF0, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x0F, 0xE0, 0x7F, 0xFF, 0xFC, 0x00,
  0x00, 0x00, 0x00, 0x0F, 0xF8, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x3F, 0xF0, 0x7F, 0xFF, 0xFE, 0x00,
  0x00, 0x00, 0x00, 0x0F, 0xFC, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x7F, 0xF0, 0x7C, 0x00, 0xFE, 0x00,
  0x00, 0x1F, 0x00, 0x0F, 0xFC, 0x3E, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xF0, 0xFC, 0x03, 0xFC, 0x00,
  0x00, 0x7F, 0xC0, 0x0F, 0xFE, 0x1C, 0x00, 0x00, 0x00, 0x03, 0xFB, 0xF0, 0xFC, 0x0F, 0xF8, 0x00,
  0x00, 0x7F, 0xE0, 0x1F, 0xFE, 0x00, 0x00, 0xF8, 0x00, 0x07, 0xE7, 0xF0, 0xF8, 0xFF, 0xC0, 0x00,
  0x00, 0x3F, 0xF8, 0x1F, 0xBF, 0x00, 0x00, 0xF8, 0x00, 0x0F, 0xC7, 0xE1, 0xFF, 0xFF, 0x00, 0x00,
  0x00, 0x3F, 0xFC, 0x1F, 0xBF, 0x00, 0x01, 0xF8, 0x00, 0x3F, 0x87, 0xE1, 0xFF, 0xF8, 0x00, 0x00,
  0x00, 0x3F, 0xFE, 0x1F, 0x9F, 0x80, 0x01, 0xF0, 0x00, 0x7F, 0x0F, 0xE1, 0xFF, 0xC0, 0x00, 0x00,
  0x00, 0x3F, 0xFF, 0x1F, 0x9F, 0xC0, 0x03, 0xF0, 0x00, 0xFF, 0xFF, 0xE0, 0x1C, 0x00, 0x00, 0x00,
  0x00, 0x1F, 0x7F, 0xBF, 0x8F, 0xC0, 0x03, 0xF0, 0x03, 0xFF, 0xFF, 0xE0, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x1F, 0xBF, 0xFF, 0x0F, 0xC0, 0x07, 0xF0, 0x07, 0xFF, 0xFF, 0xC0, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x1F, 0x9F, 0xFF, 0x07, 0xE0, 0x07, 0xF0, 0x0F, 0xF0, 0x1F, 0xC0, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x0F, 0x87, 0xFF, 0x07, 0xE0, 0x0F, 0xF0, 0x1F, 0xC0, 0x1F, 0xC0, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x0F, 0x83, 0xFF, 0x07, 0xE0, 0x0F, 0xE0, 0x3F, 0x80, 0x1F, 0xC0, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x0F, 0xC1, 0xFE, 0x00, 0xE0, 0x0F, 0xE0, 0x3F, 0x00, 0x0F, 0xC0, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x07, 0xC0, 0x7F, 0x00, 0x00, 0x1F, 0xC0, 0x10, 0x00, 0x07, 0x80, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x07, 0xC0, 0x06, 0x00, 0x00, 0x1F, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x07, 0xE0, 0x00, 0x00, 0x00, 0x3F, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x03, 0xE0, 0x00, 0x00, 0x00, 0x3F, 0x9F, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x03, 0xE0, 0x00, 0x00, 0x00, 0x7F, 0xFF, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0xC0, 0x00, 0x00, 0x00, 0x7F, 0xFF, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

// Define WiFi credentials
const char* ssid = "Xperia_4439";
const char* password = "12345678";

// Define screen dimensions
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Define paddle dimensions
#define PADDLE_WIDTH 24
#define PADDLE_HEIGHT 2

// Define ball dimensions
#define BALL_SIZE 2

#define OLED_SDA    14
#define OLED_SCL    12
#define OLED_RST   -1  // Reset pin (or -1 if not used)

// Initialize OLED displays
Adafruit_SSD1306 display1(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
Adafruit_SSD1306 display2(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Define joystick pins
const int joystickXPin = 34;
const int joystickYPin = 35;

// Define LED and speaker pins
const int ledPin = 4;
const int BEEPER = 2;

// Game state variables
int paddleX1, paddleX2;
int ballX, ballY;
int ballDirX, ballDirY;
int score1, score2;
const int WINNING_SCORE = 5; // Change this to your desired winning score

// Initialize ESP-NOW
void setupEspNow() {
  WiFi.mode(WIFI_STA);
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
}

// Callback function for received data
void onDataReceived(const uint8_t *mac, const uint8_t *incomingData, int len) {
  // Handle incoming data
}

// ESP-NOW
uint8_t peerAddress[] = {0xCC, 0xDB, 0xA7, 0x62, 0xC0, 0x8C};

typedef struct struct_message {
    int ballX;
    int ballY;
    int paddleX2;
    int score1;
    int score2;
} struct_message;

struct_message myData;

// Function prototypes
void setupHardware();
void drawGameElements(bool initial);
void updateGame();
void checkCollision();
void resetBall();
void loadScreen();
void shakeLogo();
void soundPoint();
void soundBounce();
void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status);
void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len);

void setup() {
  Serial.begin(9600);

  pinMode(joystickXPin, INPUT);
  pinMode(joystickYPin, INPUT);
  pinMode(BEEPER, OUTPUT);
  
  setupHardware();
  loadScreen();
  
  // Initialize game state
  paddleX1 = (SCREEN_WIDTH - PADDLE_WIDTH) / 2;
  paddleX2 = (SCREEN_WIDTH - PADDLE_WIDTH) / 2;
  resetBall();
  score1 = 0;
  score2 = 0;
  
  setupEspNow();
  esp_now_register_recv_cb(onDataReceived);

  // Initialize WiFi
  WiFi.mode(WIFI_STA);
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  esp_now_register_send_cb(OnDataSent);
  esp_now_register_recv_cb(OnDataRecv);

  // Register peer
  esp_now_peer_info_t peerInfo;
  memcpy(peerInfo.peer_addr, peerAddress, 6);
  peerInfo.channel = 0;  
  peerInfo.encrypt = false;
  
  if (esp_now_add_peer(&peerInfo) != ESP_OK){
    Serial.println("Failed to add peer");
    return;
  }
  
  // Draw the initial game elements
  drawGameElements(true);
}


void loop() {
  updateGame();
  drawGameElements(false);

  myData.ballX = ballX;
  myData.ballY = ballY;
  myData.paddleX2 = paddleX2;
  myData.score1 = score1;
  myData.score2 = score2;
  
  esp_now_send(peerAddress, (uint8_t *) &myData, sizeof(myData));
}

void setupHardware() {
  // Initialize OLED displays
  if (!display1.begin(SSD1306_SWITCHCAPVCC, 0x3D)) {
    Serial.println(F("Display 1 initialization failed"));
    for (;;);
  }
  if (!display2.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("Display 2 initialization failed"));
    for (;;);
  }

  // Initialize joystick and other pins
  pinMode(ledPin, OUTPUT);
  pinMode(BEEPER, OUTPUT);

  
}

void drawGameElements(bool initial) {
  // Clear displays
  display1.clearDisplay();
  display2.clearDisplay();

  // Draw the court
  display1.drawRect(0, -2, SCREEN_WIDTH, 66, WHITE);
  display2.drawRect(0, -2, SCREEN_WIDTH, 66, WHITE);


  // Draw paddles
  int paddleY = (SCREEN_HEIGHT - 5) - PADDLE_HEIGHT; // Paddle Y position
  display1.fillRect(paddleX1, paddleY, PADDLE_WIDTH, PADDLE_HEIGHT, WHITE);
  display2.fillRect(paddleX2, paddleY, PADDLE_WIDTH, PADDLE_HEIGHT, WHITE);

  // Draw ball
  display1.fillRect(ballX, ballY, BALL_SIZE, BALL_SIZE, WHITE);

  // Draw scoreboard
  display1.setTextSize(1);
  display1.setTextColor(WHITE);
  display1.setCursor((SCREEN_WIDTH / 2 - 4), 5);
  display1.print(String(score1) + ":" + String(score2));
  display1.display();
  
  display2.setTextSize(1);
  display2.setTextColor(WHITE);
  display2.setCursor((SCREEN_WIDTH / 2 - 4), 5);
  display2.print(String(score1) + ":" + String(score2));
  display2.display();
}

void updateGame() {
  // Update paddle positions based on joystick input
  int joystickValue = analogRead(joystickXPin);
  if (joystickValue > 2000) {
    paddleX1 = min(SCREEN_WIDTH - PADDLE_WIDTH, paddleX1 + 1);
  } else if (joystickValue < 1000) {
    paddleX1 = max(0, paddleX1 - 1);
  }

  // Update ball position
  ballX += ballDirX;
  ballY += ballDirY;

  checkCollision();

  // Check for winning condition
  if (score1 >= WINNING_SCORE || score2 >= WINNING_SCORE) {
    // Display winning message and reset game
    display1.clearDisplay();
    display1.setTextSize(2);
    display1.setTextColor(WHITE);
    display1.setCursor(5, 0);
    display1.print("GAME OVER!");
    display1.setCursor(15, 20);
    if (score1 >= WINNING_SCORE) {
      display1.print("Player 1");
      display1.setCursor(35, 40);
      display1.print("Wins!");
    } else {
      display1.print("Player 2");
      display1.setCursor(35, 40);
      display1.print("Wins!");
    }
    display1.display();

    display2.clearDisplay();
    display2.setTextSize(2);
    display2.setTextColor(WHITE);
    display2.setCursor(5, 0);
    display2.print("GAME OVER!");
    display2.setCursor(15, 20);
    if (score1 >= WINNING_SCORE) {
      display2.print("Player 1");
      display2.setCursor(35, 40);
      display2.print("Wins!");
    } else {
      display2.print("Player 2");
      display2.setCursor(35, 40);
      display2.print("Wins!");
    }
    display2.display();
    delay(3000); // Delay to show winning message
    // Reset game state
    score1 = 0;
    score2 = 0;
    resetBall();
  }

}

void checkCollision() {
  // Check for ball collision with paddles
  int paddleY = (SCREEN_HEIGHT - 3) - PADDLE_HEIGHT;
  if (ballY + BALL_SIZE >= paddleY) {
    soundBounce();
    if (ballX + BALL_SIZE >= paddleX1 && ballX <= paddleX1 + PADDLE_WIDTH) {
      ballDirY = -ballDirY;
    } else {
      soundPoint();
      // Ball missed paddle
      score2++;
      resetBall();
    }
  }
  
  // Check for ball collision with walls
  if (ballX <= 0 || ballX + BALL_SIZE >= SCREEN_WIDTH) {
    ballDirX = -ballDirX;
    soundBounce();
  }
  
  if (ballY <= 0) {
    // Move the ball to the second screen
    ballY = SCREEN_HEIGHT - BALL_SIZE; // Place the ball at the bottom of the second screen
    ballDirY = -ballDirY; // Reverse the y direction
    soundBounce();
    // Update display on the second screen if needed
    display2.clearDisplay();
    display2.print(score1);
    display2.display();
  } else if (ballY + BALL_SIZE >= SCREEN_HEIGHT) {
    // Move the ball to the first screen
    ballY = 0; // Place the ball at the top of the first screen
    ballDirY = -ballDirY; // Reverse the y direction
    soundBounce();
    // Increment the score on the first screen
    score1++;
    // Update display on the first screen
    display1.clearDisplay();
    display1.print(score1);
    display1.display();
  }
}



void resetBall() {
  ballX = SCREEN_WIDTH / 2;
  ballY = SCREEN_HEIGHT / 2;
  ballDirX = 1;
  ballDirY = 1;
}

void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  Serial.print("\r\nLast Packet Send Status:\t");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}

void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy(&myData, incomingData, sizeof(myData));
  ballX = myData.ballX;
  ballY = myData.ballY;
  paddleX2 = myData.paddleX2;
  score1 = myData.score1;
  score2 = myData.score2;
}

void loadScreen() {
  // Clear both displays
  display1.clearDisplay();
  display2.clearDisplay();

  // Display the logo on both screens
  display1.invertDisplay(true);
  display1.drawBitmap(0, 10, myLogo, SCREEN_WIDTH, SCREEN_HEIGHT, WHITE);
  display1.display();
  display2.invertDisplay(true);
  display2.drawBitmap(0, 10, myLogo, SCREEN_WIDTH, SCREEN_HEIGHT, WHITE);
  display2.display();
  delay(2000);
  display2.invertDisplay(false);
  display1.invertDisplay(false);

  // Shake the logo
  shakeLogo();

  // Display text on both screens
  display1.clearDisplay();
  display1.setCursor(0, 0);
  display1.setTextColor(WHITE);
  display1.setTextSize(2);
  display1.print("Handy4ndys");
  display1.setTextSize(1);
  display1.setCursor(7, 30);
  display1.print("Hackaton Submission");
  display1.setCursor(5, 50);
  display1.print("Arduino & ESP32 Pong");
  display1.display();

  display2.clearDisplay();
  display2.setCursor(0, 0);
  display2.setTextColor(WHITE);
  display2.setTextSize(2);
  display2.print("Handy4ndys");
  display2.setTextSize(1);
  display2.setCursor(7, 30);
  display2.print("Hackaton Submission");
  display2.setCursor(5, 50);
  display2.print("Arduino & ESP32 Pong");
  display2.display();

  delay(3000);

  // Clear both displays
  display1.clearDisplay();
  display2.clearDisplay();
}


void shakeLogo(){

  int shakeAmount = 1; // The amount of pixels to shake
  int shakeDelay = 10; // Delay in milliseconds between shakes
  int shakeDuration = 3000; // Total duration of the shake in milliseconds

  unsigned long startTime = millis();
  
  while (millis() - startTime < shakeDuration) {
    int xOffset = random(-shakeAmount, shakeAmount + 1);
    int yOffset = random(-shakeAmount, shakeAmount + 1);

    display1.clearDisplay();
    display2.clearDisplay();
    display1.drawBitmap(xOffset, (yOffset + 10), myLogo, SCREEN_WIDTH, SCREEN_HEIGHT, WHITE);
    display1.display();
    display2.drawBitmap(xOffset, (yOffset + 10), myLogo, SCREEN_WIDTH, SCREEN_HEIGHT, WHITE);
    display2.display();

    delay(shakeDelay);
  }
}

//Sound of ball hitting  wall and paddles
void soundBounce() {
  tone(BEEPER, 500, 50);
}
//Sound  of point scored
void soundPoint() {
  tone(BEEPER, 100, 50);
}