#include "Redo.h"
#include "Undo.h"
#include "Select.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"
#include "Action.h"

Redo::Redo(ApplicationManager* pApp) :Action(pApp)
{
	lastaction = pManager->LastAction_redo();
}
void Redo::ReadActionParameters()
{}
void Redo::Execute()
{
	Output* pOut = pManager->GetOutput();
	if (lastaction&&pManager->get_check_redo())
	{
		pManager->setAction(lastaction);
		lastaction->redo();
		pOut->PrintMessage("Redo");
	}
	else  pOut->PrintMessage("can not execute redo now");
}
void Redo::undo()
{
}
void Redo::redo()
{}

bool Redo::isRecordable()
{
	return true;
}

