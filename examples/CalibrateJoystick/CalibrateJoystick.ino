/*
  Joystick axes calibration

  Reads a press of the calibrated joystick and displays information
  in the default Serial.

  To calibrate, call the calibrate() method:

  void calibrate(LOW, HIGH);
  or
  void calibrate(ADC_MIN, ADC_MAX, DEVIATION);

  Where:
  LOW - the lower bound of the values range (default, 100);
  HIGH - the upper bound of the values range (default, 923);
  ADC_MIN - min value of the board ADC (default for Arduino, 0);
  ADC_MAX - max value of the board ADC (default for Arduino, 1023);
  DEVIATION - deviation from the value’s axis range (default, 100).

  https://github.com/YuriiSalimov/AxisJoystick

  Created by Yurii Salimov, May, 2019.
  Released into the public domain.
*/
#include <Joystick.h>
#include <AxisJoystick.h>

#define SW_PIN 5
#define VRX_PIN A1
#define VRY_PIN A2
#define ARDUINO_ADC_MIN 0
#define ARDUINO_ADC_MAX 1023
#define AXES_DEVIATION 100

Joystick* joystic;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);

  joystic = new AxisJoystick(SW_PIN, VRX_PIN, VRY_PIN);
  joystic->calibrate(ARDUINO_ADC_MIN, ARDUINO_ADC_MAX, AXES_DEVIATION);
  /*
    or
    joystic->calibrate(
      ARDUINO_ADC_MIN + AXES_DEVIATION,
      ARDUINO_ADC_MAX - AXES_DEVIATION
    );
  */
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
