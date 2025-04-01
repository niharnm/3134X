using namespace vex;

extern brain Brain;

//To set up a motor called LeftFront here, you'd use
//extern motor LeftFront;

//Add your devices below, and don't forget to do the same in robot-config.cpp:
extern motor intake1;
extern controller Controller1;
extern digital_out mogoMount;
extern inertial DrivetrainInertial;
extern motor ladybrown;
extern rotation armrot;
extern digital_out Clamp;
extern digital_out Flag;

void LadyBrownMove (void);
void LadyBrownUp (void);
void  vexcodeInit( void );
