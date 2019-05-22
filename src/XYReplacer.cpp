#include "XYReplacer.h"

XYReplacer::XYReplacer(Joystick* origin)
	: DelegateJoystick(origin) {
}

Joystick::Move XYReplacer::singleRead() {
	return replace(DelegateJoystick::singleRead());
}

Joystick::Move XYReplacer::multipleRead() {
	return replace(DelegateJoystick::multipleRead());
}

Joystick::Move XYReplacer::replace(const Joystick::Move move) {
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

boolean XYReplacer::isUp() {
	return DelegateJoystick::isRight();
}

boolean XYReplacer::isDown() {
	return DelegateJoystick::isLeft();
}

boolean XYReplacer::isRight() {
	return DelegateJoystick::isUp();
}

boolean XYReplacer::isLeft() {
	return DelegateJoystick::isDown();
}

int XYReplacer::xAxis() {
	return DelegateJoystick::yAxis();
}

int XYReplacer::yAxis() {
	return DelegateJoystick::xAxis();
}
