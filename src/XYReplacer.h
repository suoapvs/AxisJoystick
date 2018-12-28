/**
	XYReplacer.h - class-wrapper implements methods of the Joystick.h
	interface, replacing X- and Y-axes signal of the delegate joystick.

	v.2.0:
	- created.

	https://github.com/YuriiSalimov/AxisJoystick

	Created by Yurii Salimov, December, 2018.
	Released into the public domain.
*/
#ifndef XY_REPLACER_H
#define XY_REPLACER_H

#include "DelegateJoystick.h"

// class
class XYReplacer final : public DelegateJoystick {

	public:
		XYReplacer(const Joystick* origin);

		/**
			Single reading of the joystick controller.
			Replaces X- and Y-axis moves.
		*/
		Move singleRead() override;

		/**
			Multiple reading of the joystick controller.
			Replaces X- and Y-axes moves.
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
			Returns the joystick X-axis coordinate
			(really Y-axis coordinate).
		*/
		int xAxis() override;

		/**
			Returns the joystick Y-axis coordinate
			(really X-axis coordinate).
		*/
		int yAxis() override;

	private:
		/**
			Replaces the input move from X- to Y-axis
			and from Y- to X-axis.
		*/
		Move replace(Move move);
};

#endif
