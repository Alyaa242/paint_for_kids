#include "FillColorAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

FillColorAction::FillColorAction(ApplicationManager* pApp) :Action(pApp)
{
}

void FillColorAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Change Fill Color: Select a color");

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
	}

	pOut->ClearStatusBar();
}

void FillColorAction::Execute()
{
	Output* pOut = pManager->GetOutput();

	//Check that there is a selected figure
	if (!pManager->GetLatestFig()) {
		pOut->PrintMessage("Select a figure first");
		return;
	}

	//This action needs to read some parameters first
	ReadActionParameters();

	pManager->GetLatestFig()->ChngFillClr(c);	//Change selected figure fill color
	UI.FillColor = c;	//Change default fill color
	UI.isFillChanged = true;
	
}
