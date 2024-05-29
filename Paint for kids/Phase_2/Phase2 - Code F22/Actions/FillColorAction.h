#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"
class FillColorAction : public Action
{
private:
	color c;
	bool canceled;	//To know if the operation is canceled
	CFigure* latestfigure;  //set selected figure in it to be able to undo latest action while figure is unselected
	GfxInfo beforeinfo;   //to keep gfx info of figure before changing  (used in undo)
	GfxInfo afterinfo;   //to keep gfx info of figure after changing (used in redo)
public:
	FillColorAction(ApplicationManager* pApp);

	//Reads color
	virtual void ReadActionParameters();

	//Change drawing color
	virtual void Execute();

	virtual void undo();
	virtual void redo();

	virtual bool isRecordable();
};

