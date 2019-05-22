/*
  Axis Joystick for STM32

  Reads a press of the joystick and displays information
  in the default Serial.

  The Arduino Uno or any other Arduino board that uses Atmega328 as
  the Microcontroller has ADC resolution of 10 bits. Hence the values on each
  analog channel can vary from 0 to 1023.
  The STM32 board has ADC resolution of 12 bits. Hence the values on each analog
  channel can vary from 0 to 4095.

  If you use the STM32 board, you must calibrate your joystick,
  since the analogRead(*) function return 0..4095
  versus 0..1023 for Arduino.

  ---------------------------
  |       analogRead()      |
  ---------------------------
  |  Arduion   |   STM32    |
  |-------------------------|
  |  0...1023  |  0...4095  |
  ---------------------------

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
#include <Joystick.h>
#include <AxisJoystick.h>

#define SW_PIN PA5
#define VRX_PIN PA6
#define VRY_PIN PA7
#define LOW_RANGE 0
#define HIGH_RANGE 4095
#define RANGE_DIVITION 100

Joystick* joystic;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  joystic = new AxisJoystick(SW_PIN, VRX_PIN, VRY_PIN);
  joystic->calibrate(LOW_RANGE, HIGH_RANGE, RANGE_DIVITION);
}

// the loop function runs over and over again forever
void loop() {
  Serial.print("SingleRead: " + moveTitle(joystic->singleRead()));
  Serial.println(" | MultipleRead: " + moveTitle(joystic->multipleRead()));;
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
