#include "CTriangle.h"
#include <cmath>

CTriangle::CTriangle(int id, Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	ID = id+1;
	corner1 = P1;
	corner2 = P2;
	corner3 = P3;
}

CTriangle::CTriangle()
{
}
void CTriangle::Draw(Output* pOut)const
{
	pOut->DrawTriangle(corner1, corner2, corner3, FigGfxInfo, Selected);
}
void CTriangle::Save(ofstream& OutFile)
{
	OutFile << "TRI\t" << ID << "\t" << corner1.x << "\t" << corner1.y << "\t"
		<< corner2.x << "\t" << corner2.y << "\t" << corner3.x << "\t" << corner3.y
		<< "\t" << GetStrClr(FigGfxInfo.DrawClr)
		<< "\t" << GetStrClr(FigGfxInfo.FillClr) << endl;
}

void CTriangle::Load(ifstream& Infile)
{
	string DrClr;
	string FlClr;
	Infile >> ID >> corner1.x >> corner1.y >> corner2.x >> corner2.y >> corner3.x >> corner3.y >> DrClr >> FlClr;
	FigGfxInfo.DrawClr = GetClrStr(DrClr);
	FigGfxInfo.FillClr = GetClrStr(FlClr);
	if (FigGfxInfo.FillClr == NOCLR)
		FigGfxInfo.isFilled = false;
	Selected = false;
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

void CTriangle::PrintInfo(Output* pOut)
{

	string I_D = to_string(ID);
	string p1_x = to_string(corner1.x);
	string p1_y = to_string(corner1.y);
	string p2_x = to_string(corner2.x);
	string p2_y = to_string(corner2.y);
	string p3_x = to_string(corner3.x);
	string p3_y = to_string(corner3.y);
	string msg1 = "you selected a triangle ID:" + I_D + " point1 (" + p1_x + " , " + p1_y + ")  point2 (" + p2_x + " , " + p2_y + ")  point3(" + p3_x + ", " + p3_y + ")  draw color : " + GetStrClr(FigGfxInfo.DrawClr) + " , fill color : " + GetStrClr(FigGfxInfo.FillClr);
	string msg2 = "you unselected a triangle ID:" + I_D + " point1 (" + p1_x + " , " + p1_y + ")  point2 (" + p2_x + " , " + p2_y + "  point3(" + p3_x + ", " + p3_y + ")  draw color : " + GetStrClr(FigGfxInfo.DrawClr) + " , fill color : " + GetStrClr(FigGfxInfo.FillClr);
	string msg3 = "you deleted a triangle ID:" + I_D + " point1 (" + p1_x + " , " + p1_y + ")  point2 (" + p2_x + " , " + p2_y + "  point3(" + p3_x + ", " + p3_y + ")  draw color : " + GetStrClr(FigGfxInfo.DrawClr) + " , fill color : " + GetStrClr(FigGfxInfo.FillClr);

	if (isdeleted())
		pOut->PrintMessage(msg3);

	else if (IsSelected())
		pOut->PrintMessage(msg1);
	else  pOut->PrintMessage(msg2);
}
void CTriangle::setnew(Point p)
{
	Point c;
	c.x = (corner1.x + corner2.x + corner3.x) / 3;
	c.y = (corner1.y + corner2.y + corner3.y) / 3;
	double dx1 = corner1.x - c.x;
	double dy1 = corner1.y - c.y;
	double dx2 = corner2.x - c.x;
	double dy2 = corner2.y - c.y;
	double dx3 = corner3.x - c.x;
	double dy3 = corner3.y - c.y;
	corner1.x = p.x + dx1;
	corner1.y = p.y + dy1;
	corner2.x = p.x + dx2;
	corner2.y = p.y + dy2;
	corner3.x = p.x + dx3;
	corner3.y = p.y + dy3;
}
Point CTriangle::getpoint()
{
	Point c;
	c.x = (corner1.x + corner2.x + corner3.x) / 3;
	c.y = (corner1.y + corner2.y + corner3.y) / 3;
	return c;
}