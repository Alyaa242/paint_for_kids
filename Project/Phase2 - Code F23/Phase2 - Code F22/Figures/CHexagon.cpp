#include "CHexagon.h"

CHexagon::CHexagon(int id,Point P, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	ID = id;
	center = P;
}

CHexagon::CHexagon()
{
}

void CHexagon::Draw(Output* pOut)const
{
	pOut->DrawHexagon(center, FigGfxInfo, Selected);
}

void CHexagon::Save(ofstream& OutFile)
{
	OutFile << "HEX\t" << ID << "\t" << center.x << "\t" << center.y << "\t"
		<< GetStrClr(FigGfxInfo.DrawClr)
		<< "\t" << GetStrClr(FigGfxInfo.FillClr) << endl;
}

void CHexagon::Load(ifstream& Infile)
{
	string DrClr;
	string FlClr;
	Infile >> ID >> center.x >> center.y >> DrClr >> FlClr;
	FigGfxInfo.DrawClr = GetClrStr(DrClr);
	FigGfxInfo.FillClr = GetClrStr(FlClr);
	if (FigGfxInfo.FillClr == NULL)
		FigGfxInfo.isFilled = false;
	Selected = false;
}
