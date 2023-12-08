#include "AddTriAction.h"

#include "..\Figures\CTriangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\Input.h"
#include "..\GUI\Output.h"

AddTriAction::AddTriAction(ApplicationManager* pApp):Action(pApp)
{}

void AddTriAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Triangle: Click at first corner");
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Triangle: Click at second corner");
	pIn->GetPointClicked(P2.x, P2.y);

	pOut->PrintMessage("New Triangle: Click at third corner");
	pIn->GetPointClicked(P3.x, P3.y);

	TriGfxInfo.isFilled = false; //default notfilled

	TriGfxInfo.DrawClr = pOut->getCrntDrawColor();
	if (TriGfxInfo.isFilled == false)
		TriGfxInfo.FillClr = NULL;
	else
		TriGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
}

void AddTriAction::Execute()
{
	ReadActionParameters();

	CTriangle* T = new CTriangle(pManager->GetFigCount(),P1,P2,P3,TriGfxInfo);

	pManager->AddFigure(T);
}