#include "XYReplacer.h"

XYReplacer::XYReplacer(const Joystick* joystick)
	: DelegateJoystick(joystick) {
}

Joystick::Move XYReplacer::singleRead() {
  return replace(this->joystick->singleRead());
}

Joystick::Move XYReplacer::multipleRead() {
  return replace(this->joystick->multipleRead());
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
	return this->joystick->isRight();
}

boolean XYReplacer::isDown() {
	return this->joystick->isLeft();
}

boolean XYReplacer::isRight() {
	return this->joystick->isUp();
}

boolean XYReplacer::isLeft() {
	return this->joystick->isDown();
}

int XYReplacer::xAxis() {
	return this->joystick->yAxis();
}

int XYReplacer::yAxis() {
	return this->joystick->xAxis();
}
