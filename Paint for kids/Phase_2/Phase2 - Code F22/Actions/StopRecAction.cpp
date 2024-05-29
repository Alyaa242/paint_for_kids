#include "StopRecAction.h"

StopRecAction::StopRecAction(ApplicationManager* pApp) : Action(pApp)
{
}

void StopRecAction::ReadActionParameters()
{
}

void StopRecAction::Execute()
{
	Output* pOut = pManager->GetOutput();

	//Check if it was recording
	if (pManager->getIsRecording()) {
		pOut->PrintMessage("Record Stopped");

		//Set isRecording to false
		pManager->setIsRecording(false);
	}
	else {
		pOut->PrintMessage("No record in progress to stop!");
	}
}

bool StopRecAction::isRecordable()
{
	return false;
}

void StopRecAction::undo()
{
}

void StopRecAction::redo()
{
}
