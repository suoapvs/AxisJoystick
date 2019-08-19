/**
	Created by Yurii Salimov, December, 2018.
	Released into the public domain.
*/
#include "DelegateJoystick.h"

DelegateJoystick::DelegateJoystick(Joystick* origin) {
	this->origin = origin;
}

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

void DelegateJoystick::calibrate(const int low, const int high) {
	this->origin->calibrate(low, high);
}

void DelegateJoystick::calibrate(
	const int adcMin, const int adcMax, const int deviation
) {
	this->origin->calibrate(adcMin, adcMax, deviation);
}
