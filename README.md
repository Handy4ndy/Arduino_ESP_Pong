# Pong Game

## Overview

This repository contains the source code for a simple Pong game implemented in Arduino. The game features two paddles controlled by potentiometers and a ball that bounces between them. The objective is to prevent the ball from passing your paddle while trying to make it pass your opponent's paddle.

## Features

- Two-player gameplay
- Adjustable paddle speed using potentiometers
- Sound effects for ball bounces and points scored
- Score display on separate screens

## Hardware Requirements

- Arduino board
- Two potentiometers
- Two OLED displays
- Buzzer or speaker

## Getting Started

1. Connect the hardware components according to the schematic provided in the `schematic.pdf` file. * awaiting upload
2. Upload the `pong.ino` sketch to your Arduino board.
3. Adjust the potentiometers to control the paddles.
4. Play the game!

## Files

- `pong.ino`: Arduino sketch containing the game code.
- `esp32pong.ino`: ESP32 sketch containing the game code.

## Dependencies

This project relies on the Adafruit SSD1306 library for driving the OLED displays. Make sure to install this library via the Arduino Library Manager before uploading the sketch.

## Contributing

Contributions are welcome! If you have any ideas for improvements or bug fixes, feel free to open an issue or submit a pull request.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
