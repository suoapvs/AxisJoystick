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
	switch (move) {
		case Move::UP:
			return Move::DOWN;
		case Move::DOWN:
			return Move::UP;
		default:
			return move;
	}
}

boolean YInverter::isUp() {
	return DelegateJoystick::isDown();
}

boolean YInverter::isDown() {
	return DelegateJoystick::isUp();
}
