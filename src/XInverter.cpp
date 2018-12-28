#include "XInverter.h"

XInverter::XInverter(const Joystick* origin)
	: DelegateJoystick(origin) {
}

Joystick::Move XInverter::singleRead() {
	return invert(this->origin->singleRead());
}

Joystick::Move XInverter::multipleRead() {
	return invert(this->origin->multipleRead());
}

/**
	Inverts the input joystick X-axis move.
	@return value of pressing the joystick:
		Move::RIGHT - X-axis is pressed left;
		Move::LEFT - X-axis is pressed right;
		else the input move.
*/
Joystick::Move XInverter::invert(const Joystick::Move move) {
	if (move == Move::LEFT) {
		return Move::RIGHT;
	} else if (move == Move::RIGHT) {
		return Move::LEFT;
	}
	return move;
}

boolean XInverter::isRight() {
	return this->origin->isLeft();
}

boolean XInverter::isLeft() {
	return this->origin->isRight();
}
