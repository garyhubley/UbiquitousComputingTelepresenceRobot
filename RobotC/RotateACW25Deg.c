//-------------------------------Telepresence Robot----------------------------------------
//---------------------------------Raja T. Rashid------------------------------------------
//-----------------------------------CSCI 6609---------------------------------------------
//------------------------------- RotateACW25Deg.c-----------------------------------------
//This program rotates the NXT TeleP Bot anti-clockwise 25 degrees.  You get back to the same orientation you started from
//if you rotate it many times.  The 25 degrees is just an approximation.
//This might be necessary when somebody sitting close to the party currently talking to the telepresent person wants to talk.
//This would necessitate appropriate anticlockwise, i.e., 25 degree rotation
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
    nMotorEncoderTarget[motorA] 	      = 80;       // incremental amount to move motor a little bit, about 25 degrees
    motor[motorA]               				= 50;        // motor speed
    while (nMotorRunState[motorA] != runStateIdle)
    {}  																						
  }
}
