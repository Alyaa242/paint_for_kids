#ifndef SAVE_ACTION_H
#define SAVE_ACTION_H
#include <string>
#include "Action.h"
class SaveAction:public Action
{
private:
	string FileName;
public:
	SaveAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

#endif