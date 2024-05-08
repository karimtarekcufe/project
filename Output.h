#ifndef OUPTUT_H
#define OUPTUT_H
#include "Input.h"
#include <string>  // Include the <string> header

class Output	//The application manager should have a pointer to this class
{
private:	
	window* pWind;	//Pointer to the Graphics Window
	static string MenuItemImages[DRAW_ITM_COUNT];  // Declaration of static member variable
public:
	Output();		

	window* CreateWind(int, int, int , int) const; //creates the application window
	void CreateDrawToolBar() const;	//creates Draw mode toolbar & menu
	void CreatePlayToolBar() const;	//creates Play mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar

	Input* CreateInput() const; //creates a pointer to the Input object	
	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area
	
	// -- Figures Drawing functions
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected=false) const;  //Draw a rectangle
	void DrawSqr(Point P1, GfxInfo SqrGfxInfo, bool selected = false) const;
	void DrawCrcl(Point P1, Point P2, GfxInfo CrclGfxInfo, bool selected = false) const;
	void DrawHxgn(Point P1, GfxInfo HxgnGfxInfo, bool selected = false) const;
	void DrawTrngl(Point P1, Point P2, Point P3, GfxInfo TrnglGfxInfo, bool selected = false) const;

	
	///TODO:Make similar functions for drawing all other figure types.
	
	void PrintMessage(string msg) const;	//Print a message on Status bar

	color getCrntDrawColor() const;	//get current drwawing color
	color getCrntFillColor() const;	//get current filling color
	int getCrntPenWidth() const;		//get current pen width

	
	~Output();
};

#endif