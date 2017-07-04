#pragma config(Sensor, S3,     ,               sensorLightActive)
//#pragma config(Sensor, S4,     ,               sensorTouch)

//-------------------------------Telepresence Robot----------------------------------------
//---------------------------------Raja T. Rashid------------------------------------------
//-----------------------------------CSCI 6609---------------------------------------------
//---------------------------------Light_Sensor_Intro.c------------------------------------------
//This program moves the NXT TeleP Bot until the threshold of the light of the surface changes
//to the one not acceptable.  At this points the motors grind to halt and robot stops.  This program
//also introduces on the NXT screen all the group members who made this project possible.
//Tbis program uses the ROBOTC 4.x variables and constructs.
//

int sensorVal;  //To read and display the sensor value so that we could get the threshold
task main()
{
	//nxtDisplayStringAt(0, 60, "Telepresence Robot");
	sensorVal = SensorValue[S3];

	nxtDisplayStringAt(0, 60, "SensorValue = %d", sensorVal);
	nxtDisplayStringAt(0, 50, "------------------");
	nxtDisplayStringAt(0, 40, "Raja T. Rashid");
	nxtDisplayStringAt(0, 30, "Bhavya Srinivas");
	nxtDisplayStringAt(0, 20, "Carson Swinamer");
	nxtDisplayStringAt(0, 10, "Abdulaziz Sanni");
	//wait10Msec(1000);
	while(sensorVal > 30)
	{
		motor[motorB] = 50;
		motor[motorC] = 50;
		sensorVal = SensorValue[S3];
	}


		motor[motorB] = 0;  //Stop both motors
		motor[motorC] = 0;


}
