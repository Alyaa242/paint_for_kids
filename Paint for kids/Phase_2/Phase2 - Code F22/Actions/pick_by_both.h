#pragma once
#include "../Actions/Action.h"
#include"../Figures/CFigure.h"


class pick_by_both:public Action
{
	int sel;
	string* figlist;
	Point p;
	int counterTrue = 0, counterFlase = 0;
	int randfig;
	bool stop = false;
	CFigure* fig;
public:
	pick_by_both(ApplicationManager* Ap);
	void ReadActionParameters();
	virtual void undo();
	virtual void redo();
	virtual bool isRecordable();
	void Execute();
	~pick_by_both();
};

