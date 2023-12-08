#ifndef CCIRC_H
#define CCIRC_H
#include "CFigure.h"
class CCircle:public CFigure
{
private:
	Point center;
	Point edge;
public:
	CCircle(int,Point, Point, GfxInfo);
	CCircle();

	virtual void Draw(Output*)const;
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);

};

#endif