#ifndef LOAD_ACTION_H
#define LOAD_ACTION_H

#include "Action.h"
#include <string>

class LoadAction :public Action
{
private:
	string FileName;
public:
	LoadAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void undo();
	virtual void redo();
	virtual bool isRecordable();

};
#endif