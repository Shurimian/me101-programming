//Assume positive motor direction is RIGHT and DOWN, negative power is LEFT and UP

void drive(int power, float distance, char dir)
{
    int dirToggle = 1;

    if (distance < 0)
    {
        dirToggle = -1;
    }
    else if (distance == 0)
    {
        dirToggle = 0;
    }

    if (dir == 'x')
    {
        nMotorEncoder[motorA] = 0;
        motor[motorA] = motor[motorC] = power*dirToggle;
        while (abs(nMotorEncoder[motorA]) < distance*dirToggle)
        {}
        motor[motorA] = motor[motorC] = 0;
    }
    else
    {
        nMotorEncoder[motorB] = 0;
        motor[motorB] = motor[motorD] = power*dirToggle;
        while (abs(nMotorEncoder[motorB]) < distance*dirToggle)
        {}
        motor[motorB] = motor[motorD] = 0;
    }
}


task main()
{
    #include "EV3_FileIO.c"

    TFileHandle command;
    bool fileOkay = openReadPC(command, "brailleMovementOutput.txt");

    const int INDENT_DIST = 50; //Tweak in calibration
    const int LINE_LIM = 20; //Tweak in calibration
    const float DIST_LIM = 80;  //Tweak in calibration
    const float CHAR_DIST = 5;
    const float SPACE_DIST = 12;
    const float LINE_DIST = 21;
    char order = ' ';
    int x = 0;
    int y = 0;
    int lineCount = 0;
    float distTravelled = 0;
    bool cont = 1;
    SensorType[S1] = sensorEV3_Touch;
    SensorType[S2] = sensorEV3_Touch;

    while (cont == 1)
    {

      //Reset y direction if page is full
      motor[motorB] = motor[motorD] = 50;
      while (SensorValue[S2] == 0)
      {}
      motor[motorB] = motor[motorD] = 0;
      pageFull = 0;

	    //Loop controls total lines travelled
	    while (lineCount < LINE_LIM)
	    {
	        //Just keep moving backwards until touch sensor registers true (x direction).
	        motor[motorA] = motor[motorC] = -50;
	        while (SensorValue[S1] == 0)
	        {}
	        motor[motorA] = motor[motorC] = 0;

	        //Move down the specific y distance needed to get to next line
	        drive(20, (LINE_DIST*lineCount + 2*CHAR_DIST), 'y');

	        distTravelled = 0;

	        //Loop controls the x distance travelled.
	        //NOTE: Currently, the code scans one set of coordinates at a time. Characters may get cut off. Testing needed
	        while (distTravelled < DIST_LIM)
	        {
	            readCharPC(command, order);
	            readIntPC(command, x);
	            readIntPC(command, y);

	            if (order == '+')
	            {
	                //This is the indent head going down
	                nMotorEncoder[motorUH] = 0;
	                motor[motorUH] = 100;
	                while (abs(nMotorEncoder[motorUH]) < INDENT_DIST)
	                {}
	                motor[motorUH] = 0;

	                wait1Msec(100);

	                //Going up
	                nMotorEncoder[motorUH] = 0;
	                motor[motorUH] = -50;
	                while (abs(nMotorEncoder[motorUH]) < INDENT_DIST)
	                {}
	                motor[motorUH] = 0;

	                //After indenting, move 2 next position
	                drive(20, (CHAR_DIST*y), 'y');
	                drive(20, (CHAR_DIST*x), 'x');
	                distTravelled += (CHAR_DIST*x);
	            }
	            else
	            {
	                //Resets the y distance
	                drive(20, (SPACE_DIST)*y, 'y');

	                //Resets x. Slightly weirder.
	                if (x == 1)
	                {
	                    drive(20, SPACE_DIST, 'x');
	                    distTravelled += SPACE_DIST;
	                }
	                else
	                {
	                    drive(20, SPACE_DIST + CHAR_DIST, 'x');
	                    distTravelled += (SPACE_DIST + CHAR_DIST);
	                }

	                if (order == '!')
	                {
	                    drive(20, SPACE_DIST + CHAR_DIST, 'x');
	                    distTravelled += (SPACE_DIST + CHAR_DIST);
	                }
	            }
	        }

        	//At the very end, raise the lineCount
        	++lineCount;
      }
    }
}
