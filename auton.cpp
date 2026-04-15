#include "main.h"

const int DRIVE_SPEED = 110; //11.0 volts out of 12.7 volts used
const int TURN_SPEED = 90; // 9.0 volts out of 12.7 volts used
const int SWING_SPEED = 110; // 11.0 volts out of 12.7 volts used

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
  // - if we have tracking wheels, we can run this higher.  1.0 is the max
  chassis.odom_turn_bias_set(0.9);

  chassis.odom_look_ahead_set(7_in);           // This is how far ahead in the path the robot looks at
  chassis.odom_boomerang_distance_set(16_in);  // This sets the maximum distance away from target that the carrot point can be
  chassis.odom_boomerang_dlead_set(0.625);     // This handles how aggressive the end of boomerang motions are

  chassis.pid_angle_behavior_set(ez::shortest);  // Changes the default behavior for turning, this defaults it to the shortest path there
}

void Skills() {

  chassis.drive_angle_set(0_deg);
  scrapper.set(true);
  hook.set(true);
  middle.set(true);
  intake2.move(0);
  
  chassis.pid_drive_set(30_in, DRIVE_SPEED, true); 
  chassis.pid_wait();

  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();

  intake.move(127);

  chassis.pid_drive_set(17_in, 50, true);
  chassis.pid_wait();

  pros::delay(1500); //Eat first loader of Donut holes

  chassis.pid_drive_set(-14_in, 50, true);
  chassis.pid_wait();

  scrapper.set(false); 

  chassis.pid_turn_set(-45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(14_in, 50, true);
  chassis.pid_wait();

  chassis.pid_turn_set(-90_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(50_in, 50, true); //Gets too second corner
  chassis.pid_wait();

  chassis.pid_turn_set(-135_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(14_in, 50, true);
  chassis.pid_wait();

  chassis.pid_turn_set(-90_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-15_in, 50, true);
  chassis.pid_wait();

  intake.move(100);
  intake2.move(100); //Throws up first loader of donut holes
  scrapper.set(true);
  pros::delay(1000);
  intake.move(-127); 
  intake2.move(-127);
  pros::delay(100);
  intake.move(90); 
  intake2.move(80);
  pros::delay(1500);
  intake2.move(0);

  chassis.pid_turn_set(-90_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(25_in, 50, true);
  chassis.pid_wait();

  pros::delay(1500);

  chassis.pid_turn_set(-90_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-24_in, 50, true);
  chassis.pid_wait();

  intake.move(127); //throws up second loader
  intake2.move(120);
  pros::delay(1000);
  intake.move(-127); 
  intake2.move(-127);
  pros::delay(100);
  intake.move(90); 
  intake2.move(90);
  pros::delay(1500);
  intake2.move(0);
  scrapper.set(false);

//corner 3

  chassis.pid_drive_set(10_in, 50, true);
  chassis.pid_wait();

  chassis.pid_turn_set(0_deg, 50);
  chassis.pid_wait();

  //Drive to the other side of the field into the wall to fix any misalignment and hard reset X position
  chassis.pid_drive_set(-100_in, 50, true); 
  chassis.pid_wait();

  //Go back to align to loader
  chassis.pid_drive_set(13_in, 50, true);
  chassis.pid_wait();

  //Put loader down early
  scrapper.set(true);

  //Turn to face Loader
  chassis.pid_turn_set(-90_deg, 50);
  chassis.pid_wait();

  //Go into loader and hard reset in y direction
  chassis.pid_drive_set(20_in, 50, true);
  chassis.pid_wait();

  pros::delay(1500);//Eat third loader

  chassis.pid_drive_set(-12_in, 50, true);
  chassis.pid_wait();

  scrapper.set(false); 

  chassis.pid_turn_set(-225_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(14_in, 50, true);
  chassis.pid_wait();

  chassis.pid_turn_set(95_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(52_in, 50, true);
  chassis.pid_wait();

  chassis.pid_turn_set(-315_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(14.5_in, 50, true);
  chassis.pid_wait();

  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-15_in, 50, true);
  chassis.pid_wait();

  intake.move(127); 
  intake2.move(100); //Throws up third loader of donut holes
  scrapper.set(true);
  pros::delay(1000);
  intake.move(-127); 
  intake2.move(-127);
  pros::delay(100);
  intake.move(127); 
  intake2.move(100);
  pros::delay(1700);
  intake2.move(0);

  chassis.pid_turn_set(87_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(27_in, 50, true);
  chassis.pid_wait();

  pros::delay(2500);

  chassis.pid_drive_set(-24_in, 50, true);
  chassis.pid_wait();

  intake.move(127); 
  intake2.move(127);
  pros::delay(1000);
  intake.move(-127); 
  intake2.move(-127);
  pros::delay(100);
  intake.move(127); 
  intake2.move(127);
  pros::delay(1500);
  scrapper.set(false);
//park
  chassis.pid_drive_set(11_in, 50, true);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::RIGHT_SWING, 3, 85, 25);
  chassis.pid_wait();

  chassis.drive_set(90,90);

  pros::delay(1100);

  chassis.drive_set(0,0);
}


///
// Red Right
///

void red_right() {

  middle.set(true);

  intake.move(127);

  chassis.drive_angle_set(0_deg);

  scrapper.set(false);
  
  chassis.drive_angle_set(150_deg);

  chassis.pid_drive_set(30_in, 70, true);
  chassis.pid_wait();

  chassis.pid_drive_set(-7_in, 70, true);
  chassis.pid_wait();
  
  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(-94_deg, TURN_SPEED);
  chassis.pid_wait();

   scrapper.set(true);

  chassis.pid_drive_set(29.5_in, 70, true);
  chassis.pid_wait();

  //chassis.pid_drive_set(43_in, 70, true);
  //chassis.pid_wait();


  chassis.pid_turn_set(-52_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(13_in, 55, true);
  chassis.pid_wait();

  pros::delay(400);

  // chassis.pid_turn_set(0_deg, TURN_SPEED);
  // chassis.pid_wait();


  chassis.pid_drive_set(-10_in, 70, true);
  chassis.pid_wait();

  // chassis.pid_turn_set(-2_deg, TURN_SPEED);
  // chassis.pid_wait();

  chassis.pid_drive_set(-17_in, 70, true);
  chassis.pid_wait();

  intake2.move(127);

  pros::delay(5000);

  // chassis.pid_drive_set(10_in, 70, true);
  // chassis.pid_wait()/

  // chassis.pid_drive_set(-15_in, 70, true);
  // chassis.pid_wait();

}

void Skills() {
  hook.set(false);
  middle.set(true);
  intake.move(127);

  chassis.drive_angle_set(0_deg);

  scrapper.set(false);
  
  chassis.drive_angle_set(150_deg);

  chassis.pid_drive_set(30_in, 70, true);
  chassis.pid_wait();

  chassis.pid_drive_set(-7_in, 70, true);
  chassis.pid_wait();

  chassis.pid_turn_set(47_deg, TURN_SPEED);
  chassis.pid_wait();

  //middle.set(true);

  chassis.pid_drive_set(30_in, 70, true);
  chassis.pid_wait();

  //chassis.pid_drive_set(43_in, 70, true);
  //chassis.pid_wait();

  scrapper.set(true);

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(12_in, 55, true);
  chassis.pid_wait();

  // pros::delay(400);

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();
 

  chassis.pid_drive_set(-11_in, 70, true);
  chassis.pid_wait();

  chassis.pid_turn_set(-12_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-17_in, 70, true);
  chassis.pid_wait();

  intake2.move(127);

  pros::delay(1500);

  intake.move(-127);

  intake2.move(-127);

  pros::delay(200);

  intake.move(127);

  intake2.move(127);

  pros::delay(1000);

  chassis.pid_drive_set(15_in, 70, true);
  chassis.pid_wait();

  chassis.pid_turn_set(-45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-16.5_in, 70, true);
  chassis.pid_wait();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();

  hook.set(false); 

  chassis.pid_drive_set(-17_in, 70, true);
  chassis.pid_wait();

  // chassis.pid_drive_set(-15_in, 70, true);
  // chassis.pid_wait();
}

void Backup_Skills() {

  hook.set(false);
  middle.set(true);
  intake.move(127);

  chassis.drive_angle_set(0_deg);

  scrapper.set(false);
  
  chassis.drive_angle_set(150_deg);

  chassis.pid_drive_set(30_in, 70, true);
  chassis.pid_wait();

  chassis.pid_drive_set(-7_in, 70, true);
  chassis.pid_wait();

  chassis.pid_turn_set(47_deg, TURN_SPEED);
  chassis.pid_wait();

  //middle.set(true);

  chassis.pid_drive_set(30_in, 70, true);
  chassis.pid_wait();

  //chassis.pid_drive_set(43_in, 70, true);
  //chassis.pid_wait();

  scrapper.set(true);

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(12_in, 55, true);
  chassis.pid_wait();

  // pros::delay(400);

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();
 
  chassis.pid_drive_set(-11_in, 70, true);
  chassis.pid_wait();

  chassis.pid_turn_set(-3_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-17_in, 70, true);
  chassis.pid_wait();

  intake2.move(127);

  pros::delay(1500);

  intake.move(-127);

  intake2.move(-127);

  pros::delay(100);

  intake.move(127);

  intake2.move(127);

  pros::delay(2000);

  intake.move(0);

  intake2.move(0);

  chassis.pid_drive_set(15_in, 70, true);
  chassis.pid_wait();

  chassis.pid_turn_set(-45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-16.5_in, 70, true);
  chassis.pid_wait(); 

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();

  hook.set(false); 

  chassis.pid_drive_set(-20_in, 70, true);
  chassis.pid_wait();

  // chassis.pid_drive_set(-15_in, 70, true);
  // chassis.pid_wait();
  }

  // Red Left
///
void red_left() {
chassis.drive_angle_set(0_deg);

  scrapper.set(false);

  middle.set(true);
  
  chassis.drive_angle_set(150_deg);

  //Starts Motors
  intake.move(127);
  intake2.move(0);

  chassis.pid_drive_set(30_in, 70, true);
  chassis.pid_wait();

  chassis.pid_drive_set(-6_in, 70, true);
  chassis.pid_wait();

  chassis.pid_turn_set(75_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(13_in, 70, true);
  chassis.pid_wait();

  intake.move(-100);
  intake2.move(-127);


  pros::delay(1500);

  intake.move(127);

  //middle.set(false);

  chassis.pid_drive_set(-43_in, 70, true);
  chassis.pid_wait();

  scrapper.set(true);

  chassis.pid_turn_set(-58_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(12_in, 55, true);
  chassis.pid_wait();

  pros::delay(600);

  chassis.pid_drive_set(-10_in, 70, true);
  chassis.pid_wait();

  chassis.pid_turn_set(-58_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-14_in, 70, true);
  chassis.pid_wait();

  intake2.move(-127);

  pros::delay(5000);

}

// Red Left
///
void red_left() {

  intake.move(127);

  scrapper.set(false);
  
  chassis.drive_angle_set(-150_deg);

  chassis.pid_drive_set(29_in, 70, true);
  chassis.pid_wait();

  chassis.pid_drive_set(-6_in, 70, true);
  chassis.pid_wait();

  chassis.pid_turn_set(-47_deg, TURN_SPEED);
  chassis.pid_wait();

  middle.set(true);

  chassis.pid_drive_set(27_in, 70, true);
  chassis.pid_wait();

  //chassis.pid_drive_set(43_in, 70, true);
  //chassis.pid_wait();

  scrapper.set(true);

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(11_in, 55, true);
  chassis.pid_wait();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-18.5_in, 70, true);
  chassis.pid_wait();

  chassis.pid_turn_set(10_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-8.5_in, 70, true);
  chassis.pid_wait();

  intake2.move(127);

  pros::delay(1500);

  intake.move(-127);
  intake2.move(-127);

  pros::delay(100);

  intake2.move(127);
  intake.move(127);

  pros::delay(2000);

  intake.move(0);
  intake2.move(0);

  scrapper.set(false);

  chassis.pid_drive_set(15_in, 70, true);
  chassis.pid_wait();

  chassis.pid_turn_set(-45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-8_in, 70, true);
  chassis.pid_wait();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();

  hook.set(false); 

  chassis.pid_drive_set(-17_in, 70, true);
  chassis.pid_wait();
}

// Blue Right
///
void blue_right() {

  chassis.drive_angle_set(0_deg);

  scrapper.set(false);

  middle.set(true);
  
  chassis.drive_angle_set(150_deg);

  //Starts Motors
  intake.move(127);

  chassis.pid_drive_set(30_in, 70, true);
  chassis.pid_wait();

  chassis.pid_drive_set(-4_in, 70, true);
  chassis.pid_wait();

  chassis.pid_turn_set(49_deg, TURN_SPEED);
  chassis.pid_wait();

  middle.set(false);

  chassis.pid_drive_set(-14_in, 70, true);
  chassis.pid_wait();

  intake.move(50);

  intake2.move(127);

  pros::delay(2000);

  intake.move(127); 
  intake2.move(0);

  middle.set(true);

  chassis.pid_drive_set(40.5_in, 70, true);
  chassis.pid_wait();

  scrapper.set(true);

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(14_in, 55, true);
  chassis.pid_wait();

  pros::delay(200);

  chassis.pid_drive_set(-10_in, 70, true);
  chassis.pid_wait();

  chassis.pid_turn_set(-2_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-14_in, 70, true);
  chassis.pid_wait();

  intake2.move(127);

  pros::delay(3000);

  // chassis.pid_drive_set(10_in, 70, true);
  // chassis.pid_wait()/

  // chassis.pid_drive_set(-15_in, 70, true);
  // chassis.pid_wait();
}

///
// Blue Left
///
void blue_left() {
  chassis.pid_drive_set(1_in, 70, true);
  chassis.pid_wait();
}

///
// Turn Example
///
void turn_example() {
  
  chassis.drive_angle_set(0_deg);
  scrapper.set(true);
  hook.set(true);
  middle.set(true);
  intake2.move(0);
  
  chassis.pid_drive_set(30_in, DRIVE_SPEED, true); 
  chassis.pid_wait();

  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();

  intake.move(127);

  chassis.pid_drive_set(17_in, 50, true);
  chassis.pid_wait();

  pros::delay(1500); //Eat first loader of Donut holes

  chassis.pid_drive_set(-14_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  scrapper.set(false); 

  chassis.pid_turn_set(-45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(14_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(-90_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(50_in, DRIVE_SPEED, true); //Gets too second corner
  chassis.pid_wait();

  chassis.pid_turn_set(-135_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(14_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(-90_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-15_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  intake.move(127); 
  intake2.move(127); //Throws up first loader of donut holes
  scrapper.set(true);
  pros::delay(1000);
  intake.move(-127); 
  intake2.move(-127);
  pros::delay(100);
  intake.move(127); 
  intake2.move(127);
  pros::delay(1500);
  intake2.move(0);


  chassis.pid_drive_set(25_in, 50, true);
  chassis.pid_wait();

  pros::delay(1500);

  chassis.pid_turn_set(-90_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-24_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  intake.move(127); //throws up second loader
  intake2.move(127);
  pros::delay(1000);
  intake.move(-127); 
  intake2.move(-127);
  pros::delay(100);
  intake.move(90); 
  intake2.move(90);
  pros::delay(1500);
  intake2.move(0);
  scrapper.set(false);


//middle
  chassis.pid_drive_set(17_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(135_deg, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(20_in, 50, true);
  chassis.pid_wait();

  chassis.pid_drive_set(-5_in, 50, true);
  chassis.pid_wait();

  chassis.pid_drive_set(10_in, 50, true);
  chassis.pid_wait();

  chassis.pid_turn_set(-45_deg, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-17_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  middle.set(false);

  intake2.move(127);
  pros::delay(1500);
  intake2.move(0);

  middle.set(true);

  chassis.pid_drive_set(30_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(0_deg, DRIVE_SPEED);
  chassis.pid_wait();

//corner 3
  //Drive to the other side of the field into the wall to fix any misalignment and hard reset X position
  chassis.pid_drive_set(-90_in, DRIVE_SPEED, true); 
  chassis.pid_wait();

  //Go back to align to loader
  chassis.pid_drive_set(13_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  //Put loader down early
  scrapper.set(true);

  //Turn to face Loader
  chassis.pid_turn_set(-90_deg, DRIVE_SPEED);
  chassis.pid_wait();

  //Go into loader and hard reset in y direction
  chassis.pid_drive_set(20_in, 50, true);
  chassis.pid_wait();

  pros::delay(1500);//Eat third loader

  chassis.pid_drive_set(-14_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  scrapper.set(false); 

  chassis.pid_turn_set(-225_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(14_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(95_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(50_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(-315_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(14.5_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-15_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  intake.move(127); 
  intake2.move(127); //Throws up third loader of donut holes
  scrapper.set(true);
  pros::delay(1000);
  intake.move(-127); 
  intake2.move(-127);
  pros::delay(100);
  intake.move(127); 
  intake2.move(127);
  pros::delay(1500);
  intake2.move(0);

  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(27_in, 50, true);
  chassis.pid_wait();

  pros::delay(2500);

  chassis.pid_drive_set(-24_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  intake.move(127); 
  intake2.move(127);
  pros::delay(1000);
  intake.move(-127); 
  intake2.move(-127);
  pros::delay(100);
  intake.move(127); 
  intake2.move(127);
  pros::delay(1500);
  scrapper.set(false);

  chassis.pid_drive_set(15_in, 50, true);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::RIGHT_SWING, 3, 85, 25);
  chassis.pid_wait();

  chassis.drive_set(100,100);

  pros::delay(1100);

  chassis.drive_set(0,0);
}

