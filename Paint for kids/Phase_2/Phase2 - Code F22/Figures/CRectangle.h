#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
public:
	CRectangle(int, Point, Point, GfxInfo FigureGfxInfo);
	CRectangle();
	virtual void Draw(Output* pOut) const;
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& InFile);
	 bool is_in(int,int);
		 void PrintInfo(Output * pOut);
	 void PrintInfo(Output* pOut,bool);
	 void setnew(Point p);
	 Point getpoint();
};

#endif