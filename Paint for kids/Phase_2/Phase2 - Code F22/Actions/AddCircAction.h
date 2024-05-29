#ifndef ADD_CIRC_ACTION_H
#define ADD_CIRC_ACTION_H
#include "ACtion.h"
#include "..\Figures\CCircle.h"
class AddCircAction:public Action
{
private:
	
	CCircle* circ;
	Point P1, P2;
	GfxInfo CircGfxInfo;
public:
	AddCircAction(ApplicationManager* pApp);
	 
	virtual void ReadActionParameters();

	virtual void Execute();
	virtual void undo();
	virtual void redo();

	virtual bool isRecordable();

};
#endif
