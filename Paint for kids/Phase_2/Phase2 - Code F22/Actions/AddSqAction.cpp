#include "AddSqAction.h"

#include "..\Figures\CSquare.h"

#include "..\ApplicationManager.h"

#include "..\GUI\Input.h"
#include "..\GUI\Output.h"

AddSqAction::AddSqAction(ApplicationManager* pApp) :Action(pApp)
{}
void AddSqAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Square: Click at center");
	pIn->GetPointClicked(P.x, P.y);

	SqGfxInfo.isFilled = pOut->getIsFilledChanged();	//True if fill color is changed before
	SqGfxInfo.DrawClr = pOut->getCrntDrawColor();
	if (SqGfxInfo.isFilled == false)
		SqGfxInfo.FillClr = NOCLR;
	else
		SqGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
}
void AddSqAction::Execute()
{
	if (!pManager->GetIsPlaying())
		ReadActionParameters();

	CSquare* S = new CSquare(pManager->GetFigCount(), P, SqGfxInfo);
	square = S;
	pManager->AddFigure(S);
}
void AddSqAction::undo()
{
	 pManager->setdel(square);
}
void AddSqAction::redo()
{
	pManager->un_del(square);
}

bool AddSqAction::isRecordable()
{
	return true;
}

