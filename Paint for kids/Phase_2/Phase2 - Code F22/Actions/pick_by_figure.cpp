#include "pick_by_figure.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"
#include"..\ApplicationManager.h"
#include"..\Figures/CFigure.h"
#include<iostream>
#include"../Figures/CCircle.h"
#include"../Figures/CRectangle.h"
#include"../Figures/CTriangle.h"
#include"../Figures/CHexagon.h"
#include"../Figures/CSquare.h"
using namespace std;
pick_by_figure::pick_by_figure(ApplicationManager* Ap) :Action(Ap)
{
	Output* pOut = pManager->GetOutput();

	fig = NULL;
	if (pManager->isExistrectangle()|| pManager->isExistsquare()|| pManager->isExistHexagon()|| pManager->isExistriangle()|| pManager->isExistcircle()) {//check if exist figures or not
		int i = 0;
		if (pManager->isExistrectangle()) {
			i++;
		}
		if (pManager->isExistsquare()) {
			i++;
		} if (pManager->isExistHexagon()) {
			i++;
		} if (pManager->isExistriangle()) {
			i++;
		} if (pManager->isExistcircle()) {
			i++;
		}
		figlist = new string[i];//making array of existing element
		int x = i;
		i = 0;
			if (pManager->isExistrectangle()) {
				figlist[i++] = "Rectangles";
			}
			if (pManager->isExistsquare()) {
				figlist[i++] = "Squares";
			} if (pManager->isExistHexagon()) {
				figlist[i++] = "Hexagons";
			} if (pManager->isExistriangle()) {
				figlist[i++] = "Triangles";
			} if (pManager->isExistcircle()) {
				figlist[i++] = "Circles";
			}
		srand(time(0));
		randfig = rand() % (x);//choosing random element to play by it
		if (figlist[randfig] == "Rectangles")
			sel = 0;//to know what is the type of figures which will be deleted
		if (figlist[randfig] == "Squares")
			sel = 1;
		if (figlist[randfig] == "Hexagons")
			sel = 2;
		if (figlist[randfig] == "Triangles")
			sel = 3;
		if (figlist[randfig] == "Circles")
			sel = 4;
		pOut->PrintMessage("Select  " + figlist[randfig]);
	}
	else {
		pOut->PrintMessage("Draw figures first");
	}
}
void pick_by_figure::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
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
	else fig = pManager->GetFigure(p.x, p.y);
	
}

void pick_by_figure::Execute()
{
	Input* pIn = pManager->GetInput();

	Output* pOut = pManager->GetOutput();
	if (pManager->isExistrectangle() || pManager->isExistsquare() || pManager->isExistHexagon() || pManager->isExistriangle() || pManager->isExistcircle()) {


		do {
			ReadActionParameters();
		} while (fig == NULL && !(p.y < 50 && p.x < 45.5 * 7));
		if (!(p.y < 50 && p.x < 45.5 * 7)) {
			if (sel == 0) {
				if (dynamic_cast<CRectangle*>(fig) != NULL) {
					counterTrue++;
					pManager->setdelplay(fig);
					if (!pManager->isExistrectangle()) {
						stop = true;//if there are no rectangles the play will stop
					}
				}

				else
					counterFlase++;

				string tr = to_string(counterTrue);
				string fl = to_string(counterFlase);
				pOut->PrintMessage("You have choosed " + tr + " correct answers and  " + fl + " incorrect answers");

			}
			else if (sel == 1) {
				if (dynamic_cast<CSquare*>(fig) != NULL) {
					counterTrue++;
					pManager->setdelplay(fig);
					if (!pManager->isExistsquare()) {
						stop = true;
					}
				}
				else
					counterFlase++;
				string tr = to_string(counterTrue);
				string fl = to_string(counterFlase);
				pOut->PrintMessage("You have choosed " + tr + " correct answers and  " + fl + " incorrect answers");

			}
			else if (sel == 2) {
				if (dynamic_cast<CHexagon*>(fig) != NULL) {
					counterTrue++;
					pManager->setdelplay(fig);
					if (!pManager->isExistHexagon()) {
						stop = true;
					}
				}
				else
					counterFlase++;
				string tr = to_string(counterTrue);
				string fl = to_string(counterFlase);
				pOut->PrintMessage("You have choosed " + tr + " correct answers and  " + fl + " incorrect answers");

			}
			else if (sel == 3) {
				if (dynamic_cast<CTriangle*>(fig) != NULL) {
					counterTrue++;
					pManager->setdelplay(fig);
					if (!pManager->isExistriangle()) {
						stop = true;
					}
				}
				else
					counterFlase++;
				string tr = to_string(counterTrue);
				string fl = to_string(counterFlase);
				pOut->PrintMessage("You have choosed " + tr + " correct answers and  " + fl + " incorrect answers");

			}
			else {
				if (dynamic_cast<CCircle*>(fig) != NULL) {
					counterTrue++;
					pManager->setdelplay(fig);
					if (!pManager->isExistcircle()) {
						stop = true;
					}
				}
				else
					counterFlase++;
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
			pOut->PrintMessage("You have choosed " + t + " correct answers and  " + f + " incorrect answers the grade = " + t + "/" + g);
			Sleep(500);
			pOut->PrintMessage("You have choosed " + t + " correct answers and  " + f + " incorrect answers the grade = " + t + "/" + g+" let`s play again");
		}
		pManager->restore();//to restore the deleted figures
	}
		else {
			pOut->PrintMessage("Draw figures first");
		}
	
}

pick_by_figure::~pick_by_figure()
{
	delete[]figlist;
	figlist = NULL;
}
void pick_by_figure::undo()
{}

void pick_by_figure::redo()
{}

bool pick_by_figure::isRecordable()
{
	return false;
}

