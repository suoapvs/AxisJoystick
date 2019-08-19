/**
	Created by Yurii Salimov, December, 2018.
	Released into the public domain.
*/
#include "XInverterJoystick.h"

XInverterJoystick::XInverterJoystick(Joystick* origin)
: DelegateJoystick(origin) {
}

boolean XInverterJoystick::isRight() {
	return DelegateJoystick::isLeft();
}

boolean XInverterJoystick::isLeft() {
	return DelegateJoystick::isRight();
}

Joystick::Move XInverterJoystick::singleRead() {
	return invert(DelegateJoystick::singleRead());
}

Joystick::Move XInverterJoystick::multipleRead() {
	return invert(DelegateJoystick::multipleRead());
}

inline Joystick::Move XInverterJoystick::invert(const Joystick::Move move) {
	switch (move) {
		case Move::LEFT:
			return Move::RIGHT;
		case Move::RIGHT:
			return Move::LEFT;
		default:
			return move;
	}
}
