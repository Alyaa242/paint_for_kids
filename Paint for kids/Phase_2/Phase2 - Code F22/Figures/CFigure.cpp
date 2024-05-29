#include "CFigure.h"
CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
	deleted = false;
}

CFigure::CFigure()
{
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }
void CFigure::setdeleted(bool s)
{
	deleted = s;
}

bool CFigure::isdeleted() const
{
	return deleted;
}

void CFigure::setgfx(GfxInfo f)
{
	FigGfxInfo = f;
}
GfxInfo CFigure::getgfx()
{
	return FigGfxInfo;
}

string CFigure::GetStrClr(color& clr)
{
	string Color;
	if (clr == BLACK)
		Color = "BLACK";
	else if (clr == RED)
		Color = "RED";
	else if (clr == GREEN)
		Color = "GREEN";
	else if (clr == BLUE)
		Color = "BLUE";
	else if (clr == YELLOW)
		Color = "YELLOW";
	else if (clr == ORANGE)
		Color = "ORANGE";
	if (clr == NOCLR)
		Color = "NO_FILL";
	return Color;
}

color CFigure::GetClrStr(string& str)
{
	color Color;
	if (str == "BLACK")
		Color = BLACK;
	else if (str == "RED")
		Color = RED;
	else if (str == "GREEN")
		Color = GREEN;
	else if (str == "BLUE")
		Color = BLUE;
	else if (str == "YELLOW")
		Color = YELLOW;
	else if (str == "ORANGE")
		Color = ORANGE;
	else if (str == "NO_FILL")
		Color = NOCLR;
	return Color;
}

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}

 color CFigure::get_color()
 {
		 if (this != NULL) {
	 if (isfilled1()) {
			 color c = FigGfxInfo.FillClr;
			 return c;
		 }
	 }
	 return -1000;
}

 bool CFigure::isfilled1()
 {
	 return FigGfxInfo.isFilled;
 }

