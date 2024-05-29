#include "pick_by_both.h"
#include "pick_by_color.h"
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
pick_by_both::pick_by_both(ApplicationManager* Ap):Action(Ap)
{
	Output* pOut = pManager->GetOutput();
	fig = NULL;
	if (pManager->isexistfillfigure()) {//check if exist fill figures or not

		int i = 0;
		if (pManager->isExistcolorfulrect(BLACK))
			i++;
		if (pManager->isExistcolorfulrect(BLUE))
			i++;
		if (pManager->isExistcolorfulrect(GREEN))
			i++;
		if (pManager->isExistcolorfulrect(YELLOW))
			i++;
		if (pManager->isExistcolorfulrect(RED))
			i++;
		if (pManager->isExistcolorfulrect(ORANGE))
			i++;

		if (pManager->isExistcolorfulhex(BLACK))
			i++;
		if (pManager->isExistcolorfulhex(BLUE))
			i++;
		if (pManager->isExistcolorfulhex(GREEN))
			i++;
		if (pManager->isExistcolorfulhex(YELLOW))
			i++;
		if (pManager->isExistcolorfulhex(RED))
			i++;
		if (pManager->isExistcolorfulhex(ORANGE))
			i++;

		if (pManager->isExistcolorfulsquare(BLACK))
			i++;
		if (pManager->isExistcolorfulsquare(BLUE))
			i++;
		if (pManager->isExistcolorfulsquare(GREEN))
			i++;
		if (pManager->isExistcolorfulsquare(YELLOW))
			i++;
		if (pManager->isExistcolorfulsquare(RED))
			i++;
		if (pManager->isExistcolorfulsquare(ORANGE))
			i++;

		if (pManager->isExistcolorfulcircle(BLACK))
			i++;
		if (pManager->isExistcolorfulcircle(BLUE))
			i++;
		if (pManager->isExistcolorfulcircle(GREEN))
			i++;
		if (pManager->isExistcolorfulcircle(YELLOW))
			i++;
		if (pManager->isExistcolorfulcircle(RED))
			i++;
		if (pManager->isExistcolorfulcircle(ORANGE))
			i++;

		if (pManager->isExistcolorfultri(BLACK))
			i++;
		if (pManager->isExistcolorfultri(BLUE))
			i++;
		if (pManager->isExistcolorfultri(GREEN))
			i++;
		if (pManager->isExistcolorfultri(YELLOW))
			i++;
		if (pManager->isExistcolorfultri(RED))
			i++;
		if (pManager->isExistcolorfultri(ORANGE))
			i++;
		figlist = new string[i];//making array of existing element
		int x = i;
		i = 0;
		if (pManager->isExistcolorfulrect(BLACK)) {
			figlist[i] = "choose black rectangles";
			i++;
		}
		if (pManager->isExistcolorfulrect(BLUE)) {
			figlist[i] = "choose blue rectangles";
			i++;
		}
		if (pManager->isExistcolorfulrect(GREEN)) {
			figlist[i] = "choose green rectangles";
			i++;
		}
		if (pManager->isExistcolorfulrect(YELLOW)) {
			figlist[i] = "choose yellow rectangles";
			i++;
		}
		if (pManager->isExistcolorfulrect(RED)) {
			figlist[i] = "choose red rectangles";
			i++;
		}
		if (pManager->isExistcolorfulrect(ORANGE)) {
			figlist[i] = "choose oreange rectangles";
			i++;
		}

		if (pManager->isExistcolorfulhex(BLACK)) {
			figlist[i] = "choose black hexagons";
			i++;
		}
		if (pManager->isExistcolorfulhex(BLUE)) {
			figlist[i] = "choose blue hexagons";
			i++;
		}
		if (pManager->isExistcolorfulhex(GREEN)) {
			figlist[i] = "choose green hexagons";
			i++;
		}
		if (pManager->isExistcolorfulhex(YELLOW)) {
			figlist[i] = "choose yellow hexagons";
			i++;
		}
		if (pManager->isExistcolorfulhex(RED)) {
			figlist[i] = "choose red hexagons";
			i++;
		}
		if (pManager->isExistcolorfulhex(ORANGE)) {
			figlist[i] = "choose orange hexagons";
			i++;
		}
		if (pManager->isExistcolorfulsquare(BLACK)) {
			figlist[i] = "choose black squares";
			i++;
		}
		if (pManager->isExistcolorfulsquare(BLUE)) {
			figlist[i] = "choose blue squares";
			i++;
		}
		if (pManager->isExistcolorfulsquare(GREEN)) {
			figlist[i] = "choose green squares";
			i++;
		}
		if (pManager->isExistcolorfulsquare(YELLOW)) {
			figlist[i] = "choose yellow squares";
			i++;
		}
		if (pManager->isExistcolorfulsquare(RED)) {
			figlist[i] = "choose red squares";
			i++;
		}
		if (pManager->isExistcolorfulsquare(ORANGE)) {
			figlist[i] = "choose orange squares";
			i++;
		}

		if (pManager->isExistcolorfulcircle(BLACK)) {
			figlist[i] = "choose black circles";
			i++;
		}
		if (pManager->isExistcolorfulcircle(BLUE)) {
			figlist[i] = "choose blue circles";
			i++;
		}
		if (pManager->isExistcolorfulcircle(GREEN)) {
			figlist[i] = "choose green circles";
			i++;
		}
		if (pManager->isExistcolorfulcircle(YELLOW)) {
			figlist[i] = "choose yellow circles";
			i++;
		}
		if (pManager->isExistcolorfulcircle(RED)) {
			figlist[i] = "choose red circles";
			i++;
		}
		if (pManager->isExistcolorfulcircle(ORANGE)) {
			figlist[i] = "choose orange circles";
			i++;
		}

		if (pManager->isExistcolorfultri(BLACK)) {
			figlist[i] = "choose black triangles";
			i++;
		}
		if (pManager->isExistcolorfultri(BLACK)) {
			figlist[i] = "choose blue triangles";
			i++;
		}
		if (pManager->isExistcolorfultri(GREEN)) {
			figlist[i] = "choose green triangles";
			i++;
		}
		if (pManager->isExistcolorfultri(YELLOW)) {
			figlist[i] = "choose yellow triangles";
			i++;
		}
		if (pManager->isExistcolorfultri(RED)) {
			figlist[i] = "choose red triangles";
			i++;
		}
		if (pManager->isExistcolorfultri(ORANGE)) {
			figlist[i] = "choose orange triangles";
			i++;
		}
			srand(time(0));
			randfig = rand() % x;//choosing random element to play by it
			pOut->PrintMessage( figlist[randfig]); 
	}
	else {
		if (pManager->isExistrectangle() || pManager->isExistsquare() || pManager->isExistHexagon() || pManager->isExistriangle() || pManager->isExistcircle())
			pOut->PrintMessage("Fill figures first");
		else pOut->PrintMessage("Draw figures first");
	}
}

void pick_by_both::ReadActionParameters()
{
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

void pick_by_both::undo()
{
}

void pick_by_both::redo()
{
}

bool pick_by_both::isRecordable()
{
	return false;
}

void pick_by_both::Execute()
{
	Input* pIn = pManager->GetInput();

	Output* pOut = pManager->GetOutput();
	if (pManager->isexistfillfigure()) {
		do {
			ReadActionParameters();
		} while (fig == NULL && !(p.y < 50 && p.x < 45.5 * 7));
		if (!(p.y < 50 && p.x < 45.5 * 7)) {
			if (figlist[randfig] == "choose black rectangles")
				sel = 0;//to know what is the type of figures which will be deleted
			if (figlist[randfig] == "choose blue rectangles")
				sel = 1;
			if (figlist[randfig] == "choose green rectangles")
				sel = 2;
			if (figlist[randfig] == "choose red rectangles")
				sel = 3;
			if (figlist[randfig] == "choose yellow rectangles")
				sel = 4;
			if (figlist[randfig] == "choose orange rectangles")
				sel = 5;
			if (figlist[randfig] == "choose black squares")
				sel = 6;
			if (figlist[randfig] == "choose blue squares")
				sel = 7;
			if (figlist[randfig] == "choose green squares")
				sel = 8;
			if (figlist[randfig] == "choose red squares")
				sel = 9;
			if (figlist[randfig] == "choose yellow squares")
				sel = 10;
			if (figlist[randfig] == "choose orange squares")
				sel = 11;
			if (figlist[randfig] == "choose black triangles")
				sel = 12;
			if (figlist[randfig] == "choose blue triangles")
				sel = 13;
			if (figlist[randfig] == "choose green triangles")
				sel = 14;
			if (figlist[randfig] == "choose red triangles")
				sel = 15;
			if (figlist[randfig] == "choose yellow triangles")
				sel = 16;
			if (figlist[randfig] == "choose orange triangles")
				sel = 17;
			if (figlist[randfig] == "choose black hexagons")
				sel = 18;
			if (figlist[randfig] == "choose blue hexagons")
				sel = 19;
			if (figlist[randfig] == "choose green hexagons")
				sel = 20;
			if (figlist[randfig] == "choose red hexagons")
				sel = 21;
			if (figlist[randfig] == "choose yellow hexagons")
				sel = 22;
			if (figlist[randfig] == "choose orange hexagons")
				sel = 23;
			if (figlist[randfig] == "choose black circles")
				sel = 24;
			if (figlist[randfig] == "choose blue circles")
				sel = 25;
			if (figlist[randfig] == "choose green circles")
				sel = 26;
			if (figlist[randfig] == "choose red circles")
				sel = 27;
			if (figlist[randfig] == "choose yellow circles")
				sel = 28;
			if (figlist[randfig] == "choose orange circles")
				sel = 29;
			if (sel == 0) {
				if ((fig->get_color() == BLACK) && (dynamic_cast<CRectangle*>(fig) != NULL)) {
					pManager->setdelplay(fig);
					counterTrue++;
					if (!pManager->isExistcolorfulrect(BLACK))
						stop = true;//if there are no rectangles the play will stop

				}
				else counterFlase++;
				string tr = to_string(counterTrue);
				string fl = to_string(counterFlase);
				pOut->PrintMessage("You have choosed " + tr + " correct answers and  " + fl + " incorrect answers");
			}
			if (sel == 1) {
				if ((fig->get_color() == BLUE) && (dynamic_cast<CRectangle*>(fig) != NULL)) {
					pManager->setdelplay(fig);
					counterTrue++;
					if (!pManager->isExistcolorfulrect(BLUE))
						stop = true;

				}
				else counterFlase++;
				string tr = to_string(counterTrue);
				string fl = to_string(counterFlase);
				pOut->PrintMessage("You have choosed " + tr + " correct answers and  " + fl + " incorrect answers");
			}
			if (sel == 2) {
				if ((fig->get_color() == GREEN) && (dynamic_cast<CRectangle*>(fig) != NULL)) {
					pManager->setdelplay(fig);
					counterTrue++;
					if (!pManager->isExistcolorfulrect(GREEN))
						stop = true;

				}
				else counterFlase++;
				string tr = to_string(counterTrue);
				string fl = to_string(counterFlase);
				pOut->PrintMessage("You have choosed " + tr + " correct answers and  " + fl + " incorrect answers");
			}
			if (sel == 3) {
				if ((fig->get_color() == RED) && (dynamic_cast<CRectangle*>(fig) != NULL)) {
					pManager->setdelplay(fig);
					counterTrue++;
					if (!pManager->isExistcolorfulrect(RED))
						stop = true;

				}
				else counterFlase++;
				string tr = to_string(counterTrue);
				string fl = to_string(counterFlase);
				pOut->PrintMessage("You have choosed " + tr + " correct answers and  " + fl + " incorrect answers");
			}
			if (sel == 4) {
				if ((fig->get_color() == YELLOW) && (dynamic_cast<CRectangle*>(fig) != NULL)) {
					pManager->setdelplay(fig);
					counterTrue++;
					if (!pManager->isExistcolorfulrect(YELLOW))
						stop = true;

				}
				else counterFlase++;
				string tr = to_string(counterTrue);
				string fl = to_string(counterFlase);
				pOut->PrintMessage("You have choosed " + tr + " correct answers and  " + fl + " incorrect answers");
			}
			if (sel == 5) {
				if ((fig->get_color() == ORANGE) && (dynamic_cast<CRectangle*>(fig) != NULL)) {
					pManager->setdelplay(fig);
					counterTrue++;
					if (!pManager->isExistcolorfulrect(ORANGE))
						stop = true;

				}
				else counterFlase++;
				string tr = to_string(counterTrue);
				string fl = to_string(counterFlase);
				pOut->PrintMessage("You have choosed " + tr + " correct answers and  " + fl + " incorrect answers");
			}
			if (sel == 6) {
				if ((fig->get_color() == BLACK) && (dynamic_cast<CSquare*>(fig) != NULL)) {
					pManager->setdelplay(fig);
					counterTrue++;
					if (!pManager->isExistcolorfulsquare(BLACK))
						stop = true;

				}
				else counterFlase++;
				string tr = to_string(counterTrue);
				string fl = to_string(counterFlase);
				pOut->PrintMessage("You have choosed " + tr + " correct answers and  " + fl + " incorrect answers");
			}
			if (sel == 7) {
				if ((fig->get_color() == BLUE) && (dynamic_cast<CSquare*>(fig) != NULL)) {
					pManager->setdelplay(fig);
					counterTrue++;
					if (!pManager->isExistcolorfulsquare(BLUE))
						stop = true;

				}
				else counterFlase++;
				string tr = to_string(counterTrue);
				string fl = to_string(counterFlase);
				pOut->PrintMessage("You have choosed " + tr + " correct answers and  " + fl + " incorrect answers");
			}
			if (sel == 8) {
				if ((fig->get_color() == GREEN) && (dynamic_cast<CSquare*>(fig) != NULL)) {
					pManager->setdelplay(fig);
					counterTrue++;
					if (!pManager->isExistcolorfulsquare(GREEN))
						stop = true;

				}
				else counterFlase++;
				string tr = to_string(counterTrue);
				string fl = to_string(counterFlase);
				pOut->PrintMessage("You have choosed " + tr + " correct answers and  " + fl + " incorrect answers");
			}
			if (sel == 9) {
				if ((fig->get_color() == RED) && (dynamic_cast<CSquare*>(fig) != NULL)) {
					pManager->setdelplay(fig);
					counterTrue++;
					if (!pManager->isExistcolorfulsquare(RED))
						stop = true;

				}
				else counterFlase++;
				string tr = to_string(counterTrue);
				string fl = to_string(counterFlase);
				pOut->PrintMessage("You have choosed " + tr + " correct answers and  " + fl + " incorrect answers");
			}
			if (sel == 10) {
				if ((fig->get_color() == YELLOW) && (dynamic_cast<CSquare*>(fig) != NULL)) {
					pManager->setdelplay(fig);
					counterTrue++;
					if (!pManager->isExistcolorfulsquare(YELLOW))
						stop = true;

				}
				else counterFlase++;
				string tr = to_string(counterTrue);
				string fl = to_string(counterFlase);
				pOut->PrintMessage("You have choosed " + tr + " correct answers and  " + fl + " incorrect answers");
			}
			if (sel == 11) {
				if ((fig->get_color() == ORANGE) && (dynamic_cast<CSquare*>(fig) != NULL)) {
					pManager->setdelplay(fig);
					counterTrue++;
					if (!pManager->isExistcolorfulsquare(ORANGE))
						stop = true;

				}
				else counterFlase++;
				string tr = to_string(counterTrue);
				string fl = to_string(counterFlase);
				pOut->PrintMessage("You have choosed " + tr + " correct answers and  " + fl + " incorrect answers");
			}
			if (sel == 12) {
				if ((fig->get_color() == BLACK) && (dynamic_cast<CTriangle*>(fig) != NULL)) {
					pManager->setdelplay(fig);
					counterTrue++;
					if (!pManager->isExistcolorfultri(BLACK))
						stop = true;

				}
				else counterFlase++;
				string tr = to_string(counterTrue);
				string fl = to_string(counterFlase);
				pOut->PrintMessage("You have choosed " + tr + " correct answers and  " + fl + " incorrect answers");
			}
			if (sel == 13) {
				if ((fig->get_color() == BLUE) && (dynamic_cast<CTriangle*>(fig) != NULL)) {
					pManager->setdelplay(fig);
					counterTrue++;
					if (!pManager->isExistcolorfultri(BLUE))
						stop = true;

				}
				else counterFlase++;
				string tr = to_string(counterTrue);
				string fl = to_string(counterFlase);
				pOut->PrintMessage("You have choosed " + tr + " correct answers and  " + fl + " incorrect answers");
			}
			if (sel == 14) {
				if ((fig->get_color() == GREEN) && (dynamic_cast<CTriangle*>(fig) != NULL)) {
					pManager->setdelplay(fig);
					counterTrue++;
					if (!pManager->isExistcolorfultri(GREEN))
						stop = true;

				}
				else counterFlase++;
				string tr = to_string(counterTrue);
				string fl = to_string(counterFlase);
				pOut->PrintMessage("You have choosed " + tr + " correct answers and  " + fl + " incorrect answers");
			}
			if (sel == 15) {
				if ((fig->get_color() == RED) && (dynamic_cast<CTriangle*>(fig) != NULL)) {
					pManager->setdelplay(fig);
					counterTrue++;
					if (!pManager->isExistcolorfultri(RED))
						stop = true;

				}
				else counterFlase++;
				string tr = to_string(counterTrue);
				string fl = to_string(counterFlase);
				pOut->PrintMessage("You have choosed " + tr + " correct answers and  " + fl + " incorrect answers");
			}
			if (sel == 16) {
				if ((fig->get_color() == YELLOW) && (dynamic_cast<CTriangle*>(fig) != NULL)) {
					pManager->setdelplay(fig);
					counterTrue++;
					if (!pManager->isExistcolorfultri(YELLOW))
						stop = true;

				}
				else counterFlase++;
				string tr = to_string(counterTrue);
				string fl = to_string(counterFlase);
				pOut->PrintMessage("You have choosed " + tr + " correct answers and  " + fl + " incorrect answers");
			}
			if (sel == 17) {
				if ((fig->get_color() == ORANGE) && (dynamic_cast<CTriangle*>(fig) != NULL)) {
					pManager->setdelplay(fig);
					counterTrue++;
					if (!pManager->isExistcolorfultri(ORANGE))
						stop = true;

				}
				else counterFlase++;
				string tr = to_string(counterTrue);
				string fl = to_string(counterFlase);
				pOut->PrintMessage("You have choosed " + tr + " correct answers and  " + fl + " incorrect answers");
			}
			if (sel == 18) {
				if ((fig->get_color() == BLACK) && (dynamic_cast<CHexagon*>(fig) != NULL)) {
					pManager->setdelplay(fig);
					counterTrue++;
					if (!pManager->isExistcolorfulhex(BLACK))
						stop = true;

				}
				else counterFlase++;
				string tr = to_string(counterTrue);
				string fl = to_string(counterFlase);
				pOut->PrintMessage("You have choosed " + tr + " correct answers and  " + fl + " incorrect answers");
			}
			if (sel == 19) {
				if ((fig->get_color() == BLUE) && (dynamic_cast<CHexagon*>(fig) != NULL)) {
					pManager->setdelplay(fig);
					counterTrue++;
					if (!pManager->isExistcolorfulhex(BLUE))
						stop = true;

				}
				else counterFlase++;
				string tr = to_string(counterTrue);
				string fl = to_string(counterFlase);
				pOut->PrintMessage("You have choosed " + tr + " correct answers and  " + fl + " incorrect answers");
			}
			if (sel == 20) {
				if ((fig->get_color() == GREEN) && (dynamic_cast<CHexagon*>(fig) != NULL)) {
					pManager->setdelplay(fig);
					counterTrue++;
					if (!pManager->isExistcolorfulhex(GREEN))
						stop = true;

				}
				else
					counterFlase++;
				string tr = to_string(counterTrue);
				string fl = to_string(counterFlase);
				pOut->PrintMessage("You have choosed " + tr + " correct answers and  " + fl + " incorrect answers");

			}
			if (sel == 21) {
				if ((fig->get_color() == RED) && (dynamic_cast<CHexagon*>(fig) != NULL)) {
					pManager->setdelplay(fig);
					counterTrue++;
					if (!pManager->isExistcolorfulhex(RED))
						stop = true;

				}
				else counterFlase++;
				string tr = to_string(counterTrue);
				string fl = to_string(counterFlase);
				pOut->PrintMessage("You have choosed " + tr + " correct answers and  " + fl + " incorrect answers");
			}
			if (sel == 22) {
				if ((fig->get_color() == YELLOW) && (dynamic_cast<CHexagon*>(fig) != NULL)) {
					pManager->setdelplay(fig);
					counterTrue++;
					if (!pManager->isExistcolorfulhex(YELLOW))
						stop = true;

				}
				else counterFlase++;
				string tr = to_string(counterTrue);
				string fl = to_string(counterFlase);
				pOut->PrintMessage("You have choosed " + tr + " correct answers and  " + fl + " incorrect answers");
			}
			if (sel == 23) {
				if ((fig->get_color() == ORANGE) && (dynamic_cast<CHexagon*>(fig) != NULL)) {
					pManager->setdelplay(fig);
					counterTrue++;
					if (!pManager->isExistcolorfulhex(ORANGE))
						stop = true;

				}
				else counterFlase++;
				string tr = to_string(counterTrue);
				string fl = to_string(counterFlase);
				pOut->PrintMessage("You have choosed " + tr + " correct answers and  " + fl + " incorrect answers");
			}
			if (sel == 24) {
				if ((fig->get_color() == BLACK) && (dynamic_cast<CCircle*>(fig) != NULL)) {
					pManager->setdelplay(fig);
					if (!pManager->isExistcolorfulcircle(BLACK))
						stop = true;

				}
				else counterFlase++;
				string tr = to_string(counterTrue);
				string fl = to_string(counterFlase);
				pOut->PrintMessage("You have choosed " + tr + " correct answers and  " + fl + " incorrect answers");
			}
			if (sel == 25) {
				if ((fig->get_color() == BLUE) && (dynamic_cast<CCircle*>(fig) != NULL)) {
					pManager->setdelplay(fig);
					counterTrue++;
					if (!pManager->isExistcolorfulcircle(BLUE))
						stop = true;

				}
				else counterFlase++;
				string tr = to_string(counterTrue);
				string fl = to_string(counterFlase);
				pOut->PrintMessage("You have choosed " + tr + " correct answers and  " + fl + " incorrect answers");
			}
			if (sel == 26) {
				if ((fig->get_color() == GREEN) && (dynamic_cast<CCircle*>(fig) != NULL)) {
					pManager->setdelplay(fig);
					counterTrue++;
					if (!pManager->isExistcolorfulcircle(GREEN))
						stop = true;

				}
				else counterFlase++;
				string tr = to_string(counterTrue);
				string fl = to_string(counterFlase);
				pOut->PrintMessage("You have choosed " + tr + " correct answers and  " + fl + " incorrect answers");
			}
			if (sel == 27) {
				if ((fig->get_color() == RED) && (dynamic_cast<CCircle*>(fig) != NULL)) {
					pManager->setdelplay(fig);
					counterTrue++;
					if (!pManager->isExistcolorfulcircle(RED))
						stop = true;

				}
				else counterFlase++;
				string tr = to_string(counterTrue);
				string fl = to_string(counterFlase);
				pOut->PrintMessage("You have choosed " + tr + " correct answers and  " + fl + " incorrect answers");
			}
			if (sel == 28) {
				if ((fig->get_color() == YELLOW) && (dynamic_cast<CCircle*>(fig) != NULL)) {
					pManager->setdelplay(fig);
					counterTrue++;
					if (!pManager->isExistcolorfulcircle(YELLOW))
						stop = true;

				}
				else counterFlase++;
				string tr = to_string(counterTrue);
				string fl = to_string(counterFlase);
				pOut->PrintMessage("You have choosed " + tr + " correct answers and  " + fl + " incorrect answers");
			}
			if (sel == 29) {
				if ((fig->get_color() == ORANGE) && (dynamic_cast<CCircle*>(fig) != NULL)) {
					pManager->setdelplay(fig);
					counterTrue++;
					if (!pManager->isExistcolorfulcircle(ORANGE))
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
			pOut->PrintMessage("You have choosed " + t + " correct answers and  " + f + " incorrect answers the grade = " + t + "/" + g);
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

pick_by_both::~pick_by_both()
{
	delete[]figlist;
	figlist = NULL;
}
