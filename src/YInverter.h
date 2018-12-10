/**
	YInverter.h - class-wrapper implements methods of the Joystick.h
	interface, inverting Y-axis signal of the delegate joystick.

	v.2.0:
	- created.

	https://github.com/YuriiSalimov/AxisJoystick

	Created by Yurii Salimov, December, 2018.
	Released into the public domain.
*/
#ifndef Y_INVERTER_H
#define Y_INVERTER_H

#include "DelegateJoystick.h"

// class
class YInverter final : public DelegateJoystick {

	public:
		YInverter(const Joystick* joystick);

		/**
			Single reading of the joystick controller.
			Inverts the input joystick Y-axis move.
		*/
		Move singleRead() override;

		/**
			Multiple reading of the joystick controller.
			Inverts the input joystick Y-axis move.
		*/
		Move multipleRead() override;

		/**
			Checks if the joystick is pressed right (Y-axis).
			@return true - joystick is really pressed left,
			false - joystick is not pressed.
		*/
		boolean isRight() override;

		/**
			Checks if the joystick is pressed left (Y-axis).
			@return true - joystick is really pressed right,
			false - joystick is not pressed.
		*/
		boolean isLeft() override;

  private:
		/**
			Inverts the input joystick Y-axis move.
		*/
    Move invert(Move move);
};

#endif
