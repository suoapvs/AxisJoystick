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
#define JOYSTICK_AXIS_DIVITION 100

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
		int divition = JOYSTICK_AXIS_DIVITION;

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

		void calibrate(int low, int high) override;

		void calibrate(int low, int high, int divition) override;

	private:
		inline int lowRange();

		inline int highRange();
};

#endif
