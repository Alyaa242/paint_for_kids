#include "CCircle.h"
#include <cmath>
CCircle::CCircle(Point P1,Point P2,GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
	{
	center = P1;
	edge = P2;
	}
void CCircle::Draw(Output* pOut)const
{
	pOut->DrawCircle(center, edge, FigGfxInfo, Selected);
}
bool CCircle::is_in(int x, int y)
{
	if ((pow((x - center.x), 2) + pow((y - center.y), 2)) <= (pow((edge.x - center.x), 2) + pow((edge.y - center.y), 2)))
		return true;
	else return false;

}
void CCircle::PrintInfo(Output* pOut,bool x)
{
	if (x)
	pOut->PrintMessage("you selected a circle ");
	else  pOut->PrintMessage("you selected a circle ");
}
