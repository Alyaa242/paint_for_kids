#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;
	
	UI.width = 1250;
	UI.height = 650;
	UI.wx = 5;
	UI.wy =5;

	
	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 45.7;
	
	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 3;	//width of the figures frames

	
	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");
	
	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{ 
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);	
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_RECT] = "D:\\Year one\\Programming techniques\\Paint\\Project\\Icons\\rect.jpg";
	MenuItemImages[ITM_SQR] = "D:\\Year one\\Programming techniques\\Paint\\Project\\Icons\\square.jpg";
	MenuItemImages[ITM_TRI] = "D:\\Year one\\Programming techniques\\Paint\\Project\\Icons\\triangle.jpg";
	MenuItemImages[ITM_CIRC] = "D:\\Year one\\Programming techniques\\Paint\\Project\\Icons\\circle.jpg";
	MenuItemImages[ITM_HEX] = "D:\\Year one\\Programming techniques\\Paint\\Project\\Icons\\hexagon.jpg";
	MenuItemImages[ITM_SELECT] = "D:\\Year one\\Programming techniques\\Paint\\Project\\Icons\\cursorg.jpg";
	MenuItemImages[ITM_MOVE] = "D:\\Year one\\Programming techniques\\Paint\\Project\\Icons\\move.jpg";
	MenuItemImages[ITM_COLOR] = "D:\\Year one\\Programming techniques\\Paint\\Project\\Icons\\art.jpg";
	MenuItemImages[ITM_BORDER] = "D:\\Year one\\Programming techniques\\Paint\\Project\\Icons\\bordersg.jpg";
	MenuItemImages[ITM_FILL] = "D:\\Year one\\Programming techniques\\Paint\\Project\\Icons\\bucketg.jpg";
	MenuItemImages[ITM_REC] = "D:\\Year one\\Programming techniques\\Paint\\Project\\Icons\\record.jpg";
	MenuItemImages[ITM_PLAY] = "D:\\Year one\\Programming techniques\\Paint\\Project\\Icons\\playg.jpg";
	MenuItemImages[ITM_STOP] = "D:\\Year one\\Programming techniques\\Paint\\Project\\Icons\\stopg.jpg";
	MenuItemImages[ITM_UNDO] = "D:\\Year one\\Programming techniques\\Paint\\Project\\Icons\\ggundo.jpg";
	MenuItemImages[ITM_REDO] = "D:\\Year one\\Programming techniques\\Paint\\Project\\Icons\\ggredo.jpg";
	MenuItemImages[ITM_DEL] = "D:\\Year one\\Programming techniques\\Paint\\Project\\Icons\\deleteg.jpg";
	MenuItemImages[ITM_CLEAR] = "D:\\Year one\\Programming techniques\\Paint\\Project\\Icons\\gclear.jpg";
	MenuItemImages[ITM_BLACK] = "D:\\Year one\\Programming techniques\\Paint\\Project\\Icons\\black2.jpg";
	MenuItemImages[ITM_RED] = "D:\\Year one\\Programming techniques\\Paint\\Project\\Icons\\red2.jpg";
	MenuItemImages[ITM_GREEN] = "D:\\Year one\\Programming techniques\\Paint\\Project\\Icons\\green2.jpg";
	MenuItemImages[ITM_BLUE] = "D:\\Year one\\Programming techniques\\Paint\\Project\\Icons\\blue2.jpg";
	MenuItemImages[ITM_YELLOW] = "D:\\Year one\\Programming techniques\\Paint\\Project\\Icons\\yellow2.jpg";
	MenuItemImages[ITM_ORANGE] = "D:\\Year one\\Programming techniques\\Paint\\Project\\Icons\\orange2.jpg";
	MenuItemImages[ITM_SWITCH] = "D:\\Year one\\Programming techniques\\Paint\\Project\\Icons\\playmode3g.jpg";
	MenuItemImages[ITM_LOAD] = "D:\\Year one\\Programming techniques\\Paint\\Project\\Icons\\loadg.jpg";
	MenuItemImages[ITM_SAVE] = "D:\\Year one\\Programming techniques\\Paint\\Project\\Icons\\saveg.jpg";
	MenuItemImages[ITM_EXIT] = "D:\\Year one\\Programming techniques\\Paint\\Project\\Icons\\exitg.jpg";

	//MenuItemImages[ITM_CIRC] = "D:\\Year one\\Programming techniques\\Project\\Icons\\palette.jpg";
	
	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for(int i=0; i<DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;

	string MenuItemImages2[PLAY_ITM_COUNT];
	MenuItemImages2[ITM_PICK_BY_FIGURE] = "D:\\Year one\\Programming techniques\\Paint\\Project\\Phase1 - Code F23\\Phase1 - Code F22\\images\\MenuItems\\Menu_FIGURE2.jpg";
	MenuItemImages2[ITM_PICK_BY_COLOR] = "D:\\Year one\\Programming techniques\\Paint\\Project\\Phase1 - Code F23\\Phase1 - Code F22\\images\\MenuItems\\Menu_COLOR.jpg";
	MenuItemImages2[ITM_PAUSE] = "D:\\Year one\\Programming techniques\\Paint\\Project\\Phase1 - Code F23\\Phase1 - Code F22\\images\\MenuItems\\both.jpeg";
	MenuItemImages2[ITM_SWITCH2] = "D:\\Year one\\Programming techniques\\Paint\\Project\\Phase1 - Code F23\\Phase1 - Code F22\\images\\MenuItems\\Menu_SWITCH.jpg";

	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
	
	for (int i = 0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages2[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	///TODO: write code to create Play mode menu
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
	
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight/1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drawing color
{	return UI.DrawColor;	}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{	return UI.FillColor;	}
//////////////////////////////////////////////////////////////////////////////////////////
	
int Output::getCrntPenWidth() const		//get current pen width
{	return UI.PenWidth;	}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = RectGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr,1);
	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else	
		style = FRAME;

	
	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);
	
}


//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

