#ifndef SHOOTER_SUCKER_H
#define SHOOTER_SUCKER_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "OI.h"

class ShooterSucker: public CommandBase
{
private:
	Timer time;
	int num;
	int lastNum;
public:
	ShooterSucker();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif