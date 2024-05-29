#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H
#include <iostream>
#include <fstream>
#include "DEFS.h"

#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"
#include "Actions\Action.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int sharedcount;  //for undo ,redo 
	Action* ArrAction_undo[5];
	Action* ArrAction_redo[5];
	bool set;
	bool check_redo;
	int Arrcount_undo; //number of actions in undo arr
	int FigCount;		//Actual number of figures
	int delfigcount; //for deleted figures array
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	CFigure* deletedfigures[MaxFigCount];  //List of deleted figures (Array of pointers)
	///////////////////////////////
	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;
	int recActsCount;	//Number of recorded actions
	Action* recActs[20];	//Array of recorded actions
	bool isRecording;	//Boolean to know if recording action is in progress
	bool isPlaying;	//Boolean to know if the record is being played
	CFigure* delpFigList[MaxFigCount];	// deleted figures in playmode

public:	
	void setdelplay(CFigure*);//delete f for play mode
	ApplicationManager(); 
	~ApplicationManager();
	void restore();
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	Action* LastAction_undo();  //get last action in undo list 
	Action* LastAction_redo();  //get last actnion in rdo list 
	// -- Figures Management Functions
	bool get_check_redo();
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	void SaveAll(ofstream& File);
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	CFigure* GetLatestFig();   //get latest selected figure
	void setdel(CFigure*);// function to determine deleted figures and set it in deleted figureslist (delete action,undo for add action)
	void un_del(CFigure*);  // function to return deleted figure to figlist (undo for delete action)
	void setAction(Action*);  // store actions in arr to undo and redo them
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	
	void ClearDrawArea();
	int GetFigCount()const;  //returns figure index

	bool isExistsquare();
	bool isExistcolorfulsquare(color c);
	bool isExistcolorfulrect(color c);
	bool isExistcolorfultri(color c);
	bool isExistcolorfulhex(color c);
	bool isExistcolorfulcircle(color c);
	bool isExistcircle();
	bool isExistriangle();
	bool isExistHexagon();
	bool isExistrectangle();
	bool isExistcolor(color c);
	bool isexistfillfigure();

	// -- Record-Stop-Play-Related functions
	void setIsRecording(bool x);	//Function to set isRecording
	int getRecActsCount() const;	//Get recorded actions count
	void playAction(int i);	//To call Execute on the passed recorded action order
	bool getIsRecording() const;	//To know if recording is in progress
	void resetRecord();	//Reset all values of record action action (delete recorded actions)
	void setIsPlaying(bool p);	//Set isPlaying
	bool GetIsPlaying() const;	//To know if playing record is in progress
};

#endif