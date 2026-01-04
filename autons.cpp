#include "main.h"

/////
// For installation, upgrading, documentations, and tutorials, check out our website!
// https://ez-robotics.github.io/EZ-Template/
/////

// These are out of 127
const int DRIVE_SPEED = 110;
const int TURN_SPEED = 90;
const int SWING_SPEED = 110;

///
// Constants
///
void default_constants() {
  // P, I, D, and Start I
  chassis.pid_drive_constants_set(20.0, 0.0, 100.0);         // Fwd/rev constants, used for odom and non odom motions
  chassis.pid_heading_constants_set(11.0, 0.0, 20.0);        // Holds the robot straight while going forward without odom
  chassis.pid_turn_constants_set(3.0, 0.05, 20.0, 15.0);     // Turn in place constants
  chassis.pid_swing_constants_set(6.0, 0.0, 65.0);           // Swing constants
  chassis.pid_odom_angular_constants_set(6.5, 0.0, 52.5);    // Angular control for odom motions
  chassis.pid_odom_boomerang_constants_set(5.8, 0.0, 32.5);  // Angular control for boomerang motions

  // Exit conditions
  chassis.pid_turn_exit_condition_set(90_ms, 3_deg, 250_ms, 7_deg, 500_ms, 500_ms);
  chassis.pid_swing_exit_condition_set(90_ms, 3_deg, 250_ms, 7_deg, 500_ms, 500_ms);
  chassis.pid_drive_exit_condition_set(90_ms, 1_in, 250_ms, 3_in, 500_ms, 500_ms);
  chassis.pid_odom_turn_exit_condition_set(90_ms, 3_deg, 250_ms, 7_deg, 500_ms, 750_ms);
  chassis.pid_odom_drive_exit_condition_set(90_ms, 1_in, 250_ms, 3_in, 500_ms, 750_ms);
  chassis.pid_turn_chain_constant_set(3_deg);
  chassis.pid_swing_chain_constant_set(5_deg);
  chassis.pid_drive_chain_constant_set(3_in);

  // Slew constants
  chassis.slew_turn_constants_set(3_deg, 70);
  chassis.slew_drive_constants_set(3_in, 70);
  chassis.slew_swing_constants_set(3_in, 80);

  // The amount that turns are prioritized over driving in odom motions
  // - if you have tracking wheels, you can run this higher.  1.0 is the max
  chassis.odom_turn_bias_set(0.9);

  chassis.odom_look_ahead_set(7_in);           // This is how far ahead in the path the robot looks at
  chassis.odom_boomerang_distance_set(16_in);  // This sets the maximum distance away from target that the carrot point can be
  chassis.odom_boomerang_dlead_set(0.625);     // This handles how aggressive the end of boomerang motions are

  chassis.pid_angle_behavior_set(ez::shortest);  // Changes the default behavior for turning, this defaults it to the shortest path there
}


// Red Right
///
void Main_Skills() {

  chassis.drive_angle_set(3_deg);
  scrapper.set(false);
  hook.set(false);
  
  chassis.pid_drive_set(30_in, DRIVE_SPEED, true); 
  
  chassis.pid_wait();

  chassis.pid_turn_set(-90_deg, TURN_SPEED);
  chassis.pid_wait();

  scrapper.set(true);
  intake.move(-127);
  
  pros::delay(500);

  chassis.pid_drive_set(15_in, 50, true);
  chassis.pid_wait();

  pros::delay(3500); //Eat first loader of Donut holes

  chassis.pid_drive_set(-14_in, 50, true);
  chassis.pid_wait();

  scrapper.set(false); 

  // intake2.move(-127);
  // pros::delay(3500);
  // intake2.move(0);

  // chassis.pid_drive_set(10_in, 50, true);
  // chassis.pid_wait();

  chassis.pid_turn_set(45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(15_in, 50, true);
  chassis.pid_wait();

  chassis.pid_turn_set(93_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(50_in, 50, true);
  chassis.pid_wait();

  chassis.pid_turn_set(135_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(15_in, 50, true);
  chassis.pid_wait();

  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-15_in, 50, true);
  chassis.pid_wait();

  intake2.move(-127); //Throws up first loader of donut holes
  scrapper.set(true);
  pros::delay(3500);
  intake2.move(0);

  chassis.pid_turn_set(96_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(25_in, 50, true);
  chassis.pid_wait();

  pros::delay(3500);

  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-24_in, 50, true);
  chassis.pid_wait();

  intake2.move(-127);
  scrapper.set(false);
  pros::delay(3500);
}


///
// Red Right
///
void red_right_S() {

  chassis.drive_angle_set(180_deg);

  //Starts Motors Q12
  intake.move(127);

  outtake.move(-127);

  // pros::delay(3000);

  //Drives forward slightly and then turn to first block 
  chassis.pid_drive_set(-8.5_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::LEFT_SWING, 90_deg, 60);
  chassis.pid_wait();

  //move forward to second block then turn to third block
  chassis.pid_drive_set(-3_in, 60, true);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::RIGHT_SWING, 0_deg, 60);
  chassis.pid_wait();
  
  chassis.pid_drive_set(8_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-12_in, 50, true);
  chassis.pid_wait();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-5.5_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  hook.set(false);

  // basket.move(127);

  outtake.move(-127);

  pros::delay(6000);

}


void red_right_C() {

  chassis.drive_angle_set(0_deg);

  //Starts Motors Q12
  intake.move(127);

  outtake.move(-127);

  // pros::delay(3000);

  //Drives forward slightly and then turn to first block 
  chassis.pid_drive_set(8.5_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::LEFT_SWING, 90_deg, 60);
  chassis.pid_wait();

  //move forward to second block then turn to third block
  chassis.pid_drive_set(3_in, 60, true);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::RIGHT_SWING, 0_deg, 60);
  chassis.pid_wait();
  
  chassis.pid_drive_set(-8_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(20_in, 50, true);
  chassis.pid_wait();

  chassis.pid_turn_set(180_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(5.5_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  intake2.move(127);
  outtake.move(127);

  // basket.move(127);

  // outtake.move(-127);

  pros::delay(6000);

}

///
///
void Backup_Skills() {

  scrapper.set(true);
 
  chassis.pid_drive_set(13_in, DRIVE_SPEED, true); 
  
  chassis.pid_wait();

  chassis.pid_turn_set(-90_deg, TURN_SPEED);
  chassis.pid_wait();

  outtake.move(-127);
  intake.move(-127);
  pros::delay(500);
  chassis.pid_drive_set(30_in, 127, false);
  chassis.pid_wait();
  
  pros::delay(15000);
  /*for (int i = 0; i < 4; i++){
    intake.move(127);
    outtake.move(0);
    chassis.pid_drive_set(4_in, 127, false); //moving forward during intake
    chassis.pid_wait();
    outtake.move(-127);
    pros::delay(500);
    chassis.pid_drive_set(-1_in, 127, false); //moving forward during intake
    chassis.pid_wait();
    intake.move(0);
    pros::delay(200);
  }*/

  intake.move(127);

  pros::delay(2000);

  chassis.pid_drive_set(-3.5_in, 50, true);
  chassis.pid_wait();

  scrapper.set(false);  //scoring code

  intake.move(-127);

  pros::delay(1000);

  intake.move(0);

  chassis.pid_turn_set(85_deg, 30, true);
  chassis.pid_wait();  

  chassis.pid_drive_set(2.5_in, DRIVE_SPEED, true);
  chassis.pid_wait(); 

  hook.set(false); //scoring code
  outtake.move(-127);    //scoring code
  intake.move(127);  //scoring code
  // basket.move(127); //scoring code

  pros::delay(4000);

  outtake.move(0);    //scoring code
  intake.move(0);  //scoring code
  // basket.move(0); //scoring code

  for (int i = 0; i < 5; i++){
    chassis.pid_drive_set(4_in, 127, false); //moving forward during intake
    chassis.pid_wait();
    pros::delay(50);
    chassis.pid_drive_set(-5_in, 127, false); //moving forward during intake
    pros::delay(50);
  }

  chassis.pid_drive_set(-0.5_in, DRIVE_SPEED, true);
  chassis.pid_wait(); 

  outtake.move(-127);    //scoring code
  intake.move(127);  //scoring code
  // basket.move(127); //scoring code

  pros::delay(15000);


  chassis.pid_drive_set(-3_in, DRIVE_SPEED, true);
  chassis.pid_wait(); 

  chassis.pid_turn_set(-180_deg, 30, true);
  chassis.pid_wait();  

  chassis.pid_drive_set(19_in, DRIVE_SPEED, true);
  chassis.pid_wait(); 

  chassis.pid_turn_set(-90_deg, 50, true);
  chassis.pid_wait();

  chassis.pid_drive_set(-5_in, DRIVE_SPEED, true);
  chassis.pid_wait(); 

  chassis.pid_drive_set(30_in, DRIVE_SPEED, true);
  chassis.pid_wait(); 
}

void Backup_Skills_Right() {

  chassis.pid_drive_set(13_in, DRIVE_SPEED, true); 
  
  chassis.pid_wait();

  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();

  scrapper.set(false);
  outtake.move(-127);
  intake.move(-127);
  
  chassis.pid_drive_set(12_in, 127, false);
  chassis.pid_wait();

  
  
  /*for (int i = 0; i < 2; i++){
    intake.move(127);
    chassis.pid_drive_set(4_in, 127, false); //moving forward during intake
    chassis.pid_wait();
    pros::delay(500);
    chassis.pid_drive_set(-1_in, 127, false); //moving forward during intake
    chassis.pid_wait();
    intake.move(0);
    pros::delay(200);
  }*/
 
  // for (int i = 0; i < 5; i++){
  //   intake.move(127);
  //   chassis.pid_drive_set(2.5_in, 127, false); //moving forward during intake
  //   chassis.pid_wait();
  //   pros::delay(400);
  //   chassis.pid_drive_set(-1_in, 127, false); //moving forward during intake
  //   chassis.pid_wait();
  //   intake.move(0);
  //   pros::delay(200);
  // }
  
  chassis.pid_drive_set(-3.5_in, 50, true);
  chassis.pid_wait();

  scrapper.set(true);  //scoring code

  intake.move(0);

  chassis.pid_turn_set(-90_deg, 30, true);
  chassis.pid_wait();  

  intake.move(127);  //scoring code
  // basket.move(127);
  hook.set(false);

  chassis.pid_drive_set(4_in, DRIVE_SPEED, true);
  chassis.pid_wait(); 
  
//  hood.set(false); //scoring code
  // outtake.move(-127);    //scoring code
  //intake.move(127);  //scoring code
  //basket.move(127); //scoring code

  pros::delay(11000);

  // outtake.move(0);    //scoring code
  // intake.move(0);  //scoring code
  // basket.move(0); //scoring code

  // for (int i = 0; i < 5; i++){
  //   chassis.pid_drive_set(4_in, 127, false); //moving forward during intake
  //   chassis.pid_wait();
  //   pros::delay(50);
  //   chassis.pid_drive_set(-5_in, 127, false); //moving forward during intake
  //   pros::delay(50);
  // }

  // chassis.pid_drive_set(-0.5_in, DRIVE_SPEED, true);
  // chassis.pid_wait(); 

  // outtake.move(-127);    //scoring code
  // intake.move(127);  //scoring code
  // basket.move(127); //scoring code

  // pros::delay(7000);
  }
  /* add for skills if dependable
  chassis.drive_angle_set(0_deg);

  //Starts Motors
  intake.move(127);

  outtake.move(-127);

  //Drives forward slightly and then turn to first block 
  chassis.pid_drive_set(7_in, DRIVE_SPEED, true);

 chassis.pid_wait();

  chassis.pid_swing_set(ez::LEFT_SWING, 90_deg, 60);
  chassis.pid_wait();

  //move forward to second block then turn to third block
  chassis.pid_drive_set(3_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::RIGHT_SWING, 0_deg, 60);
  chassis.pid_wait();
  
  chassis.pid_drive_set(-2_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(-45_deg, TURN_SPEED);
  chassis.pid_wait();

  basket.move(127);

  chassis.pid_drive_set(8_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  outtake.move(127);

  pros::delay(1500);

  outtake.move(-127);

  chassis.pid_drive_set(-20_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(7_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  hood.set(true);

  pros::delay(4000);
  */


///
// Red Left
///
void red_left_C() {

  chassis.drive_angle_set(0_deg);

  //Starts Motors
  intake.move(127);

  outtake.move(-127);

  //Drives forward slightly and then turn to first block 
  chassis.pid_drive_set(6_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::RIGHT_SWING, -90_deg, 60);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::LEFT_SWING, 0_deg, 60);
  chassis.pid_wait();
  
  chassis.pid_drive_set(1_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(-135_deg, TURN_SPEED);
  chassis.pid_wait();

  pros::delay(2000);

  // basket.move(127);

  chassis.pid_drive_set(5_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  outtake.move(80);

  pros::delay(6000);

  outtake.move(0);

  chassis.pid_drive_set(-6_in, DRIVE_SPEED, true);
  chassis.pid_wait();

}

// Red Left
///
void red_left_S() {

  chassis.drive_angle_set(180_deg);

  //Starts Motors
  intake.move(127);

  outtake.move(-127);

  //Drives forward slightly and then turn to first block 
  chassis.pid_drive_set(-6_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::LEFT_SWING, 90_deg, 60);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::RIGHT_SWING, 180_deg, 60);
  chassis.pid_wait();
  
  chassis.pid_drive_set(-1_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(-45_deg, TURN_SPEED);
  chassis.pid_wait();

  pros::delay(2000);

  // basket.move(127);

  chassis.pid_drive_set(-5_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  outtake.move(80);

  pros::delay(6000);

  outtake.move(0);

  chassis.pid_drive_set(6_in, DRIVE_SPEED, true);
  chassis.pid_wait();

}

///
// Blue Right
///
void blue_right() {

  scrapper.set(false);
  
  chassis.drive_angle_set(150_deg);

  //Starts Motors
  intake.move(-127);

  chassis.pid_drive_set(30_in, 70, true);
  chassis.pid_wait();

  chassis.pid_drive_set(-6_in, 70, true);
  chassis.pid_wait();

  chassis.pid_turn_set(45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-15_in, 70, true);
  chassis.pid_wait();

  intake2.move(-127);

  pros::delay(2500);

  intake2.move(0);

  chassis.pid_drive_set(43_in, 70, true);
  chassis.pid_wait();

  scrapper.set(true);

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(10_in, 70, true);
  chassis.pid_wait();

  pros::delay(2000);

  chassis.pid_drive_set(-24_in, 70, true);
  chassis.pid_wait();

  intake2.move(-127);
}

///
// Blue Left
///
void blue_left() {

}

///
// Turn Example
///
void turn_example() {
  // The first parameter is the target in degrees
  // The second parameter is max speed the robot will drive at

  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();
}
