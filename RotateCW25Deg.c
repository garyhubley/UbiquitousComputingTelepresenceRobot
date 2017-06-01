//-------------------------------Telepresence Robot----------------------------------------
//---------------------------------Raja T. Rashid------------------------------------------
//-----------------------------------CSCI 6609---------------------------------------------
//------------------------------- RotateCW25Deg.c-----------------------------------------
//This program rotates the NXT TeleP Bot clockwise 25 degrees.  You get back to the same orientation you started from
//if you rotate it many times.  The 25 degrees is just an approximation.
//This might be necessary when somebody sitting close to the party currently talking to the telepresent person wants to talk.
//This would necessitate appropriate clockwise, i.e., 25 degree rotation
//-------------------------------------------------------------------------------------------------------------------------
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
  // Rotate about center of virtual "axle" joining two motors.
  //   Primary motor forward
  //   Slave   motor reverse
  //
  for (nCount = 0; nCount < kMaxCounts; ++nCount)
  {
	  nSyncedMotors            						= synchCA;   // "C" will be synchronized to "A".
	  nSyncedTurnRatio         						= -100;      // Reversed
    nMotorEncoderTarget[motorC] 	      = 80;       // incremental amount to move motor -- one revolution to appx 25 deg
    motor[motorC]               				= 75;        // motor speed
    while (nMotorRunState[motorC] != runStateIdle)
    {}  																						// wait for action to complete
    //wait1Msec(2000);																// a little delay between actions
  }
}
