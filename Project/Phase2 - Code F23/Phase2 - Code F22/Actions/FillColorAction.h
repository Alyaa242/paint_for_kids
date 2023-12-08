#pragma once
#include "Action.h"
class FillColorAction : public Action
{
private:
	color c;
public:
	FillColorAction(ApplicationManager* pApp);

	//Reads color
	virtual void ReadActionParameters();

	//Change drawing color
	virtual void Execute();
};

