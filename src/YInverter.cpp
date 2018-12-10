#include "YInverter.h"

YInverter::YInverter(const Joystick* joystick)
	: DelegateJoystick(joystick) {
}

Joystick::Move YInverter::singleRead() {
  return invert(this->joystick->singleRead());
}

Joystick::Move YInverter::multipleRead() {
  return invert(this->joystick->multipleRead());
}

Joystick::Move YInverter::invert(const Joystick::Move move) {
  if (move == Move::LEFT) {
		return Move::RIGHT;
	} else if (move == Move::RIGHT) {
		return Move::LEFT;
	}
	return move;
}

boolean YInverter::isRight() {
	return this->joystick->isLeft();
}

boolean YInverter::isLeft() {
	return this->joystick->isRight();
}
