#include "SaveAction.h"
#include "..\ApplicationManager.h"
#include "..\Figures\CFigure.h"
SaveAction::SaveAction(ApplicationManager* pApp):Action(pApp)
{}

void SaveAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Save New File: Enter its name");

	FileName = pIn->GetSrting(pOut);
	FileName = "saved files\\" + FileName + ".txt";
	

	pOut->ClearStatusBar();

}

void SaveAction::Execute()
{
	Output* pOut = pManager->GetOutput();

	ReadActionParameters();
	ofstream outFile;
	outFile.open(FileName);
	if (outFile.is_open())
	{
		outFile << CFigure::GetStrClr(pOut->getCrntDrawColor()) << "\t" << CFigure::GetStrClr(pOut->getCrntFillColor()) << endl;
		outFile << pManager->GetFigCount()<<endl;
		pManager->SaveAll(outFile);
			outFile.close();
	}
}
