/**
	AxisJoystick.h - class implements methods of the Joystick.h
	interface for working with an analog joystick controller.

	v.1.0.3:
	- optimized call of the init() method.

	v.2.0:
	- added implementation of the Joystick interface;
	- replaced X and Y axes.

	https://github.com/YuriiSalimov/AxisJoystick

	Created by Yurii Salimov, February, 2018.
	Released into the public domain.
*/
#ifndef AXIS_JOYSTICK_H
#define AXIS_JOYSTICK_H

#include "Joystick.h"

/**
	The value at which the joystick axis
	is considered to be on (15%).
*/
#define JOYSTICK_AXIS_ON_PERCENT	0.15

/**
	Min value of Arduino ADC.
*/
#define JOYSTICK_ADC_MIN	0

/**
	Max value of Arduino ADC.
*/
#define JOYSTICK_ADC_MAX	1023

/**
	Values diapason of Arduino ADC
*/
#define JOYSTICK_ADC	(JOYSTICK_ADC_MAX - JOYSTICK_ADC_MIN)

/**
	The value at which the joystick axis
	is considered to be on.
*/
#define JOYSTICK_AXIS_ON_RANGE	(JOYSTICK_ADC * JOYSTICK_AXIS_ON_PERCENT)

/**
	The upper limit of the range of values
	at which the joystick axis is considered
	to be pressed UP.
*/
#define JOYSTICK_AXIS_HIGH_RANGE	(JOYSTICK_ADC_MAX - JOYSTICK_AXIS_ON_RANGE)

/**
	The lower limit of the range of values
	at which the joystick axis is considered
	to be pressed DOWN.
*/
#define JOYSTICK_AXIS_LOW_RANGE	(JOYSTICK_ADC_MIN + JOYSTICK_AXIS_ON_RANGE)

/**
	Signal when the joystick button is pressed.
*/
#define JOYSTICK_BUTTON_PRESS_SIGNAL	LOW

// class
class AxisJoystick final : public Joystick {

	private:
		int SW_pin;
		int VRx_pin;
		int VRy_pin;

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

	private:
		/**
			Initialization of the module.
		*/
		inline void init();
};

#endif
