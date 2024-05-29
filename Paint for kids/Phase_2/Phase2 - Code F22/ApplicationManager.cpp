#include "ApplicationManager.h"
#include "Actions\Delete.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddSqAction.h"
#include "Actions\AddTriAction.h"
#include "Actions\AddHexAction.h"
#include "Actions\AddCircAction.h"
#include"Actions/pick_by_figure.h"
#include "Actions/SaveAction.h"
#include "Actions/LoadAction.h"
#include"Actions/Move.h"
#include "Actions/DrawColorAction.h"
#include "Actions\Select.h"
#include "Actions/FillColorAction.h"
#include "Actions/ClearAction.h"
#include"Actions/Switch_to_play.h"
#include"Figures/CCircle.h"
#include"Figures/CRectangle.h"
#include"Figures/CTriangle.h"
#include"Figures/CHexagon.h"
#include"Figures/CSquare.h"
#include"Actions/pick_by_color.h"
#include "Actions\Undo.h"
#include "Actions\Redo.h"
#include "Actions\RecordAction.h"
#include "Actions/StopRecAction.h"
#include "Actions/PlayRecAction.h"
#include "Actions\Action.h"
#include "Actions/pick_by_both.h"
#include "Actions/SwitchToDraw.h"

void ApplicationManager::setdelplay(CFigure*a)
{
	for (int i = 0; i < 200; i++) {
		if (a == FigList[i]) {
			for (int k = 0; i < 200; k++) {
				if (delpFigList[k] == NULL) {
					delpFigList[k] = FigList[i];
					break;
				}
			}
			FigList[i] = NULL;
			break;
		}
	}
}

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	sharedcount = 0;
	FigCount = 0;
	delfigcount = 0;
	Arrcount_undo = 0;
	recActsCount = 0;
	isRecording = false;
	isPlaying = false;

	//Create an array of figure pointers and set them to NULL		
	for (int i = 0; i < MaxFigCount; i++) 
		FigList[i] = NULL;
	for (int i = 0; i < MaxFigCount; i++)
		delpFigList[i] = NULL;
	
	for (int i = 0; i < MaxFigCount; i++)
		deletedfigures[i] = NULL;
	//Create an array of recorded actions and set them to NULL
	for (int i = 0; i < 20; i++)
		recActs[i] = NULL;

	for (int i = 0; i < 5; i++)
	{
		ArrAction_undo[i] = NULL;
		ArrAction_redo[i] = NULL;
	}
	set = false;
	check_redo = false;
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case DRAW_RECTANGLE:
		if (pOut->Sound())
			PlaySound("sound effects\\Rectangle.wav", NULL, SND_ASYNC);
		pAct = new AddRectAction(this);
		break;

	case DRAW_SQARE:
		if (pOut->Sound())
			PlaySound("sound effects\\Square.wav", NULL, SND_ASYNC);
		pAct = new AddSqAction(this);
		break;
	case DRAW_TRIANGLE:
		if (pOut->Sound())
			PlaySound("sound effects\\Triangle.wav", NULL, SND_ASYNC);
		pAct = new AddTriAction(this);
		break;

	case DRAW_CIRCLE:
		if (pOut->Sound())
			PlaySound("sound effects\\Circle.wav", NULL, SND_ASYNC);
		pAct = new AddCircAction(this);
		break;

	case DRAW_HEXOGONAL:
		if (pOut->Sound())
			PlaySound("sound effects\\Hexagon.wav", NULL, SND_ASYNC);
		pAct = new AddHexAction(this);
		break;

	case SAVE:
		pAct = new SaveAction(this);
		break;
	case LOAD:
		pAct = new LoadAction(this);
		break;
	case MOVE:
		pAct = new Move(this);
		break;
	case SWITCH_TO_PLAY:
		pAct = new Switch_to_play(this);
		break;
	case PICK_BY_FIGURE:
		pAct = new pick_by_figure(this);
		break;
	case PICK_BY_COLOR:
		pAct = new pick_by_color(this);
		break;
	case BOTH:
		pAct = new pick_by_both(this);
		break;
	case SOUND:
		pOut->CreateDrawToolBar();
		break;

	case SELECT:
		pAct = new Select(this);
		break;
	case BORDER:
		pAct = new DrawColorAction(this);
		break;
	case FILL:
		pAct = new FillColorAction(this);
		break;
	case CLEAR:
		pAct = new ClearAction(this);
		break;
	case DEL:
		pAct = new Delete(this);
		break;
	case UNDO:
		pAct = new Undo(this);
		break;
	case REDO:
		pAct = new Redo(this);
		break;
	case REC:
		pAct = new RecordAction(this);
		break;
	case STOP:
		pAct = new StopRecAction(this);
		break;
	case PLAY:
		pAct = new PlayRecAction(this);
		break;
	case SWITCH_TO_DRAW:
		pAct = new SwitchToDraw(this);
		break;

	case EXIT:
		///create ExitAction here
		ClearDrawArea();
		break;
	
		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	if(pAct != NULL)
	{
		pAct->Execute();	//Execute
		setAction(pAct);
		if (dynamic_cast<Redo*>(pAct) || dynamic_cast<Undo*>(pAct))
			check_redo = true;
		else check_redo = false;
		if (isRecording && pAct->isRecordable()) {
			if (recActsCount < 20)
				recActs[recActsCount++] = pAct;
			else {
				isRecording = false;
			}
		}
		else if (!set)
		{
			
			delete pAct;
			pAct = NULL;
		}
	}
	
	//Execute the created action
}
	
	
bool ApplicationManager::get_check_redo()
{
	return check_redo;
}

//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;	
}

void ApplicationManager::SaveAll(ofstream& File)
{
	for (int i = 0; i < FigCount; i++) {
		if(FigList[i]!=NULL)
		FigList[i]->Save(File);
	}
}
void ApplicationManager::setAction(Action* pAct)
{
	if (pAct != NULL)
	{
		if (dynamic_cast<AddHexAction*>(pAct)|| dynamic_cast<AddRectAction*>(pAct)|| dynamic_cast<AddSqAction*>(pAct)|| dynamic_cast<AddTriAction*>(pAct)|| dynamic_cast<AddCircAction*>(pAct)||dynamic_cast<Move*>(pAct)|| dynamic_cast<DrawColorAction*>(pAct)|| dynamic_cast<FillColorAction*>(pAct)|| dynamic_cast<Delete*>(pAct))
		{
			if (Arrcount_undo == 5)
			{
				/*if (!(isRecording && ArrAction_undo[0]->isRecordable()) && !isPlaying)
				{
					delete ArrAction_undo[0];
					ArrAction_undo[0] = NULL;
				}*/
				for (int i = 0; i < Arrcount_undo - 1; i++)
					ArrAction_undo[i] = ArrAction_undo[i + 1];
				ArrAction_undo[Arrcount_undo - 1] = pAct;
			}
			else
				ArrAction_undo[Arrcount_undo++] = pAct;
			set = true;
		}
		else set = false;
	}
}

Action* ApplicationManager::LastAction_undo()
{
	bool flag = true;
	for (sharedcount = Arrcount_undo - 1; sharedcount >= 0 && flag; sharedcount--)
	{
		if (ArrAction_undo[sharedcount])
		{
			flag = false;
			ArrAction_redo[sharedcount] = ArrAction_undo[sharedcount];
			Arrcount_undo--;
			return ArrAction_undo[sharedcount];
		}
	}
	if (flag)
		return NULL;
}
Action* ApplicationManager::LastAction_redo()
{
	bool flag = true;
	if (sharedcount == -1)
		sharedcount = 0;
	for (int i = sharedcount; i < 5 && flag; i++)
		if (ArrAction_redo[i])
		{
			flag = false;
			sharedcount++;
			return ArrAction_redo[i];
		}
	if (flag)
		return NULL;
}

////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL
	bool flag = true;
	for (int i = 0; (i < FigCount)&&flag; i++)
	{
		if (FigList[i] != NULL)
		{
			if (FigList[i]->is_in(x, y))
			{
				return FigList[i];
				flag = false;
			}
		}
	}
	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.
	if  (flag)
	return NULL;
}
CFigure* ApplicationManager::GetLatestFig()
{
	bool flag = true;
	for (int i = 0; (i < FigCount)&&flag; i++)
		if (FigList[i] != NULL)
			if (FigList[i]->IsSelected())
			{
				return FigList[i];   flag = false; 
			}
	if (flag)
		return NULL;
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//
void ApplicationManager::setdel(CFigure* f) 
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i] == f)
		{
			deletedfigures[delfigcount++]=FigList[i];
			FigCount--;
			FigList[i] = FigList[FigCount];
		}
	}
}
void ApplicationManager::un_del(CFigure* f) //to undo delete action
{
	FigList[FigCount++] = deletedfigures[delfigcount - 1];
	deletedfigures[delfigcount - 1] = NULL;
	delfigcount--;
}
//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	pOut->ClearDrawArea();
	//clear drawing area
	for (int i = 0; i < FigCount; i++)
		if (FigList[i])
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
void ApplicationManager::ClearDrawArea()
{
	for (int i = 0; i < FigCount; i++) {
		delete FigList[i];
		FigList[i] = NULL;
	}
	FigCount = 0;
	pOut->ClearDrawArea();
}
int ApplicationManager::GetFigCount() const
{
	return FigCount;
}
bool ApplicationManager::isExistsquare()
{
	for (int i = 0; i < 200; i++) {
		if ((FigList[i]) != NULL)
		if (dynamic_cast<CSquare*>(FigList[i]) != NULL) {
			return true;
					}
	}
		return false;
}
bool ApplicationManager::isExistcolorfulsquare(color c)
{
	for (int i = 0; i < 200; i++) {
		if (FigList[i] != NULL) {
			if ((dynamic_cast<CSquare*>(FigList[i]) != NULL) && ((FigList[i]->get_color()) == c)) {
				return true;
			}
		}
	}
	return false;
}


bool ApplicationManager::isExistcolorfulrect(color c)
{
	for (int i = 0; i < 200; i++) {
		if (FigList[i] != NULL) {
			if ((dynamic_cast<CRectangle*>(FigList[i]) != NULL) && ((FigList[i]->get_color() )== c)) {
				return true;
			}
		}
	}
	return false;
}

bool ApplicationManager::isExistcolorfultri(color c)
{
	for (int i = 0; i < 200; i++) {
		if (FigList[i] != NULL) {
			if ((dynamic_cast<CTriangle*>(FigList[i]) != NULL) && ((FigList[i]->get_color()) == c)) {
				return true;
			}
		}
	}
	return false;
}

bool ApplicationManager::isExistcolorfulhex(color c)
{
	for (int i = 0; i < 200; i++) {
		if (FigList[i] != NULL) {
			if ((dynamic_cast<CHexagon*>(FigList[i]) != NULL) && ((FigList[i]->get_color()) == c)) {
				return true;
			}
		}
	}
	return false;
}

bool ApplicationManager::isExistcolorfulcircle(color c)
{
	for (int i = 0; i < 200; i++) {
		if (FigList[i] != NULL) {
			if ((dynamic_cast<CCircle*>(FigList[i]) != NULL) && ((FigList[i]->get_color()) == c)) {
				return true;
			}
		}
	}
	return false;
}


bool ApplicationManager::isExistcircle()
{
	for (int i = 0; i < 200; i++) {
		if ((FigList[i]) != NULL)

		if (dynamic_cast<CCircle*>(FigList[i]) != NULL) {
			return true;

		}
		
	}
	return false;
}
bool ApplicationManager::isExistriangle()
{
	for (int i = 0; i < 200; i++) {
		if ((FigList[i]) != NULL)

		if (dynamic_cast<CTriangle*>(FigList[i]) != NULL) {
			return true;

		}

	}
	return false;
}
bool ApplicationManager::isExistHexagon()
{
	for (int i = 0; i < 200; i++) {
		if ((FigList[i]) != NULL)
		if (dynamic_cast<CHexagon*>(FigList[i]) != NULL) {
			return true;

		}

	}
	return false;
}
bool ApplicationManager::isExistrectangle()
{
	for (int i = 0; i < 200; i++) {
		if((FigList[i]) != NULL)
		if (dynamic_cast<CRectangle*>(FigList[i]) != NULL) {
			return true;

		}

	}
	return false;
}
bool ApplicationManager::isExistcolor(color c)
{
	for (int i = 0; (i < 200); i++) {
		if (FigList[i] != NULL) {
			if ((FigList[i]->get_color()) == (c) && FigList[i]->isfilled1()) {
				return true;

			}
		}
	}
	return false;
}

bool ApplicationManager::isexistfillfigure()
{

	for (int i = 0; (i < 200) ; i++) {
		if (FigList[i] != NULL) {
			if (FigList[i]->isfilled1()) {
				
					return true;
			}
		}
	}
	return false;
}

		

void ApplicationManager::setIsRecording(bool x)
{
	isRecording = x;
}

int ApplicationManager::getRecActsCount() const
{
	return recActsCount;
}

void ApplicationManager::playAction(int i)
{
	recActs[i]->Execute();
	UpdateInterface();
	setAction(recActs[i]);
}
bool ApplicationManager::getIsRecording() const
{
	return isRecording;
}
void ApplicationManager::resetRecord()
{
	for (int i = 0; i < recActsCount; i++) {
		delete recActs[i];
		recActs[i] = NULL;
	}
	recActsCount = 0;
}
void ApplicationManager::setIsPlaying(bool p)
{
	isPlaying = p;
}
bool ApplicationManager::GetIsPlaying() const
{
	return isPlaying;
}

////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input* ApplicationManager::GetInput() const
{
	return pIn;
}
//Return a pointer to the output
Output* ApplicationManager::GetOutput() const
{
	return pOut;
}
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for (int i = 0; i <= FigCount; i++) {
		if (FigList[i] != NULL) {
			delete FigList[i];
			FigList[i] = NULL;
		}
	}

	for (int i = 0; i <= delfigcount; i++) {
		if (deletedfigures[i] != NULL) {
			delete deletedfigures[i];
			deletedfigures[i] = NULL;
		}
	}

	for (int i = 0; i <= recActsCount; i++) {
		if (recActs[i] != NULL) {
			for (int k = 0; k < 5; k++) {
				if (recActs[i] == ArrAction_undo[k])
					ArrAction_undo[k] = NULL;
			}

			delete recActs[i];
			recActs[i] = NULL;
		}
	}
	for (int i = 0; i <= 5;i++) {
		if (ArrAction_undo[i] != NULL) {
			delete ArrAction_undo[i];
			ArrAction_undo[i] = NULL;
		}
	}
	delete pIn;
	delete pOut;
	pOut = NULL;
	pIn = NULL;
}

void ApplicationManager::restore()//for play mode to restore deleted figures
{
	for (int i = 0; i < 200; i++) {
		if (delpFigList[i] != NULL) {
			for (int k = 0; k < 200; k++) {
				if (FigList[k] == NULL) {
					FigList[k] = delpFigList[i];
					delpFigList[i] = NULL;
					break;
				}
			}
		
		}
	}
}
