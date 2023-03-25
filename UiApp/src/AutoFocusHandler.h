#include "AutoFocus.h"

class AutoFocusHandler
{
public:
	AutoFocusHandler()
	{
		Autofocus::StepperPins motor1Pins;
		motor1Pins.step = 2;
		motor1Pins.en = 1;
		motor1Pins.dir = 0;
		motor1Pins.ms1 = 0;
		motor1Pins.ms1 = 0;

		motor1 = new Autofocus::StepperMotor(motor1Pins);
		img = new Autofocus::ImageAcquisition();
	}

	~AutoFocusHandler()
	{
		delete motor1;
		delete img;
		delete frame;
	}

	Autofocus::StepperMotor* GetMotor1()
	{
		return motor1;
	}

	void RunMotor(Autofocus::StepperMotor* motor, int dir, int angle, int speed)
	{
		motor->RunMotor(dir, angle, speed);
	}

private:
	Autofocus::StepperMotor* motor1;
	Autofocus::ImageAcquisition* img;
	cv::Mat* frame;
};