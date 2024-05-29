#include "SwitchToDraw.h"
#include "..\ApplicationManager.h"

#include "..\Figures\CRectangle.h"
#include "..\Figures\CSquare.h"
#include "..\Figures\CTriangle.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\CHexagon.h"
#include "LoadAction.h"

SwitchToDraw::SwitchToDraw(ApplicationManager* Ap) : Action(Ap)
{
}

void SwitchToDraw::ReadActionParameters()
{
}

void SwitchToDraw::Execute()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Switching to draw mode...");
	pOut->CreateDrawToolBar();
	
}

void SwitchToDraw::undo()
{
}

void SwitchToDraw::redo()
{
}

bool SwitchToDraw::isRecordable()
{
	return false;
}
