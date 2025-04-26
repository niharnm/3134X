#include "vex.h"
#include <iostream>
using namespace vex;
competition Competition;

/*---------------------------------------------------------------------------*/
/*                             VEXcode Config                                */
/*                                                                           */
/*  Before you do anything else, start by configuring your motors and        */
/*  sensors. In VEXcode Pro V5, you can do this using the graphical          */
/*  configurer port icon at the top right. In the VSCode extension, you'll   */
/*  need to go to robot-config.cpp and robot-config.h and create the         */
/*  motors yourself by following the style shown. All motors must be         */
/*  properly reversed, meaning the drive should drive forward when all       */
/*  motors spin forward.                                                     */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*                             JAR-Template Config                           */
/*                                                                           */
/*  Where all the magic happens. Follow the instructions below to input      */
/*  all the physical constants and values for your robot. You should         */
/*  already have configured your motors.                                     */
/*---------------------------------------------------------------------------*/
motor LeftA = motor(PORT14, ratio6_1, true);
motor LeftB = motor(PORT19, ratio6_1, true);
motor LeftC = motor(PORT11, ratio6_1, true);
motor_group Lefts = motor_group(LeftA, LeftB,LeftC);

motor RightA = motor(PORT6, ratio6_1, false);
motor RightB = motor(PORT17, ratio6_1, false);
motor RightC = motor(PORT15, ratio6_1, false);
motor_group Rights = motor_group(RightA, RightB, RightC);

Drive chassis(

//Pick your drive setup from the list below:
//ZERO_TRACKER_NO_ODOM
//ZERO_TRACKER_ODOM
//TANK_ONE_FORWARD_ENCODER
//TANK_ONE_FORWARD_ROTATION
//TANK_ONE_SIDEWAYS_ENCODER
//TANK_ONE_SIDEWAYS_ROTATION
//TANK_TWO_ENCODER
//TANK_TWO_ROTATION
//HOLONOMIC_TWO_ENCODER
//HOLONOMIC_TWO_ROTATION
//
//Write it here:
ZERO_TRACKER_NO_ODOM,

//Add the names of your Drive motors into the motor groups below, separated by commas, i.e. motor_group(Motor1,Motor2,Motor3).
//You will input whatever motor names you chose when you configured your robot using the sidebar configurer, they don't have to be "Motor1" and "Motor2".

//Left Motors:
Lefts,

//Right Motors:
Rights,

//Specify the PORT NUMBER of your inertial sensor, in PORT format (i.e. "PORT1", not simply "1"):
PORT16,

//Input your wheel diameter. (4" omnis are actually closer to 4.125"):
3.25,

//External ratio, must be in decimal, in the format of input teeth/output teeth.
//If your motor has an 84-tooth gear and your wheel has a 60-tooth gear, this value will be 1.4.
//If the motor drives the wheel directly, this value is 1:
0.6,

//Gyro scale, this is what your gyro reads when you spin the robot 360 degrees.
//For most cases 360 will do fine here, but this scale factor can be very helpful when precision is necessary.
360,

/*---------------------------------------------------------------------------*/
/*                                  PAUSE!                                   */
/*                                                                           */
/*  The rest of the drive constructor is for robots using POSITION TRACKING. */
/*  If you are not using position tracking, leave the rest of the values as  */
/*  they are.                                                                */
/*---------------------------------------------------------------------------*/

//If you are using ZERO_TRACKER_ODOM, you ONLY need to adjust the FORWARD TRACKER CENTER DISTANCE.

//FOR HOLONOMIC DRIVES ONLY: Input your drive motors by position. This is only necessary for holonomic drives, otherwise this section can be left alone.
//LF:      //RF:    
PORT1,     -PORT2,

//LB:      //RB: 
PORT3,     -PORT4,

//If you are using position tracking, this is the Forward Tracker port (the tracker which runs parallel to the direction of the chassis).
//If this is a rotation sensor, enter it in "PORT1" format, inputting the port below.
//If this is an encoder, enter the port as an integer. Triport A will be a "1", Triport B will be a "2", etc.
3,

//Input the Forward Tracker diameter (reverse it to make the direction switch):
2.75,

//Input Forward Tracker center distance (a positive distance corresponds to a tracker on the right side of the robot, negative is left.)
//For a zero tracker tank drive with odom, put the positive distance from the center of the robot to the right side of the drive.
//This distance is in inches:
-2,

//Input the Sideways Tracker Port, following the same steps as the Forward Tracker Port:
1,

//Sideways tracker diameter (reverse to make the direction switch):
-2.75,

//Sideways tracker center distance (positive distance is behind the center of the robot, negative is in front):
5.5

);

int current_auton_selection = 0;
bool auto_started = false;

/**
 * Function before autonomous. It prints the current auton number on the screen
 * and tapping the screen cycles the selected auton by 1. Add anything else you
 * may need, like resetting pneumatic components. You can rename these autons to
 * be more descriptive, if you like.
 */

void pre_auton() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  default_constants();

  while(!auto_started){
    std::cout << armrot.position(degrees) << std::endl;
    Brain.Screen.clearScreen();
    Brain.Screen.printAt(5, 20, "JAR Template v1.2.0");
    Brain.Screen.printAt(5, 40, "Battery Percentage:");
    Brain.Screen.printAt(5, 60, "%d", Brain.Battery.capacity());
    Brain.Screen.printAt(5, 80, "Chassis Heading Reading:");
    Brain.Screen.printAt(5, 100, "%f", chassis.get_absolute_heading());
    Brain.Screen.printAt(5, 120, "Selected Auton:");
    switch(current_auton_selection){
      case 0:
        Brain.Screen.printAt(5, 140, "Red Negative");
        Controller1.Screen.setCursor(3,1);
        Controller1.Screen.print("Red Negative");
        break;
      case 1:
        Brain.Screen.printAt(5, 140, "Red Positive");
        Controller1.Screen.setCursor(3,1);
        Controller1.Screen.print("Red Positive");
        break;
      case 2:
        Brain.Screen.printAt(5, 140, "Blue Negative");
        Controller1.Screen.setCursor(3,1);
        Controller1.Screen.print("Blue Negative");
        break;
      case 3:
        Brain.Screen.printAt(5, 140, "Blue Positive");
        Controller1.Screen.setCursor(3,1);
        Controller1.Screen.print("Blue Positive");
        break;

    }
    if(Brain.Screen.pressing()){
      while(Brain.Screen.pressing()) {}
      current_auton_selection ++;
    } else if (current_auton_selection == 4){
      current_auton_selection = 0;
    }
    wait(10,msec);
  }
}

/**
 * Auton function, which runs the selected auton. Case 0 is the default,
 * and will run in the brain screen goes untouched during preauton. Replace
 * drive_test(), for example, with your own auton function you created in
 * autons.cpp and declared in autons.h.
 */

void autonomous(void) {

  auto_started = true;
  switch(current_auton_selection){ 
    case 0:
      rednegative();
      break;
    case 1:         
      redpositive();
      break;
    case 2:
      bluenegative();
      break;
    case 3:
      bluepositive();
      break;
    case 4:
      full_test();
      break;
    case 5:
      odom_test();
      break;
    case 6:
      tank_odom_test();
      break;
    case 7:
      holonomic_odom_test();
      break;
 }
 
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void ClampToggle(){
  if (mogoMount.value() == true){
    mogoMount.set(false);
  }
  else {
    mogoMount.set(true);
    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

 void FlagToggle(){
   if (Flag.value() == true){
     Flag.set(false);
   }
   else {
     Flag.set(true);
     wait(20, msec); // Sleep the task for a short amount of time to
                     // prevent wasted resources.
   }
}


const float kp = 1;
const float ki = 0.1;
const float kd = 2;
const float starti = 5;
const float settle_error = 1;   // Considered settled within 1 degree
const float settle_time = 500;  // 500ms to be considered settled
const float timeout = 2000;     // Give up after 5 seconds
const float update_period = 10;

// void ladybrown_move(float output) {
//     ladybrown.spin(output);
// }

enum LadybrownPositions {
    SET = 50,
    SCORE = 270,
    RESET = 0,
};

// Global Variable for MoveToAngle Task
float targetAngleGlobal;

bool isRunning = false;

void moveToAngle() {
    isRunning = true;
    // Get the current angle of the arm
   // Target angle in degrees
    float currentAngle = armrot.position(rotationUnits::deg);  // Get current angle from the rotational sensor

    // Initialize PID controller with the current error
    PID ladybrownPID(reduce_negative_180_to_180(targetAngleGlobal - currentAngle), kp, ki, kd, starti, settle_error, settle_time, timeout, update_period);

    // Loop until the PID controller settles
    while (!ladybrownPID.is_settled()) {
        // Calculate the current error
        float error = reduce_negative_180_to_180(targetAngleGlobal  - armrot.position(rotationUnits::deg));

        // Compute the output using the PID controller
        float output = ladybrownPID.compute(error);

        // Clamp the output to the maximum voltage to avoid overdriving the motor
        output = clamp(output, -12, 12);  // Assuming 12V is the maximum voltage


   
        // Move the motor with the computed output
        if (output > 0) {
            ladybrown.spin(directionType::rev, output, voltageUnits::volt);  // Move forward
        } else if (output < 0) {
            ladybrown.spin(directionType::fwd, -output, voltageUnits::volt);  // Move reverse
        }

        // Sleep for the update period to control the loop frequency
        wait(10,msec);
    }

    // Once settled, stop the motor and hold its position
    ladybrown.stop(brakeType::hold);

}

void startMoveToAngle(float angle) {
    targetAngleGlobal = angle;
    if (!isRunning) {
        vex::thread moveToAngleThread(moveToAngle);
        moveToAngleThread.detach();
    }
    isRunning = false;
}


void usercontrol(void) {
   ladybrown.spin(fwd,100,pct);
 wait(.5,sec);
 ladybrown.stop(hold);
 ladybrown.resetPosition();
 ladybrown.stop(hold);
  bool big = false;
  bool Flagtrueorfalse = false;

  // User control code here, inside the loop
  while (true) {
    chassis.control_arcade();
  
    intake1.setVelocity(100, pct);
    ladybrown.setVelocity(100, pct);

    if(Controller1.ButtonB.pressing()){
      Clamp.set(!big);
      big = !big;
      wait(200, msec);
    }

    if(Controller1.ButtonDown.pressing()){
      Flag.set(!Flagtrueorfalse);
      Flagtrueorfalse = !Flagtrueorfalse;
      wait(200, msec);
    }
    //  Flag.set(true);
    //}
    //else {
    //  Flag.set(false);
    //}

    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    //Replace this line with chassis.control_tank(); for tank drive 
    //or chassis.control_holonomic(); for holo drive.
    if (Controller1.ButtonR1.pressing()) {
        intake1.spin(forward);
        
      } else if (Controller1.ButtonR2.pressing()) {
      intake1.spin(reverse);
        
      } else {
        intake1.stop();
        // set the toggle so that we don't constantly tell the motor to stop when the buttons are released
        
      }
if (Controller1.ButtonL1.pressing()) {
        ladybrown.spin(forward);
        
      } else if (Controller1.ButtonL2.pressing()) {
        ladybrown.spin(reverse);
        
      } else {
       ladybrown.stop();
      }
  
      if (Controller1.ButtonA.pressing()){
        startMoveToAngle(3.7);
      }
      if(Controller1.ButtonY.pressing()){
        startMoveToAngle(480);
      }
      

  

      wait(20,msec);

    


  }
}


//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(bluenegWP);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
  
