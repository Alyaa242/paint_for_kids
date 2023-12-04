#include "CCircle.h"

CCircle::CCircle(Point P1,Point P2,GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
	{
	center = P1;
	edge = P2;
	}
void CCircle::Draw(Output* pOut)const
{
	pOut->DrawCircle(center, edge, FigGfxInfo, Selected);
}