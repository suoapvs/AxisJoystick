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
#include <AxisJoystick.h>

#define SW_PIN  5
#define VRX_PIN A1
#define VRY_PIN A2

AxisJoystick* joystick;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  joystick = new AxisJoystick(SW_PIN, VRX_PIN, VRY_PIN);
}

// the loop function runs over and over again forever
void loop() {
  const AxisJoystick::Move move = joystick->singleRead();
  String moveTitle;
  if (move == AxisJoystick::Move::PRESS) {
    moveTitle = "PRESS";
  } else if (move == AxisJoystick::Move::UP) {
    moveTitle = "UP";
  } else if (move == AxisJoystick::Move::DOWN) {
    moveTitle = "DOWN";
  } else if (move == AxisJoystick::Move::RIGHT) {
    moveTitle = "RIGHT";
  } else if (move == AxisJoystick::Move::LEFT) {
    moveTitle = "LEFT";
  } else {
    moveTitle = "NOT";
  }
  Serial.println("Joystick, Multiple Reading: " + moveTitle);
  delay(500); // To delay the output of information.
}
