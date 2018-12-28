#include "XYReplacer.h"

XYReplacer::XYReplacer(const Joystick* origin)
	: DelegateJoystick(origin) {
}

Joystick::Move XYReplacer::singleRead() {
	return replace(this->origin->singleRead());
}

Joystick::Move XYReplacer::multipleRead() {
	return replace(this->origin->multipleRead());
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
	return this->origin->isRight();
}

boolean XYReplacer::isDown() {
	return this->origin->isLeft();
}

boolean XYReplacer::isRight() {
	return this->origin->isUp();
}

boolean XYReplacer::isLeft() {
	return this->origin->isDown();
}

int XYReplacer::xAxis() {
	return this->origin->yAxis();
}

int XYReplacer::yAxis() {
	return this->origin->xAxis();
}
