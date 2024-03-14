/***********************************************************************
 * Header File:
 *    TEST POSITION
 * Author:
 *    <your name here>
 * Summary:
 *    Unit tests for the Position class.
 ************************************************************************/

#pragma once

#include "unitTest.h"
#include "position.h"
#include "velocity.h"
#include "acceleration.h"

using namespace std;

/*******************************
 * TEST Position
 * A friend class for Position which contains the Position unit tests
 ********************************/
class TestPosition : public UnitTest
{
public:
   void run()
   {
      // Ticket 7: Meters
      construct_default();
      construct_nonDefault();
      construct_copy();
      assign();
      setMetersX();
      setMetersY();
      getMetersX();
      getMetersY();

      // Ticket 8: Pixels and Zoom
      setZoom_member();
      setZoom_anotherVariable();
      getZoom_member();
      getZoom_anotherVariable();
      setPixelsX_noZoom();
      setPixelsX_zoom();
      setPixelsY_noZoom();
      setPixelsY_zoom();
      getPixelsX_noZoom();
      getPixelsX_zoom();
      getPixelsY_noZoom();
      getPixelsY_zoom();

      // Ticket 9: Add
      addMetersX();
      addMetersY();
      addPixelsX_noZoom();
      addPixelsX_zoom();
      addPixelsY_noZoom();
      addPixelsY_zoom();
      add_stationary();
      add_moving();
      add_movingLonger();
      add_fromStop();
      add_fromStopLonger();
      add_complex();
      
      report("Position");
   }
   
private:


   /*****************************************************************
    *****************************************************************
    * CONSTRUCTOR
    *****************************************************************
    *****************************************************************/

   /*********************************************
    * name:    DEFAULT CONSTRUCTOR
    * input:   nothing
    * output:  pos=(0, 0))
    *********************************************/
   void construct_default()
   {
      // setup
      double metersFromPixels = Position::metersFromPixels;
      Position::metersFromPixels = 99.9;
      // exercise
      Position pos;
      // verify
      assertEquals(pos.x, 0.0);
      assertEquals(pos.y, 0.0);
      assertEquals(pos.metersFromPixels, 99.9);
      // teardown
      Position::metersFromPixels = metersFromPixels;
   }

   /*********************************************
    * name:    NON-DEFAULT CONSTRUCTOR
    * input:   x=120.0, y=360.0
    * output:  pos=(120.0, 360.0)
    *********************************************/
   void construct_nonDefault()
   {
      // setup
      double metersFromPixels = Position::metersFromPixels;
      Position::metersFromPixels = 99.9;
      double x = 120.0;
      double y = 360.0;
      // exercise
      Position pos(x, y);
      // verify
      assertEquals(pos.x, 120.0);
      assertEquals(pos.y, 360.0);
      assertEquals(pos.metersFromPixels, 99.9);
      assertEquals(x, 120.0);
      assertEquals(y, 360.0);
      // teardown
      Position::metersFromPixels = metersFromPixels;
   }

   /*********************************************
    * name:    COPY CONSTRUCTOR
    * input:   posRHS = (1234.5, 6789.0)
    * output:  pos = (1234.5, 6789.0)
    *********************************************/
   void construct_copy()
   {
      // setup
      double metersFromPixels = Position::metersFromPixels;
      Position::metersFromPixels = 99.9;
      Position posRHS;
      posRHS.x = 1234.5;
      posRHS.y = 6789.0;
      // exercise
      Position pos(posRHS);
      // verify
      assertEquals(posRHS.x, 1234.5);
      assertEquals(posRHS.y, 6789.0);
      assertEquals(posRHS.metersFromPixels, 99.9);
      assertEquals(pos.x, 1234.5);
      assertEquals(pos.y, 6789.0);
      assertEquals(pos.metersFromPixels, 99.9);
      // teardown
      Position::metersFromPixels = metersFromPixels;
   }

   /*********************************************
    * name:    ASSIGNMENT OPERATOR
    * input:   posLHS=(-99.9, -88.8)  posRHS=(24.68, -13,57)
    * output:  posLHS=(24.68, -13,57)
    *********************************************/
   void assign()
   {
      // setup
      double metersFromPixels = Position::metersFromPixels;
      Position::metersFromPixels = 99.9;
      Position posLHS;
      posLHS.x = -99.9;
      posLHS.y = -88.8;
      Position posRHS;
      posRHS.x =  24.68;
      posRHS.y = -13.57;
      // exercise
      posLHS = posRHS;
      // verify
      assertEquals(posRHS.x, 24.68);
      assertEquals(posRHS.y, -13.57);
      assertEquals(posRHS.metersFromPixels, 99.9);
      assertEquals(posLHS.x, 24.68);
      assertEquals(posLHS.y, -13.57);
      assertEquals(posLHS.metersFromPixels, 99.9);
      // teardown
      Position::metersFromPixels = metersFromPixels;
   }

   /*****************************************************************
    *****************************************************************
    * GETTERS
    *****************************************************************
    *****************************************************************/
   
   /*********************************************
    * name:    GET ZOOM : member variable
    * input:   pos.metersFromPixels=123.4
    * output:  zoom=123.4
    *          Position::metersFromPixels=123.4
    *********************************************/
   void getZoom_member()
   {
      // setup
      Position pos;
      pos.metersFromPixels = 123.4;
      double zMember = -99.9;
      
      // exercise
      zMember = pos.getZoom();
      
      // verify
      assertEquals(zMember, 123.4);
   } // teardown
   
   /*********************************************
    * name:    GET ZOOM : another variable
    * input:   pos1.metersFromPixels=99.9
    *          pos2.metersFromPixels=123.4
    * output:  zoom=123.4
    *          pos1.metersFromPixels=123.4
    *          pos2.metersFromPixels=123.4
    *********************************************/
   void getZoom_anotherVariable()
   {
      // setup
      Position pos1;
      Position pos2;
      
      // exercise
      pos1.metersFromPixels = 99.9;
      pos2.metersFromPixels = 123.4;
      
      // verify
      assertEquals(pos1.metersFromPixels, 123.4);
      assertEquals(pos2.metersFromPixels, 123.4);
   } // teardown


   /*********************************************
    * name:    GET METERS X
    * input:   pos=(4500.0, 2500.0)
    * output:  x=4500.0
    *********************************************/
   void getMetersX()
   {
      // setup
      double metersFromPixels = Position::metersFromPixels;
      Position::metersFromPixels = 99.9;
      Position pos;
      pos.x = 4500.0;
      pos.y = 2500.0;
      // exercise
      double x = pos.getMetersX();
      // verify
      assertEquals(x, 4500.0);
      assertEquals(pos.x, 4500.0);
      assertEquals(pos.y, 2500.0);
      assertEquals(pos.metersFromPixels, 99.9);
      // teardown
      Position::metersFromPixels = metersFromPixels;
   }

   /*********************************************
    * name:    GET METERS Y
    * input:   pos=(4500.0, 2500.0)
    * output:  y=4500.0
    *********************************************/
   void getMetersY()
   {
      // setup
      double metersFromPixels = Position::metersFromPixels;
      Position::metersFromPixels = 99.9;
      Position pos;
      pos.x = 4500.0;
      pos.y = 2500.0;
      // exercise
      double y = pos.getMetersY();
      // verify
      assertEquals(pos.x, 4500.0);
      assertEquals(pos.y, 2500.0);
      assertEquals(pos.metersFromPixels, 99.9);
      assertEquals(y, 2500.0);
      // teardown
      Position::metersFromPixels = metersFromPixels;
   }

   /*********************************************
    * name:    GET METERS X NO ZOOM
    * input:   pos=(123.4, 567.8) metersFromPixels=1
    * output:  x=123.4
    *********************************************/
   void getPixelsX_noZoom()
   {
      // setup
      Position pos;
      pos.x = 123.4;
      pos.y = 567.8;
      pos.metersFromPixels = 1;
      double x = -99.9;
      
      // exercise
      x = pos.getPixelsX();
      
      // verify
      assertEquals(x, 123.4);
      assertEquals(pos.y, 567.8);
   } // teardown
   
   /*********************************************
    * name:    GET METERS X ZOOM
    * input:   pos=(123.4, 567.8) metersFromPixels=100
    * output:  x=1.234
    *********************************************/
   void getPixelsX_zoom()
   {
      // setup
      Position pos;
      pos.x = 123.4;
      pos.y = 567.8;
      pos.metersFromPixels = 100;
      double x = -99.9;
      
      // exercise
      x = pos.getPixelsX();
      
      // verify
      assertEquals(x, 1.234);
      assertEquals(pos.y, 567.8);
   }

   /*********************************************
    * name:    GET METERS Y NO ZOOM
    * input:   pos=(123.4, 567.8) metersFromPixels=1
    * output:  y=567.8
    *********************************************/
   void getPixelsY_noZoom()
   {
      // setup
      Position pos;
      pos.x = 123.4;
      pos.y = 567.8;
      pos.metersFromPixels = 1;
      double y = -99.9;
      
      // exercise
      y = pos.getPixelsY();
      
      // verify
      assertEquals(pos.x, 123.4);
      assertEquals(y, 567.8);
   }

   /*********************************************
    * name:    GET METERS Y ZOOM
    * input:   pos=(123.4, 567.8) metersFromPixels=100
    * output:  y=5.678
    *********************************************/
   void getPixelsY_zoom()
   {
      // setup
      Position pos;
      pos.x = 123.4;
      pos.y = 567.8;
      pos.metersFromPixels = 100;
      double y = -99.9;
      
      // exercise
      y = pos.getPixelsY();
      
      // verify
      assertEquals(pos.x, 123.4);
      assertEquals(y, 5.678);
   }

   /*****************************************************************
    *****************************************************************
    * SETTERS
    *****************************************************************
    *****************************************************************/
   
   /*********************************************
    * name:    SET METERS Y
    * input:   pos=(999.9, 888.8) x = 123.4
    * output:  pos=(123.4, 888.8)
    *********************************************/
   void setMetersX()
   {  // setup
      double metersFromPixels = Position::metersFromPixels;
      Position::metersFromPixels = 99.9;
      Position pos;
      pos.x = 999.9;
      pos.y = 888.8;
      // exercise
      pos.setMetersX(123.4);
      // verify
      assertEquals(pos.x, 123.4);
      assertEquals(pos.y, 888.8);
      assertEquals(pos.metersFromPixels, 99.9);
      // teardown
      Position::metersFromPixels = metersFromPixels;
   }

   /*********************************************
    * name:    GET METERS Y ZOOM
    * input:   pos=(999.9, 888.8) y = 123.4
    * output:  pos=(999.9, 123.4)
    *********************************************/
   void setMetersY()
   {  // setup
      double metersFromPixels = Position::metersFromPixels;
      Position::metersFromPixels = 99.9;
      Position pos;
      pos.x = 999.9;
      pos.y = 888.8;
      // exercise
      pos.setMetersY(123.4);
      // verify
      assertEquals(pos.y, 123.4);
      assertEquals(pos.metersFromPixels, 99.9);
      // teardown
      Position::metersFromPixels = metersFromPixels;
   }

   /*********************************************
    * name:    SET METERS X NO ZOOM
    * input:   pos=(999.9, 888.8) x=123.4 zoom=1
    * output:  pos=(123.4, 888.8)
    *********************************************/
   void setPixelsX_noZoom()
   {
      // setup
      Position pos;
      pos.x = 999.9;
      pos.y = 888.8;
      pos.metersFromPixels = 1;
      
      // exercise
      pos.setPixelsX(123.4);
      
      // verify
      assertEquals(pos.x, 123.4);
      assertEquals(pos.y, 888.8);
   } // teardown

   /*********************************************
    * name:    SET METERS X ZOOM
    * input:   pos=(999.9, 888.8) x=123.4 zoom=100
    * output:  pos=(1.234,  888.8)
    *********************************************/
   void setPixelsX_zoom()
   {
      // setup
      Position pos;
      pos.x = 999.9;
      pos.y = 888.8;
      pos.metersFromPixels = 100;
      
      // exercise
      pos.setPixelsX(123.4);
      
      // verify
      assertEquals(pos.x, 1.234);
      assertEquals(pos.y, 888.8);
   } // teardown
   
   /*********************************************
    * name:    SET METERS Y NO ZOOM
    * input:   pos=(999.9, 888.8) y=123.4 zoom=1
    * output:  pos=(999.9, 123.4)
    *********************************************/
   void setPixelsY_noZoom()
   {
      // setup
      Position pos;
      pos.x = 999.9;
      pos.y = 888.8;
      pos.metersFromPixels = 1;
      
      // exercise
      pos.setPixelsY(123.4);
      
      // verify
      assertEquals(pos.x, 999.9);
      assertEquals(pos.y, 123.4);
   } // teardown

   /*********************************************
    * name:    SET METERS Y ZOOM
    * input:   pos=(999.9, 888.8) y=123.4 zoom=100
    * output:  pos=(999.9, 1.234)
    *********************************************/
   void setPixelsY_zoom()
   {
      // setup
      Position pos;
      pos.x = 999.9;
      pos.y = 888.8;
      pos.metersFromPixels = 100;
      
      // exercise
      pos.setPixelsY(123.4);
      
      // verify
      assertEquals(pos.x, 999.9);
      assertEquals(pos.y, 1.234);
   }

   /*********************************************
    * name:    ADD METERS X
    * input:   pos=(4500,2500) x=123.4 
    * output:  pos=(4623.4,2500)
    *********************************************/
   void addMetersX()
   {
      // setup
      Position pos;
      pos.x = 4500.0;
      pos.y = 2500.0;
      
      // exercise
      pos.addMetersX(123.4);
      
      // verify
      assertEquals(pos.x, 4623.4);
      assertEquals(pos.y, 2500.0);
   } // teardown

   /*********************************************
    * name:    ADD METERS Y
    * input:   pos=(4500,2500) y=123.4
    * output:  pos=(4500,2623.4)
    *********************************************/
   void addMetersY()
   {
      // setup
      Position pos;
      pos.x = 4500.0;
      pos.y = 2500.0;
      
      // exercise
      pos.addMetersY(123.4);
      
      // verify
      assertEquals(pos.x, 4500.0);
      assertEquals(pos.y, 2623.4);
   }

   /*********************************************
    * name:    ADD METERS X ZERO ZOOM
    * input:   pos=(4500,2500) x=3pixels zoom=1.0
    * output:  pos=(4503,2500)
    *********************************************/
   void addPixelsX_noZoom()
   {
      // setup
      Position pos;
      pos.x = 4500.0;
      pos.y = 2500.0;
      pos.metersFromPixels = 1.0;
      
      // exercise
      pos.addPixelsX(3.0);
      
      // verify
      assertEquals(pos.x, 4503.0);
      assertEquals(pos.y, 2500.0);
   }

   /*********************************************
    * name:    ADD METERS X ZERO ZOOM
    * input:   pos=(4500,2500) x=3pixels zoom=50.0
    * output:  pos=(4650, 2500)
    *********************************************/
   void addPixelsX_zoom()
   {
      // setup
      Position pos;
      pos.x = 4500.0;
      pos.y = 2500.0;
      pos.metersFromPixels = 50.0;
      
      // exercise
      pos.addPixelsX(3.0);
      
      // verify
      assertEquals(pos.x, 4650.0);
      assertEquals(pos.y, 2500.0);
   }

   /*********************************************
    * name:    ADD METERS Y ZERO ZOOM
    * input:   pos=(4500,2500) y=3pixels zoom=1.0
    * output:  pos=(4500,2503)
    *********************************************/
   void addPixelsY_noZoom()
   {
      // setup
      Position pos;
      pos.x = 4500.0;
      pos.y = 2500.0;
      pos.metersFromPixels = 1.0;
      
      // exercise
      pos.addPixelsY(3.0);
      
      // verify
      assertEquals(pos.x, 4500.0);
      assertEquals(pos.y, 2503.0);
   }

   /*********************************************
    * name:    ADD METERS Y ZERO ZOOM
    * input:   pos=(4500,2500) y=3pixels zoom=50.0
    * output:  pos=(4500,2650)
    *********************************************/
   void addPixelsY_zoom()
   {
      // setup
      Position pos;
      pos.x = 4500.0;
      pos.y = 2500.0;
      pos.metersFromPixels = 50.0;
      
      // exercise
      pos.addPixelsY(3.0);
      
      // verify
      assertEquals(pos.x, 4500.0);
      assertEquals(pos.y, 2650.0);
   }

   /*********************************************
    * name:    SET ZOOM : member variable
    * input:   pos.metersFromPixels = 99.9, setZoom(123.4)
    * output:  pos.metersFromPixels=123.4
    *          Position::metersFromPixels=123.4
    *********************************************/
   void setZoom_member()
   {
      // setup
      Position pos;
      pos.metersFromPixels = 99.9;
      
      // exercise
      pos.setZoom(123.4);
      
      // verify
      assertEquals(pos.metersFromPixels, 123.4);
      assertEquals(Position::metersFromPixels, 123.4);
   }

   /*********************************************
    * name:    SET ZOOM : another variable
    * input:   pos1.metersFromPixels=99.9
    *          pos2.metersFromPixels=88.9
    *          pos2.setZoom(123.4)
    * output:  pos1.metersFromPixels=123.4
    *          pos2.metersFromPixels=123.4
    *          Position::metersFromPixels=123.4
    *********************************************/
   void setZoom_anotherVariable()
   {
      // setup
      Position pos1;
      pos1.metersFromPixels = 99.9;
      
      Position pos2;
      pos2.metersFromPixels = 99.9;
      
      // exercise
      pos1.setZoom(123.4);
      pos2.setZoom(123.4);
      
      // verify
      assertEquals(pos1.metersFromPixels, 123.4);
      assertEquals(pos2.metersFromPixels, 123.4);
      assertEquals(Position::metersFromPixels, 123.4);
   }

   // Double classes to test Position and avoid testing Velocity

   // Note that Velocity0 ALWAYS returns v=(0.0,0.0)
   class Velocity0 : public VelocityDummy
   {
      double getDX()  const { return 0.0; }
      double getDY()  const { return 0.0; }
   };

   // Note that Velocity54 ALWAYS returns v=(0.5,0.4)
   class Velocity54 : public VelocityDummy
   {
      double getDX()  const { return 0.5; }
      double getDY()  const { return 0.4; }
   };

   // Double classes to test Position and avoid testing Acceleration

   // Note that Acceleration0 ALWAYS returns a=(0.0,0.0)
   class Acceleration0 : public AccelerationDummy
   {
      double getDDX() const { return 0.0; }
      double getDDY() const { return 0.0; }
   };

   // Note that Acceleration23 ALWAYS returns a=(0.2,0.3)
   class Acceleration23 : public AccelerationDummy
   {
      double getDDX() const { return 0.2; }
      double getDDY() const { return 0.3; }
   };


   /*********************************************
    * name:    ADD update position when not moving and not accelerating
    * input:   pos=(11.1, 22.2) acc=(0,0), vel=(0,0) t=1
    * output:  pos=(11.1, 22.2)
    *********************************************/
   void add_stationary()
   {
      // setup
      Position pos;
      pos.x = 11.1;
      pos.y = 22.2;
      
      Acceleration a(0.0, 0.0);
      Velocity v(0.0, 0.0);
      
      // exercise
      pos.add(a, v, 1.0);
      
      // verify
      assertEquals(pos.x, 11.1);
      assertEquals(pos.y, 22.2);
   } // teardown

   /*********************************************
    * name:    ADD update position when moving but not accelerating
    * input:   pos=(11.1,22.2) acc=(0,0), vel=(0.5,0.4) t=1
    * output:  pos.x = 11.6 = 11.1 + 0.5*1
    *          pos.y = 22.6 = 22.2 + 0.4*1
    *********************************************/
   void add_moving()
   {
      // setup
      Position pos;
      pos.x = 11.1;
      pos.y = 22.2;
      
      Acceleration a(0.0, 0.0);
      Velocity54 v;
      
      // exercise
      pos.add(a, v, 1.0);
      
      // verify
      assertEquals(pos.x, 11.6);
      assertEquals(pos.y, 22.6);
   } // teardown

   /*********************************************
    * name:    ADD update position when moving longer (2 seconds) but not accelerating
    * input:   pos=(11.1,22.2) acc=(0,0), vel=(0.5,0.4) t=2
    * output:  pos.x = 12.1 = 11.1 + 0.5*2
    *          pos.y = 23.0 = 22.2 + 0.4*2
    *********************************************/
   void add_movingLonger()
   {
      // setup
      Position pos;
      pos.x = 11.1;
      pos.y = 22.2;
      
      Acceleration a(0.0, 0.0);
      Velocity54 v;
      
      // exercise
      pos.add(a, v, 2.0);
      
      // verify
      assertEquals(pos.x, 12.1);
      assertEquals(pos.y, 23.0);
   } // teardown

   /*********************************************
    * name:    ADD update position when accelerating but not moving
    * input:   pos=(11.1,22.2) acc=(0.2,0.3), vel=(0,0) t=1
    * output:  pos.x = 11.20 = 11.1 + 1/2 .2 1^2
    *          pos.y = 22.35 = 22.2 + 1/2 .3 1^2
    *********************************************/
   void add_fromStop()
   {
      // setup
      Position pos;
      pos.x = 11.1;
      pos.y = 22.2;
      
      Acceleration23 a;
      Velocity0 v;
      
      // exercise
      pos.add(a, v, 1.0);
      
      // verify
      assertEquals(pos.x, 11.20);
      assertEquals(pos.y, 22.35);
   } // teardown

   /*********************************************
    * name:    ADD update position when accelerating longer (2 seconds)
    * input:   pos=(11.1,22.2) acc=(0.2,0.3), vel=(0,0) t=2
    * output:  pos.x = 11.5 = 11.1 + 1/2 .2 2^2
    *          pos.y = 22.8 = 22.2 + 1/2 .3 2^2
    *********************************************/
   void add_fromStopLonger()
   {
      // setup
      Position pos;
      pos.x = 11.1;
      pos.y = 22.2;
      
      Acceleration23 a;
      Velocity0 v;
      
      // exercise
      pos.add(a, v, 2.0);
      
      // verify
      assertEquals(pos.x, 11.5);
      assertEquals(pos.y, 22.8);
   } // teardown

   /*********************************************
    * name:    ADD update position when both moving and accelerating for 2 seconds
    * input:   pos=(11.1,22.2) acc=(0.2,0.3), vel=(0.5,0.4) t=2
    * output:  pos.x = 12.5 = 11.1 + 0.5*2 + 1/2 .2 2^2
    *          pos.y = 23.6 = 22.2 + 0.4*2 + 1/2 .3 2^2
    *********************************************/
   // update position when both moving and accelerating for 2 seconds
   void add_complex()
   {  // SETUP
      Position       pos;
      Velocity54     vel;
      Acceleration23 acc;
      double         time(2.0);
      pos.x = 11.1;
      pos.y = 22.2;

      // EXERCISE
      pos.add(acc, vel, time);

      // VERIFY
      assertEquals(pos.x, 12.5);
      assertEquals(pos.y, 23.6);
   }  // TEARDOWN



};
