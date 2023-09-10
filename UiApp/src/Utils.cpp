#include "Utils.h"

Utils::Utils()
{

}

Utils::~Utils()
{
    delete(frameData);
}

void Utils::StreamLoop(Autofocus::ImageAcquisition* img, cv::Mat* frame, UiEngine::Image* image)
{
    while(true)
    {
        img->CaptureImage(frame);
        // frameData = new unsigned char[frame->total() * frame->elemSize()];
        // std::memcpy(frameData, frame->data, frame->total() * frame->elemSize());
	    // image->ShowVideoFromImage(frameData, &frame->cols, &frame->rows);
    }
}

void Utils::Dummy()
{
    while(true)
    {
        std::cout << "Here" << std::endl;
    }
}

bool Utils::FocusAlgorithm(cv::Mat* frame, Autofocus::StepperMotor* motor)
{
    cv::Mat laplacian;
    cv::Laplacian(*frame, laplacian, CV_64F);
    cv::Scalar mean, stddev;
    cv::meanStdDev(laplacian, mean, stddev);
    double laplacianVar = stddev.val[0] * stddev.val[0];
	std::cout << laplacianVar << std::endl;
	
	if(laplacianVar < 30)
	{
		motor->RunMotor(0, 120, 2500);
	}
	else
	{
		if(previousLaplacianVar < laplacianVar)
		{
			previousLaplacianVar = laplacianVar;
			motor->RunMotor(0, 30, 2500);
		}
		else
		{
			motor->RunMotor(1, 30, 2500);
			highestRes = true;
		}
	}

    return highestRes;
}