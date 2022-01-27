#include "../subsystem/input.hpp"


class joystick: public Input{
    protected:
        frc::Joystick device{0};     

        enum class inputs{Trigger,X,Y,Z,Button,Twist,Throttle,Channel};

    public:
    joystick(int port){
        device = frc::Joystick(port);
    }

    double Get(inputs port){
       //find actual values of buttons later
       switch(port){
           case inputs::X: return device.GetX(); break;
           case inputs::Y: return device.GetY(); break;
           case inputs::Z: return device.GetZ(); break;
           case inputs::Twist: return device.GetTwist();
           case inputs::Throttle: return device.GetThrottle(); break;
           case inputs::Trigger: return device.GetTrigger(); break;
           default: return -1; break;
       }
    }
    double Get(inputs port, inputs Channel){
        switch(Channel){
            case inputs::X: return device.GetXChannel(); break;
            case inputs::Y: return device.GetYChannel(); break;
            case inputs::Z: return device.GetZChannel(); break;
            case inputs::Throttle: return device.GetThrottleChannel(); break;
            case inputs::Twist: return device.GetTwistChannel(); break;
            default: return -1.0; break;
        }
    }
    double Get(inputs port, int numButton){
        return device.GetRawButton(numButton);
    }



};