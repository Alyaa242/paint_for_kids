#include "CCircle.h"

CCircle::CCircle(int id,Point P1,Point P2,GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
	{
	ID = id;
	center = P1;
	edge = P2;
	}
CCircle::CCircle()
{
}
void CCircle::Draw(Output* pOut)const
{
	pOut->DrawCircle(center, edge, FigGfxInfo, Selected);
}

void CCircle::Save(ofstream& OutFile)
{
	OutFile << "CIRC\t" << ID << "\t" << center.x << "\t" << center.y << "\t"
		<< edge.x << "\t" << edge.y << "\t" << GetStrClr(FigGfxInfo.DrawClr)
		<< "\t" << GetStrClr(FigGfxInfo.FillClr) << endl;
}

void CCircle::Load(ifstream& Infile)
{
	string DrClr;
	string FlClr;
	Infile >> ID >> center.x >> center.y >> edge.x >> edge.y >> DrClr >> FlClr;
	FigGfxInfo.DrawClr = GetClrStr(DrClr);
	FigGfxInfo.FillClr = GetClrStr(FlClr);
	if (FigGfxInfo.FillClr == NULL)
		FigGfxInfo.isFilled = false;
	Selected = false;
}
