#include "pick_by_figure.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"
#include"..\ApplicationManager.h"
#include"..\Figures/CFigure.h"
#include<iostream>
#include"Figures/CCircle.h"
#include"Figures/CRectangle.h"
#include"Figures/CTriangle.h"
#include"Figures/CHexagon.h"
#include"Figures/CSquare.h"
using namespace std;
pick_by_figure::pick_by_figure(ApplicationManager* Ap) :Action(Ap)
{
	Output* pOut = pManager->GetOutput();

	fig = NULL;
	if (pManager->isExistrectangle()|| pManager->isExistsquare()|| pManager->isExistHexagon()|| pManager->isExistriangle()|| pManager->isExistcircle()) {
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
		figlist = new string[i];
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
		randfig = rand() % (x);
		if (figlist[randfig] == "Rectangles")
			sel = 0;
		if (figlist[randfig] == "Squares")
			sel = 1;
		if (figlist[randfig] == "Hexagons")
			sel = 2;
		if (figlist[randfig] == "Triangles")
			sel = 3;
		if (figlist[randfig] == "Circles")
			sel = 4;


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
	fig = pManager->GetFigure(p.x, p.y);
	if (fig == NULL) {
		counterTrue--;
		Execute();
	}
}

void pick_by_figure::Execute()
{
	Output* pOut = pManager->GetOutput();
	if (pManager->isExistrectangle() || pManager->isExistsquare() || pManager->isExistHexagon() || pManager->isExistriangle() || pManager->isExistcircle()) {
		pOut->PrintMessage("Select  " + figlist[randfig]);
		ReadActionParameters();


		if (sel == 0) {
			if (dynamic_cast<CRectangle*>(fig) != NULL) {
				counterTrue++;
				pManager->setdel(fig);
				if (!pManager->isExistrectangle()) {
					stop = true;
				}
			}
			else {
				counterFlase++;
			}
		}
		else if (sel == 1) {
			if (dynamic_cast<CSquare*>(fig) != NULL) {
				counterTrue++;
				pManager->setdel(fig);
				if (!pManager->isExistsquare()) {
					stop = true;
				}
			}
			else {
				counterFlase++;
			}
		}
		else if (sel == 2) {
			if (dynamic_cast<CHexagon*>(fig) != NULL) {
				counterTrue++;
				pManager->setdel(fig);
				if (!pManager->isExistHexagon()) {
					stop = true;
				}
			}
				else {
					counterFlase++;
				}
		}
		else if (sel == 3) {
			if (dynamic_cast<CTriangle*>(fig) != NULL) {
				counterTrue++;
				pManager->setdel(fig);
				if (!pManager->isExistriangle()) {
					stop = true;
				}
			}
				else {
					counterFlase++;
				}
		}
		else   {
			if (dynamic_cast<CCircle*>(fig) != NULL) {
				counterTrue++;
				pManager->setdel(fig);
				if (!pManager->isExistcircle()) {
					stop = true;
				}
			}
				else {
					counterFlase++;
				}
		}
		pManager->UpdateInterface();
		if (!stop)
			Execute();
		string t = to_string(counterTrue);
		string f = to_string(counterFlase);
		string g = to_string(counterTrue + counterFlase);
		pOut->PrintMessage("You have choosed " + t + " correct answers and  " + f + " incorrect answers the grade = " + t + "/" + g);
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

