#ifndef ADD_TRI_ACTION_H
#define ADD_TRI_ACTION_H
#include "Action.h"
#include "..\Figures\CTriangle.h"
class AddTriAction:public Action
{
private:
	
	CTriangle *triangle;
	Point P1, P2, P3;
	GfxInfo TriGfxInfo;
public:
	AddTriAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void undo();
	virtual void redo();

	virtual bool isRecordable();
};

#endif