#pragma config(Motor,  port1,           arriereDroit,  tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           avantDroit,    tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port3,           avantGauche,   tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port4,           brasDownGauche, tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port5,           brasDownDroite, tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port6,           brasUpGauche,  tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port7,           brasUpDroite,  tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port8,           moteurCube,    tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port9,           moteurPince,   tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port10,          arriereGauche, tmotorVex393_HBridge, openLoop)

task testMoteurRoue()
{
	motor[avantGauche]  = 70;
	wait1Msec(3000);
	motor[avantGauche]  = 0;

  motor[arriereGauche]  = 50;
  wait1Msec(3000);
	motor[arriereGauche]  = 0;

  motor[avantDroit] = 70;
  wait1Msec(3000);
	motor[avantDroit]  = 0;

  motor[arriereDroit] = 70;
  wait1Msec(3000);
	motor[arriereDroit]  = 0;
}

task move()
{
	//wait1Msec(12000);
	int joy_x;            // will hold the X value of the analog stick (choices below)
  int joy_y;            // will hold the Y value of the analog stick (choices below)
  int threshold = 5;   // helps to eliminate 'noise' from a joystick that isn't perfectly at (0,0)
	int vitesse = 1;

  while(1 == 1)
  {
  	if(vexRT[Btn5U] == 1)
  	{
  		vitesse = 2;
  	}

    joy_x = vexRT[Ch1];   // This is the RIGHT analog stick.  For LEFT, change 'Ch1' to 'Ch4'.
    joy_y = vexRT[Ch2];   // This is the RIGHT analog stick.  For LEFT, change 'Ch2' to 'Ch3'.

    if((abs(joy_x) > threshold) && (abs(joy_y) > threshold) && (joy_x > 30) && (joy_y < 50) && (joy_y > -50))
    {
    	motor[avantGauche]  = joy_x/vitesse;
      motor[arriereGauche]  = joy_x/vitesse;
      motor[avantDroit] = -joy_x/vitesse;
      motor[arriereDroit] = -joy_x/vitesse;
    }

    else if((abs(joy_x) > threshold) && (abs(joy_y) > threshold) && (joy_x < -30) && (joy_y < 50) && (joy_y > -50))
    {
    	motor[avantGauche]  = joy_x/vitesse;
      motor[arriereGauche]  = joy_x/vitesse;
      motor[avantDroit] = -joy_x/vitesse;
      motor[arriereDroit] = -joy_x/vitesse;
    }

    /*else if((abs(joy_x) > threshold) && (abs(joy_y) > threshold) && (joy_y > 90) && (joy_x < 30) && (joy_x > -30))
    {
    	motor[avantGauche]  = joy_x/vitesse;
      motor[arriereGauche]  = joy_x/vitesse;
      motor[avantDroit] = joy_x/vitesse;
      motor[arriereDroit] = joy_x/vitesse;
    }

    else if((abs(joy_x) > threshold) && (abs(joy_y) > threshold) && (joy_y < -90) && (joy_x < 30) && (joy_x > -30))
    {
    	motor[avantGauche]  = -joy_x/vitesse;
      motor[arriereGauche]  = -joy_x/vitesse;
      motor[avantDroit] = -joy_x/vitesse;
      motor[arriereDroit] = -joy_x/vitesse;
    }*/

    // Forward, and swing turns: (both abs(X) and abs(Y) are above the threshold, and Y is POSITIVE)
    else if((abs(joy_x) > threshold) && (abs(joy_y) > threshold) && (joy_y > 0))
    {
      motor[avantGauche]  = ((joy_y + joy_x)/2)/vitesse;
      motor[arriereGauche]  = ((joy_y + joy_x)/2)/vitesse;
      motor[avantDroit] = ((joy_y - joy_x)/2)/vitesse;
      motor[arriereDroit] = ((joy_y - joy_x)/2)/vitesse;
    }
    // Backwards and swing turns: (both abs(X) and abs(Y) are above the threshold, and Y is NEGATIVE)
    else if((abs(joy_x) > threshold) && (abs(joy_y) > threshold) && (joy_y < 0))
    {
      motor[avantGauche]  = ((joy_y - joy_x)/2)/vitesse;
      motor[arriereGauche]  = ((joy_y - joy_x)/2)/vitesse;
      motor[avantDroit] = ((joy_y + joy_x)/2)/vitesse;
      motor[arriereDroit] = ((joy_y + joy_x)/2)/vitesse;
    }
    // Turning in place: (abs(X) is above the threshold, abs(Y) is below the threshold)
    else if((abs(joy_x) > threshold) && (abs(joy_y) < threshold))
    {
      motor[avantGauche]  = joy_x/vitesse;
      motor[arriereGauche]  = joy_x/vitesse;
      motor[avantDroit] = (-1 * joy_x)/vitesse;
      motor[arriereDroit] = (-1 * joy_x)/vitesse;
    }
    // Standing still: (both abs(X) and abs(Y) are below the threshold)
    else
    {
      motor[avantGauche]  = 0;
      motor[arriereGauche]  = 0;
      motor[avantDroit] = 0;
      motor[arriereDroit] = 0;
    }
  }
}

task moveArm()
{
	while(true)
	{
		if(vexRT[Btn8D] == 0 && vexRT[Btn5D] == 0)
		{
			motor[brasDownDroite] = vexRT[Ch4]; // marche
			motor[brasDownGauche] = vexRT[Ch4]; // marche
			motor[brasUpDroite] = vexRT[Ch3]; // marche
			motor[brasUpGauche] = vexRT[Ch3]; // marche
		}
		if(vexRT[Btn8D] == 1 && vexRT[Btn5D] == 0)
		{
			motor[brasDownDroite] = vexRT[Ch3]*3;
			motor[brasDownGauche] = vexRT[Ch3]*3;
			motor[brasUpDroite] = vexRT[Ch3];
			motor[brasUpGauche] = vexRT[Ch3];
		}
		if(vexRT[Btn8D] == 0 && vexRT[Btn5D] == 1)
		{
			motor[brasDownDroite] = vexRT[Ch2];
			motor[brasDownGauche] = vexRT[Ch2];
			motor[brasUpDroite] = vexRT[Ch3];
			motor[brasUpGauche] = vexRT[Ch3];
		}
	}
}

task moveCube()
{
	while(true)
	{
		if(vexRT[Btn6D] == 1)	 // if Btn6D is pressed:
		{
			motor[moteurCube] = 80;
		}
		if(vexRT[Btn6U] == 1)
		{
			motor[moteurCube] = -80;
		}
		if(vexRT[Btn6D] == 0 && vexRT[Btn6U] == 0)
		{
			motor[moteurCube] = 0;
		}
	}
}

task movePince()
{
	while(true)
	{
		if(vexRT[Btn7D] == 1)	 // if Btn6D is pressed:
		{
			motor[moteurPince] = 80;
		}
		if(vexRT[Btn7L] == 1)
		{
			motor[moteurPince] = -80;
		}
		if(vexRT[Btn7D] == 0 && vexRT[Btn7L] == 0)
		{
			motor[moteurPince] = 0;
		}
	}
}



/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 User Control Task
//
// This task is used to control your robot during the user control phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task main()
{
	// User control code here, inside the loop

	while (true)
	{
	  // This is the main execution loop for the user control program. Each time through the loop
	  // your program should update motor + servo values based on feedback from the joysticks.
		//startTask(testMoteurRoue);
		startTask(move);
  	startTask(moveArm);
	  startTask(moveCube);
	  startTask(movePince);
	  //startTask(testMoteur);
	  while(true)
	  {
	  	wait1Msec(1);
	  }
	}
}
