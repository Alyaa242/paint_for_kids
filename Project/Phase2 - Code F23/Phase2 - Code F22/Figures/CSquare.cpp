#include "CSquare.h"
CSquare::CSquare(int id,Point P, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	ID = id;
	Center = P;
}

CSquare::CSquare()
{
}

void CSquare::Draw(Output* pOut) const
{
	pOut->DrawSquare(Center, FigGfxInfo, Selected);
}

void CSquare::Save(ofstream& OutFile)
{
	OutFile << "SQ\t" << ID << "\t" << Center.x << "\t" << Center.y << "\t"
		<< GetStrClr(FigGfxInfo.DrawClr)
		<< "\t" << GetStrClr(FigGfxInfo.FillClr) << endl;
}

void CSquare::Load(ifstream& Infile)
{
	string DrClr;
	string FlClr;
	Infile >> ID >> Center.x >> Center.y >> DrClr >> FlClr;
	FigGfxInfo.DrawClr = GetClrStr(DrClr);
	FigGfxInfo.FillClr = GetClrStr(FlClr);
	if (FigGfxInfo.FillClr == NULL)
		FigGfxInfo.isFilled = false;
	Selected = false;
}
