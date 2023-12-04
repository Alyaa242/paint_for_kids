#include "CTriangle.h"

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


