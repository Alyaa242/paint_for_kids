#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"
class Delete :public Action
{
	
	CFigure* f;
public:

	Delete(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void undo();
	virtual void redo();

	virtual bool isRecordable();
};

