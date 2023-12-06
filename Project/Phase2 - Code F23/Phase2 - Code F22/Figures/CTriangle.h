#ifndef CTRI_H
#define CTRI_H
#include "CFigure.h"

class CTriangle:public CFigure
{
private:
	Point corner1;
	Point corner2;
	Point corner3;
public:
	CTriangle(Point, Point, Point, GfxInfo);
	virtual void Draw(Output*)const;
	bool is_in(int, int);
	void PrintInfo(Output* pOut,bool);

};

#endif