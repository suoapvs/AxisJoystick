/*
  Joystick axes calibration

  Reads a press of the calibrated joystick and displays information
  in the default Serial.

  To calibrate, call the calibrate() method:

  void calibrate(low, high);
  or
  void calibrate(low, high, deviation);

  Where:
  low - the lower bound of the values range (default, 0);
  high - the upper bound of the values range (default, 1023);
  deviation - deviation from the value’s axis range (default, 100),
  when the axis is considered activated:
  axis value <= (low + deviation) or
  axis value >= (high - deviation).

  https://github.com/YuriiSalimov/AxisJoystick

  Created by Yurii Salimov, May, 2019.
  Released into the public domain.
*/
#include <AxisJoystick.h>

#define SW_PIN 5
#define VRX_PIN A1
#define VRY_PIN A2
#define LOW_RANGE 0
#define HIGH_RANGE 1023
#define RANGE_DEVIATION 100

Joystick* joystic;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  joystic = new AxisJoystick(SW_PIN, VRX_PIN, VRY_PIN);
  joystic->calibrate(LOW_RANGE, HIGH_RANGE, RANGE_DEVIATION);
}

// the loop function runs over and over again forever
void loop() {
  Serial.print("| SingleRead: " + moveTitle(joystic->singleRead()));
  Serial.print(" | MultipleRead: " + moveTitle(joystic->multipleRead()));
  Serial.print(" | Press: " + String(joystic->isPress()));
  Serial.print(" | Up: " + String(joystic->isUp()));
  Serial.print(" | Down: " + String(joystic->isDown()));
  Serial.print(" | Right: " + String(joystic->isRight()));
  Serial.print(" | Left: " + String(joystic->isLeft()));
  Serial.print(" | VRx: " + String(joystic->readVRx()));
  Serial.print(" | VRy: " + String(joystic->readVRy()));
  Serial.println(" | SW: " + String(joystic->readSW()) + " |");
  delay(500); // To delay the output of information.
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
