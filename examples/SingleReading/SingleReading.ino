/*
  Axis Joystick, Single Reading

  Reads a press of the joystick and displays information
  in the default Serial.

  Single reading of the joystick controller.
  If the joystick is clamped, the next
  value of pressing - NOT.
  Return value of pressing the remote control:
    Move::PRESS - button is pressed;
    Move::UP - X axis is pressed up;
    Move::DOWN - X axis is pressed down;
    Move::RIGTH - Y axis is pressed right;
    Move::LEFT - Y axis is pressed left;
    Move::NOT - not pressed.

  https://github.com/YuriiSalimov/AxisJoystick

  Created by Yurii Salimov, February, 2018.
  Released into the public domain.
*/
#include <Joystick.h>
#include <AxisJoystick.h>

#define SW_PIN 5
#define VRX_PIN A1
#define VRY_PIN A2

Joystick* joystick;

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

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);

  joystick = new AxisJoystick(SW_PIN, VRX_PIN, VRY_PIN);
}

// the loop function runs over and over again forever
void loop() {
  Serial.print("Joystick, Single Reading: ");
  Serial.println(moveTitle(joystick->singleRead()));

  delay(500); // optionally, only to delay the output of information in the example
}
