#pragma once
#include "Action.h"

class PlayRecAction :public Action {
public:

	PlayRecAction(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();

	virtual bool isRecordable();

	virtual void undo();
	virtual void redo();

};