#ifndef CFIGURE_H
#define CFIGURE_H
#include "../Actions/Action.h"
#include "..\defs.h"
#include "..\GUI\Output.h"
#include "..\GUI\UI_Info.h"
#include <fstream>
#include <string>

//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	
	/// Add more parameters if needed.

public:
	CFigure(GfxInfo FigureGfxInfo);
	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected
	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
	virtual bool isInside(int x, int y) const = 0;
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color
	void setID(int id);
	GfxInfo getGfx() const;
	void returnGfx(GfxInfo Gfx);
	int getID() const;
	virtual int getShapeIdentity() const = 0;
	virtual void PrintShapeInfo(Output* pOut) const = 0;
	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	


	//virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	//virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file

	//virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
};

#endif