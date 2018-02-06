/**
	AxisJoystick.h - The interface describes a set of methods 
	for working with a joystick controller.

	https://github.com/YuriiSalimov/AxisJoystick
	
	Created by Yurii Salimov, February, 2018.
	Released into the public domain.
*/
#ifndef AXIS_JOYSTICK_H
#define AXIS_JOYSTICK_H

#if defined(ARDUINO) && (ARDUINO >= 100)
	#include <Arduino.h>
#else
	#include <WProgram.h>
#endif 

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

class AxisJoystick final {
	
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

	private:
		int SW_pin = 0;
		int VRx_pin = 0;
		int VRy_pin = 0;

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
			@param VRx_pin - a analog port pin of X axis.
			@param VRy_pin - a analog port pin of Y axis.
		*/
		AxisJoystick(const int SW_pin, const int VRx_pin, const int VRy_pin);

		/**
			Single reading of the joystick controller.
			If the joystick is clamped, the next 
			value of pressing - NOT.
			@return value of pressing the joystick.
		*/
		Move singleRead();

		/**
			Multiple reading of the joystick controller.
			If the joystick is clamped, 
			returns a pressed button value.
			@return value of pressing the joystick.
		*/
		Move multipleRead();

		/**
			Checks if the joystick button is pressed.
			@return true - button is pressed, 
			false - button is not pressed.
		*/
		boolean isPress();

		/**
			Checks if the joystick is pressed up (X axis).
			@return true - joystick is pressed up, 
			false - joystick is not pressed.
		*/
		boolean isUp();

		/**
			Checks if the joystick is pressed down (X axis).
			@return true - joystick is pressed down, 
			false - joystick is not pressed.
		*/
		boolean isDown();

		/**
			Checks if the joystick is pressed right (Y axis).
			@return true - joystick is pressed right, 
			false - joystick is not pressed.
		*/
		boolean isRight();

		/**
			Checks if the joystick is pressed left (Y axis).
			@return true - joystick is pressed left, 
			false - joystick is not pressed.
		*/
		boolean isLeft();

		/**
			Returns the joystick X axis coordinate.
			@return X axis coordinate.
		*/
		int xAxis();

		/**
			Returns the joystick Y axis coordinate.
			@return Y axis coordinate.
		*/
		int yAxis();
	
	private:
		/**
			Initialization of the module.
		*/
		void init();
};

#endif
