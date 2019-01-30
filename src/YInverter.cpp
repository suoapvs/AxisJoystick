#include "YInverter.h"

YInverter::YInverter(Joystick* origin)
	: DelegateJoystick(origin) {
}

Joystick::Move YInverter::singleRead() {
	return invert(DelegateJoystick::singleRead());
}

Joystick::Move YInverter::multipleRead() {
	return invert(DelegateJoystick::multipleRead());
}

Joystick::Move YInverter::invert(const Joystick::Move move) {
	if (move == Move::UP) {
		return Move::DOWN;
	} else if (move == Move::DOWN) {
		return Move::UP;
	}
	return move;
}

boolean YInverter::isUp() {
	return DelegateJoystick::isDown();
}

boolean YInverter::isDown() {
	return DelegateJoystick::isUp();
}
