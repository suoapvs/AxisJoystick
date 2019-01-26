#include "YInverter.h"

YInverter::YInverter(Joystick* origin)
	: DelegateJoystick(origin) {
}

Joystick::Move YInverter::singleRead() {
	return invert(this->origin->singleRead());
}

Joystick::Move YInverter::multipleRead() {
	return invert(this->origin->multipleRead());
}

/**
	Inverts the input joystick Y-axis move.
	@return value of pressing the joystick:
		Move::UP - Y-axis is pressed down;
		Move::DOWN - Y-axis is pressed up;
		else the input move.
*/
Joystick::Move YInverter::invert(const Joystick::Move move) {
	if (move == Move::UP) {
		return Move::DOWN;
	} else if (move == Move::DOWN) {
		return Move::UP;
	}
	return move;
}

boolean YInverter::isUp() {
	return this->origin->isDown();
}

boolean YInverter::isDown() {
	return this->origin->isUp();
}
