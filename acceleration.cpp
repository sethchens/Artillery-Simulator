/***********************************************************************
 * Source File:
 *    ACCELERATION 
 * Author:
 *    Seth and Will
 * Summary:
 *    Everything we need to know about changing speed
 ************************************************************************/

#include "acceleration.h"
#include "angle.h"

#include <cmath>



/*********************************************
 * ACCELERATION : SET
 *  set from angle and direction
 *********************************************/
void Acceleration::set(const Angle & a, double magnitude)
{
   ddx = sin(a.getRadians()) * magnitude;
   ddy = cos(a.getRadians()) * magnitude;
}
void AccelerationDummy::set(const Angle& a, double magnitude)
{
   assert(false);
}

/*********************************************
 * ACCELERATION : ADD
 *  a += a
 *********************************************/
void Acceleration::add(const Acceleration& acceleration)
{
   ddx += acceleration.getDDX();
   ddy += acceleration.getDDY();
}
