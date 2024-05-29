#pragma once
#include "Action.h"

class SwitchToDraw : public Action {

public:
	SwitchToDraw(ApplicationManager* Ap);
	void ReadActionParameters();
	void Execute();

	virtual void undo();
	virtual void redo();

	virtual bool isRecordable();


};