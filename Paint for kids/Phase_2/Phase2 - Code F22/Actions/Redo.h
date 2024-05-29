#pragma once
#include "Action.h"
class Redo :public Action
{
	Action* lastaction;
public:
	Redo(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void undo();
	virtual void redo();

	virtual bool isRecordable();
};


