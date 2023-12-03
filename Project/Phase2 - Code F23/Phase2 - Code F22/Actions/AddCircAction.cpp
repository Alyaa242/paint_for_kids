#include "AddCircAction.h"

#include "..\Figures\CCircle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\Input.h"
#include "..\GUI\Output.h"

AddCircAction::AddCircAction(ApplicationManager* pApp):Action(pApp)
{}

void AddCircAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Cricle: Click at center ");
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Circle: Click at edge");
	pIn->GetPointClicked(P2.x, P2.y);

	CircGfxInfo.isFilled = false; //dafault notfilled
	CircGfxInfo.DrawClr = pOut->getCrntDrawColor();
	CircGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
}

void AddCircAction::Execute()
{
	ReadActionParameters();

	CCircle* C = new CCircle(P1, P2, CircGfxInfo);

	pManager->AddFigure(C);
}