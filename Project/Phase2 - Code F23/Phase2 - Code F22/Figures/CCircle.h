#ifndef CCIRC_H
#define CCIRC_H
#include "CFigure.h"
class CCircle:public CFigure
{
private:
	Point center;
	Point edge;
public:
	CCircle(Point, Point, GfxInfo);

	virtual void Draw(Output*)const;

};

#endif