#include "DelegateJoystick.h"

DelegateJoystick::DelegateJoystick(const Joystick* joystick) {
	this->joystick = joystick;
}

Joystick::Move DelegateJoystick::singleRead() {
  return this->joystick->singleRead();
}

Joystick::Move DelegateJoystick::multipleRead() {
  return this->joystick->multipleRead();
}

boolean DelegateJoystick::isPress() {
	return this->joystick->isPress();
}

boolean DelegateJoystick::isUp() {
	return this->joystick->isUp();
}

boolean DelegateJoystick::isDown() {
	return this->joystick->isDown();
}

boolean DelegateJoystick::isRight() {
	return this->joystick->isRight();
}

boolean DelegateJoystick::isLeft() {
	return this->joystick->isLeft();
}

int DelegateJoystick::xAxis() {
	return this->joystick->xAxis();
}

int DelegateJoystick::yAxis() {
		return this->joystick->yAxis();
}

int DelegateJoystick::readVRx() {
	return this->joystick->readVRx();
}

int DelegateJoystick::readVRy() {
	return this->joystick->readVRy();
}

int DelegateJoystick::readSW() {
	return this->joystick->readSW();
}
