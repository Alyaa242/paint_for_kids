#pragma once
#include "../Actions/Action.h"
#include"../Figures/CFigure.h"
#include<iostream>
using namespace std;
class pick_by_figure : public Action
{
	int sel;
	string *figlist;
	Point p;
	int counterTrue=0, counterFlase=0;
	int randfig;
	bool stop = false;
	CFigure* fig;
public:
	pick_by_figure(ApplicationManager* Ap);
	void ReadActionParameters();
	void Execute();
	virtual void undo();
	virtual void redo();

	virtual bool isRecordable();

	~pick_by_figure();
};

