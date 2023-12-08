#ifndef CHEX_H
#define CHEX_H
#include"CFigure.h"
class CHexagon:public CFigure
{
private:
	Point center;
public:
	CHexagon(int,Point, GfxInfo);
	CHexagon();
	virtual void Draw(Output*)const;
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
};

#endif
