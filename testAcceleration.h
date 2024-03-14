/***********************************************************************
 * Header File:
 *    TEST ACCELERATION
 * Author:
 *    <your name here>
 * Summary:
 *    Unit tests for the Acceleration class.
 ************************************************************************/

#pragma once

#include "unitTest.h"
#include "acceleration.h"
#include "angle.h"
#define _USE_MATH_DEFINES
#include <math.h>

/*********************************************
 * TEST ACCELERATION
 * Unit tests for Acceleration
 *********************************************/
class TestAcceleration : public UnitTest
{
public:
   void run()
   {
      // Ticket 3: Without Add
      constructor_default();
      constructor_nonDefault();
      getDDX();
      getDDY();
      setDDX();
      setDDY();
      set_up();
      set_down();
      set_left();
      set_right();
      set_diagonal();

      // Ticket 4: Add
      addDDX_zero();
      addDDX_value();
      addDDY_zero();
      addDDY_value();
      add_zeroZero();
      add_valueZero();
      add_zeroValue();
      add_valueValue();

      report("Acceleration");
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
    * output:  zeros
    *********************************************/
   void constructor_default()
   {  // setup
      // exercise
      Acceleration a;

      // verify
      assertEquals(a.ddx, 0.0);
      assertEquals(a.ddy, 0.0);
   }  // teardown
      
   /*********************************************
    * name:    NON-DEFAULT CONSTRUCTOR
    * input:   2.3, 4.5
    * output:  (2.3, 4.5)
    *********************************************/
   void constructor_nonDefault()
   {  // setup
      double ddx = 2.3;
      double ddy = 4.5;
      // exercise
      Acceleration a(ddx, ddy);

      // verify
      assertEquals(a.ddx, 2.3);
      assertEquals(a.ddy, 4.5);
      assertEquals(ddx, 2.3);
      assertEquals(ddy, 4.5);
   }  // teardown


   /*****************************************************************
    *****************************************************************
    * GETTERS
    *****************************************************************
    *****************************************************************/


   /*********************************************
    * name:    GET DDX
    * input:   (2.3, 4.5)
    * output:  2.3
    *********************************************/
   void getDDX()
   {  // setup
      Acceleration a;
      a.ddx = 2.3;
      a.ddy = 4.5;
      double ddx = 99.9;

      // exercise
      ddx = a.getDDX();

      // verify
      assertEquals(a.ddx, 2.3);
      assertEquals(a.ddy, 4.5);
      assertEquals(ddx,2.3);
   }  // teardown

   /*********************************************
    * name:    GET DDY
    * input:   (2.3, 4.5)
    * output:  4.5
    *********************************************/
   void getDDY()
   {  // setup
      Acceleration a;
      a.ddx = 2.3;
      a.ddy = 4.5;
      double ddy = 99.9;

      // exercise
      ddy = a.getDDY();

      // verify
      assertEquals(a.ddx, 2.3);
      assertEquals(a.ddy, 4.5);
      assertEquals(ddy, 4.5);
   }  // teardown


   /*****************************************************************
    *****************************************************************
    * SETTERS
    *****************************************************************
    *****************************************************************/

   /*********************************************
    * name:    SET DDX
    * input:   (-99.9, -88.8) 11.1
    * output:  (11.1, -88.8)
    *********************************************/
   void setDDX()
   {  // setup
      Acceleration a;
      a.ddx = -99.9;
      a.ddy = -88.8;
      
      // exercise
      a.setDDX(11.1);

      // verify
      assertEquals(a.ddx, 11.1);
      assertEquals(a.ddy, -88.8);
   }

   /*********************************************
    * name:    SET DDX
    * input:   (-99.9, -88.8) 11.1
    * output:  (-99.9, 11.1)
    *********************************************/
   void setDDY()
   {  // setup
      Acceleration a;
      a.ddx = -99.9;
      a.ddy = -88.8;

      // exercise
      a.setDDY(11.1);

      // verify
      assertEquals(a.ddx, -99.9);
      assertEquals(a.ddy, 11.1);
   }

   /*********************************************
    * name:    SET UP
    * input:   (-99.9, -88.8) 0 degrees, 3.3
    * output:  (0.0, 3.3)
    *********************************************/
   void set_up()
   {  // setup
      Acceleration a;
      a.ddx = -99.9;
      a.ddy = -88.8;
      Angle angle;
      angle.radians = 0.0; // up
      double magnitude = 3.3;

      // exercise
      a.set(angle, magnitude);

      // verify
      assertEquals(a.ddx, 0.0);
      assertEquals(a.ddy, 3.3);
      assertEquals(angle.radians, 0.0);
      assertEquals(magnitude, 3.3);
   }
   
   /*********************************************
    * name:    SET DOWN
    * input:   (-99.9, -88.8) 180 degrees, 3.3
    * output:  (0.0, -3.3)
    *********************************************/
   void set_down()
   {  // setup
      Acceleration a;
      a.ddx = -99.9;
      a.ddy = -88.8;
      Angle angle;
      angle.radians = M_PI; // DOWN
      double magnitude = 3.3;

      // exercise
      a.set(angle, magnitude);

      // verify
      assertEquals(a.ddx, 0.0);
      assertEquals(a.ddy,-3.3);
      assertEquals(angle.radians, M_PI);
      assertEquals(magnitude, 3.3);
   }

   /*********************************************
    * name:    SET RIGHT
    * input:   (-99.9, -88.8) 90 degrees, 3.3
    * output:  (3.3, 0.0)
    *********************************************/
   void set_right()
   {  // setup
      Acceleration a;
      a.ddx = -99.9;
      a.ddy = -88.8;
      Angle angle;
      angle.radians = M_PI_2; // RIGHT
      double magnitude = 3.3;

      // exercise
      a.set(angle, magnitude);

      // verify
      assertEquals(a.ddx, 3.3);
      assertEquals(a.ddy, 0.0);
      assertEquals(angle.radians, M_PI_2);
      assertEquals(magnitude, 3.3);
   }
   
   /*********************************************
    * name:    SET LEFT
    * input:   (-99.9, -88.8) 270 degrees, 3.3
    * output:  (3.3, 0.0)
    *********************************************/
   void set_left()
   {  // setup
      Acceleration a;
      a.ddx = -99.9;
      a.ddy = -88.8;
      Angle angle;
      angle.radians = M_PI_2 + M_PI; // RIGHT
      double magnitude = 3.3;

      // exercise
      a.set(angle, magnitude);

      // verify
      assertEquals(a.ddx, -3.3);
      assertEquals(a.ddy, 0.0);
      assertEquals(angle.radians, M_PI_2 + M_PI);
      assertEquals(magnitude, 3.3);
   }
   
   /*********************************************
    * name:    SET DIAGONAL
    * input:   (-99.9, -88.8) 57 degrees, 1.0
    * output:  (0.84, 0.54)
    *********************************************/
   void set_diagonal()
   {  // setup
      Acceleration a;
      a.ddx = -99.9;
      a.ddy = -88.8;
      Angle angle;
      angle.radians = 1.0; // up and right somewhat
      double magnitude = 1.0;

      // exercise
      a.set(angle, magnitude);

      // verify
      assertEquals(a.ddx, 0.8414);
      assertEquals(a.ddy, 0.5403);
      assertEquals(angle.radians, 1.0);
      assertEquals(magnitude,1.0);
   }
   
   /*****************************************************************
    *****************************************************************
    * SETTERS
    *****************************************************************
    *****************************************************************/

   /*********************************************
    * name:    ADD DDX ZERO
    * input:   a=(2.3, 4.5) ddx=0.0
    * output:  a=(2.3, 4.5)
    *********************************************/
   void addDDX_zero()
   {
      // setup
      Acceleration a;
      a.ddx = 2.3;
      a.ddy = 4.5;
      double ddx = 0.0;
      
      // exercise
      a.addDDX(ddx);
      
      // verify
      assertEquals(a.ddx, 2.3);
      assertEquals(a.ddy, 4.5);
   } // teardown
   
   /*********************************************
    * name:    ADD DDX 4.1
    * input:   a=(2.3, 4.5) ddx=4.1
    * output:  a=(6.4, 4.5)
    *********************************************/
   void addDDX_value()
   {
      // setup
      Acceleration a;
      a.ddx = 2.3;
      a.ddy = 4.5;
      double ddx = 4.1;
      
      // exercise
      a.addDDX(ddx);
      
      // verify
      assertEquals(a.ddx, 6.4);
      assertEquals(a.ddy, 4.5);
   } // teardown

   /*********************************************
    * name:    ADD DDY ZERO
    * input:   a=(2.3, 4.5) ddy=0.0
    * output:  a=(2.3, 4.5)
    *********************************************/
   void addDDY_zero()
   {
      // setup
      Acceleration a;
      a.ddx = 2.3;
      a.ddy = 4.5;
      double ddy = 0.0;
      
      // exercise
      a.addDDY(ddy);
      
      // verify
      assertEquals(a.ddx, 2.3);
      assertEquals(a.ddy, 4.5);
   } // teardown

   /*********************************************
    * name:    ADD DDY 4.1
    * input:   a=(2.3, 4.5) ddy=4.1
    * output:  a=(2.3, 8.6)
    *********************************************/
   void addDDY_value()
   {
      // setup
      Acceleration a;
      a.ddx = 2.3;
      a.ddy = 4.5;
      double ddy = 4.1;
      
      // exercise
      a.addDDY(ddy);
      
      // verify
      assertEquals(a.ddx, 2.3);
      assertEquals(a.ddy, 8.6);
   } // teardown

   /*********************************************
    * name:    ADD NOTHING TO NOTHING
    * input:   aLHS=(0.0, 0.0) aRHS=(0.0, 0.0)
    * output:  aLHS=(0.0, 0.0)
    *********************************************/
   void add_zeroZero()
   {
      // setup
      Acceleration aLHS(0.0, 0.0);
      Acceleration aRHS(0.0, 0.0);
      
      // exercise
      aLHS.add(aRHS);
      
      // verify
      assertEquals(aLHS.ddx, 0.0);
      assertEquals(aLHS.ddy, 0.0);
      assertEquals(aRHS.ddx, 0.0);
      assertEquals(aRHS.ddy, 0.0);
   } // teardown

   /*********************************************
    * name:    ADD NOTHING TO A VALUE
    * input:   aLHS=(1.1, 2.2) aRHS=(0.0, 0.0)
    * output:  aLHS=(1.1, 2.2)
    *********************************************/
   void add_valueZero()
   {
      // setup
      Acceleration aLHS(1.1, 2.2);
      Acceleration aRHS(0.0, 0.0);
      
      // exercise
      aLHS.add(aRHS);
      
      // verify
      assertEquals(aLHS.ddx, 1.1);
      assertEquals(aLHS.ddy, 2.2);
      assertEquals(aRHS.ddx, 0.0);
      assertEquals(aRHS.ddy, 0.0);
   }

   /*********************************************
    * name:    ADD A VALUE TO NOTHING
    * input:   aLHS=(0.0, 0.0) aRHS=(4.4, 7.7)
    * output:  aLHS=(4.4, 7.7)
    *********************************************/
   void add_zeroValue()
   {
      // setup
      Acceleration aLHS(0.0, 0.0);
      Acceleration aRHS(4.4, 7.7);
      
      // exercise
      aLHS.add(aRHS);
      
      // verify
      assertEquals(aLHS.ddx, 4.4);
      assertEquals(aLHS.ddy, 7.7);
      assertEquals(aRHS.ddx, 4.4);
      assertEquals(aRHS.ddy, 7.7);
   } // teardown

   /*********************************************
    * name:    ADD A VALUE TO ANOTHER VALUE
    * input:   aLHS=(1.1, 2.2) aRHS=(4.4, 7.7)
    * output:  aLHS=(5.5, 9.9)
    *********************************************/
   void add_valueValue()
   {
      // setup
      Acceleration aLHS(1.1, 2.2);
      Acceleration aRHS(4.4, 7.7);
      
      // exercise
      aLHS.add(aRHS);
      
      // verify
      assertEquals(aLHS.ddx, 5.5);
      assertEquals(aLHS.ddy, 9.9);
      assertEquals(aRHS.ddx, 4.4);
      assertEquals(aRHS.ddy, 7.7);

   } // teardown

};
