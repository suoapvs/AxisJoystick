#include "YInverterJoystick.h"

YInverterJoystick::YInverterJoystick(Joystick* origin)
	: DelegateJoystick(origin) {
}

boolean YInverterJoystick::isUp() {
	return DelegateJoystick::isDown();
}

boolean YInverterJoystick::isDown() {
	return DelegateJoystick::isUp();
}

Joystick::Move YInverterJoystick::singleRead() {
	return invert(DelegateJoystick::singleRead());
}

Joystick::Move YInverterJoystick::multipleRead() {
	return invert(DelegateJoystick::multipleRead());
}

Joystick::Move YInverterJoystick::invert(const Joystick::Move move) {
	switch (move) {
		case Move::UP:
			return Move::DOWN;
		case Move::DOWN:
			return Move::UP;
		default:
			return move;
	}
}
