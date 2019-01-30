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
	if (move == Move::UP) {
		return Move::RIGHT;
	} else if (move == Move::DOWN) {
		return Move::LEFT;
	} else if (move == Move::RIGHT) {
		return Move::UP;
	} else if (move == Move::LEFT) {
		return Move::DOWN;
	}
	return move;
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
