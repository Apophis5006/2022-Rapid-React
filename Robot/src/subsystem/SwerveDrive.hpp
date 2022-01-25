
/*
An abstract class for interacting with the TalonFX/TalonSRX motor controllers
*/
class SwerveDrive {
protected:
    //Variables
    double* baseState; //the base state of the drive
    double* targetState; //the target state of the drive
    
    bool enabled = false; //if the swerve drive is enabled
    
    TalonFX steerMotor {{0}}; //the motor for steering the SwerveDrive
    TalonFX driveMotor {{1}}; //the motor for driving the SwerveDrive

public:
    //Constructors
    /*
    Creates a SwerveDrive object from the steer motor id and the drive motor id

    @param steerMotorId the port id of the motor controlling the SwerveDrive steering (direction)
    @param driveMotorId the port id of the motor controlling the SwerveDrive driving (speed)
    */
    SwerveDrive(int steerMotorId, int driveMotorId) : steerMotor{{steerMotorId}}, driveMotor{{driveMotorId}} {
        double originState[2] = {0, 0};
        double setState[2] = {0, 0};
        
        baseState = originState;
        targetState = setState;
    }
    /*
    Creates a SwerveDrive object from the steer motor id, the drive motor id, and the base rotation (steer)

    @param steerMotorId the port id of the motor controlling the SwerveDrive steering (direction)
    @param driveMotorId the port id of the motor controlling the SwerveDrive driving (speed)
    @param originState the base state the drive defaults to
    */
    SwerveDrive(int steerMotorId, int driveMotorId, double originState[2]) : steerMotor{{steerMotorId}}, driveMotor{{driveMotorId}} {
        double setState[2] = {0, 0};
        
        baseState = originState;
        targetState = setState;
    }
    /*
    Creates a SwerveDrive object from the steer motor id, the drive motor id, and the base rotation (steer)

    @param steerMotorId the port id of the motor controlling the SwerveDrive steering (direction)
    @param driveMotorId the port id of the motor controlling the SwerveDrive driving (speed)
    @param originState the base state the drive defaults to
    @param setState the target state the drive runs at relative to the originState
    */
    SwerveDrive(int steerMotorId, int driveMotorId, double originState[2], double setState[2]) : steerMotor{{steerMotorId}}, driveMotor{{driveMotorId}} {
        baseState = originState;
        targetState = setState;
    }

    //Methods
    /*
    Sets the swerve drive rotation (in radians) and speed (in fps)

    @param setState
        [1]: the rotation (in radians) to set the drive at
        - [2]: the speed (in fps) to set the drive at
    */
    void Set(double setState[2]) {
        this->targetState = setState;
    }
    /*
    Sets the swerve drive rotation (in radians) and speed (in fps)

    @param setState
        [1]: the rotation (in radians) to set the drive at
        - [2]: the speed (in fps) to set the drive at
    @originState the base state the drive defaults to
    */
    void Set(double setState[2], double originState[2]) {
        this->targetState = setState;
        this->baseState = originState;
    }
    /*
    Sets the swerve drive rotation (in radians) and speed (in fps)

    @param rotation the rotation (in radians) to set the drive at
    @param speed the speed (in fps) to set the drive at
    */
    void Set(double rotation, double speed) {
        this->targetState[0] = rotation;
        this->targetState[1] = speed;
    }

    /*
    Returns if the swerve drive is enabled

    @return boolean value indicating if the drive is enabled
    */
    bool IsEnabled() {
        return this->enabled;
    }

    /*
    Returns the absolute state of the swerve drive (originState + setState)

    @return the absolute rotation (in radians) and speed (in fps) of the swerve drive target state
    */
    tuple<double, double> GetAbsoluteTargetState() {
        return make_tuple(this->baseState[0] + this->targetState[0], this->baseState[1] + this->targetState[1]);
    }
};