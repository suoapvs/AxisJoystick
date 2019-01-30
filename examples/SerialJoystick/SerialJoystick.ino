/*
  Axis Joystick

  Reads a press of the joystick and displays information
  in the default Serial.

  https://github.com/YuriiSalimov/AxisJoystick

  Created by Yurii Salimov, February, 2018.
  Released into the public domain.
*/
#include <AxisJoystick.h>

#define SW_PIN 5
#define VRX_PIN A1
#define VRY_PIN A2

Joystick* joystic;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  joystic = new AxisJoystick(SW_PIN, VRX_PIN, VRY_PIN);
}

// the loop function runs over and over again forever
void loop() {
  Serial.print("| SingleRead: " + String(joystic->singleRead()));
  Serial.print(" | MultipleRead: " + String(joystic->multipleRead()));
  Serial.print(" | Press: " + String(joystic->isPress()));
  Serial.print(" | Up: " + String(joystic->isUp()));
  Serial.print(" | Down: " + String(joystic->isDown()));
  Serial.print(" | Right: " + String(joystic->isRight()));
  Serial.print(" | Left: " + String(joystic->isLeft()));
  Serial.print(" | VRx: " + String(joystic->readVRx()));
  Serial.print(" | VRy: " + String(joystic->readVRy()));
  Serial.println(" | SW: " + String(joystic->readSW()) + " |");
}
