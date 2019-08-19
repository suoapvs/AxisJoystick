/*
  Replace X- and Y-axis of Joystick

  Reads a press of the joystick and displays information
  in the default Serial.

  https://github.com/YuriiSalimov/AxisJoystick

  Created by Yurii Salimov, December, 2018.
  Released into the public domain.
*/
#include <Joystick.h>
#include <AxisJoystick.h>
#include <XYReplacerJoystick.h>

#define SW_PIN 5
#define VRX_PIN A1
#define VRY_PIN A2

Joystick* original;
Joystick* xyReplacer;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);

  original = new AxisJoystick(SW_PIN, VRX_PIN, VRY_PIN);
  xyReplacer = new XYReplacerJoystick(original);
}

// the loop function runs over and over again forever
void loop() {
  Serial.print("original: " + moveTitle(original->multipleRead()));
  Serial.println(" | replace XY: " + moveTitle(xyReplacer->multipleRead()));

  delay(500); // optionally, only to delay the output of information in the example
}

/**
  Return title of the input joystick move.
*/
String moveTitle(const Joystick::Move move) {
  switch (move) {
    case Joystick::Move::NOT:
      return "NOT";
    case Joystick::Move::PRESS:
      return "PRESS";
    case Joystick::Move::UP:
      return "UP";
    case Joystick::Move::DOWN:
      return "DOWN";
    case Joystick::Move::RIGHT:
      return "RIGHT";
    case Joystick::Move::LEFT:
      return "LEFT";
    default:
      return "???";
  }
}
