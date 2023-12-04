#ifndef ADD_SQ_ACTION_H
#define ADD_SQ_ACTION_H
#include "Action.h"
class AddSqAction:public Action
{
private:
	Point P;
	GfxInfo SqGfxInfo;
public:
	AddSqAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

#endif