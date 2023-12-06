#include "CTriangle.h"
#include <cmath>
CTriangle::CTriangle(Point P1,Point P2,Point P3,GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	corner1 = P1;
	corner2 = P2;
	corner3 = P3;
}

void CTriangle::Draw(Output* pOut)const
{
	pOut->DrawTriangle(corner1, corner2, corner3, FigGfxInfo, Selected);
}

bool CTriangle::is_in(int x, int y)
{
	double d,d1, d2, d3;
	d1 = ((corner2.y - corner3.y) * (x - corner3.x) + (corner3.x - corner2.x) * (y - corner3.y));
	d2 = ((corner3.y - corner1.y) * (x - corner3.x) + (corner1.x - corner3.x) * (y - corner3.y));
	d = ((corner2.y - corner3.y) * (corner1.x - corner3.x) + (corner3.x - corner2.x) * (corner1.y - corner3.y));
	d1 = d1 / d;
	d2 = d2 / d;
	d3 = 1 - d1 - d2;
	if (d1 >= 0 && d1 <= 1 && d2 >= 0 && d2 <= 1 && d3 >= 0 && d3 <= 1)
		return true;
	else return false;
}

void CTriangle::PrintInfo(Output* pOut,bool x)
{
	if (x)
	pOut->PrintMessage("you selected a triangle ");
	else  pOut->PrintMessage("you unselected a triangle ");
}
