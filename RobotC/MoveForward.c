//-------------------------------Telepresence Robot----------------------------------------
//---------------------------------Raja T. Rashid------------------------------------------
//-----------------------------------CSCI 6609---------------------------------------------
//---------------------------------MoveForward.c-------------------------------------------
//This program moves the NXT TeleP Bot forwards until you stop it.
//If not stopped, the bot goes forward in straight line for at least 12 feet
//It uses the ROBOTC 4.x variables and constructs.
//

typedef struct
{
	float  X;
	float  Y;
	float  heading;    // Radians
} tLocation;

tLocation target;
tLocation currPos;
tLocation maxDeviation;

int motorPower   = 50;
const int k_h    = 5; //Kludege

//Set the location to zero for starters

void zeroLocation(tLocation &theLocation)
{
	theLocation.X = 0;
	theLocation.Y = 0;
	theLocation.heading = 0;
}

void calculateHeadingAndDistance()
{
	tLocation delta;
	float DesiredDistance;
	float DesiredHeading;
	float headingErr;
	int   nPowerAdjust;

	delta.Y = target.Y - currPos.Y;
	delta.X = target.X - currPos.X;
	DesiredDistance = sqrt(delta.Y*delta.Y + delta.X*delta.X);
  if (delta.X == 0)
  	DesiredHeading = 0;
  else
  	DesiredHeading = atan(delta.Y / delta.X);
  headingErr    = DesiredHeading - currPos.heading;
  nPowerAdjust  = headingErr * k_h * DesiredDistance;
  
  return;
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

//calculateCurrentPosition()
//
// Background task that runs around calculating the current location based
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

		distance = (deltaLeft + deltaRight) / (float) 4.0;
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


//--------------------------------------Main Program----------------------------------------

task main()
{
  //
  // These variables are declared as RAM values. 

  //
  int nMoveSize     = 360 * 5;    // Ten rotations
  int nSpeed        = 40;
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
  //                   -100% -- reversed direct and same speed as primary
  //
  nSyncedMotors            = kSyncType;  // "C" will be synchronized to "A".
  nSyncedTurnRatio         = nTurnRatio;
  nPidUpdateInterval    = 10;   // Best performance if we do really frequent updates
                                     // (i.e. calculation) on the motor speeds to correct
                                     // for errors.
  for (nCount = 0; nCount < 10; ++nCount)
  {
    //
    // Move the motors forward 10 revolution of "A"
    //
    nMotorEncoderTarget[kPrimaryMotor] = nMoveSize; // incremental amount to move motor
    motor[kPrimaryMotor]               = nSpeed;    // motor speed
    while (    (nMotorRunState[kPrimaryMotor] != runStateIdle)
    				&& (nMotorRunState[kPrimaryMotor] != runStateHoldPosition))
    {}

  }
}
