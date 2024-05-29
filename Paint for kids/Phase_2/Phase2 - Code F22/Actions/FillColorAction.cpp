#include "FillColorAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

FillColorAction::FillColorAction(ApplicationManager* pApp) :Action(pApp)
{
	canceled = false;
	latestfigure = pManager->GetLatestFig();
}

void FillColorAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Check that there is a selected figure
	if (!latestfigure) {
		pOut->PrintMessage("Select a figure first");
		canceled = true;
		return;
	}


	pOut->PrintMessage("Change Fill Color: Select a color");

	beforeinfo = latestfigure->getgfx(); //set the color before changing to use it in undo
	//Read color
	ActionType selectedColor = pManager->GetUserAction();

	switch (selectedColor) {
	case COLOR_BLACK:
		c = BLACK;
		break;
	case COLOR_RED:
		c = RED;
		break;
	case COLOR_GREEN:
		c = GREEN;
		break;
	case COLOR_BLUE:
		c = BLUE;
		break;
	case COLOR_YELLOW:
		c = YELLOW;
		break;
	case COLOR_ORANGE:
		c = ORANGE;
		break;
	default:
		canceled = true;	//If the user clicked anywhere else the operation would be canceled
		break;
	}

	pOut->ClearStatusBar();
}

void FillColorAction::Execute()
{
	latestfigure = pManager->GetLatestFig();

	if (!pManager->GetIsPlaying())
		ReadActionParameters();

	//Check if the user didn't click anywhere else
	if (!canceled) {
		latestfigure->ChngFillClr(c);	//Change selected figure fill color
		UI.FillColor = c;	//Change default fill color
		UI.isFillChanged = true;	//set isFilled for all coming figures to be true
		afterinfo = latestfigure->getgfx();
	}
}
void FillColorAction::undo()
{
	if (latestfigure)
	{
		latestfigure->setgfx(beforeinfo);
		UI.FillColor = beforeinfo.FillClr;
		UI.isFillChanged = beforeinfo.isFilled;
	}
}
void FillColorAction::redo()
{
	if (latestfigure)
	{
		latestfigure->setgfx(afterinfo);
		UI.FillColor = afterinfo.FillClr;
		UI.isFillChanged = afterinfo.isFilled;
	}
}

bool FillColorAction::isRecordable()
{
	return true;
}

