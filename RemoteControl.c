#include<stdio.h>

int ahead = 1;
int back = 2;

task main()
{

	//int right = 3;
	//int left = 4;

	int var = 0;
	scanf("%d", &var);
	while(var != 0)
	{
		if(var == ahead)
		{
			motor[motorB] = 75;
			motor[motorC] = 75;
		}
		else if(var == back)
		{
			motor[motorB] = -75;
			motor[motorC] = -75;
		}
		scanf("%d", &var);

	}

	motor[motorB] = 0;
	motor[motorC] = 0;

}
