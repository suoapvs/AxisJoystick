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
		Move::UP - X axis is pressed down;
		Move::DOWN - X axis is pressed up;
		else the input move.
*/
Joystick::Move XInverter::invert(const Joystick::Move move) {
  if (move == Move::UP) {
		return Move::DOWN;
	} else if (move == Move::DOWN) {
		return Move::UP;
	}
	return move;
}

boolean XInverter::isUp() {
	return this->joystick->isDown();
}

boolean XInverter::isDown() {
	return this->joystick->isUp();
}
