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
	if (pManager->isexistfillfigure()) {

		int i = 0;
		if (pManager->isExistBlack())
			i++;
		if (pManager->isExistblue())
			i++;
		if (pManager->isExistgreen())
			i++;
		if (pManager->isExistyellow())
			i++;
		if (pManager->isExistred())
			i++;
		if (pManager->isExistorange())
			i++;
		int x = i;
		i = 0;
		colors = new string[x];
		if (pManager->isExistBlack())
			colors[i++] = "Chose black figures";
		if (pManager->isExistblue())
			colors[i++] = "Chose blue figures";
		if (pManager->isExistgreen())
			colors[i++] = "Chose green figures";
		if (pManager->isExistyellow())
			colors[i++] = "Chose yellow figures";
		if (pManager->isExistred())
			colors[i++] = "Chose red figures";
		if (pManager->isExistorange())
			colors[i++] = "Chose orange figures";
		srand(time(0));
		randcol = rand() % x;
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
	fig = pManager->GetFigure(p.x, p.y);
	if(fig==NULL){
		counterTrue--;
		Execute();
	}


	
}

void pick_by_color::Execute()
{
		Output* pOut = pManager->GetOutput();
	if (pManager->isexistfillfigure()) {
	pOut->PrintMessage(colors[randcol]);
	ReadActionParameters();
	if (colors[randcol] == "Chose black figures")
		sel = 0;
	if (colors[randcol] == "Chose blue figures")
		sel = 1;
	if (colors[randcol] == "Chose green figures")
		sel = 2;
	if (colors[randcol] == "Chose yellow figures")
		sel = 3;
	if (colors[randcol] == "Chose red figures")
		sel = 4;
	if (colors[randcol] == "Chose orange figures")
		sel = 5;


		
			if (sel == 0) {
				if (fig->get_color() == BLACK) {
					pManager->setdel(fig);
					counterTrue++;
					if (!pManager->isExistBlack())
						stop = true;
				}
				else counterFlase++;
			}

			 if (sel == 1) {
				if (fig->get_color() == BLUE) {
					pManager->setdel(fig);
					counterTrue++;
					if (!pManager->isExistblue())
						stop = true;
				}
				else counterFlase++;

			}

			 if (sel == 2) {
				if (fig->get_color() == GREEN) {
					pManager->setdel(fig);
					counterTrue++;
					if (!pManager->isExistgreen())
						stop = true;
				}
				else counterFlase++;
			}

			 if (sel == 3) {
				if (fig->get_color() == YELLOW) {
					pManager->setdel(fig);
					counterTrue++;
					if (!pManager->isExistyellow())
						stop = true;
				}
				else counterFlase++;
			}

			 if (sel == 4) {
				if (fig->get_color() == RED) {
					pManager->setdel(fig);
					counterTrue++;
					if (!pManager->isExistred())
						stop = true;
				}
				else counterFlase++;
			}

			if (sel == 5) {
				if (fig->get_color() == ORANGE) {
					pManager->setdel(fig);
					counterTrue++;
					if (!pManager->isExistorange())
						stop = true;
				}
				else counterFlase++;
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
		if ((pManager->isExistrectangle()) ||( pManager->isExistsquare()) || (pManager->isExistHexagon()) ||( pManager->isExistriangle() )||( pManager->isExistcircle()))
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

