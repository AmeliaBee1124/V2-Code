#pragma once

#include "EZ-Template/api.hpp"
#include "api.h"

extern Drive chassis;

// Your motors, sensors, etc. should go here.  Below are examples

// inline pros::Motor intake(1);
// inline pros::adi::DigitalIn limit_switch('A');
inline pros::Motor intake(-1);
inline pros::Motor outtake(2);
inline pros::Motor basket(3);
inline ez::Piston scrapper('A');
inline ez::Piston hood('B');
inline pros::Distance distancesensor(13);