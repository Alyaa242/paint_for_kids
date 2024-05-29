#ifndef ADD_SQ_ACTION_H
#define ADD_SQ_ACTION_H
#include "Action.h"
#include "..\Figures\CSquare.h"
class AddSqAction:public Action
{
private:
	
	CSquare *square;
	Point P;
	GfxInfo SqGfxInfo;
public:
	AddSqAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void undo();
	virtual void redo();

	virtual bool isRecordable();
};

#endif