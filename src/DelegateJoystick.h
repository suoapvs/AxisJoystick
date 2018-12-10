/**
	DelegateJoystick.h - abstract class-wrapper implements methods of
	the Joystick.h interface, delegating call methods to the input joystick.

	v.2.0:
	- created.

	https://github.com/YuriiSalimov/AxisJoystick

	Created by Yurii Salimov, December, 2018.
	Released into the public domain.
*/
#ifndef DELEGATE_JOYSTICK_H
#define DELEGATE_JOYSTICK_H

#include "Joystick.h"

// abstract class
class DelegateJoystick : public Joystick {

	protected:
		Joystick* joystick;

	protected:
		DelegateJoystick(const Joystick* joystick);

  public:
		virtual Move singleRead() override;

		virtual Move multipleRead() override;

		virtual boolean isPress() override;

		virtual boolean isUp() override;

		virtual boolean isDown() override;

		virtual boolean isRight() override;

		virtual boolean isLeft() override;

		virtual int xAxis() override;

		virtual int yAxis() override;

		int readVRx() override;

		int readVRy() override;

		int readSW() override;
};

#endif
