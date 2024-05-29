#include "RecordAction.h"
#include "..\ApplicationManager.h"

RecordAction::RecordAction(ApplicationManager* pApp) :Action(pApp)
{
}

void RecordAction::ReadActionParameters()
{
}

void RecordAction::Execute()
{
	Output* pOut = pManager->GetOutput();

	//Check that no record is in progress
	if (pManager->getIsRecording()) {
		pOut->PrintMessage("You are already recording!");
	}
	//Check that draw area is clear
	else if (pManager->GetFigCount() != 0) {
		pOut->PrintMessage("Draw area must be clear!");
	}
	else {
		pManager->resetRecord();	//Reset record actions array to recieve new record
		pOut->PrintMessage("Record Started");

		//Set isRecording to true
		pManager->setIsRecording(true);
	}
}

void RecordAction::undo()
{}
void RecordAction::redo()
{}

bool RecordAction::isRecordable()
{
	return false;
}


