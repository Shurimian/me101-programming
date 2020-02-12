// Chamath Wijesekera - ME 101
// Cleaning the ION Platform


// It's a mess, incomplete.

void configureAllSensors();

const MAX_WAIT_TIME = 15 * 60 * 1000;
const WHEEL_RADIUS = 5;

void goDist(distance)
{
	int direction = 1;
	if (distance < 0)
	{
		direction = -direction;
	}
	nMotorEncoder = 0;
	motor[motorA] = motor[motorD] = 30 * direction;

	while (direction * nMotorEncoder < direction * distance * 180 / (PI * WHEEL_RADIUS))
	{}

	motor[motorA] = motor[motorD] = 0;
}

void turn(angle)
{
	resetGyro(S1);
	motor[motorA] = -30;
	motor[motorD] =  30;

	while (SensorValue[S1] < angle)
	{}

	motor[motorA] = motor[motorD] = 0;
}

void doSquare()
{
	for (int sides = 0; sides < 4; sides++)
	{
		goDist(800);
		turn(90);
	}
}

task main()
{
	configureAllSensors();

	while (SensorValue[S2] > 20 && time1[T1] < MAX_WAIT_TIME)
	{
			while (SensorValue[S4] == 30)
			{}

			goDist(-90);

			delay(10000);

			while (SensorValue[S3] == 40)
			{}

			goDist(90);

			motor[motorB] = 100;

			doSquare();

			motor[motorB] = 0;

	}
}
