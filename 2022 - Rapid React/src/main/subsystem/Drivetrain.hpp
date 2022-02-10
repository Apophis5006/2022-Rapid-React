#include <../class/drivetrain/SwerveDrive.hpp>

class Drivetrain {
private:
    enum class DriveMode {FieldCentric,RobotCentric,FrontSteer}; //The drive mode of the robot

    //Do the math on each wheel to find the new angle and speed required
    void Calc4WheelTurn() {
        /*double A,B,C,D,R,temp;
        R = SW_L+SW_W;

        A = SWRVX-SWRVZ*(SW_L/R);
        B = SWRVX+SWRVZ*(SW_L/R);
        C = SWRVY-SWRVZ*(SW_W/R);
        D = SWRVY+SWRVZ*(SW_W/R);
        
        ModDir[FR] = atan2(B,C)*180/PI;
        ModSpd[FR]=  sqrt(pow(B,2)+pow(C,2));

        ModDir[FL] = atan2(B,D)*180/PI;
        ModSpd[FL]=  sqrt(pow(B,2)+pow(D,2));

        ModDir[RL] = atan2(A,D)*180/PI;
        ModSpd[RL]=  sqrt(pow(A,2)+pow(D,2));

        ModDir[RR] = atan2(A,C)*180/PI;
        ModSpd[RR]=  sqrt(pow(A,2)+pow(C,2));

        //Evenly reduces ModSpd members so that the highest value will always be 1
        temp = 0;
        for (int i=0;i<4;i++) {
            if(ModSpd[i]>temp) {
                temp=ModSpd[i];
            }
        }
        if (temp>1.0) {
            for(int i=0;i<4;i++) {
                ModSpd[i]/=temp;
            }
        }
        */
    }

protected:
    SwerveDrive FLSwerve; //the front-left swervedrive
    SwerveDrive FRSwerve; //the front-right swervedrive
    SwerveDrive BLSwerve; //the back-left swervedrive
    SwerveDrive BRSwerve; //the back-right swervedrive

    DriveMode driveMode = DriveMode::FieldCentric; //the drive mode of the robot
    bool enabled = true; //the value indicating if the drivetrain is enabled

public:
    //Constructors
    Drivetrain(int FL[2], int FR[2], int BL[2], int BR[2]) : FLSwerve(FL[0],FL[1]),FRSwerve(FR[0],FR[1]),BLSwerve(BL[0],BL[1]),BRSwerve(BR[0],BR[1]) {}

    //Members
    //enum DriveMode; //The publicly accessible member for the drivemode
    
    //Methods
    /*
    Updates the states of the swerve drives
    */
    void Update() {
        
    }

    void Set(double state[2]){
        FRSwerve.Set(state);
        FLSwerve.Set(state);
        BRSwerve.Set(state);
        BRSwerve.Set(state);
    }
    void Set(double stateFR[2],double stateFL[2],double stateBR[2],double stateBL[2]){
        FRSwerve.Set(stateFR);
        FLSwerve.Set(stateFL);
        BRSwerve.Set(stateBR);
        BRSwerve.Set(stateBL);
    }

    /*
    Sets the drivetrain to enabled or disabled

    @param enabled sets the drivetrain to enabled if true
    */
    void SetEnabled(bool enabled = false) {
        this->FLSwerve.SetEnabled(enabled);
        this->FRSwerve.SetEnabled(enabled);
        this->BLSwerve.SetEnabled(enabled);
        this->BLSwerve.SetEnabled(enabled);
        this->enabled = enabled;
    }
    //@returns boolean value indicating if the drivetrain is enabled
    bool IsEnabled() {
        return this->enabled;
    }

    /*
    Sets the current drivemode

    @param driveMode the mode that controls how the robot is driven
    */
    void SetDriveMode(DriveMode driveMode) {
        this->driveMode = driveMode;
    }
    //@returns the current DriveMode the robot is in
    DriveMode GetDriveMode() const {return this->driveMode;}
};
