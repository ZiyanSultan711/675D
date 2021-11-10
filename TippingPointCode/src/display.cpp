#include "vex.h"
using namespace vex;

int selection = 1;
bool autonSelected = false;
int numAuto = 6;

int upSelection(void) {
  while (!autonSelected) {
    if (limitFront.value() == 1) {
      task::sleep(11);
      if (limitFront.value() == 0) {
        if (selection == numAuto) {
          selection = 1;
        } else {
          selection = selection + 1;
        }
      }
    }

    if (Controller1.ButtonRight.pressing() == true) {
      task::sleep(11);
      if (Controller1.ButtonRight.pressing() == false) {
        if (selection == numAuto) {
          selection = 1;
        } else {
          selection = selection + 1;
        }
      }
    }

    if (limitBack.value() == 1) {
      task::sleep(11);
      if (limitBack.value() == 0) {
        autonSelected = true;
      }
    }

    if (Controller1.ButtonDown.pressing() == true) {
      task::sleep(11);
      if (Controller1.ButtonDown.pressing() == false) {
        autonSelected = true;
      }
    }
  }
  return 1;
}

void startDisplayCode(void) { 
  task display(displayCode); 
}

int displayCode(void) {
  task up(upSelection);
  

  while (true) {
    {
      myBrain.Screen.clearScreen();

      myBrain.Screen.setPenColor(white);
      myBrain.Screen.setFont(fontType::mono20);
      myBrain.Screen.setCursor(1, 3);
      myBrain.Screen.print("Motor Temp:");

      myBrain.Screen.setFont(fontType::mono15);
      myBrain.Screen.setCursor(3, 1);
      myBrain.Screen.print("FL:");
      myBrain.Screen.setCursor(3, 5);
      myBrain.Screen.print(fl.temperature(temperatureUnits::celsius));

      myBrain.Screen.setFont(fontType::mono15);
      myBrain.Screen.setCursor(4, 1);
      myBrain.Screen.print("BL:");
      myBrain.Screen.setCursor(4, 5);
      myBrain.Screen.print(bl.temperature(temperatureUnits::celsius));

      myBrain.Screen.setFont(fontType::mono15);
      myBrain.Screen.setCursor(3, 12);
      myBrain.Screen.print("FR:");
      myBrain.Screen.setCursor(3, 17);
      myBrain.Screen.print(fr.temperature(temperatureUnits::celsius));

      myBrain.Screen.setFont(fontType::mono15);
      myBrain.Screen.setCursor(4, 12);
      myBrain.Screen.print("BR:");
      myBrain.Screen.setCursor(4, 17);
      myBrain.Screen.print(br.temperature(temperatureUnits::celsius));

      myBrain.Screen.setFont(fontType::mono15);
      myBrain.Screen.setCursor(6, 1);
      myBrain.Screen.print("Left Lift:");
      myBrain.Screen.setCursor(6, 17);
      myBrain.Screen.print(lift2.temperature(temperatureUnits::celsius));

      myBrain.Screen.setFont(fontType::mono15);
      myBrain.Screen.setCursor(7, 1);
      myBrain.Screen.print("Right Lift:");
      myBrain.Screen.setCursor(7, 17);
      myBrain.Screen.print(lift.temperature(temperatureUnits::celsius));

      myBrain.Screen.setFont(fontType::mono15);
      myBrain.Screen.setCursor(8, 1);
      myBrain.Screen.print("Claw:");
      myBrain.Screen.setCursor(8, 17);
      myBrain.Screen.print(arm.temperature(temperatureUnits::celsius));

      myBrain.Screen.setFont(fontType::mono15);
      myBrain.Screen.setCursor(9, 1);
      myBrain.Screen.print("Mogo Lift:");
      myBrain.Screen.setCursor(9, 17);
      myBrain.Screen.print(mogo.temperature(temperatureUnits::celsius));
    }

    if (!Competition.isAutonomous() && !Competition.isDriverControl()) //! Competition.isAutonomous() || !Competition.isDriverControl()
    {

      myBrain.Screen.setFont(fontType::mono30);
      myBrain.Screen.setCursor(1, 14);
      if (!autonSelected) {
        myBrain.Screen.print("Auton Selection:");
      } else {
        myBrain.Screen.print("Auton is Selected:");
      }

      if (selection == 1) {
        myBrain.Screen.setFillColor(red);
      }
      myBrain.Screen.setFont(fontType::mono20);
      myBrain.Screen.setCursor(3, 21);
      if (!(selection != 1 && autonSelected)) {
        if (autonSelected) {
          myBrain.Screen.setFillColor(green);
          myBrain.Screen.setPenColor(black);
        }
        myBrain.Screen.print("Auton 1");
      }
      myBrain.Screen.setFillColor(black);

      if (selection == 2) {
        myBrain.Screen.setFillColor(red);
      }
      myBrain.Screen.setFont(fontType::mono20);
      myBrain.Screen.setCursor(4, 21);
      if (!(selection != 2 && autonSelected)) {
        if (autonSelected) {
          myBrain.Screen.setFillColor(green);
          myBrain.Screen.setPenColor(black);
        }
        myBrain.Screen.print("Auton 2");
      }
      myBrain.Screen.setFillColor(black);

      if (selection == 3) {
        myBrain.Screen.setFillColor(red);
      }
      myBrain.Screen.setFont(fontType::mono20);
      myBrain.Screen.setCursor(5, 21);
      if (!(selection != 3 && autonSelected)) {
        if (autonSelected) {
          myBrain.Screen.setFillColor(green);
          myBrain.Screen.setPenColor(black);
        }
        myBrain.Screen.print("Auton 3");
      }
      myBrain.Screen.setFillColor(black);

      if (selection == 4) {
        myBrain.Screen.setFillColor(red);
      }
      myBrain.Screen.setFont(fontType::mono20);
      myBrain.Screen.setCursor(6, 21);
      if (!(selection != 4 && autonSelected)) {
        if (autonSelected) {
          myBrain.Screen.setFillColor(green);
          myBrain.Screen.setPenColor(black);
        }
        myBrain.Screen.print("Auton 4");
      }
      myBrain.Screen.setFillColor(black);

      if (selection == 5) {
        myBrain.Screen.setFillColor(red);
      }
      myBrain.Screen.setFont(fontType::mono20);
      myBrain.Screen.setCursor(7, 21);
      if (!(selection != 5 && autonSelected)) {
        if (autonSelected) {
          myBrain.Screen.setFillColor(green);
          myBrain.Screen.setPenColor(black);
        }
        myBrain.Screen.print("Auton 5");
      }
      myBrain.Screen.setFillColor(black);

      if (selection == 6) {
        myBrain.Screen.setFillColor(red);
      }
      myBrain.Screen.setFont(fontType::mono20);
      myBrain.Screen.setCursor(8, 21);
      if (!(selection != 6 && autonSelected)) {
        if (autonSelected) {
          myBrain.Screen.setFillColor(green);
          myBrain.Screen.setPenColor(black);
        }
        myBrain.Screen.print("Auton 6");
      }
      myBrain.Screen.setFillColor(black);
    }
    else{
      autonSelected = true;
    }

    myBrain.Screen.waitForRefresh();

    Controller1.Screen.setCursor(4, 1);
    Controller1.Screen.print("Selection:");

    Controller1.Screen.setCursor(4, 12);
    Controller1.Screen.print(selection);

  }

  return 1;
}