#include "PlayRecAction.h"
#include "..\ApplicationManager.h"

PlayRecAction::PlayRecAction(ApplicationManager* pApp) : Action(pApp)
{
}

void PlayRecAction::ReadActionParameters()
{
}

void PlayRecAction::Execute()
{
	Output* pOut = pManager->GetOutput();

	pManager->setIsPlaying(true);

	//Check if recording isn't finished
	if (pManager->getIsRecording()) {
		pOut->PrintMessage("Record is still in progress!");
	}

	//Check if there's a record
	else if (pManager->getRecActsCount()) {
		pOut->PrintMessage("Playing record...");
		pManager->ClearDrawArea();
		for (int i = 0; i < pManager->getRecActsCount(); i++) {
			Sleep(1000);
			pManager->playAction(i);
		}
	}

	else {
		pOut->PrintMessage("You don't have any recorded actions!");
	}

	pManager->setIsPlaying(false);

}

bool PlayRecAction::isRecordable()
{
	return false;
}

void PlayRecAction::undo()
{
}

void PlayRecAction::redo()
{
}
