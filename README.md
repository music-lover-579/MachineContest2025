# MachineContest2025

A repository for the machine code of the 15th SJTU *Liming Cup* Mechanical Innovation Competition for Freshmen.

## Table of Contents

- [Overview](#overview)
- [Program Structure](#program-structure)
- [Hardware Design](#hardware-design)
- [Current Progress](#current-progress)
- [Lessons Learned](#lessons-learned)
- [Future Work](#future-work)
- [License](#license)

## Overview

This project controls a multifunctional robot with mecanum wheels, servo-controlled arms, and a stepper motor, operated via a PS2X controller. The code runs on an Arduino MEGA 2560.

## Program Structure

- ```MachineContest2025.ino```: **Main** program.
  
  ```cpp
  PS2X ps2x; // The PS2X controller class
  Arm arm; // The arm class, contains three servos

  void setup(); // Initialization function
  void loop(); // Main program loop
  ```

- ```Globals.h```, ```Globals.cpp```: **Global** stuff.
  
  ```cpp
  // 1-bit data type definitions
  typedef unsigned char UByte;
  typedef signed char Byte;

  // PS2X controller pins
  // PS2X controller buttons
  // Wheel motor pins
  // Servo pins
  // Servo angles
  // Servo status bitmask
  // Stepper motor steps
  
  #define TRUNCATE(x, MIN, MAX); // Macro function for truncating x into a range [MIN, MAX]
  
  // Motor speed structure
  struct MotorSpeed {
    int LF;
    int RF;
    int LB;
    int RB;
  };

  // Servo angle structure
  struct ServoAngle {
    int BOTTOM;
    int MIDDLE;
    int PAW;
  };

  // Arm structure
  struct Arm {
    Servo bottom;
    Servo middle;
    Servo paw;
  };

  // Initialization methods
  void InitWheels(); // Initialize the mecanum wheels
  void InitArm(Arm& arm); // Initialize the servos
  void InitStepper(); // Initialize the stepper motor
  ```

- ```Controller.h```, ```Controller.cpp```: Methods that **read** input from PS2X controller.
  
  ```cpp
  void MoveWheels(PS2X& ps2x); // Move the four mecanum wheels based on the controller input
  void MoveArm(PS2X& ps2x, Arm& arm); // Move the servos based on the controller input
  void MoveStepper(PS2X& ps2x); // Move the stepper motor based on the controller input
  void CompleteAction(PS2X& ps2x, Arm& arm); // Complete the designated actions based on the controller input (TODO)
  ```

- ```Movements.h```, ```Movements.cpp```: Methods that **implement** the movements on the machine.
  
  ```cpp
  // Basic movements
  
  void SetMotorSpeed(const MotorSpeed& speed); // Motor speed setting, range -128 ~ 127
  void IncrementServoAngle(Arm& arm, const UByte& status); // Increment the servo angle based on the button status
  void SetServoAngle(Arm& arm, const ServoAngle& angle); // Set the servo angle
  void MoveStepper(bool direction); // Move the stepper motor in the specified direction

  // Advanced movements
  // TODO
  ```

- ```PS2X_lib.h```, ```PS2X_lib.cpp```: This library is imported externally.

## Hardware Design

- **Controller**: Arduino MEGA 2560  
- **Mobility**: 4 Mecanum wheels (X configuration) controlled via 2 L298N boards  
- **Manipulators**: 3 servos (bottom, middle, paw) + 1 vertical stepper motor  
- **Input**: PS2X controller (with future plans for Bluetooth)

## Current Progress

- ✅ Minimal working robot code  
- ✅ Mecanum wheel movement implemented  
- ✅ Initial hardware tuning  
- ❌ Stepper motor and paw servo not fully functional  
- ❌ Movement speed needs tuning  
- ❌ Advanced movement logic incomplete  
- ❌ Switch to Bluetooth control  

## Lessons Learned

We scored 201 points in the preliminary round, which wasn’t enough to enter the finals. Despite starting just one week before the contest, we built a working prototype, tackled mechanical and software challenges, and learned a lot.

**Pro Tip**: Start early. It’s not just about avoiding last-minute panic; it gives you time to actually *optimize*.

## Future Work

- Fix stepper motor and paw servo bugs  
- Refactor movement code for speed and responsiveness  
- Implement integrated action sequences  
- Migrate control system to Bluetooth and mobile app

## License

This project is licensed under the GNU General Public License v3.0.
See the ```license.txt``` file for details.

Note: This project uses the [PS2X_lib](https://github.com/madsci1016/Arduino-PS2X) library, which is licensed under the GNU General Public License v3.0 (GPLv3).  
As a result, any distribution of this project must also comply with the terms of the GPLv3.

You can view the full license [here](https://www.gnu.org/licenses/gpl-3.0.html).
