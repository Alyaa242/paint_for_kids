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
	UI.MenuItemWidth = 47;
	
	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = WHITE;		//Messages color
	UI.BkGrndColor = color(252, 224, 224);	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = color(53, 80, 130);		//Status bar color
	UI.PenWidth = 3;	//width of the figures frames

	
	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");

	Opening();	//opening window
	
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
const int space = 10; //space for toolbar line

window* Output::CreateWind(int w, int h, int x, int y) const
{ 
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight+space, w, h);	
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::Opening() const
{
	pWind->DrawRectangle(0, 0, UI.width, UI.height);	//Create opening window by drawing a rectangle
	pWind->DrawImage("images\\openning.jpg", 0, 0,UI.width ,UI.height);		//Add image to opening
	PlaySound("sound effects\\greeting.wav", NULL, SND_SYNC);	//Add sound to opening
	ClearDrawArea();

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

	//TODO: Prepare images for each menu item and add it to the list

	MenuItemImages[ITM_RECT] = "images\\MenuItems\\rect.jpg";
	MenuItemImages[ITM_SQR] = "images\\MenuItems\\square.jpg";
	MenuItemImages[ITM_TRI] = "images\\MenuItems\\triangle.jpg";
	MenuItemImages[ITM_CIRC] = "images\\MenuItems\\circle.jpg";
	MenuItemImages[ITM_HEX] = "images\\MenuItems\\hexagon.jpg";
	MenuItemImages[ITM_SELECT] = "images\\MenuItems\\cursorg.jpg";
	MenuItemImages[ITM_MOVE] = "images\\MenuItems\\move.jpg";
	MenuItemImages[ITM_BORDER] = "images\\MenuItems\\bordersg.jpg";
	MenuItemImages[ITM_FILL] = "images\\MenuItems\\bucketg.jpg";
	MenuItemImages[ITM_REC] = "images\\MenuItems\\record.jpg";
	MenuItemImages[ITM_PLAY] = "images\\MenuItems\\playg.jpg";
	MenuItemImages[ITM_STOP] = "images\\MenuItems\\stopg.jpg";
	MenuItemImages[ITM_UNDO] = "images\\MenuItems\\ggundo.jpg";
	MenuItemImages[ITM_REDO] = "images\\MenuItems\\ggredo.jpg";
	MenuItemImages[ITM_DEL] = "images\\MenuItems\\deleteg.jpg";
	MenuItemImages[ITM_CLEAR] = "images\\MenuItems\\gclear.jpg";
	MenuItemImages[ITM_BLACK] = "images\\MenuItems\\black2.jpg";
	MenuItemImages[ITM_RED] = "images\\MenuItems\\red2.jpg";
	MenuItemImages[ITM_GREEN] = "images\\MenuItems\\green2.jpg";
	MenuItemImages[ITM_BLUE] = "images\\MenuItems\\blue2.jpg";
	MenuItemImages[ITM_YELLOW] = "images\\MenuItems\\yellow2.jpg";
	MenuItemImages[ITM_ORANGE] = "images\\MenuItems\\orange2.jpg";
	MenuItemImages[ITM_SWITCH] = "images\\MenuItems\\playmode5.jpg";
	MenuItemImages[ITM_LOAD] = "images\\MenuItems\\loadg.jpg";
	MenuItemImages[ITM_SAVE] = "images\\MenuItems\\saveg.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\exitg.jpg";

	//Draw menu item one image at a time
	for(int i=0; i<DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(color(53, 80, 130), 5);
	pWind->DrawLine(0, UI.ToolBarHeight+space, UI.width, UI.ToolBarHeight+space);	

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{
	///TODO: write code to create Play mode menu

	UI.InterfaceMode = MODE_PLAY;

	string MenuItemImages2[PLAY_ITM_COUNT];
	MenuItemImages2[ITM_PICK_BY_FIGURE] = "images\\MenuItems\\Figure.jpg";
	MenuItemImages2[ITM_PICK_BY_COLOR] = "images\\MenuItems\\Menu_COLOR.jpg";
	MenuItemImages2[ITM_BOTH] = "images\\MenuItems\\Both.jpg";
	MenuItemImages2[ITM_SWITCH_TO_DRAW] = "images\\MenuItems\\drawmode2.jpg";

	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
	pWind->SetPen(color(53, 80, 130), 5);
	pWind->DrawLine(0, UI.ToolBarHeight+10, UI.width, UI.ToolBarHeight+10);

	for (int i = 0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages2[i], i *2* UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);
	/* second term (i * UI.MenuItemWidth) was multiblied by 2 to make icons spaced apart  */   
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight+13, UI.width, UI.height - UI.StatusBarHeight);
	
	
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight/1.25), msg);
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

//Draw rectangle function
void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;
	pWind->SetPen(DrawingClr, 1);

	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;
	if (P1.y < UI.ToolBarHeight + 13)
		P1.y = UI.ToolBarHeight + 13;
	if (P2.y < UI.ToolBarHeight + 13)
		P2.y = UI.ToolBarHeight + 13;
	


	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);
}

//Draw square function
void Output::DrawSquare(Point p, GfxInfo SquareGfxInfo, bool selected)const
{
	color DrawingClr;
	int HalfsideLenght = 100;
	if (selected)
		DrawingClr = UI.HighlightColor;
	else
		DrawingClr = SquareGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (SquareGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(SquareGfxInfo.FillClr);
	}
	else
		style = FRAME;
	if (p.y < UI.ToolBarHeight + 13 + HalfsideLenght )
		p.y = UI.ToolBarHeight + 13 + HalfsideLenght ;
	pWind->DrawRectangle(p.x - HalfsideLenght, p.y - HalfsideLenght, p.x + HalfsideLenght, p.y + HalfsideLenght, style);
}

//Draw triangle function
void Output::DrawTriangle(Point p1, Point p2, Point p3, GfxInfo TriangleGfxInfo, bool selected)const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor;
	else
		DrawingClr = TriangleGfxInfo.DrawClr;
	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (TriangleGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TriangleGfxInfo.FillClr);
	}
	else
		style = FRAME;
	if (p1.y < UI.ToolBarHeight + 13)
		p1.y = UI.ToolBarHeight + 13;
	if (p2.y < UI.ToolBarHeight + 13)
		p2.y = UI.ToolBarHeight + 13;
	if (p3.y < UI.ToolBarHeight + 13)
		p3.y = UI.ToolBarHeight + 13;
	
	pWind->DrawTriangle(p1.x, p1.y, p2.x, p2.y, p3.x, p3.y, style);
}

//Draw hexagon function
void Output::DrawHexagon(Point p, GfxInfo HexagonGfxInfo, bool selected)const
{
	const int vertices = 6;
	int sideLenght = 100;
	if (p.y < UI.ToolBarHeight + 13 + (sideLenght / 2) * sqrt(3))
		p.y = UI.ToolBarHeight + 13 + (sideLenght / 2) * sqrt(3);
	const int xvalues[vertices] = { p.x + sideLenght / 2,p.x + sideLenght,p.x + sideLenght / 2,p.x - sideLenght / 2,p.x - sideLenght,p.x - sideLenght / 2 };
	const int yvalues[vertices] = { p.y + (sideLenght / 2) * sqrt(3),p.y,p.y - (sideLenght / 2) * sqrt(3),p.y - (sideLenght / 2) * sqrt(3),p.y,p.y + (sideLenght / 2) * sqrt(3) };


	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor;
	else
		DrawingClr = HexagonGfxInfo.DrawClr;
	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (HexagonGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(HexagonGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawPolygon(xvalues, yvalues, vertices, style);

}

//Draw circle function
void Output::DrawCircle(Point Pc, Point P, GfxInfo CircleGfxInfo, bool selected)const
{
	if (P.y < UI.ToolBarHeight + 13)
		P.y = UI.ToolBarHeight + 13;
	int radius = sqrt(pow(Pc.x - P.x, 2) + pow(Pc.y - P.y, 2));
	if (Pc.y < UI.ToolBarHeight + 13 + radius)
		Pc.y = UI.ToolBarHeight + 13 + radius;
	
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor;
	else
		DrawingClr = CircleGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (CircleGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(CircleGfxInfo.FillClr);
	}
	else
		style = FRAME;



	pWind->DrawCircle(Pc.x, Pc.y, radius, style);

}


//////////////////////////////////////////////////////////////////////////////////////////

Output::~Output()
{
	delete pWind;
}

