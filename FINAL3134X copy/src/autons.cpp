#include "vex.h"



#pragma region EXAMP
/**
 * Resets the constants for auton movement.
 * Modify these to change the default behavior of functions like
 * drive_distance(). For explanations of the difference between
 * drive, heading, turning, and swinging, as well as the PID and
 * exit conditions, check the docs.
 */

void default_constants(){
  // Each constant set is in the form of (maxVoltage, kP, kI, kD, startI).
  chassis.set_drive_constants(10, 1.5, 0, 10, 0);
  chassis.set_heading_constants(6, .4, 0, 1, 0);
  chassis.set_turn_constants(12, .25, .03, 2, 15);
  chassis.set_swing_constants(12, .3, .001, 2, 15);

  // Each exit condition set is in the form of (settle_error, settle_time, timeout).
  chassis.set_drive_exit_conditions(1.5, 50, 2000);
  chassis.set_turn_exit_conditions(1, 50, 800);
  chassis.set_swing_exit_conditions(1, 50, 800);
}

/**
 * Sets constants to be more effective for odom movements.
 * For functions like drive_to_point(), it's often better to have
 * a slower max_voltage and greater settle_error than you would otherwise.
 */

void odom_constants(){
  default_constants();
  chassis.heading_max_voltage = 10;
  chassis.drive_max_voltage = 8;
  chassis.drive_settle_error = 3;
  chassis.boomerang_lead = .5;
  chassis.drive_min_voltage = 0;
}

/**
 * The expected behavior is to return to the start position.
 */

void drive_test(){
chassis.turn_to_angle(180);
}

/**
 * The expected behavior is to return to the start angle, after making a complete turn.
 */

void turn_test(){
  chassis.turn_to_angle(90);
  chassis.turn_to_angle(180);
  chassis.turn_to_angle(270);
  chassis.turn_to_angle(360);
  chassis.turn_to_angle(0);
}

/**
 * Should swing in a fun S shape.
 */

void swing_test(){
  chassis.left_swing_to_angle(90);
  chassis.right_swing_to_angle(0);
}

/**
 * A little of this, a little of that; it should end roughly where it started.
 */

void full_test(){
  chassis.drive_distance(24);
  chassis.turn_to_angle(-45);
  chassis.drive_distance(-36);
  chassis.right_swing_to_angle(-90);
  chassis.drive_distance(24);
  chassis.turn_to_angle(0);
}

/**
 * Doesn't drive the robot, but just prints coordinates to the Brain screen 
 * so you can check if they are accurate to life. Push the robot around and
 * see if the coordinates increase like you'd expect.
 */

void odom_test(){
  chassis.set_coordinates(0, 0, 0);
  while(1){
    Brain.Screen.clearScreen();
    Brain.Screen.printAt(5,20, "X: %f", chassis.get_X_position());
    Brain.Screen.printAt(5,40, "Y: %f", chassis.get_Y_position());
    Brain.Screen.printAt(5,60, "Heading: %f", chassis.get_absolute_heading());
    Brain.Screen.printAt(5,80, "ForwardTracker: %f", chassis.get_ForwardTracker_position());
    Brain.Screen.printAt(5,100, "SidewaysTracker: %f", chassis.get_SidewaysTracker_position());
    
  }
}

/**
 * Should end in the same place it began, but the second movement
 * will be curved while the first is straight.
 */

void tank_odom_test(){
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.turn_to_point(24, 24);
  chassis.drive_to_point(24,24);
  chassis.drive_to_point(0,0);
  chassis.turn_to_angle(0);
}

/**
 * Drives in a square while making a full turn in the process. Should
 * end where it started.
 */

void holonomic_odom_test(){
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.holonomic_drive_to_pose(0, 18, 90);
  chassis.holonomic_drive_to_pose(18, 0, 180);
  chassis.holonomic_drive_to_pose(0, 18, 270);
  chassis.holonomic_drive_to_pose(0, 0, 0);
}


#pragma endregion

void bluenegative(){  
  ladybrown.resetPosition();
  chassis.drive_max_voltage = 10;
  intake1.setVelocity(100, pct);
  ladybrown.setVelocity(100, pct);
  chassis.set_heading(90);
  Clamp.set(false);
  chassis.drive_distance(-5);
  
  chassis.right_swing_to_angle(120);
  // chassis.drive_distance(-5);
  
  // chassis.turn_to_angle(120);
  chassis.drive_distance(-19);
  chassis.drive_max_voltage = 6;
  chassis.drive_distance(-6);
  Clamp.set(true);
  
  chassis.drive_max_voltage = 6;
  
  chassis.turn_to_angle(360);
  intake1.spin(forward);
  chassis.drive_max_voltage = 8;
  wait(200,msec);
  chassis.drive_distance(20);
  chassis.turn_to_angle(270);
  chassis.drive_distance(10);
  chassis.turn_to_angle(180);
  intake1.spin(forward);
  chassis.drive_distance(7);
  wait(700,msec);
  chassis.drive_distance(8);
 // chassis.turn_to_angle(270);
  //chassis.drive_distance(4);
  //chassis.turn_to_angle(90);
  //chassis.drive_distance(2);
  //chassis.turn_to_angle(270);
 // chassis.drive_distance(8);
  //ladybrown.spin(reverse,100,pct);


  //wait(400,msec);


  //chassis.drive_max_voltage = 8;
  //chassis.drive_distance(27);
  //ladybrown.spin(reverse,100,pct);
  //wait(200,msec); 

//here
     // ladybrown.spin(reverse,100,pct);
     // wait(300, msec);
     // ladybrown.spin(forward,100,pct);
     // chassis.turn_to_angle(4);
     //chassis.turn_to_angle(18);
      //chassis.drive_distance(10);
      //chassis.turn_to_angle(270); 
      
      //here

      // chassis.drive_distance(13);
            //   chassis.drive_max_voltage = 8;

     //  chassis.drive_distance(-15);
     //  chassis.left_swing_to_angle(90);
      // chassis.drive_distance(15);
     //  chassis.turn_to_angle(180);
     //  chassis.drive_distance(30);
      // intake1.stop();
       //               chassis.drive_max_voltage = 4;
      //                     chassis.drive_distance(10);






   //intake1.setVelocity(200,pct);
   //chassis.set_heading(180);
  // ladybrown.setVelocity(100,pct);

   //ladybrown.spin(reverse,100,pct);


 //chassis.drive_distance(16);
  // chassis.turn_to_angle(270);
  // ladybrown.spinToPosition(6.5,rev);
  // chassis.drive_distance(-5);
  // ladybrown.spin(reverse,100,pct);
  // chassis.turn_to_angle(225);
 // Clamp.set(true);
  // chassis.drive_distance(-23.3);
  // chassis.drive_distance(-2);
  // chassis.drive_distance(-6);
  // Clamp.set(false);
  // intake1.spin(fwd,100,pct);
  // chassis.turn_to_angle(0);
  // chassis.drive_distance(33);
  // chassis.drive_distance(-38);
  // chassis.turn_to_angle(37);
  // chassis.drive_distance(25);
  // chassis.turn_to_angle(20);
 // chassis.drive_distance(12);
  
}
void redpositive(){
ladybrown.resetPosition();
chassis.drive_max_voltage = 10;
intake1.setVelocity(100, pct);
ladybrown.setVelocity(100, pct);
chassis.set_heading(-90);
Clamp.set(false);
chassis.drive_distance(-5);

chassis.left_swing_to_angle(-120);
// chassis.drive_distance(-5);

// chassis.turn_to_angle(120);
chassis.drive_distance(-19);
chassis.drive_max_voltage = 4;
chassis.drive_distance(-7);
Clamp.set(true);

chassis.drive_max_voltage = 6;

chassis.turn_to_angle(-180);
intake1.spin(forward);
chassis.drive_distance(22);
chassis.drive_max_voltage = 8;
chassis.drive_max_voltage = 4;
chassis.drive_distance(-11);
chassis.turn_to_angle(0);
chassis.drive_max_voltage = 5;
chassis.drive_distance(22.25);
ladybrown.spin(reverse,100,pct);
wait(200,msec); 
ladybrown.stop(coast);
intake1.stop();

//chassis.drive_max_voltage = 2;
//chassis.drive_distance(10);
    //chassis.drive_timeout = 1200;
    //intake1.setVelocity(100, pct);
    //Clamp.set(true);
    //chassis.drive_distance(-20, 0);
    //chassis.drive_max_voltage = 9;
    //chassis.turn_to_angle(-30);
    //chassis.drive_distance(-9.5, -30);
    //chassis.drive_max_voltage = 12;
    //wait(35, msec);
    //Clamp.set(false);
    //wait(35, msec);
    //intake1.spin(forward);
    //wait(110, msec);
   // chassis.turn_to_angle(-100);
   // chassis.drive_distance(19, -100);
   // wait(135, msec);
   //chassis.turn_to_angle(61.5);
   // chassis.drive_max_voltage = 9;
   /** chassis.drive_distance(38, 61.5);
    chassis.drive_max_voltage = 12;
    wait(320, msec);/**/
    /*intake1.stop();
    /*chassis.drive_distance(-10,61.5);
    /*intake1.stop();
    Clamp.set(true);
    chassis.drive_distance(3, 61.5);
    chassis.turn_to_angle(218);
    chassis.drive_distance(-27, 220); 
    chassis.drive_distance(9.5, 220);
    wait(45, msec);
    chassis.turn_to_angle(176);
    Clamp.set(false);
    chassis.drive_distance(-14, 176);
    intake1.spin(reverse);
    intake1.spin(reverse);
    wait(1.8, sec);
    chassis.drive_max_voltage = 12;
    chassis.drive_distance(30,176); */
}

void rednegative(){
  ladybrown.resetPosition();
chassis.drive_max_voltage = 10;
intake1.setVelocity(100, pct);
ladybrown.setVelocity(100, pct);
chassis.set_heading(90);
Clamp.set(false);
chassis.drive_distance(-5);

chassis.right_swing_to_angle(120);
// chassis.drive_distance(-5);

// chassis.turn_to_angle(120);
chassis.drive_distance(-19);
chassis.drive_max_voltage = 6;
chassis.drive_distance(-6);
Clamp.set(true);

chassis.drive_max_voltage = 6;

chassis.turn_to_angle(360);
intake1.spin(forward);
chassis.drive_max_voltage = 8;
chassis.drive_distance(20);
chassis.turn_to_angle(180);
chassis.drive_max_voltage = 8;
chassis.drive_distance(27);
ladybrown.spin(reverse,100,pct);
wait(200,msec); 
ladybrown.stop(coast);
intake1.stop();

 // intake1.setVelocity(100, pct);
 // Clamp.set(false);
  //chassis.set_heading(-90);
  //chassis.turn_to_angle(-65);
  //chassis.drive_max_voltage = 8;
  //chassis.drive_distance(-25);
    // chassis.drive_max_voltage = 2;
      // chassis.drive_distance(-7);
      // Clamp.set(true);
             //wait(200, msec);

      // chassis.turn_to_angle(-304);
      // intake1.spin(forward);
       //  chassis.drive_max_voltage = 8;

       //chassis.drive_distance(13.25);
       //chassis.turn_to_angle(4);
       //chassis.right_swing_to_angle(4);
       //        chassis.drive_max_voltage = 4;

       //chassis.drive_distance(13);
        //       chassis.drive_max_voltage = 8;



}

void bluepositive(){
// chassis.drive_max_voltage = 12;
//     chassis.drive_timeout = 1200;
//     intake1.setVelocity(100, pct);
//     chassis.drive_distance(-15, 0);
//     Clamp.set(true);
//     Clamp.set(true);
//     intake1.spin(forward);
//     chassis.drive_distance(16.5, 0);
//     intake1.stop();
//     chassis.turn_to_angle(90);
//     intake1.spin(forward);
//     chassis.drive_distance(25,  0);
//     chassis.turn_to_angle(225);
//     chassis.drive_distance(10, 0);
//     intake1.spin(forward);
//     chassis.drive_distance(15, 0);
//     chassis.turn_to_angle(15);
//     chassis.drive_distance(15, 0);
//     chassis.drive_distance(-3, 0);
//     chassis.drive_distance(5, 0);
//     chassis.drive_distance(-3, 0);
ladybrown.resetPosition();
chassis.drive_max_voltage = 10;
intake1.setVelocity(100, pct);
ladybrown.setVelocity(100, pct);
chassis.set_heading(-90);
Clamp.set(false);
chassis.drive_distance(-5);

chassis.left_swing_to_angle(-120);
// chassis.drive_distance(-5);

// chassis.turn_to_angle(120);
chassis.drive_distance(-19);
chassis.drive_max_voltage = 4;
chassis.drive_distance(-7);
Clamp.set(true);

chassis.drive_max_voltage = 6;

chassis.turn_to_angle(-180);
intake1.spin(forward);
chassis.drive_distance(22);
chassis.drive_max_voltage = 8;
chassis.drive_max_voltage = 4;
chassis.drive_distance(-10);
chassis.turn_to_angle(0);
chassis.drive_max_voltage = 8;
chassis.drive_distance(25);
chassis.drive_max_voltage = 2;
chassis.drive_distance(10);
//chassis.turn_to_angle(180);
//chassis.drive_distance(50);
//wait(100,msec);
//chassis.turn_to_angle(270);
//chassis.drive_distance(23);
//ladybrown.spinToPosition(10,rev);
//chassis.drive_max_voltage = 2;
//chassis.drive_distance(10);









// chassis.turn_to_angle(87);
// ladybrown.spinToPosition(-2, rev, false);
// // intake1.spin(reverse);
// chassis.drive_distance(30);
// chassis.drive_max_voltage = 8;
// //chassis.right_swing_to_angle(60);
// chassis.left_swing_to_angle(172);
// intake1.stop();


// chassis.drive_distance(15);
// intake1.spin(forward);
// chassis.drive_max_voltage = 8;
// chassis.drive_distance(12.5);
// //chassis.left_swing_to_angle(170);

// chassis.drive_distance(-10);
// chassis.drive_max_voltage = 8;
// chassis.turn_to_angle(310);
// intake1.spin(reverse);
// chassis.drive_distance(40);
// chassis.drive_max_voltage = 4;
// chassis.drive_distance(10);








    //chassis.drive_distance(8);
    //intake1.spin(reverse);
    //chassis.drive_distance(5, 0);
    //chassis.drive_distance(-10, 0);
    //chassis.turn_to_angle(270);
    //chassis.drive_distance(4, 0);
    //chassis.drive_distance(-20, 0);
    //chassis.drive_max_voltage = 9;
    //chassis.turn_to_angle(30);
    //chassis.drive_distance(-9.5, 30);
    //chassis.drive_max_voltage = 12;
    //wait(35, msec);
    //Clamp.set(false);
    //wait(35, msec);
    //intake1.spin(forward);
    //wait(110, msec);
    //chassis.turn_to_angle(100);
    //chassis.drive_distance(19, 100);
    //intake1.spin(forward);
    //wait(135, msec);
   //chassis.turn_to_angle(-61.5);
   // chassis.drive_max_voltage = 9;
}

void testrun(){
  chassis.set_heading(0);
  intake1.setVelocity(100,pct);
  chassis.turn_to_angle(-45),
  chassis.drive_distance(12);
  intake1.spin(fwd,100,pct);

}
  



 /*chassis.turn_to_angle(190);
  chassis.drive_distance(15);
  intake1.spinFor(2,sec);

  chassis.turn_to_angle(195);
  chassis.drive_distance(15);
  intake1.spin(fwd,100,pct);
  wait(1,sec);

  chassis.turn_to_angle(0); */
