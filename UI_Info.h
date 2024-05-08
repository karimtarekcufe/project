#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_PLAY	//Playing mode
};

enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	//Note: Items are **(ordered)** here as they appear in menu
	//If you want to change the menu items order, change the order here
		//Recangle item in menu
	
	//TODO: Add more items names here
	ITM_EXIT,		//Exit item
	ITM_RECT,
	ITM_CIRCLE,
	ITM_SQUARE,
	ITM_TRIANGLE,
	ITM_HEXAGON,
	ITM_Select,			//Select button in menu
	ITM_BLACK_BORDER,
	ITM_YELLOW_BORDER,
	ITM_ORANGE_BORDER,
	ITM_RED_BORDER,
	ITM_GREEN_BORDER,
	ITM_BLUE_BORDER,
	ITM_BORDER,
	ITM_FILL,
	CHANGE,				//Change item in menu
	COLORBORDER,
	FILLCOLOR,			
	CUT,				//Cut item in menu
	COPY,				//Copy item in menu
	PASTE,				//Paste item in menu
	ERASE,				//Erase item in menu
	CLEAR,				//Clear item in menu
	FORWARD,			//Bring forward item in menu
	BACKWARD,			//Bring backward item in menu
	SAVE,				//Save item in menu
	DOWNLOAD,			//Download item in menu
	PLAY,	 				//BC item in menu
	
	DRAW_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
	
};

enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	//Note: Items are **(ordered)** here as they appear in menu
	//If you want to change the menu items order, change the order here
	
	//TODO: Add more items names here
	ITM_EXIT2,
	ITM_PICK_BY_TYPE,
	ITM_PICK_BY_COLOR,
	ITM_PICK_BY_TYPE_AND_COLOR,
	ITM_RESTART_GAME,
	ITM_SWITCH_TO_DRAW_MODE,
	PLAY_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
	
};





__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;
	
	int	width, height,	    //Window width and height
		wx , wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		LineUnderTBWidth,	//line Under the Toolbar Pen Width
		MenuItemWidth;		//Width of each item in toolbar menu
	

	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes

	/// Add more members if needed
	
}UI;	//create a global object UI

#endif