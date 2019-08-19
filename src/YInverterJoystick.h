/**
	YInverter - class-wrapper implements methods of the Joystick.h
	interface, inverting Y-axis signal of the origin joystick.

	v.2.0:
	- created.

	v.2.1.1
	- optimized replace() method.

	v.2.2.0
	- renamed from YInverter.

	https://github.com/YuriiSalimov/AxisJoystick

	Created by Yurii Salimov, December, 2018.
	Released into the public domain.
*/
#ifndef Y_INVERTER_JOYSTICK_H
#define Y_INVERTER_JOYSTICK_H

#include "DelegateJoystick.h"

class YInverterJoystick final : public DelegateJoystick {

	public:
		/**
			Constructor

			@param origin - the origin joystick (not NULL)
		*/
		YInverterJoystick(Joystick* origin);

		/**
			Single reading of the joystick controller.
			Inverts the input joystick Y-axis move.

			@return value of pressing the joystick (never NULL):
			Move::UP - Y-axis is pressed down;
			Move::DOWN - Y-axis is pressed up;
			else the input move.
		*/
		Move singleRead() override;

		/**
			Multiple reading of the joystick controller.
			Inverts the input joystick Y-axis move.

			@return value of pressing the joystick (never NULL):
			Move::UP - Y-axis is pressed down;
			Move::DOWN - Y-axis is pressed up;
			else the input move.
		*/
		Move multipleRead() override;

		/**
			Checks if the joystick is pressed up (Y-axis).

			@return true - joystick is really pressed down,
			false - joystick is not pressed.
		*/
		boolean isUp() override;

		/**
			Checks if the joystick is pressed down (Y-axis).

			@return true - joystick is really pressed up,
			false - joystick is not pressed.
		*/
		boolean isDown() override;

	private:
		/**
			Inverts the input joystick Y-axis move.

			@param move - the origin move to invert (not NULL)
			@return value of pressing the joystick (never NULL):
			Move::UP - Y-axis is pressed down;
			Move::DOWN - Y-axis is pressed up;
			else the input move.
		*/
		inline Move invert(Move move);
};

#endif
