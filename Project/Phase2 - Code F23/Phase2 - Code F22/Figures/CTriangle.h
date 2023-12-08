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
	CTriangle(int,Point, Point, Point, GfxInfo);
	CTriangle();
	virtual void Draw(Output*)const;
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
};

#endif