#include "Delete.h"
#include "Select.h"

#include "..\Figures\CSquare.h"

#include "..\ApplicationManager.h"

#include "..\GUI\Input.h"
#include "..\GUI\Output.h"

Delete::Delete(ApplicationManager* pApp) :Action(pApp)
{
}
void Delete::ReadActionParameters()
{}
void Delete::Execute()
{
	f = (pManager->GetLatestFig());

	Output* pOut = pManager->GetOutput();
	
	if (f)
	{
		f->setdeleted(true);
		f->PrintInfo(pOut);
		pManager->setdel(f);
	}
	else pOut->PrintMessage("select a figure first to delete it ");
}
void Delete::undo()
{
	if (f) {
		f->setdeleted(false);
		f->SetSelected(false);
		pManager->un_del(f);
	}
}
void Delete::redo()
{
	Output* pOut = pManager->GetOutput();
	if (f) {
		f->setdeleted(true);
		f->PrintInfo(pOut);
		pManager->setdel(f);
	}
}

bool Delete::isRecordable()
{
	return true;
}

