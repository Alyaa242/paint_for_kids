#pragma once
#include "Action.h"
class DrawColorAction : public Action
{
private:
	color c;
	bool canceled;
public:
	DrawColorAction(ApplicationManager* pApp);

	//Reads color
	virtual void ReadActionParameters();

	//Change drawing color
	virtual void Execute();
};

