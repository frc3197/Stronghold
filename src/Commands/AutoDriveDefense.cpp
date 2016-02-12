#include "AutoDriveDefense.h"

#define CAN_MOTOR_SLOW_SPEED -.4
#define CAN_MOTOR_FAST_SPEED -.45

AutoDriveDefense::AutoDriveDefense()
{
	Requires(autoDriveToDefense);
	Requires(chassis);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void AutoDriveDefense::Initialize()
{
	//Robot.work(please?); (don't question our motives)
	oi->gyroReset();
	chassis->ResetEncoder();
	time.Reset();
	time.Start();
}

// Called repeatedly when this Command is scheduled to run
void AutoDriveDefense::Execute()
{
	SmartDashboard::PutNumber("State", state);
	SmartDashboard::PutNumber("Gyro", oi->getAngle());
	switch(position)
	{
	case 1://low bar position 1
		switch(state)
		{
			case 1:
				if(time.Get() <= 2.5)//chassis->GetEncodeDistance() < (149.34))
				{
					chassis->tankDrive2(CAN_MOTOR_SLOW_SPEED, CAN_MOTOR_SLOW_SPEED);

				}
				else
				{
					chassis->tankDrive2(0, 0);
					state = 2;
				}
				SmartDashboard::PutNumber("case 1", 1);

			break;

			case 2:
				if(oi->getAngle() < 60)
				{
					chassis->tankDrive2(CAN_MOTOR_FAST_SPEED, -CAN_MOTOR_FAST_SPEED);
				}
				else
				{
					chassis->tankDrive2(0, 0);
					chassis->ResetEncoder();
					state = 3;
					time.Reset();
				}
				SmartDashboard::PutNumber("case 2", 2);
			break;

			case 3:
				if(time.Get() <= 2.5)//chassis->GetEncodeDistance() < 149.34 + 68.1 - 17)
				{
					chassis->tankDrive2(CAN_MOTOR_SLOW_SPEED, CAN_MOTOR_SLOW_SPEED);
				}
				else
				{
					chassis->tankDrive2(0, 0);
					finish = true;
				}
			 SmartDashboard::PutNumber("case 3", 3);
			break;

			default:

			break;
		}
	break;

	case 2://position 2
		switch(state)
		{
			case 1:
				if(chassis->GetEncodeDistance() < (137.59))
				{
					chassis->tankDrive2(CAN_MOTOR_SLOW_SPEED, CAN_MOTOR_SLOW_SPEED);
				}
				else
				{
					state = 2;
				}
			break;

			case 2:
				if(oi->getAngle() < 60)
				{
					chassis->tankDrive2(CAN_MOTOR_FAST_SPEED, -CAN_MOTOR_FAST_SPEED);
				}
				else
				{
					chassis->ResetEncoder();
					state = 3;
				}
			break;

			case 3:
				if(chassis->GetEncodeDistance() < 36.34 - 17)
				{
					chassis->tankDrive2(CAN_MOTOR_SLOW_SPEED, CAN_MOTOR_SLOW_SPEED);
				}
				else
				{
					finish = true;
				}
			break;

			default:

			break;
		}
	break;

	case 3://position 3
		switch(state)
		{
			case 1:
				if(chassis->GetEncodeDistance() <= 27.33)
				{
					chassis->tankDrive2(CAN_MOTOR_SLOW_SPEED, CAN_MOTOR_SLOW_SPEED);
				}
				else
				{
					state = 2;
				}
			break;

			case 2:
				if(oi->getAngle() <= 45)
				{
					chassis->tankDrive2(CAN_MOTOR_FAST_SPEED, -CAN_MOTOR_FAST_SPEED);
				}
				else
				{
					chassis->ResetEncoder();
					state = 3;
				}
			break;

			case 3:
				if(chassis->GetEncodeDistance() <= 54)
				{
					chassis->tankDrive2(CAN_MOTOR_SLOW_SPEED, CAN_MOTOR_SLOW_SPEED);
				}
				else
				{
					oi->gyroReset();
					state = 4;
				}
			break;

			case 4:
				if(oi->getAngle() >= -45)
				{
					chassis->tankDrive2(-CAN_MOTOR_FAST_SPEED, CAN_MOTOR_FAST_SPEED);
				}
				else
				{
					chassis->ResetEncoder();
					state = 5;
				}
			break;

			case 5:
				if(chassis->GetEncodeDistance() <= (57.3 - 17))
				{
					chassis->tankDrive2(CAN_MOTOR_SLOW_SPEED, CAN_MOTOR_SLOW_SPEED);
				}
				else
				{
					finish = true;
				}
			break;

			default:

			break;
		}
	break;

	case 4: //position 4
		switch(state)
		{
			case 1:
				if(chassis->GetEncodeDistance() <= 48.36)
				{
					chassis->tankDrive2(CAN_MOTOR_SLOW_SPEED, CAN_MOTOR_SLOW_SPEED);
				}
				else
				{
					state = 2;
				}
			break;

			case 2:
				if(oi->getAngle() >= -45)
				{
					chassis->tankDrive2(-CAN_MOTOR_FAST_SPEED, CAN_MOTOR_FAST_SPEED);
				}
				else
				{
					chassis->ResetEncoder();
					state = 3;
				}
			break;

			case 3:
				if(chassis->GetEncodeDistance() <= 24.85)
				{
					chassis->tankDrive2(CAN_MOTOR_SLOW_SPEED,CAN_MOTOR_SLOW_SPEED);
				}
				else
				{
					oi->gyroReset();
					state = 4;
				}
			break;

			case 4:
				if(oi->getAngle() <= 45)
				{
					chassis->tankDrive2(CAN_MOTOR_FAST_SPEED, -CAN_MOTOR_FAST_SPEED);
				}
				else
				{
					chassis->ResetEncoder();
					state = 5;
				}
			break;

			case 5:
				if(chassis->GetEncodeDistance() <= 57.43 - 17)
				{
					chassis->tankDrive2(CAN_MOTOR_SLOW_SPEED, CAN_MOTOR_SLOW_SPEED);
				}
				else
				{
					finish = true;
				}
			break;

			default:

			break;
		}
	break;

	case 5: //position 5
		switch(state)
		{
			case 1:
				if(chassis->GetEncodeDistance() < (154.91 - 17))
				{
					chassis->tankDrive2(CAN_MOTOR_SLOW_SPEED, CAN_MOTOR_SLOW_SPEED);
				}
				else
				{
					state = 2;
				}
			break;

			case 2:
				if(oi->getAngle() > -180 + 116.45)
				{
					chassis->tankDrive2(-CAN_MOTOR_FAST_SPEED, CAN_MOTOR_FAST_SPEED);
				}
				else
				{
					chassis->ResetEncoder();
					state = 3;
				}
			break;

			case 3:
				if(chassis->GetEncodeDistance() < 9.34)
				{
					chassis->tankDrive2(CAN_MOTOR_SLOW_SPEED, CAN_MOTOR_SLOW_SPEED);
				}
				else
				{
					finish = true;
				}
			break;

			default:

			break;
		}
	break;

	default:

	break;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool AutoDriveDefense::IsFinished()
{
	return finish;
}

// Called once after isFinished returns true
void AutoDriveDefense::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoDriveDefense::Interrupted()
{

}