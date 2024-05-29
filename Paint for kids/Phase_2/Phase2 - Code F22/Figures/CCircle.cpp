#include "CCircle.h"
#include <cmath>

CCircle::CCircle(int id, Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	ID = id+1;
	center = P1;
	edge = P2;
}
CCircle::CCircle()
{
}
void CCircle::Draw(Output* pOut)const
{
	pOut->DrawCircle(center, edge, FigGfxInfo, Selected);
}

void CCircle::Save(ofstream& OutFile)
{
	OutFile << "CIRC\t" << ID << "\t" << center.x << "\t" << center.y << "\t"
		<< edge.x << "\t" << edge.y << "\t" << GetStrClr(FigGfxInfo.DrawClr)
		<< "\t" << GetStrClr(FigGfxInfo.FillClr) << endl;
}

void CCircle::Load(ifstream& Infile)
{
	string DrClr;
	string FlClr;
	Infile >> ID >> center.x >> center.y >> edge.x >> edge.y >> DrClr >> FlClr;
	FigGfxInfo.DrawClr = GetClrStr(DrClr);
	FigGfxInfo.FillClr = GetClrStr(FlClr);
	if (FigGfxInfo.FillClr == NOCLR)
		FigGfxInfo.isFilled = false;
	Selected = false;
}

bool CCircle::is_in(int x, int y)
{
	if ((pow((x - center.x), 2) + pow((y - center.y), 2)) <= (pow((edge.x - center.x), 2) + pow((edge.y - center.y), 2)))
		return true;
	else return false;

}
void CCircle::PrintInfo(Output* pOut)
{
	string c_x = to_string( center.x);
	string c_y = to_string(center.y);
	string e_x = to_string(edge.x);
	string e_y = to_string(edge.y);
	string I_D = to_string(ID);
	string msg1 = "you selected a circle ID:" + I_D + "  center (" + c_x + " , " + c_y + ")  edge (" + e_x + " , " + e_y + ")  draw color : " + GetStrClr(FigGfxInfo.DrawClr) + " , fill color : " + GetStrClr(FigGfxInfo.FillClr);
	string msg2 = "you unselected a circle ID:" + I_D + "  center (" + c_x + " , " + c_y + ")  edge (" + e_x + " , " + e_y + ")  draw color : " + GetStrClr(FigGfxInfo.DrawClr) + " , fill color : " + GetStrClr(FigGfxInfo.FillClr);
	string msg3 = "you deleted a circle ID:" + I_D + "  center (" + c_x + " , " + c_y + ")  edge (" + e_x + " , " + e_y + ")  draw color : " + GetStrClr(FigGfxInfo.DrawClr) + " , fill color : " + GetStrClr(FigGfxInfo.FillClr);

	if (isdeleted())
		pOut->PrintMessage(msg3);

	else if (IsSelected())
		pOut->PrintMessage(msg1);
	else  pOut->PrintMessage(msg2);
}
void CCircle::setnew(Point p)
{
	double tempx = center.x;
	double tempy = center.y;
	center = p;
	edge.x = sqrt(pow((tempx - edge.x), 2) + pow((tempy - edge.y), 2)) + center.x;
	edge.y = center.y;
}
Point CCircle::getpoint()
{
	return center;
}