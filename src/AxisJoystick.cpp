#include "AxisJoystick.h"

AxisJoystick::AxisJoystick(
	const int SW_pin,
	const int VRx_pin,
	const int VRy_pin
) {
	this->SW_pin = SW_pin;
	this->VRx_pin = VRx_pin;
	this->VRy_pin = VRy_pin;
	init();
}

inline void AxisJoystick::init() {
	pinMode(this->SW_pin, INPUT_PULLUP);
	pinMode(this->VRx_pin, INPUT);
	pinMode(this->VRy_pin, INPUT);
}

Joystick::Move AxisJoystick::singleRead() {
	const Move joystickMove = multipleRead();
	if (joystickMove != this->previousMove) {
		this->previousMove = joystickMove;
		return joystickMove;
	}
	return Move::NOT;
}

/**
	Multiple reading of the joystick controller.
	@return value of pressing the joystick:
		Move::PRESS - button is pressed;
		Move::UP - Y-axis is pressed up;
		Move::DOWN - Y-axis is pressed down;
		Move::RIGTH - X-axis is pressed right;
		Move::LEFT - X-axis is pressed left;
		Move::NOT - not pressed.
*/
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
	return readVRy() >= JOYSTICK_AXIS_HIGH_RANGE;
}

boolean AxisJoystick::isDown() {
	return readVRy() <= JOYSTICK_AXIS_LOW_RANGE;
}

boolean AxisJoystick::isRight() {
	return readVRx() >= JOYSTICK_AXIS_HIGH_RANGE;
}

boolean AxisJoystick::isLeft() {
	return readVRx() <= JOYSTICK_AXIS_LOW_RANGE;
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
