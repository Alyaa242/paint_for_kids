#include "CRectangle.h"

CRectangle::CRectangle(int id, Point P1, Point P2, GfxInfo FigureGfxInfo) : CFigure(FigureGfxInfo)
{
	ID = id+1;
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
	if (FigGfxInfo.FillClr == NOCLR)
		FigGfxInfo.isFilled = false;
	Selected = false;

}

bool CRectangle::is_in(int x,int y)
{
	if (x >= min(Corner1.x,Corner2.x) && x <= max(Corner2.x,Corner1.x) && y >= min(Corner1.y, Corner2.y) && y <= max(Corner1.y, Corner2.y))
		return true;
	else return false;
}
void CRectangle::PrintInfo(Output* pOut)

{
	string I_D = to_string(ID);
	string p1_x = to_string(Corner1.x);
	string p1_y = to_string(Corner1.y);
	string p2_x = to_string(Corner2.x);
	string p2_y = to_string(Corner2.y);
	string msg1 = "you selected a rectangle ID:" + I_D + " point1 (" + p1_x + " , " + p1_y + ")  point2 (" + p2_x + " , " + p2_y + ")   draw color : " + GetStrClr(FigGfxInfo.DrawClr) + " , fill color : " + GetStrClr(FigGfxInfo.FillClr);
	string msg2 = "you unselected a rectangle ID:" + I_D + " point1 (" + p1_x + " , " + p1_y + ")  point2 (" + p2_x + " , " + p2_y + ")   draw color : " + GetStrClr(FigGfxInfo.DrawClr) + " , fill color : " + GetStrClr(FigGfxInfo.FillClr);
	string msg3 = "you deleted a rectangle ID:" + I_D + " point1 (" + p1_x + " , " + p1_y + ")  point2 (" + p2_x + " , " + p2_y + ")   draw color : " + GetStrClr(FigGfxInfo.DrawClr) + " , fill color : " + GetStrClr(FigGfxInfo.FillClr);

	if (isdeleted())
		pOut->PrintMessage(msg3);

	else if (IsSelected())
		pOut->PrintMessage(msg1);
	else  pOut->PrintMessage(msg2);
}
void CRectangle::setnew(Point p)
{
	Point c;
	c.x = (Corner1.x + Corner2.x) / 2;
	c.y = (Corner1.y + Corner2.y) / 2;
	double dx = Corner1.x - c.x;
	double dy = Corner1.y - c.y;
	Corner1.x = p.x + dx;
	Corner2.x = p.x - dx;
	Corner1.y = p.y + dy;
	Corner2.y = p.y - dy;

}
Point CRectangle::getpoint()
{
	Point c;
	c.x = (Corner1.x + Corner2.x) / 2;
	c.y = (Corner1.y + Corner2.y) / 2;
	return c;
}