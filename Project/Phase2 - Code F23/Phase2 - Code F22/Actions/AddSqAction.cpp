#include "AddSqAction.h"

#include "..\Figures\CSquare.h"

#include "..\ApplicationManager.h"

#include "..\GUI\Input.h"
#include "..\GUI\Output.h"

AddSqAction::AddSqAction(ApplicationManager* pApp):Action(pApp)
{}
void AddSqAction:: ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Square: Click at center");
	pIn->GetPointClicked(P.x,P.y);

	SqGfxInfo.isFilled = false;
	SqGfxInfo.DrawClr = pOut->getCrntDrawColor();
	SqGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
}
void AddSqAction::Execute()
{
	ReadActionParameters();

	CSquare* S = new CSquare(P, SqGfxInfo);

	pManager->AddFigure(S);
}