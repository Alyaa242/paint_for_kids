#pragma once
#include "Action.h"
class Undo :public Action
{
public:
	Undo(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void undo();
	virtual void redo();

	virtual bool isRecordable();
};

