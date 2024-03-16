/***********************************************************************
 * Source File:
 *    PHYSICS
 * Author:
 *    Seth and Will
 * Summary:
 *    Laws of motion, effects of gravity, wind resistence, etc.
 ************************************************************************/
  
 #include "physics.h"  // for the prototypes
#include <vector>      // for tables of known data

using namespace std;
 
 /*********************************************************
 * LINEAR INTERPOLATION
 * From a list of domains and ranges, linear interpolate
 *********************************************************/
double linearInterpolation(const Mapping mapping[], int numMapping, double domain)
{
   int lowerIndex = -1;
   int upperIndex = -1;
   
   if (domain > mapping[numMapping - 1].domain)
      return mapping[numMapping - 1].range;
   if (domain < mapping[0].domain)
      return mapping[0].range;
   
   for (int i = 0; i < numMapping; ++i)
   {
      if (mapping[i].domain == domain) {
         // If the domain exactly matches one of the mappings, return the corresponding range
         return mapping[i].range;
      }
      else if (mapping[i].domain < domain)
         lowerIndex = i;
      else {
         upperIndex = i;
         break;
      }
   }
 
   double d0 = mapping[lowerIndex].domain;
   double r0 = mapping[lowerIndex].range;
   double d1 = mapping[upperIndex].domain;
   double r1 = mapping[upperIndex].range;
 
 
   return linearInterpolation(d0, r0, d1, r1, domain);
}

/*********************************************************
 * GRAVITY FROM ALTITUDE
 * Determine gravity coefficient based on the altitude
 *********************************************************/
double gravityFromAltitude(double altitude)
{
   
   // Initiate the corelating data that is already known
   Mapping gravityInAltitude[] = {
      {0.0    , 9.807},
      {1000.0 , 9.804},
      {2000.0 , 9.801},
      {3000.0 , 9.797},
      {4000.0 , 9.794},
      {5000.0 , 9.791},
      {6000.0 , 9.788},
      {7000.0 , 9.785},
      {8000.0 , 9.782},
      {9000.0 , 9.779},
      {10000.0, 9.776},
      {15000.0, 9.761},
      {20000.0, 9.745},
      {25000.0, 9.730}
   };
   
   return linearInterpolation(gravityInAltitude, 14, altitude);
}

/*********************************************************
 * DENSITY FROM ALTITUDE
 * Determine the density of air based on the altitude
 *********************************************************/
double densityFromAltitude(double altitude)
{
   return -99.9;
}

/*********************************************************
 * SPEED OF SOUND FROM ALTITUDE
 * determine the speed of sound for a given altitude.
 ********************************************************/
double speedSoundFromAltitude(double altitude)
{
   Mapping speedSoundAltitude[] = {
      {0, 340},
      {1000, 336},
      {2000, 332},
      {3000, 328},
      {4000, 324},
      {5000, 320},
      {6000, 316},
      {7000, 312},
      {8000, 308},
      {9000, 303},
      {10000, 299},
      {15000, 295},
      {20000, 295},
      {25000, 295},
      {30000, 305},
      {40000, 324}
   };
   
   return linearInterpolation(speedSoundAltitude, 16, altitude);
}


/*********************************************************
 * DRAG FROM MACH
 * Determine the drag coefficient for a M795 shell given speed in Mach
 *********************************************************/
double dragFromMach(double speedMach)
{
   return -99.9;
}
