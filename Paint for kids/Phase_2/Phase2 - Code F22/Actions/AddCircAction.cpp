#include "AddCircAction.h"

#include "..\Figures\CCircle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\Input.h"
#include "..\GUI\Output.h"

AddCircAction::AddCircAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddCircAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Cricle: Click at center ");
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Circle: Click at edge");
	pIn->GetPointClicked(P2.x, P2.y);

	CircGfxInfo.isFilled = pOut->getIsFilledChanged();	//True if fill color is changed before
	CircGfxInfo.DrawClr = pOut->getCrntDrawColor();
	if (CircGfxInfo.isFilled == false)
		CircGfxInfo.FillClr = NOCLR;
	else
		CircGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
}

void AddCircAction::Execute()
{
	if (!pManager->GetIsPlaying())
		ReadActionParameters();

	CCircle* C = new CCircle(pManager->GetFigCount(), P1, P2, CircGfxInfo);
	circ = C;
	pManager->AddFigure(C);
}
void AddCircAction::undo()
{
	 pManager->setdel(circ);
}
void AddCircAction::redo()
{
	pManager->un_del(circ);
}

bool AddCircAction::isRecordable()
{
	return true;
}

