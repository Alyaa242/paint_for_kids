#include "Input.h"
#include "Output.h"


Input::Input(window* pW) 
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int &x, int &y) const
{
	pWind->FlushMouseQueue();	//not to skip the message
	pWind->FlushKeyQueue();
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output *pO) const 
{
	string Label;
	char Key;
	while(1)
	{
		pWind->WaitKeyPress(Key);
		if(Key == 27 )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if(Key == 13 )	//ENTER key is pressed
			
			return Label;
		if((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() -1 );			
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
	
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{	
	int x,y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if(UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			//Check which Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_RECT: return DRAW_RECTANGLE;
			case ITM_SQR: return DRAW_SQARE;
			case ITM_TRI: return DRAW_TRIANGLE;
			case ITM_CIRC: return DRAW_CIRCLE;
			case ITM_HEX: return DRAW_HEXOGONAL;
			case ITM_SELECT: return SELECT;
			case ITM_MOVE: return MOVE;
			case ITM_BORDER: return BORDER;
			case ITM_FILL: return FILL;
			case ITM_REC:  return REC;
			case ITM_PLAY: return PLAY;
			case ITM_STOP: return STOP;
			case ITM_UNDO: return UNDO;
			case ITM_REDO: return REDO;
			case ITM_DEL: return DEL;
			case ITM_CLEAR: return CLEAR;
			case ITM_BLACK: return COLOR_BLACK;
			case ITM_RED: return COLOR_RED;
			case ITM_GREEN: return COLOR_GREEN;
			case ITM_BLUE: return COLOR_BLUE;
			case ITM_YELLOW: return COLOR_YELLOW;
			case ITM_ORANGE: return COLOR_ORANGE;
			case ITM_SWITCH: return SWITCH_TO_PLAY;
			case ITM_LOAD: return LOAD;
			case ITM_SAVE: return SAVE;
			case ITM_EXIT: return EXIT;
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;	
		}
		
		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//GUI is in PLAY mode
	{
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

				///TODO:
			//perform checks similar to Draw mode checks above
			//and return the correspoding action
			switch (ClickedItemOrder) {
			case 2*ITM_PICK_BY_FIGURE: return PICK_BY_FIGURE;
			case 2*ITM_PICK_BY_COLOR: return PICK_BY_COLOR;
			case 2*ITM_BOTH: return BOTH;
			case 2*ITM_SWITCH_TO_DRAW: return SWITCH_TO_DRAW;
			default: return EMPTY;	//A click on empty place in desgin toolbar

			}

		}
		/*user clicks on playmode area*/

		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return PLAYING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;		
		}

}
/////////////////////////////////
	
Input::~Input() {};
