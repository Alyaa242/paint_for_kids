#ifndef CHEX_H
#define CHEX_H
#include"CFigure.h"
class CHexagon:public CFigure
{
private:
	Point center;
public:
	CHexagon(Point, GfxInfo);
	virtual void Draw(Output*)const;
};

#endif
