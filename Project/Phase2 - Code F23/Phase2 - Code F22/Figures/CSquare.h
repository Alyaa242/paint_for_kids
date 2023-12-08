#ifndef CSQ_H
#define CSQ_H
#include "CFigure.h"

class CSquare:public CFigure
{
private:
	Point Center;
public:
	CSquare(int,Point, GfxInfo FigureGfxInfo);
	CSquare();
	virtual void Draw(Output* pOut) const;
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);

};

#endif