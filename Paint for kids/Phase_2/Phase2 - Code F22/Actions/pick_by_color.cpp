#include "pick_by_color.h"
#include "pick_by_figure.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"
#include"..\ApplicationManager.h"
#include"..\Figures/CFigure.h"
#include<iostream>
using namespace std;
pick_by_color::pick_by_color(ApplicationManager* Ap):Action(Ap)
{
	Output* pOut = pManager->GetOutput();
	fig = NULL;
	if (pManager->isexistfillfigure()) {//check if exist fill figures or not

		int i = 0;
		if (pManager->isExistcolor(BLACK))
			i++;
		if (pManager->isExistcolor(ORANGE))
			i++;
		if (pManager->isExistcolor(RED))
			i++;
		if (pManager->isExistcolor(YELLOW))
			i++;
		if (pManager->isExistcolor(GREEN))
			i++;
		if (pManager->isExistcolor(BLUE))
			i++;
		int x = i;
		i = 0;
		colors = new string[x];//making array of existing element
		if (pManager->isExistcolor(BLACK))
			colors[i++] = "Choose black figures";
		if (pManager->isExistcolor(BLUE))
			colors[i++] = "Choose blue figures";
		if (pManager->isExistcolor(GREEN))
			colors[i++] = "Choose green figures";
		if (pManager->isExistcolor(YELLOW))
			colors[i++] = "Choose yellow figures";
		if (pManager->isExistcolor(RED))
			colors[i++] = "Choose red figures";
		if (pManager->isExistcolor(ORANGE))
			colors[i++] = "Choose orange figures";
		srand(time(0));
		randcol = rand() % x;//choosing random element to play by it
		pOut->PrintMessage(colors[randcol]);

	}
	else {
		if (pManager->isExistrectangle() || pManager->isExistsquare() || pManager->isExistHexagon() || pManager->isExistriangle() || pManager->isExistcircle())
			pOut->PrintMessage("Fill figures first");
		else pOut->PrintMessage("Draw figures first");
	}

	
}

void pick_by_color::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();

	Output* pOut = pManager->GetOutput();
	pIn->GetPointClicked(p.x, p.y);
	if (p.y < 50 && p.x < 45.5 * 7) {
		if (p.x < 45.5)
			pManager->ExecuteAction(PICK_BY_FIGURE);
		if (p.x > 45.5 * 2 && p.x < 45.5 * 3)
			pManager->ExecuteAction(PICK_BY_COLOR);
		if (p.x > 45.5 * 4 && p.x < 45.5 * 5)
			pManager->ExecuteAction(PICK_BY_COLOR);
		if (p.x > 45.5 * 6 && p.x < 45.5 * 7)
			pManager->ExecuteAction(SWITCH_TO_DRAW);

	}
	else  fig = pManager->GetFigure(p.x, p.y);

	
}

void pick_by_color::Execute()
{
	Input* pIn = pManager->GetInput();

		Output* pOut = pManager->GetOutput();
		if (pManager->isexistfillfigure()) {
			do {
				ReadActionParameters();
			} while (fig == NULL && !(p.y < 50 && p.x < 45.5 * 7));
			if (!(p.y < 50 && p.x < 45.5 * 7)) {
				if (colors[randcol] == "Choose black figures")
					sel = 0;//to know what is the type of figures which will be deleted
				if (colors[randcol] == "Choose blue figures")
					sel = 1;
				if (colors[randcol] == "Choose green figures")
					sel = 2;
				if (colors[randcol] == "Choose yellow figures")
					sel = 3;
				if (colors[randcol] == "Choose red figures")
					sel = 4;
				if (colors[randcol] == "Choose orange figures")
					sel = 5;



				if (sel == 0) {
					if (fig->get_color() == BLACK) {
						pManager->setdelplay(fig);
						counterTrue++;
						if (!pManager->isExistcolor(BLACK))
							stop = true;//if there are no rectangles the play will stop

					}
					else counterFlase++;
					string tr = to_string(counterTrue);
					string fl = to_string(counterFlase);
					pOut->PrintMessage("You have choosed " + tr + " correct answers and  " + fl + " incorrect answers");
				}

				if (sel == 1) {
					if (fig->get_color() == BLUE) {
						pManager->setdelplay(fig);
						counterTrue++;
						if (!pManager->isExistcolor(BLUE))
							stop = true;
					}
					else counterFlase++;
					string tr = to_string(counterTrue);
					string fl = to_string(counterFlase);
					pOut->PrintMessage("You have choosed " + tr + " correct answers and  " + fl + " incorrect answers");

				}

				if (sel == 2) {
					if (fig->get_color() == GREEN) {
						pManager->setdelplay(fig);
						counterTrue++;
						if (!pManager->isExistcolor(GREEN))
							stop = true;
					}
					else counterFlase++;
					string tr = to_string(counterTrue);
					string fl = to_string(counterFlase);
					pOut->PrintMessage("You have choosed " + tr + " correct answers and  " + fl + " incorrect answers");
				}

				if (sel == 3) {
					if (fig->get_color() == YELLOW) {
						pManager->setdelplay(fig);
						counterTrue++;
						if (!pManager->isExistcolor(YELLOW))
							stop = true;
					}

					else counterFlase++;
					string tr = to_string(counterTrue);
					string fl = to_string(counterFlase);
					pOut->PrintMessage("You have choosed " + tr + " correct answers and  " + fl + " incorrect answers");
				}


				if (sel == 4) {
					if (fig->get_color() == RED) {
						pManager->setdelplay(fig);
						counterTrue++;
						if (!pManager->isExistcolor(RED))

							stop = true;
					}
					else counterFlase++;
					string tr = to_string(counterTrue);
					string fl = to_string(counterFlase);
					pOut->PrintMessage("You have choosed " + tr + " correct answers and  " + fl + " incorrect answers");
				}

				if (sel == 5) {
					if (fig->get_color() == ORANGE) {
						pManager->setdelplay(fig);
						counterTrue++;
						if (!pManager->isExistcolor(ORANGE))
							stop = true;
					}
					else counterFlase++;
					string tr = to_string(counterTrue);
					string fl = to_string(counterFlase);
					pOut->PrintMessage("You have choosed " + tr + " correct answers and  " + fl + " incorrect answers");
				}
				pManager->UpdateInterface();


				if (!stop)
					Execute();
				string t = to_string(counterTrue);
				string f = to_string(counterFlase);
				string g = to_string(counterTrue + counterFlase);
				pOut->PrintMessage("You have choosed " + t + " correct answers and  " + f + " incorrect answers the grade = " + t + "/" + g );
				Sleep(500);
				pOut->PrintMessage("You have choosed " + t + " correct answers and  " + f + " incorrect answers the grade = " + t + "/" + g + " let`s play again");
			}
			

			pManager->restore();//to restore the deleted figures
		}
		else {
				if ((pManager->isExistrectangle()) || (pManager->isExistsquare()) || (pManager->isExistHexagon()) || (pManager->isExistriangle()) || (pManager->isExistcircle()))
					pOut->PrintMessage("Fill figures first");
				else pOut->PrintMessage("Draw figures first");
		}
}
	

pick_by_color::~pick_by_color()
	{
		delete[]colors;
		colors = NULL;
	}
void pick_by_color::undo()
{}

void pick_by_color::redo()
{}

bool pick_by_color::isRecordable()
{
	return false;
}

