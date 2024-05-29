#include "Switch_to_play.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"
#include"..\ApplicationManager.h"
#include "SaveAction.h"
#include"Action.h"

Switch_to_play::Switch_to_play(ApplicationManager* a) :Action(a)
{

}

void Switch_to_play::ReadActionParameters()
{

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Lets play");
	pOut->CreatePlayToolBar();
}

void Switch_to_play::Execute()
{
	Output* pOut = pManager->GetOutput();

	ReadActionParameters();
	
}
void Switch_to_play::undo()
{}
void Switch_to_play::redo()
{}

bool Switch_to_play::isRecordable()
{
	return false;
}
