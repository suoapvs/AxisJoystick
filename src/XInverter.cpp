#include "XInverter.h"

XInverter::XInverter(Joystick* origin)
	: DelegateJoystick(origin) {
}

Joystick::Move XInverter::singleRead() {
	return invert(DelegateJoystick::singleRead());
}

Joystick::Move XInverter::multipleRead() {
	return invert(DelegateJoystick::multipleRead());
}

Joystick::Move XInverter::invert(const Joystick::Move move) {
	switch (move) {
		case Move::LEFT:
			return Move::RIGHT;
		case Move::RIGHT:
			return Move::LEFT;
		default:
			return move;
	}
}

boolean XInverter::isRight() {
	return DelegateJoystick::isLeft();
}

boolean XInverter::isLeft() {
	return DelegateJoystick::isRight();
}
