#include "DrawColorAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

DrawColorAction::DrawColorAction(ApplicationManager* pApp) :Action(pApp)
{
	canceled = false;
}

void DrawColorAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Change Drawing Color: Select a color");

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
		canceled = true;
		break;
	}

	pOut->ClearStatusBar();
}

void DrawColorAction::Execute()
{
	Output* pOut = pManager->GetOutput();

	if (!pManager->GetLatestFig()) {
		pOut->PrintMessage("Select a figure first");
		return;
	}

	//This action needs to read some parameters first
	ReadActionParameters();

	//Check that the user didn't click anywhere else
	if (!canceled) {
		pManager->GetLatestFig()->ChngDrawClr(c);	//Change selected figure draw color
		UI.DrawColor = c;	//Change default draw color
	}
}
