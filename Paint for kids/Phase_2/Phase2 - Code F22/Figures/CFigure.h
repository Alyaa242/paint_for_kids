#ifndef CFIGURE_H
#define CFIGURE_H
#include <fstream>

#include "..\defs.h"
#include "..\GUI\Output.h"

//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected,deleted;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	
	/// Add more parameters if needed.

public:
	CFigure(GfxInfo FigureGfxInfo);
	CFigure();

	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected
	void setdeleted(bool);      //delete/undelete the figure
	bool isdeleted() const;    //check whether fig is deleted
	
	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
	
	virtual void Save(ofstream& OutFile) = 0;	//Save the figure parameters to the file
	virtual void Load(ifstream& Infile) = 0;	//Load the figure parameters to the file
	static string GetStrClr(color& clr);        //convert type color to string
	static color  GetClrStr(string& str);       ////convert type string to color
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color
	 color get_color();

	 GfxInfo getgfx();   //returns graphics info of the figure to use it in undo,redo
	 void setgfx(GfxInfo);  //returns graphics info of the figure to use it in undo,redo
	 virtual Point getpoint() = 0;
	virtual void setnew(Point) = 0;

	 virtual bool is_in(int ,int)=0;
	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	
	 bool isfilled1();

	//virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	//virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file

	//virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
	 virtual void PrintInfo(Output* pOut) = 0;

};

#endif