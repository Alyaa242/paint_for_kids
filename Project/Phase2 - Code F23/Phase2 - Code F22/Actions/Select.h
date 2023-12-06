#pragma once
#include "Action.h"
class Select :public Action
{
private :
	Point P;

public:
	Select(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

