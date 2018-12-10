/**
	XInverter.h - class-wrapper implements methods of the Joystick.h
	interface, inverting X-axis signal of the delegate joystick.

	v.2.0:
	- created.

	https://github.com/YuriiSalimov/AxisJoystick

	Created by Yurii Salimov, December, 2018.
	Released into the public domain.
*/
#ifndef X_INVERTER_H
#define X_INVERTER_H

#include "DelegateJoystick.h"

// class
class XInverter final : public DelegateJoystick {

	public:
		XInverter(const Joystick* joystick);

		/**
			Single reading of the joystick controller.
			Inverts the input joystick X-axis move.
		*/
		Move singleRead() override;

		/**
			Multiple reading of the joystick controller.
			Inverts the input joystick X-axis move.
		*/
		Move multipleRead() override;

		/**
			Checks if the joystick is pressed up (X-axis).
			@return true - joystick is really pressed down,
			false - joystick is not pressed.
		*/
		boolean isUp() override;

		/**
			Checks if the joystick is pressed down (X-axis).
			@return true - joystick is really pressed up,
			false - joystick is not pressed.
		*/
		boolean isDown() override;

  private:
		/**
			Inverts the input joystick X-axis move.
		*/
    Move invert(Move move);
};

#endif
