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
	ReadActionParameters();
	CFigure* f = (pManager->GetFigure(P.x, P.y));
	Output* pOut = pManager->GetOutput();
	CFigure *lf= (pManager->GetLatestFig());
	if (f)
	{
		f->SetSelected(true);

		if (lf)
		{
			if (f == lf)
				f->PrintInfo(pOut, 0);
			else
				f->PrintInfo(pOut, 1);

			lf->SetSelected(false);
		}
		else f->PrintInfo(pOut, 1);
	}
	else pOut->PrintMessage("Click into any figure ");
}