/**
	Joystick - interface describes a set of methods
	for working with a joystick controller.

	v.2.1.0
	- added calibration methods for joystick axes

	v.2.2.1
	- updated methods for Joystick calibration

	v.2.2.3
	- added virtual destructor

	https://github.com/YuriiSalimov/AxisJoystick

	Created by Yurii Salimov, December, 2018.
	Released into the public domain.
*/
#ifndef JOYSTICK_H
#define JOYSTICK_H

#if defined(ARDUINO) && (ARDUINO >= 100)
	#include <Arduino.h>
#else
	#include <WProgram.h>
#endif

class Joystick {

	public:
		/**
			Enums of a possible pressings
			of the joystick controller:
			PRESS - button is pressed;
			UP - X axis is pressed UP;
			DOWN - X axis is pressed DOWN;
			RIGTH - Y axis is pressed RIGHT;
			LEFT - Y axis is pressed LEFT;
			NOT - not pressed.
		*/
		enum Move {
			PRESS, UP, DOWN, RIGHT, LEFT, NOT
		};

		/**
      Destructor
      Deletes Joystick instance.
    */
		virtual ~Joystick() {};

		/**
			Single reading of the joystick controller.
			If the joystick is clamped, the next
			value of pressing - NOT.

			@return value of pressing the joystick.
		*/
		virtual Move singleRead() = 0;

		/**
			Multiple reading of the joystick controller.
			If the joystick is clamped,
			returns a pressed button value.

			@return value of pressing the joystick:
			Move::PRESS - button is pressed;
			Move::UP - Y-axis is pressed up;
			Move::DOWN - Y-axis is pressed down;
			Move::RIGTH - X-axis is pressed right;
			Move::LEFT - X-axis is pressed left;
			Move::NOT - not pressed.
		*/
		virtual Move multipleRead() = 0;

		/**
			Checks if the joystick button is pressed.

			@return true - button is pressed,
			false - button is not pressed.
		*/
		virtual boolean isPress() = 0;

		/**
			Checks if the joystick is pressed up (Y-axis).

			@return true - joystick is pressed up,
			false - joystick is not pressed.
		*/
		virtual boolean isUp() = 0;

		/**
			Checks if the joystick is pressed down (Y-axis).

			@return true - joystick is pressed down,
			false - joystick is not pressed.
		*/
		virtual boolean isDown() = 0;

		/**
			Checks if the joystick is pressed right (X-axis).

			@return true - joystick is pressed right,
			false - joystick is not pressed.
		*/
		virtual boolean isRight() = 0;

		/**
			Checks if the joystick is pressed left (X-axis).

			@return true - joystick is pressed left,
			false - joystick is not pressed.
		*/
		virtual boolean isLeft() = 0;

		/**
			Reads the joystick X-axis coordinate.

			@return X-axis coordinate.
		*/
		virtual int xAxis() = 0;

		/**
			Reads the joystick Y-axis coordinate.

			@return Y-axis coordinate.
		*/
		virtual int yAxis() = 0;

		/**
			Reads the VRx pin value.

			@return VRx value.
		*/
		virtual int readVRx() = 0;

		/**
			Reads the VRy pin value.

			@return VRy value.
		*/
		virtual int readVRy() = 0;

		/**
			Reads the SW pin value.

			@return SW value.
		*/
		virtual int readSW() = 0;

		/**
			Joystick axes calibration.

			@param low - the lower bound of the values range;
			@param high - the upper bound of the values range;
		*/
		virtual void calibrate(int low, int high) = 0;

		/**
			Joystick axes calibration.

			@param adcMin - min value of the board ADC;
			@param adcMax - max value of the board ADC;
			@param deviation - deviation from the value’s axis range,
			when the axis is considered activated:
			axis value <= (low + deviation)
			or
			axis value >= (high - deviation).
		*/
		virtual void calibrate(int adcMin, int adcMax, int deviation) = 0;
};

#endif
