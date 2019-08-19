/**
	XYReplacer - class-wrapper implements methods of the Joystick.h
	interface, replacing X- and Y-axes signal of the origin joystick.

	v.2.0:
	- created.

	v.2.1.1
	- optimized replace() method.

	v.2.2.0
	- renamed from XYReplacer.

	https://github.com/YuriiSalimov/AxisJoystick

	Created by Yurii Salimov, December, 2018.
	Released into the public domain.
*/
#ifndef XY_REPLACER_JOYSTICK_H
#define XY_REPLACER_JOYSTICK_H

#include "DelegateJoystick.h"

class XYReplacerJoystick final : public DelegateJoystick {

	public:
		/**
			Constructor

			@param origin - the origin joystick (not NULL)
		*/
		XYReplacerJoystick(Joystick* origin);

		/**
			Single reading of the joystick controller.
			Replaces X- and Y-axis moves.

			@return value of pressing the joystick (never NULL):
			Move::UP - X-axis is pressed right;
			Move::DOWN - X-axis is pressed left;
			Move::LEFT - Y-axis is pressed down;
			Move::RIGHt - Y-axis is pressed up;
			else the input move.
		*/
		Move singleRead() override;

		/**
			Multiple reading of the joystick controller.
			Replaces X- and Y-axes moves.

			@return value of pressing the joystick (never NULL):
			Move::UP - X-axis is pressed right;
			Move::DOWN - X-axis is pressed left;
			Move::LEFT - Y-axis is pressed down;
			Move::RIGHt - Y-axis is pressed up;
			else the input move.
		*/
		Move multipleRead() override;

		/**
			Checks if the joystick is pressed up (Y-axis).

			@return true - joystick is really pressed right (X-axis),
			false - joystick is not pressed.
		*/
		boolean isUp() override;

		/**
			Checks if the joystick is pressed down (Y-axis).

			@return true - joystick is really pressed left (X-axis),
			false - joystick is not pressed.
		*/
		boolean isDown() override;

		/**
			Checks if the joystick is pressed right (X-axis).

			@return true - joystick is really pressed up (Y-axis),
			false - joystick is not pressed.
		*/
		boolean isRight() override;

		/**
			Checks if the joystick is pressed left (X-axis).

			@return true - joystick is really pressed down (Y-axis),
			false - joystick is not pressed.
		*/
		boolean isLeft() override;

		/**
			Reads the joystick X-axis coordinate
			(really Y-axis coordinate).

			@return X-axis (really Y-axis) coordinate
		*/
		int xAxis() override;

		/**
			Returns the joystick Y-axis coordinate
			(really X-axis coordinate).

			@return Y-axis (really X-axis) coordinate
		*/
		int yAxis() override;

	private:
		/**
			Replaces the input move from X- to Y-axis
			and from Y- to X-axis.

			@param move - the origin move to invert (not NULL)
			@return value of pressing the joystick (never NULL):
			Move::UP - X-axis is pressed right;
			Move::DOWN - X-axis is pressed left;
			Move::LEFT - Y-axis is pressed down;
			Move::RIGHt - Y-axis is pressed up;
			else the input move.
		*/
		inline Move replace(Move move);
};

#endif
