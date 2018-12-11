/*
  Replace and Invert X- and Y-axes of Joystick

  Reads a press of the joystick and displays information
  in the default Serial.

  https://github.com/YuriiSalimov/AxisJoystick

  Created by Yurii Salimov, December, 2018.
  Released into the public domain.
*/
#include <Joystick.h>
#include <AxisJoystick.h>
#include <XYReplacer.h>
#include <XInverter.h>
#include <YInverter.h>

#define SW_PIN  5
#define VRX_PIN A1
#define VRY_PIN A2

Joystick* original;
Joystick* modified;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  original = new AxisJoystick(SW_PIN, VRX_PIN, VRY_PIN);
  modified = new XYReplacer(
    new XInverter(
      new XInverter(
        original
      )
    )
  );
}

// the loop function runs over and over again forever
void loop() {
  Serial.print("original: " + getMoveTitle(original->multipleRead()));
  Serial.println(" | modified: " + getMoveTitle(modified->multipleRead()));
}

/**
  Return title of the input joystick move.
*/
String getMoveTitle(const Joystick::Move move) {
  if (move == Joystick::Move::NOT) {
    return "NOT";
  } else if (move == Joystick::Move::PRESS) {
    return "PRESS";
  } else if (move == Joystick::Move::UP) {
    return "UP";
  } else if (move == Joystick::Move::DOWN) {
    return "DOWN";
  } else if (move == Joystick::Move::RIGHT) {
    return "RIGHT";
  } else if (move == Joystick::Move::LEFT) {
    return "LEFT";
  } else {
    return "???";
  }
}
