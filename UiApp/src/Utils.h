#include "UiEngine.h"
#include "AutoFocus.h"

class Utils
{
public:
    Utils();
    ~Utils();

    void Dummy();
    void StreamLoop(Autofocus::ImageAcquisition* img, cv::Mat* frame, UiEngine::Image* image);
    bool FocusAlgorithm(cv::Mat* frame, Autofocus::StepperMotor* motor);
private:
    unsigned char* frameData;
    bool highestRes = false;
    double previousLaplacianVar = 0.0;
};