#ifndef CSQ_H
#define CSQ_H
#include "CFigure.h"

class CSquare:public CFigure
{
private:
	Point Center;
public:
	CSquare(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	 
	 bool is_in(int ,int);
	 void PrintInfo(Output* pOut,bool);
};

#endif