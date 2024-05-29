#include "Undo.h"
#include "Select.h"
#include "Delete.h"
#include "..\Figures\CSquare.h"

#include "..\ApplicationManager.h"

#include "..\GUI\Input.h"
#include "..\GUI\Output.h"
#include "Action.h"
Undo::Undo(ApplicationManager* pApp) :Action(pApp)
{}
void Undo::ReadActionParameters()
{}
void Undo::Execute()
{
	Output* pOut = pManager->GetOutput();
	
	Action* lastaction = pManager->LastAction_undo();
	if (lastaction)
	{
		lastaction->undo();
		pOut->PrintMessage("Undo");
	}
	else pOut->PrintMessage("can not execute undo now");
}
void Undo::undo()
{}
void Undo::redo()
{}

bool Undo::isRecordable()
{
	return true;
}

