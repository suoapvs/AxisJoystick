#include "AxisJoystick.h"

AxisJoystick::AxisJoystick(
	const int SW_pin,
	const int VRx_pin,
	const int VRy_pin
) {
	pinMode(this->SW_pin = SW_pin, INPUT_PULLUP);
	pinMode(this->VRx_pin = VRx_pin, INPUT);
	pinMode(this->VRy_pin = VRy_pin, INPUT);
}

Joystick::Move AxisJoystick::singleRead() {
	const Move joystickMove = multipleRead();
	if (joystickMove != this->previousMove) {
		return this->previousMove = joystickMove;
	}
	return Move::NOT;
}

Joystick::Move AxisJoystick::multipleRead() {
	if (isPress()) {
		return Move::PRESS;
	} else if (isUp()) {
		return Move::UP;
	} else if (isDown()) {
		return Move::DOWN;
	} else if (isRight()) {
		return Move::RIGHT;
	} else if (isLeft()) {
		return Move::LEFT;
	}
	return Move::NOT;
}

boolean AxisJoystick::isPress() {
	return readSW() == JOYSTICK_BUTTON_PRESS_SIGNAL;
}

boolean AxisJoystick::isUp() {
	return readVRy() >= highRange();
}

boolean AxisJoystick::isDown() {
	return readVRy() <= lowRange();
}

boolean AxisJoystick::isRight() {
	return readVRx() >= highRange();
}

boolean AxisJoystick::isLeft() {
	return readVRx() <= lowRange();
}

int AxisJoystick::readVRx() {
	return analogRead(this->VRx_pin);
}

int AxisJoystick::readVRy() {
	return analogRead(this->VRy_pin);
}

int AxisJoystick::readSW() {
	return digitalRead(this->SW_pin);
}

int AxisJoystick::xAxis() {
	return readVRx();
}

int AxisJoystick::yAxis() {
	return readVRy();
}

void AxisJoystick::calibrate(const int low, const int high) {
	this->low = low;
	this->high = high;
}

void AxisJoystick::calibrate(
	const int low, const int high, const int divition
) {
	calibrate(low, high);
	this->divition = divition;
}

inline int AxisJoystick::lowRange() {
	return (this->low + this->divition);
}

inline int AxisJoystick::highRange() {
	return (this->high - this->divition);
}
