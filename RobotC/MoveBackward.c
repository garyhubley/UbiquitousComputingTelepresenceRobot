//-------------------------------Telepresence Robot----------------------------------------
//---------------------------------Raja T. Rashid------------------------------------------
//-----------------------------------CSCI 6609---------------------------------------------
//---------------------------------MoveBackWard.c------------------------------------------
//This program moves the NXT TeleP Bot backwards until you stop it.
//It uses the ROBOTC 4.x variables and constructs.
//

typedef struct
{
	float  X;
	float  Y;
	float  heading;    // Radians
} tLocation;

//tLocation target;
tLocation currPos;
tLocation maxDeviation;

//Set the location to zero
void zeroLocation(tLocation &theLocation)
{
	theLocation.X = 0;
	theLocation.Y = 0;
	theLocation.heading = 0;
}

void calculateMaxDeviation()
{
	if (maxDeviation.X < abs(currPos.X))
		maxDeviation.X = abs(currPos.X);

	if (maxDeviation.Y < abs(currPos.Y))
		maxDeviation.Y = abs(currPos.Y);

	if (maxDeviation.heading < abs(currPos.heading))
		maxDeviation.heading = abs(currPos.heading);
	return;
}

//                            calculateCurrentPosition
//
// Background task that is running around calculating the current location based
// on incremental movement during the last time period.


task calculateCurrentPosition()
{
	float distance;
	static int lastLeft = 0;
	static int lastRight = 0;
	int currLeft;
	int currRight;
	int deltaLeft;
	int deltaRight;

	//
	// One-time initialization on startup
	//
	const float kWheelDiameterInInches = 2.25;
	const float kInchesPerEncoderCount = PI * kWheelDiameterInInches / 360;
	const float kWheelBaseInInches     = 4 + 7/(float)16;

	zeroLocation(maxDeviation);

	//
	// Loop every 25 msec
	//
	while (true)
	{
		currLeft  = nMotorEncoder[motorA];
		currRight = nMotorEncoder[motorC];

		deltaLeft  = currLeft  - lastLeft;
		deltaRight = currRight - lastRight;

		lastLeft  = currLeft;
		lastRight = currRight;

		distance = (deltaLeft + deltaRight) / (float) 8.0;
		distance *= kInchesPerEncoderCount;

		currPos.heading += ((float) (deltaLeft - deltaRight)) * (kInchesPerEncoderCount / kWheelBaseInInches);
		if (currPos.heading > (2 * PI))
		  currPos.heading -= 2 * PI;
		else if (currPos.heading < -(2 * PI))
		  currPos.heading += 2 * PI;

		currPos.Y 			+= distance * sin(currPos.heading);
		currPos.X 			+= distance * cos(currPos.heading);

		calculateMaxDeviation();
		wait1Msec(50);
  }
}

//--------------------------------Main Program-----------------------------------------

task main()
{
  //
  // These variables are declared as RAM values. This will allow you, in the ROBOTC
  // interactive real-time debugger to change them and watch the effect on the motor.
  //
  int nMoveSize     = 360 * 2;    // Ten rotation
  int nSpeed        = 40;
  int nDelay        = 1000;
  int nTurnRatio    = 100;  //C has same speed as A, but opposite direction
  int nCount;

  const TSynchedMotors kSyncType     = synchAC;
  const tMotor         kPrimaryMotor = motorA;
  //
  // Setup the motor configuration
  //
  startTask(calculateCurrentPosition);
  bFloatDuringInactiveMotorPWM = false;

  nMotorEncoder[kPrimaryMotor]       = 0;
  nMotorEncoderTarget[kPrimaryMotor] = 0;

  //
  // Enable synchronization between two motors.
  //     -- motor A will be the 'primary' motor
  //     -- motor C will be the slave motor
  //     -- Turn ratio +100% -- same direction and same speed as primary
  //                      0  -- stopped
  //                   -100% -- reversed direction and same speed as primary
  //
  nSyncedMotors            = kSyncType;  // "C" will be synchronized to "A".
  nSyncedTurnRatio         = nTurnRatio;
  nPidUpdateInterval    = 10;   // Best performance if we do really frequent updates
                                     // (i.e. calculation) on the motor speeds to correct
                                     // for errors.
  for (nCount = 0; nCount < 10; ++nCount)
  {
    nMotorEncoderTarget[kPrimaryMotor] = nMoveSize; // incremental amount to move motor
    motor[kPrimaryMotor]               = -nSpeed;    // motor speed in reverse direction
    while (    (nMotorRunState[kPrimaryMotor] != runStateIdle)
    				&& (nMotorRunState[kPrimaryMotor] != runStateHoldPosition))
    {}

  }
}
