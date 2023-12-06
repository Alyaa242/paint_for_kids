#include "CHexagon.h"

CHexagon::CHexagon(Point P, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	center = P;
}

void CHexagon::Draw(Output* pOut)const
{
	pOut->DrawHexagon(center, FigGfxInfo, Selected);
}

bool CHexagon::is_in(int x, int y)
{
	if ((pow((x-center.x),2)+pow((y-center.y),2))<=10000)
		return true;
	else return false;
}
void CHexagon::PrintInfo(Output* pOut,bool x)
{
	if (x)
	pOut->PrintMessage("you selected a hexagon ");
	else  pOut->PrintMessage("you unselected a hexagon ");
}
