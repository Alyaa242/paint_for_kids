#include "CHexagon.h"

CHexagon::CHexagon(int id, Point P, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	ID = id+1;
	center = P;
}

CHexagon::CHexagon()
{
}

void CHexagon::Draw(Output* pOut)const
{
	pOut->DrawHexagon(center, FigGfxInfo, Selected);
}

void CHexagon::Save(ofstream& OutFile)
{
	OutFile << "HEX\t" << ID << "\t" << center.x << "\t" << center.y << "\t"
		<< GetStrClr(FigGfxInfo.DrawClr)
		<< "\t" << GetStrClr(FigGfxInfo.FillClr) << endl;
}

void CHexagon::Load(ifstream& Infile)
{
	string DrClr;
	string FlClr;
	Infile >> ID >> center.x >> center.y >> DrClr >> FlClr;
	FigGfxInfo.DrawClr = GetClrStr(DrClr);
	FigGfxInfo.FillClr = GetClrStr(FlClr);
	if (FigGfxInfo.FillClr == NOCLR)
		FigGfxInfo.isFilled = false;
	Selected = false;
}

bool CHexagon::is_in(int x, int y)
{
	const int vertices = 6;
	int sideLenght = 100;
	Point p = center;
	int xvalues[vertices] = { p.x + sideLenght / 2,p.x + sideLenght,p.x + sideLenght / 2,p.x - sideLenght / 2,p.x - sideLenght,p.x - sideLenght / 2 };
    int yvalues[vertices] = { p.y + (sideLenght / 2) * sqrt(3),p.y,p.y - (sideLenght / 2) * sqrt(3),p.y - (sideLenght / 2) * sqrt(3),p.y,p.y + (sideLenght / 2) * sqrt(3) };
	bool f1, f2, f3;
	double d, d1, d2,d3;
	d1 = ((yvalues[1] - yvalues[2]) * (x - xvalues[2]) + (xvalues[2] - xvalues[1]) * (y - yvalues[2]));
	d2 = ((yvalues[2] - yvalues[0]) * (x - xvalues[2]) + (xvalues[0] - xvalues[2]) * (y - yvalues[2]));
	d = ((yvalues[1] - yvalues[2]) * (xvalues[0] - xvalues[2]) + (xvalues[2] - xvalues[1]) * (yvalues[0] - yvalues[2]));
	d1 = d1 / d;
	d2 = d2 / d;
	d3 = 1 - d1 - d2;
	f1 = (d1 >= 0 && d1 <= 1 && d2 >= 0 && d2 <= 1 && d3 >= 0 && d3 <= 1);
	d1 = ((yvalues[4] - yvalues[5]) * (x - xvalues[5]) + (xvalues[5] - xvalues[4]) * (y - yvalues[5]));
	d2 = ((yvalues[5] - yvalues[3]) * (x - xvalues[5]) + (xvalues[3] - xvalues[5]) * (y - yvalues[5]));
	d  = ((yvalues[4] - yvalues[5]) * (xvalues[3] - xvalues[5]) + (xvalues[5] - xvalues[4]) * (yvalues[3] - yvalues[5]));
	d1 = d1 / d;
	d2 = d2 / d;
	d3 = 1 - d1 - d2;
	f2 = (d1 >= 0 && d1 <= 1 && d2 >= 0 && d2 <= 1 && d3 >= 0 && d3 <= 1);
	f3 = (x >= min(xvalues[0], xvalues[3]) && x <= max(xvalues[0], xvalues[3]) && y >= min(yvalues[0], yvalues[3]) && y <= max(yvalues[0], yvalues[3]));
	return (f1 || f2 || f3);
}
void CHexagon::PrintInfo(Output* pOut)
{
	string c_x = to_string(center.x);
	string c_y = to_string(center.y);
	string I_D = to_string(ID);
	string msg1 = "you selected a hexagon ID:" + I_D + " center (" + c_x + " , " + c_y + ")  side length : 100   draw color : " + GetStrClr(FigGfxInfo.DrawClr) + " , fill color : " + GetStrClr(FigGfxInfo.FillClr);
	string msg2 = "you unselected a hexagon ID:" + I_D + " center (" + c_x + " , " + c_y + ")  side length : 100   draw color : " + GetStrClr(FigGfxInfo.DrawClr) + " , fill color : " + GetStrClr(FigGfxInfo.FillClr);
	string msg3 = "you deleted a hexagon ID:" + I_D + " center (" + c_x + " , " + c_y + ")  side length : 100   draw color : " + GetStrClr(FigGfxInfo.DrawClr) + " , fill color : " + GetStrClr(FigGfxInfo.FillClr);
	if (isdeleted())
		pOut->PrintMessage(msg3);

	else if (IsSelected())
	pOut->PrintMessage(msg1);
	else  pOut->PrintMessage(msg2);
}
void CHexagon::setnew(Point p)
{
	center = p;
}
Point CHexagon::getpoint()
{
	return center;
}