#include "DelegateJoystick.h"

DelegateJoystick::DelegateJoystick(const Joystick* origin) {
	this->origin = origin;
}

/**
	Destructor.
	On deleting deletes the original joystick.
*/
DelegateJoystick::~DelegateJoystick() {
	delete this->origin;
}

Joystick::Move DelegateJoystick::singleRead() {
	return this->origin->singleRead();
}

Joystick::Move DelegateJoystick::multipleRead() {
	return this->origin->multipleRead();
}

boolean DelegateJoystick::isPress() {
	return this->origin->isPress();
}

boolean DelegateJoystick::isUp() {
	return this->origin->isUp();
}

boolean DelegateJoystick::isDown() {
	return this->origin->isDown();
}

boolean DelegateJoystick::isRight() {
	return this->origin->isRight();
}

boolean DelegateJoystick::isLeft() {
	return this->origin->isLeft();
}

int DelegateJoystick::xAxis() {
	return this->origin->xAxis();
}

int DelegateJoystick::yAxis() {
	return this->origin->yAxis();
}

int DelegateJoystick::readVRx() {
	return this->origin->readVRx();
}

int DelegateJoystick::readVRy() {
	return this->origin->readVRy();
}

int DelegateJoystick::readSW() {
	return this->origin->readSW();
}
