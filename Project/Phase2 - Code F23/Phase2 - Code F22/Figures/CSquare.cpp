#include "CSquare.h"
CSquare::CSquare(Point P, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P;
}

void CSquare::Draw(Output* pOut) const
{
	pOut->DrawSquare(Center, FigGfxInfo, Selected);
}

bool CSquare::is_in(int x, int y)
{
	if ((x >= (Center.x) - 100) && (x <= (Center.x) + 100) && (y >= (Center.y) - 100) && (y <= (Center.y) + 100))
		return true;
	else return false;
}
void CSquare::PrintInfo(Output* pOut, bool x)
{
	if (x)
	pOut->PrintMessage("you selected a square ");
   else pOut->PrintMessage("you unselected a square ");
}

