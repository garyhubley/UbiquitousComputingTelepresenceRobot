//-------------------------------Telepresence Robot----------------------------------------
//---------------------------------Raja T. Rashid------------------------------------------
//-----------------------------------CSCI 6609---------------------------------------------
//-----------------------------------SpinTwice.c-------------------------------------------
//This program rotates the NXT TeleP Bot clockwise 180 degrees.  You get back to the same orientation you started from
//if you attempt two rotations on the fly
//This might be necessary when somebody sitting across the party currently talking to the telepresent person wants to talk.
//This would necessitate full clockwise or anticlockwise 360 degree rotation
//This program uses the ROBOTC 4.x variables and constructs.
//

#pragma platform(NXT)

task main()
{
  //
  // These variables are declared as RAM values. 
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
	  nSyncedMotors            						= synchCA;   // "C" will be synchronized to "A".
	  nSyncedTurnRatio         						= -100;      // Reversed
    nMotorEncoderTarget[motorC] 	      = 720;       // incremental amount to move motor -- two revolutions
    motor[motorC]               				= 75;        // motor speed
    while (nMotorRunState[motorC] != runStateIdle)
    {}  																						
  }
}                    
  