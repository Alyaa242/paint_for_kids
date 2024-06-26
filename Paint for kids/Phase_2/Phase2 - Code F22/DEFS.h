#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	DRAW_RECTANGLE,	//Draw Rectangle

	///TODO: Add the other action types of the two modes
	DRAW_SQARE,
	DRAW_TRIANGLE,
	DRAW_CIRCLE,
	DRAW_HEXOGONAL,
	SELECT,
	MOVE,
	BORDER,
	FILL,
	REC,
	PLAY,
	STOP,
	UNDO,
	REDO,
	DEL,
	CLEAR,
	COLOR_BLACK,
	COLOR_RED,
	COLOR_GREEN,
	COLOR_BLUE,
	COLOR_YELLOW,
	COLOR_ORANGE,
	SWITCH_TO_PLAY,
	LOAD,
	SAVE,
	PICK_BY_FIGURE,
	PICK_BY_COLOR,
	BOTH,
	SWITCH_TO_DRAW,
	EXIT,			//Exit
	SOUND,
	TO_DRAW,		//Switch interface to Draw mode
	TO_PLAY,		//Switch interface to Play mode
	EMPTY,			//A click on empty place in the toolbar
	DRAWING_AREA,	//A click on the drawing area
	PLAYING_AREA,
	STATUS			//A click on the status bar

};

struct Point	//To be used for figures points
{ int x,y; };

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders
	
};

#endif