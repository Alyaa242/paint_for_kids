#include "CSquare.h"

CSquare::CSquare(int id, Point P, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	ID = id+1;
	Center = P;
}

CSquare::CSquare()
{
}

void CSquare::Draw(Output* pOut) const
{
	pOut->DrawSquare(Center, FigGfxInfo, Selected);
}

void CSquare::Save(ofstream& OutFile)
{
	OutFile << "SQ\t" << ID << "\t" << Center.x << "\t" << Center.y << "\t"
		<< GetStrClr(FigGfxInfo.DrawClr)
		<< "\t" << GetStrClr(FigGfxInfo.FillClr) << endl;
}

void CSquare::Load(ifstream& Infile)
{
	string DrClr;
	string FlClr;
	Infile >> ID >> Center.x >> Center.y >> DrClr >> FlClr;
	FigGfxInfo.DrawClr = GetClrStr(DrClr);
	FigGfxInfo.FillClr = GetClrStr(FlClr);
	if (FigGfxInfo.FillClr == NOCLR)
		FigGfxInfo.isFilled = false;
	Selected = false;
}

bool CSquare::is_in(int x, int y)
{
	if ((x >= (Center.x) - 100) && (x <= (Center.x) + 100) && (y >= (Center.y) - 100) && (y <= (Center.y) + 100))
		return true;
	else return false;
}
void CSquare::PrintInfo(Output* pOut)
{

	string I_D = to_string(ID);
	string c_x = to_string(Center.x);
	string c_y = to_string(Center.y);
	string msg1 = "you selected a Square ID:" + I_D + "  center (" + c_x + " , " + c_y + ")  side length : 200   draw color : " + GetStrClr(FigGfxInfo.DrawClr) + " , fill color : " + GetStrClr(FigGfxInfo.FillClr);
	string msg2 = "you unselected a Square ID:" + I_D + "  center (" + c_x + " , " + c_y + ")  side length : 200   draw color : " + GetStrClr(FigGfxInfo.DrawClr) + " , fill color : " + GetStrClr(FigGfxInfo.FillClr);
	string msg3 = "you deleted a Square ID:" + I_D + "  center (" + c_x + " , " + c_y + ")  side length : 200   draw color : " + GetStrClr(FigGfxInfo.DrawClr) + " , fill color : " + GetStrClr(FigGfxInfo.FillClr);
	
	if (isdeleted())
		pOut->PrintMessage(msg3);

	else if (IsSelected())
		pOut->PrintMessage(msg1);
	else  pOut->PrintMessage(msg2);
}
void CSquare::setnew(Point p)
{
	Center = p;
}
Point CSquare::getpoint()
{
	return Center;
}
