/**
	AxisJoystick.h - class implements methods of the Joystick.h
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

	https://github.com/YuriiSalimov/AxisJoystick

	Created by Yurii Salimov, February, 2018.
	Released into the public domain.
*/
#ifndef AXIS_JOYSTICK_H
#define AXIS_JOYSTICK_H

#include "Joystick.h"

/**
	The value at which the joystick axis
	is considered to be on.
*/
#define JOYSTICK_AXIS_DEVIATION 100

/**
	Min value of Arduino ADC.
*/
#define JOYSTICK_ADC_MIN 0

/**
	Max value of Arduino ADC.
*/
#define JOYSTICK_ADC_MAX 1023

/**
	Signal when the joystick button is pressed.
*/
#define JOYSTICK_BUTTON_PRESS_SIGNAL LOW

class AxisJoystick final : public Joystick {

	private:
		int SW_pin;
		int VRx_pin;
		int VRy_pin;
		int low = JOYSTICK_ADC_MIN;
		int high = JOYSTICK_ADC_MAX;
		int deviation = JOYSTICK_AXIS_DEVIATION;

		/**
		The value for the temporary storage
		of the previous pressing of the joystick
		controller.
		*/
		Move previousMove = Move::NOT;

	public:
		/**
			Constructor.
			@param SW_pin - a digital port pin of a button.
			@param VRx_pin - a analog port pin of X-axis.
			@param VRy_pin - a analog port pin of Y-axis.
		*/
		AxisJoystick(int SW_pin, int VRx_pin, int VRy_pin);

		Move singleRead() override;

		Move multipleRead() override;

		boolean isPress() override;

		boolean isUp() override;

		boolean isDown() override;

		boolean isRight() override;

		boolean isLeft() override;

		int readVRx() override;

		int readVRy() override;

		int readSW() override;

		int xAxis() override;

		int yAxis() override;

		/**
			Joystick axes calibration.
			@param low - the lower bound of the values range (default, 0);
			@param high - the upper bound of the values range (default, 1023);
		*/
		void calibrate(int low, int high) override;

		/**
			Joystick axes calibration.
			@param low - the lower bound of the values range (default, 0);
			@param high - the upper bound of the values range (default, 1023);
			@param deviation - deviation from the value’s axis range (default, 100),
				when the axis is considered activated:
				axis value <= (low + deviation)
				or
				axis value >= (high - deviation).
		*/
		void calibrate(int low, int high, int deviation) override;

	private:
		inline int lowRange();

		inline int highRange();
};

#endif
