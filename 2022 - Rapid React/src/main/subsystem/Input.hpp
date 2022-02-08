#include <../class/input/Joystick.hpp>

class Input {
protected:
    Joystick driveStick; //the joystick that controls the driving
    Joystick steerStick; //the joystick that controls the steering

public:
    Input(int drivePort, int steerPort) : driveStick(drivePort),steerStick(steerPort) {}

    //@returns returns an array (double[4]) containing the drive velocity, steer angle, and steer pivot offset
    double* GetInput() {
        double* drivePosition = this->driveStick.GetPosition();
        double* steerPosition = this->steerStick.GetPosition();
        
        double stickInput[4] = {drivePosition[0],drivePosition[1],steerPosition[0],steerPosition[1]};
        return stickInput;
    }
};