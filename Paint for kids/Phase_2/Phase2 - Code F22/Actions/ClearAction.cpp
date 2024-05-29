#include "ClearAction.h"
#include "SaveAction.h"
ClearAction::ClearAction(ApplicationManager* pApp) : Action(pApp)
{
}

void ClearAction::ReadActionParameters()
{
}

void ClearAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	UI.DrawColor = BLUE;
	UI.FillColor = GREEN;
	UI.isFillChanged = false;

	pManager->ClearDrawArea();
}
void ClearAction::undo()
{}
void ClearAction::redo()
{}

bool ClearAction::isRecordable()
{
	return true;
}


