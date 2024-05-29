#pragma once
#include "Action.h"
#include "..\ApplicationManager.h"

class StopRecAction :public Action {

public:

	StopRecAction(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();

	virtual bool isRecordable();

	virtual void undo();
	virtual void redo();

};