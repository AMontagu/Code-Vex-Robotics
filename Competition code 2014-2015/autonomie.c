#pragma config(Motor,  port1,           arriereDroit,  tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           avantDroit,    tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port3,           avantGauche,   tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port4,           brasDownGauche, tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port5,           brasDownDroite, tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port6,           brasUpGauche,  tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port7,           brasUpDroite,  tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port8,           moteurCube,    tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port9,           moteurPince,   tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port10,          arriereGauche, tmotorVex393_HBridge, openLoop)

task main()
{
	//avancer ?

	//on serre la pince
	motor[moteurPince] = -50;
	wait1Msec(1500);
	motor[moteurPince] = 0;

	//On tourne
	motor[avantDroit] = 60;
	motor[arriereDroit] = 60;
	wait1Msec(1500);
	motor[avantDroit] = 0;
	motor[arriereDroit] = 0;

	//On reavance ?

	//On pose le cube
	motor[moteurCube] = -50;
	wait1Msec(1000);
	motor[moteurCube] = -50;

	//on lache le tube
	motor[moteurPince] = 50;
	wait1Msec(1500);
	motor[moteurPince] = 0;

	//On tourne
	motor[avantGauche] = 60;
	motor[arriereGauche] = 60;
	wait1Msec(1500);
	motor[avantGauche] = 0;
	motor[arriereDroit] = 0;
}
