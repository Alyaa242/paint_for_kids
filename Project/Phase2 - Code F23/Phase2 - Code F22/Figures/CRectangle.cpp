#include "CRectangle.h"

CRectangle::CRectangle(int id,Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	ID = id;
	Corner1 = P1;
	Corner2 = P2;
}

CRectangle::CRectangle()
{
}
	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}

void CRectangle::Save(ofstream& OutFile)
{

	OutFile << "RECT\t" << ID << "\t" << Corner1.x << "\t" << Corner1.y << "\t"
		<< Corner2.x << "\t" << Corner2.y << "\t" << GetStrClr(FigGfxInfo.DrawClr)
		<< "\t" << GetStrClr(FigGfxInfo.FillClr) << endl;
}

void CRectangle::Load(ifstream& Infile)
{
	string DrClr;
	string FlClr;
	Infile >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> DrClr >> FlClr;
	FigGfxInfo.DrawClr = GetClrStr(DrClr);
	FigGfxInfo.FillClr = GetClrStr(FlClr);
	if (FigGfxInfo.FillClr == NULL)
		FigGfxInfo.isFilled = false;
	Selected = false;

}
