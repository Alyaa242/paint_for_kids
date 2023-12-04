#ifndef ADD_TRI_ACTION_H
#define ADD_TRI_ACTION_H
#include "Action.h"
class AddTriAction:public Action
{
private:
	Point P1, P2, P3;
	GfxInfo TriGfxInfo;
public:
	AddTriAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

#endif