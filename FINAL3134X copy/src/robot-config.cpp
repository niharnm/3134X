#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen.
brain  Brain;

//The motor constructor takes motors as (port, ratio, reversed), so for example
//motor LeftFront = motor(PORT1, ratio6_1, false);

//Add your devices below, and don't forget to do the same in robot-config.h:
motor intake1 = motor(PORT2, ratio6_1, false);
controller Controller1 = controller(primary);
digital_out mogoMount = digital_out(Brain.ThreeWirePort.F);
inertial DrivetrainInertial = inertial(PORT16);
motor ladybrown = motor(PORT13, ratio18_1, true);
rotation armrot = rotation(PORT21,false);
digital_out Clamp = digital_out(Brain.ThreeWirePort.F);
digital_out Flag = digital_out(Brain.ThreeWirePort.G);


double angle = armrot.angle(degrees);

void vexcodeInit( void ) {
}

void LadyBrownUp(void) {
  ladybrown.spinToPosition(-1,rev);
  ladybrown.stop(hold);
}

 
