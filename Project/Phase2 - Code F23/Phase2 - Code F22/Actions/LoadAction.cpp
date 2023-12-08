#include "LoadAction.h"
#include "..\ApplicationManager.h"

#include "..\Figures\CRectangle.h"
#include "..\Figures\CSquare.h"
#include "..\Figures\CTriangle.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\CHexagon.h"


LoadAction::LoadAction(ApplicationManager* pApp):Action(pApp)
{}

void LoadAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Load File: Enter its name");

	FileName=pIn->GetSrting(pOut);
	FileName = "saved files\\" + FileName + ".txt";

	pOut->ClearStatusBar();

}

void LoadAction::Execute()
{
	pManager->ClearDrawArea();

	ReadActionParameters();
	string CrntDrClr;
	string CrntFlClr;
	int ignore;
	string type;
	CFigure* Figure;

	ifstream inFile;
	inFile.open(FileName);
	
	if (inFile.is_open())
	{
		inFile >> CrntDrClr >> CrntFlClr >> ignore;
		UI.DrawColor = CFigure::GetClrStr(CrntDrClr);
		UI.FillColor = CFigure::GetClrStr(CrntFlClr);

		while (!inFile.eof())
		{
			inFile >> type;

			if (type == "RECT")
				Figure = new CRectangle;
			else if (type == "SQ")
				Figure = new CSquare;
			else if (type == "TRI")
				Figure = new CTriangle;
			else if (type == "CIRC")
				Figure = new CCircle;
			else
				Figure = new CHexagon;

		Figure->Load(inFile);
		pManager->AddFigure(Figure);
		}
		inFile.close();
	}
}

