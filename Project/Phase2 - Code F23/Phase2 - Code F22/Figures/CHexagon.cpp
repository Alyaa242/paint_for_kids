#include "CHexagon.h"

CHexagon::CHexagon(Point P, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	center = P;
}

void CHexagon::Draw(Output* pOut)const
{
	pOut->DrawHexagon(center, FigGfxInfo, Selected);
}