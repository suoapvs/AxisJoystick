/**
	Joystick.h - interface describes a set of methods
	for working with a joystick controller.

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

// interface
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

	protected:
		Joystick() {}

  public:
		virtual ~Joystick() {}

		/**
			Single reading of the joystick controller.
			If the joystick is clamped, the next
			value of pressing - NOT.
			@return value of pressing the joystick.
		*/
		virtual Move singleRead() {}

		/**
			Multiple reading of the joystick controller.
			If the joystick is clamped,
			returns a pressed button value.
			@return value of pressing the joystick.
		*/
		virtual Move multipleRead() {}

		/**
			Checks if the joystick button is pressed.
			@return true - button is pressed,
			false - button is not pressed.
		*/
		virtual boolean isPress() {}

		/**
			Checks if the joystick is pressed up (Y-axis).
			@return true - joystick is pressed up,
			false - joystick is not pressed.
		*/
		virtual boolean isUp() {}

		/**
			Checks if the joystick is pressed down (Y-axis).
			@return true - joystick is pressed down,
			false - joystick is not pressed.
		*/
		virtual boolean isDown() {}

		/**
			Checks if the joystick is pressed right (X-axis).
			@return true - joystick is pressed right,
			false - joystick is not pressed.
		*/
		virtual boolean isRight() {}

		/**
			Checks if the joystick is pressed left (X-axis).
			@return true - joystick is pressed left,
			false - joystick is not pressed.
		*/
		virtual boolean isLeft() {}

		/**
			Returns the joystick X-axis coordinate.
		*/
		virtual int xAxis() {}

		/**
			Returns the joystick Y-axis coordinate.
		*/
		virtual int yAxis() {}

		/**
			Returns VRx pin value.
		*/
		virtual int readVRx() {}

		/**
			Returns VRy pin value.
		*/
		virtual int readVRy() {}

		/**
			Returns SW pin value.
		*/
		virtual int readSW() {}
};

#endif
