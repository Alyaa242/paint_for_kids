#pragma once
#include "Action.h"
#include "StopRecAction.h"
#include "PlayRecAction.h"

class RecordAction : public Action {
private:
	Action* recActions[20];
	int numActions;
public:
	RecordAction(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();
	virtual void undo();
	virtual void redo();

	virtual bool isRecordable();
};