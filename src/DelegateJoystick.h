/**
	DelegateJoystick.h - abstract class-wrapper implements methods of
	the Joystick.h interface, delegating call methods to the input joystick.

	v.2.0:
	- created.

	v.2.0.1
	- added destructor.

	v.2.1.0
	- added calibration methods for joystick axes.

	https://github.com/YuriiSalimov/AxisJoystick

	Created by Yurii Salimov, December, 2018.
	Released into the public domain.
*/
#ifndef DELEGATE_JOYSTICK_H
#define DELEGATE_JOYSTICK_H

#include "Joystick.h"

class DelegateJoystick : public Joystick {

	private:
		Joystick* origin;

	protected:
		/**
			Constructor

			@param origin - the origin joystick (not NULL)
		*/
		DelegateJoystick(Joystick* origin);

	public:
		/**
			Destructor.
			On deleting deletes the original joystick.
		*/
		~DelegateJoystick();

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

		void calibrate(int low, int high) override;

		void calibrate(int adcMin, int adcMax, int deviation) override;
};

#endif
