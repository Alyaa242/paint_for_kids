#include "Move.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"
#include"..\ApplicationManager.h"
#include"..\Figures/CFigure.h"

Move::Move(ApplicationManager* Ap):Action(Ap)
{
	Output* pOut = pManager->GetOutput();
	
	fig = NULL;
}

void Move::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Move the figure ");
	fig = pManager->GetLatestFig();
	fig2 = fig;

}

void Move::Execute()
{

	Output* pOut = pManager->GetOutput();
	if (pManager->GetLatestFig() != NULL) {
		fig = pManager->GetLatestFig();
		if (!pManager->GetIsPlaying())
			ReadActionParameters();
		
		if (fig != NULL)
			p2 = fig->getpoint();

		if (pManager->isExistHexagon() || pManager->isExistcircle() || pManager->isExistsquare() || pManager->isExistriangle() || pManager->isExistrectangle()) {

			if (!pManager->GetIsPlaying()) {
				while (pOut->getstate(p.x,p.y)) {
					pOut->setmouse(p.x, p.y);//to update the center of figure
					fig->setnew(p);//to change the coordinates of figure
					Sleep(10);//to drag the figure
					pManager->UpdateInterface();
				}
			}
			else {
				fig->setnew(p);
				pManager->UpdateInterface();
			}
		}
		else pOut->PrintMessage("Draw figures first");
	}
	else pOut->PrintMessage("please select the figure first");
}
void Move::undo()
{
	if (fig2)
		fig2->setnew(p2);
}
void Move::redo()
{
	if (fig2)
		fig2->setnew(p);
}

bool Move::isRecordable()
{
	return true;
}
