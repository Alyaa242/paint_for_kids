#include "CTriangle.h"

CTriangle::CTriangle(int id,Point P1,Point P2,Point P3,GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	ID = id;
	corner1 = P1;
	corner2 = P2;
	corner3 = P3;
}

CTriangle::CTriangle()
{
}

void CTriangle::Draw(Output* pOut)const
{
	pOut->DrawTriangle(corner1, corner2, corner3, FigGfxInfo, Selected);
}

void CTriangle::Save(ofstream& OutFile)
{
	OutFile << "TRI\t" << ID << "\t" << corner1.x << "\t" << corner1.y << "\t"
		<< corner2.x << "\t" << corner2.y << "\t" << corner3.x << "\t" << corner3.y 
		<< "\t" << GetStrClr(FigGfxInfo.DrawClr)
		<< "\t" << GetStrClr(FigGfxInfo.FillClr) << endl;
}

void CTriangle::Load(ifstream& Infile)
{
	string DrClr;
	string FlClr;
	Infile >> ID >> corner1.x >> corner1.y >> corner2.x >> corner2.y >>corner3.x>>corner3.y>> DrClr >> FlClr;
	FigGfxInfo.DrawClr = GetClrStr(DrClr);
	FigGfxInfo.FillClr = GetClrStr(FlClr);
	if (FigGfxInfo.FillClr == NULL)
		FigGfxInfo.isFilled = false;
	Selected = false;
}


