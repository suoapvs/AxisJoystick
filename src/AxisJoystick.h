/**
	AxisJoystick - class implements methods of the Joystick.h
	interface for working with an analog joystick controller.

	v.1.0.3:
	- optimized call of the init() method.

	v.2.0:
	- added implementation of the Joystick interface;
	- replaced X and Y axes.

	v.2.1.0
	- added calibration methods for joystick axes.

	v.2.1.1
	- optimized singleRead() method.

	v.2.2.1
	- optimized methods for Joystick calibration.

	v.2.2.2
	Replaced "define" constants with "static const".

	https://github.com/YuriiSalimov/AxisJoystick

	Created by Yurii Salimov, February, 2018.
	Released into the public domain.
*/
#ifndef AXIS_JOYSTICK_H
#define AXIS_JOYSTICK_H

#include "Joystick.h"

class AxisJoystick final : public Joystick {

	private:
		/**
			The value at which the joystick axis
			is considered to be on.
		*/
		static const int AXIS_DEVIATION = 100;
		// Min value of Arduino ADC.
		static const int ADC_MIN = 0;
		// Max value of Arduino ADC.
		static const int ADC_MAX = 1023;
		// Signal when the joystick button is pressed.
		static const int BUTTON_PRESS_SIGNAL = LOW;

		int SW_pin;
		int VRx_pin;
		int VRy_pin;
		int min = ADC_MIN + AXIS_DEVIATION;
		int max = ADC_MAX - AXIS_DEVIATION;

		/**
			The value for the temporary storage
			of the previous pressing of the joystick
			controller.
		*/
		Move previousMove = Move::NOT;

	public:
		/**
			Constructor

			@param SW_pin - a digital port pin of a button.
			@param VRx_pin - a analog port pin of X-axis.
			@param VRy_pin - a analog port pin of Y-axis.
		*/
		AxisJoystick(int SW_pin, int VRx_pin, int VRy_pin);

		/**
			Single reading of the joystick controller.
			If the joystick is clamped, the next
			value of pressing - NOT.

			@return value of pressing the joystick (never NULL)
		*/
		Move singleRead() override;

		/**
			Multiple reading of the joystick controller.
			If the joystick is clamped,
			returns a pressed button value.

			@return value of pressing the joystick (never NULL):
			Move::PRESS - button is pressed;
			Move::UP - Y-axis is pressed up;
			Move::DOWN - Y-axis is pressed down;
			Move::RIGTH - X-axis is pressed right;
			Move::LEFT - X-axis is pressed left;
			Move::NOT - not pressed.
		*/
		Move multipleRead() override;

		/**
			Checks if the joystick button is pressed.

			@return true - button is pressed,
			false - button is not pressed.
		*/
		boolean isPress() override;

		/**
			Checks if the joystick is pressed up (Y-axis).

			@return true - joystick is pressed up,
			false - joystick is not pressed.
		*/
		boolean isUp() override;

		/**
			Checks if the joystick is pressed down (Y-axis).

			@return true - joystick is pressed down,
			false - joystick is not pressed.
		*/
		boolean isDown() override;

		/**
			Checks if the joystick is pressed right (X-axis).

			@return true - joystick is pressed right,
			false - joystick is not pressed.
		*/
		boolean isRight() override;

		/**
			Checks if the joystick is pressed left (X-axis).

			@return true - joystick is pressed left,
			false - joystick is not pressed.
		*/
		boolean isLeft() override;

		/**
			Reads the joystick X-axis coordinate.

			@return X-axis coordinate.
		*/
		int xAxis() override;

		/**
			Reads the joystick Y-axis coordinate.

			@return Y-axis coordinate.
		*/
		int yAxis() override;

		/**
			Reads the VRx pin value.

			@return VRx value.
		*/
		int readVRx() override;

		/**
			Reads the VRy pin value.

			@return VRy value.
		*/
		int readVRy() override;

		/**
			Reads the SW pin value.

			@return SW value.
		*/
		int readSW() override;

		/**
			Joystick axes calibration.

			@param low - the lower bound of the values range (default, 100);
			@param high - the upper bound of the values range (default, 923);
		*/
		void calibrate(int low, int high) override;

		/**
			Joystick axes calibration.

			@param adcMin - min value of the board ADC (default for Arduino, 0);
			@param adcMax - max value of the board ADC (default for Arduino, 1023);
			@param deviation - deviation from the value’s axis range (default, 100),
			when the axis is considered activated:
			axis value <= (low + deviation)
			or
			axis value >= (high - deviation).
		*/
		void calibrate(int adcMin, int adcMax, int deviation) override;

	private:
		inline boolean isLow(int value);

		inline boolean isHigh(int value);
};

#endif
