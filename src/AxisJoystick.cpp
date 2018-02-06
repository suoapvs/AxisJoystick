/**
	The class implements a set of methods of the AxisJoystick.h 
	interface for working with a joystick controller.

	https://github.com/YuriiSalimov/AxisJoystick
	
	Created by Yurii Salimov, February, 2018.
	Released into the public domain.
*/
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

void AxisJoystick::init() {
	pinMode(this->SW_pin, INPUT_PULLUP);
	pinMode(this->VRx_pin, INPUT);
	pinMode(this->VRy_pin, INPUT);
}

/**
	Single reading of the joystick controller.
	If the joystick is clamped, the next 
	value of pressing - NOT.
	@return value of pressing the joystick:
		Move::PRESS - button is pressed;
		Move::UP - X axis is pressed up;
		Move::DOWN - X axis is pressed down;
		Move::RIGTH - Y axis is pressed right;
		Move::LEFT - Y axis is pressed left;
		Move::NOT - not pressed.
*/
AxisJoystick::Move AxisJoystick::singleRead() {
  Move move;
  const Move joystickMove = multipleRead();
  if (joystickMove != this->previousMove) {
    move = joystickMove;
    this->previousMove = joystickMove;
  } else {
    move = Move::NOT;
  }
  return move;
}

/**
	Multiple reading of the joystick controller.
	@return value of pressing the joystick:
		Move::PRESS - button is pressed;
		Move::UP - X axis is pressed up;
		Move::DOWN - X axis is pressed down;
		Move::RIGTH - Y axis is pressed right;
		Move::LEFT - Y axis is pressed left;
		Move::NOT - not pressed.
*/
AxisJoystick::Move AxisJoystick::multipleRead() {
	Move move;
	if (isPress()) {
		move = Move::PRESS;
	} else if (isUp()) {
		move = Move::UP;
	} else if (isDown()) {
		move = Move::DOWN;
	} else if (isRight()) {
		move = Move::RIGHT;
	} else if (isLeft()) {
		move = Move::LEFT;
	} else {
		move = Move::NOT;
	}
	return move;
}

boolean AxisJoystick::isPress() {
	return digitalRead(this->SW_pin) == JOYSTICK_BUTTON_PRESS_SIGNAL;
}

boolean AxisJoystick::isUp() {
	return xAxis() >= JOYSTICK_AXIS_HIGH_RANGE;
}

boolean AxisJoystick::isDown() {
	return xAxis() <= JOYSTICK_AXIS_LOW_RANGE;
}

boolean AxisJoystick::isRight() {
	return yAxis() >= JOYSTICK_AXIS_HIGH_RANGE;
}

boolean AxisJoystick::isLeft() {
	return yAxis() <= JOYSTICK_AXIS_LOW_RANGE;
}

int AxisJoystick::xAxis() {
	return analogRead(this->VRx_pin);
}
	
int AxisJoystick::yAxis() {
	return analogRead(this->VRy_pin);
}
