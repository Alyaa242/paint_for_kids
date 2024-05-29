#include "DrawColorAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
DrawColorAction::DrawColorAction(ApplicationManager* pApp) :Action(pApp)
{
	canceled = false;
	latestfigure = pManager->GetLatestFig();
}

void DrawColorAction::ReadActionParameters()
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

	pOut->PrintMessage("Change Drawing Color: Select a color");

	beforeinfo = latestfigure->getgfx();  //set the color before changing to use it in undo

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
		canceled = true;	//If user clicked anywhere else the operation would be canceled
		break;
	}

	pOut->ClearStatusBar();
}

void DrawColorAction::Execute()
{
	latestfigure = pManager->GetLatestFig();

	if (!pManager->GetIsPlaying())
		ReadActionParameters();

	//Check that the user didn't click anywhere else
	if (!canceled) {

		latestfigure->ChngDrawClr(c);	//Change selected figure draw color
		UI.DrawColor = c;	//Change default draw color
		afterinfo = latestfigure->getgfx();
	}
}
void DrawColorAction::undo()
{
	if (latestfigure)
	{
		latestfigure->setgfx(beforeinfo);
		UI.DrawColor = beforeinfo.DrawClr;  //Change default draw color

	}
}
void DrawColorAction::redo()
{

	if (latestfigure)
	{
		latestfigure->setgfx(afterinfo);
		UI.DrawColor = afterinfo.DrawClr;  //Change default draw color
	}

}

bool DrawColorAction::isRecordable()
{
	return true;
}

