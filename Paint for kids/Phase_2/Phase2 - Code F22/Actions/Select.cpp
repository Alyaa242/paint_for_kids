#include "Select.h"

#include "..\Figures\CSquare.h"

#include "..\ApplicationManager.h"

#include "..\GUI\Input.h"
#include "..\GUI\Output.h"

Select::Select(ApplicationManager* pApp) :Action(pApp)
{}

void Select::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Select a figure ");
	pIn->GetPointClicked(P.x, P.y);
}
void Select::Execute()
{
	if (!pManager->GetIsPlaying())
		ReadActionParameters();

	CFigure* f = (pManager->GetFigure(P.x, P.y));
	Output* pOut = pManager->GetOutput();
	CFigure *lf= (pManager->GetLatestFig());
	if (f)
	{
		f->SetSelected(true);

		if (lf)
		{

			lf->SetSelected(false);
			if (f == lf)
			{
				lf->PrintInfo(pOut);
			}
			else
				f->PrintInfo(pOut);
		}
		else f->PrintInfo(pOut);
	}
	else pOut->PrintMessage("Click into any figure ");
}
void Select::undo()
{
}
void Select::redo()
{
}

bool Select::isRecordable()
{
	return true;
}

