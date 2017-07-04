//-------------------------------Telepresence Robot----------------------------------------
//---------------------------------Raja T. Rashid------------------------------------------
//-----------------------------------CSCI 6609---------------------------------------------
//-----------------------------------------------------------------------------------------
//This program rotates the NXT TeleP Bot anti-clockwise 180 degrees.  You get back to the same orientation you started from
//if you rotate it twice
//This might be necessary when somebody sitting across the party currently talking to the telepresent person wants to talk.
//This would necessitate full anticlockwise 360 degree rotation in merely two attempts
//This program uses the ROBOTC 4.x variables and constructs.
//

#pragma platform(NXT)

task main()
{
  //
  //RAM variables
  //
  int nCount;
  const int kMaxCounts = 1;

  const tMotor         kPrimaryMotor = motorC;
  //
  // Setup the motor configuration
  //
  bFloatDuringInactiveMotorPWM = false;

  nMotorEncoder[kPrimaryMotor]       = 0;
  nMotorEncoderTarget[kPrimaryMotor] = 0;

  nPidUpdateInterval       = 10;
  //
  // Rotate about center of virtual "axle" joinging two motors.
  //   Primary motor forward
  //   Slave   motor reverse
  //
  for (nCount = 0; nCount < kMaxCounts; ++nCount)
  {
	  nSyncedMotors            						= synchAC;   // "A" will be synchronized to "C".
	  nSyncedTurnRatio         						= -100;      // AntiClockWise Rotation
    nMotorEncoderTarget[motorA] 	      = 380;       // incremental amount to move motor one rev plus some more to make it actual 360 deg
    motor[motorA]               				= 50;        // motor speed
    while (nMotorRunState[motorA] != runStateIdle)
    {}  																						// wait for action to complete
    //wait1Msec(2000);																// a little delay between actions
  }
}
