#pragma config(Sensor, S4,     sonarSensor,         sensorSONAR)


//-------------------------------Telepresence Robot----------------------------------------
//---------------------------------Raja T. Rashid------------------------------------------
//-----------------------------------CSCI 6609---------------------------------------------
//---------------------------------UltraSonar.c------------------------------------------
//This program moves the NXT TeleP Bot until the distance from an obstacle is 50 cms.
//At this points the motors grind to halt and robot stops.
//Tbis program uses the ROBOTC 4.x variables and constructs.
//


task main()
{
  int dist = 50;   // Create variable 'dist' and initialize it to 50 cms.

   while(SensorValue[sonarSensor] > dist)   // While the Sonar Sensor readings are less than the specified, 'distance_in_cm':
   {
      motor[motorB] = 75;                     // Motor B is run at a 75 power level.  This distance can be increased/decreased
      motor[motorC] = 75;                     // Motor C is run at a 75 power level
   }
   motor[motorB] = 0;    // Motor B is stopped at a 0 power level
   motor[motorC] = 0;    // Motor C is stopped at a 0 power level
}
