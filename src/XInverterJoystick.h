/**
	XInverter - class-wrapper implements methods of the Joystick.h
	interface, inverting X-axis signal of the origin joystick.

	v.2.0:
	- created.

	v.2.1.1
	- optimized invert() method.

	v.2.2.0
	- renamed from XInverter.

	https://github.com/YuriiSalimov/AxisJoystick

	Created by Yurii Salimov, December, 2018.
	Released into the public domain.
*/
#ifndef X_INVERTER_JOYSTICK_H
#define X_INVERTER_JOYSTICK_H

#include "DelegateJoystick.h"

class XInverterJoystick final : public DelegateJoystick {

	public:
		/**
			Constructor

			@param origin - the origin joystick (not NULL)
		*/
		XInverterJoystick(Joystick* origin);

		/**
			Single reading of the joystick controller.
			Inverts the input joystick X-axis move.

			@return value of pressing the joystick (never NULL):
			Move::RIGHT - X-axis is pressed left;
			Move::LEFT - X-axis is pressed right;
			else the origin move.
		*/
		Move singleRead() override;

		/**
			Multiple reading of the joystick controller.
			Inverts the input joystick X-axis move.

			@return value of pressing the joystick (never NULL):
			Move::RIGHT - X-axis is pressed left;
			Move::LEFT - X-axis is pressed right;
			else the origin move.
		*/
		Move multipleRead() override;

		/**
			Checks if the joystick is pressed right (X-axis).

			@return true - joystick is really pressed left,
			false - joystick is not pressed.
		*/
		boolean isRight() override;

		/**
			Checks if the joystick is pressed left (X-axis).

			@return true - joystick is really pressed right,
			false - joystick is not pressed.
		*/
		boolean isLeft() override;

	private:
		/**
			Inverts the input joystick X-axis move.

			@param move - the origin move to invert (not NULL)
			@return value of pressing the joystick (never NULL):
			Move::RIGHT - X-axis is pressed left;
			Move::LEFT - X-axis is pressed right;
			else the input move.
		*/
		inline Move invert(Move move);
};

#endif
