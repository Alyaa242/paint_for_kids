#ifndef ADD_RECT_ACTION_H
#define ADD_RECT_ACTION_H

#include "Action.h"
#include "..\Figures\CRectangle.h"
//Add Rectangle Action class
class AddRectAction: public Action
{
private:
	
	CRectangle* rect;
	Point P1, P2; //Rectangle Corners
	GfxInfo RectGfxInfo;
public:
	AddRectAction(ApplicationManager *pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();
	
	//Add rectangle to the ApplicationManager
	virtual void Execute() ;
	virtual void undo();
	virtual void redo();

	virtual bool isRecordable();
	
};

#endif