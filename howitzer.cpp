//
//  howitzer.cpp
//  Lab09
//
//  Created by Seth on 3/28/24.
//

#include "howitzer.h"

/***********************************************
 * HOWITZER :: GENERATE POSITION
 * generate a new position for the howitzer
 * *********************************************/
void Howitzer::generatePosition(const Position& posUpperRight)
{
   double xPixels = random(posUpperRight.getPixelsX() * 0.1,
   posUpperRight.getPixelsX() * 0.9);
   position.setPixelsX(xPixels);
   position.setPixelsY(0);
}

/***********************************************
 * HOWITZER :: RAISE
 * raise (or lower) the howitzer
 * *********************************************/
void Howitzer::raise(double radian)
{
   elevation.add(elevation.isRight() ? -radian : radian);
}

void Howitzer::draw(ogstream& gout, double flightTime) const
{
   gout.drawHowitzer(position,
      elevation.getRadians(),
      flightTime);
}

