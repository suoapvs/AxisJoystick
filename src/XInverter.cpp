#include "XInverter.h"

XInverter::XInverter(const Joystick* joystick)
	: DelegateJoystick(joystick) {
}

Joystick::Move XInverter::singleRead() {
  return invert(this->joystick->singleRead());
}

Joystick::Move XInverter::multipleRead() {
  return invert(this->joystick->multipleRead());
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
	return this->joystick->isLeft();
}

boolean XInverter::isLeft() {
	return this->joystick->isRight();
}
