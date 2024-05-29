#pragma once
#include "Action.h"
#include "..\ApplicationManager.h"

class ClearAction : public Action {
private:
	
public:
	ClearAction(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();
	virtual void undo();
	virtual void redo();

	virtual bool isRecordable();

};
