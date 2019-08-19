/**
	Created by Yurii Salimov, December, 2018.
	Released into the public domain.
*/
#include "XYReplacerJoystick.h"

XYReplacerJoystick::XYReplacerJoystick(Joystick* origin)
: DelegateJoystick(origin) {
}

boolean XYReplacerJoystick::isUp() {
	return DelegateJoystick::isRight();
}

boolean XYReplacerJoystick::isDown() {
	return DelegateJoystick::isLeft();
}

boolean XYReplacerJoystick::isRight() {
	return DelegateJoystick::isUp();
}

boolean XYReplacerJoystick::isLeft() {
	return DelegateJoystick::isDown();
}

int XYReplacerJoystick::xAxis() {
	return DelegateJoystick::yAxis();
}

int XYReplacerJoystick::yAxis() {
	return DelegateJoystick::xAxis();
}

Joystick::Move XYReplacerJoystick::singleRead() {
	return replace(DelegateJoystick::singleRead());
}

Joystick::Move XYReplacerJoystick::multipleRead() {
	return replace(DelegateJoystick::multipleRead());
}

inline Joystick::Move XYReplacerJoystick::replace(const Joystick::Move move) {
	switch (move) {
		case Move::UP:
			return Move::RIGHT;
		case Move::DOWN:
			return Move::LEFT;
		case Move::RIGHT:
			return Move::UP;
		case Move::LEFT:
			return Move::DOWN;
		default:
			return move;
	}
}
