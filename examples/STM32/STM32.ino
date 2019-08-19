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

#define SW_PIN PA5
#define VRX_PIN PA6
#define VRY_PIN PA7
#define STM32_ADC_MIN 0
#define STM32_ADC_MAX 4095
#define AXES_DEVIATION 100

Joystick* joystic;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);

  joystic = new AxisJoystick(SW_PIN, VRX_PIN, VRY_PIN);
  joystic->calibrate(STM32_ADC_MIN, STM32_ADC_MAX, AXES_DEVIATION);
  /*
    or
    joystic->calibrate(
      STM32_ADC_MIN + AXES_DEVIATION,
      STM32_ADC_MAX - AXES_DEVIATION
    );
  */
}

// the loop function runs over and over again forever
void loop() {
  Serial.print("SingleRead: " + moveTitle(joystic->singleRead()));
  Serial.println(" | MultipleRead: " + moveTitle(joystic->multipleRead()));

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
