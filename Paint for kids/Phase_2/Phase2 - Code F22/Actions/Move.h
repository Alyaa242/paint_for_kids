#pragma once
#include"Action.h"
#include"..\Figures/CFigure.h"
#include "..\Figures\CFigure.h"
class Move :public Action
{
	Point p;
	
	Point p2;
	CFigure* fig2;
	CFigure* fig ;
public:
	Move(ApplicationManager* Ap);
	void ReadActionParameters();
	void Execute();
	virtual void undo();
	virtual void redo();

	virtual bool isRecordable();
};



