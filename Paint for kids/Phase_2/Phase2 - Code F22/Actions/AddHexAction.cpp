#include "AddHexAction.h"

#include "..\Figures\CHexagon.h"

#include "..\ApplicationManager.h"

#include "..\GUI\Input.h"
#include "..\GUI\Output.h"

AddHexAction::AddHexAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddHexAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Hexagon: Click at center");
	pIn->GetPointClicked(P.x, P.y);

	HexGfxInfo.isFilled = pOut->getIsFilledChanged();	//True if fill color is changed before
	HexGfxInfo.DrawClr = pOut->getCrntDrawColor();
	if (HexGfxInfo.isFilled == false)
		HexGfxInfo.FillClr = NOCLR;
	else
		HexGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
}

void AddHexAction::Execute()
{
	if (!pManager->GetIsPlaying())
		ReadActionParameters();

	CHexagon* H = new CHexagon(pManager->GetFigCount(), P, HexGfxInfo);
	hex = H;
	pManager->AddFigure(H);
}
void AddHexAction::undo()
{
	pManager->setdel(hex);
}
void AddHexAction::redo()
{
	pManager->un_del(hex);
}

bool AddHexAction::isRecordable()
{
	return true;
}

