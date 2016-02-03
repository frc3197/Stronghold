#ifndef AUTODRIVEDEFENSE_H
#define AUTODRIVEDEFENSE_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutoDriveDefense: public CommandBase
{
private:
	int num = 0;

public:
	AutoDriveDefense();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
