#include "Input.h"
#include "Output.h"


Input::Input(window* pW) 
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int &x, int &y) const
{
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
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_RECT: return DRAW_RECT;
			case ITM_EXIT: return EXIT;
			case ITM_CIRCLE: return DRAW_CRCL;
			case ITM_SQUARE: return DRAW_SQR;
			case ITM_TRIANGLE: return DRAW_TRNGL;
			case ITM_HEXAGON: return DRAW_HXGN;
			case ITM_Select: return SELECT;
			case ITM_BLACK_BORDER: return BLACK_BORDER;
			case ITM_YELLOW_BORDER: return YELLOW_BORDER;
			case ITM_ORANGE_BORDER: return ORANGE_BORDER;
			case ITM_RED_BORDER: return RED_BORDER;
			case ITM_GREEN_BORDER: return GREEN_BORDER;
			case ITM_BLUE_BORDER: return BLUE_BORDER;
			case ITM_BORDER: return BORDER;
			case ITM_FILL: return FILL;
			case COLORBORDER: return COLOR_BORDER;
			case FILLCOLOR: return FILL_COLOR;
			case CHANGE: return CHANGE_ITEM;
			case CUT: return CUT_ITEM;
			case COPY: return COPY_ITEM;
			case PASTE: return PASTE_ITEM;
			case ERASE: return ERASE_ITEM;
			case CLEAR: return CLEAR_ITEM;
			case FORWARD: return FORWARD_ITEM;
			case BACKWARD: return BACKWARD_ITEM;
			case SAVE: return SAVE_ITEM;
			case DOWNLOAD: return DOWNLOAD_ITEM;
			case PLAY: return TO_PLAY;
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
			int ClickedItemOrderr = (x / UI.MenuItemWidth);

			switch (ClickedItemOrderr)
			{
			case ITM_EXIT2:
				return EXIT;
			case ITM_PICK_BY_TYPE:
				return PICK_BY_TYPE_ACTION;
			case ITM_PICK_BY_COLOR:
				return PICK_BY_COLOR_ACTION;
			case ITM_PICK_BY_TYPE_AND_COLOR:
				return PICK_BY_TYPE_AND_COLOR_ACTION;
			case ITM_RESTART_GAME:
				return RESTART_GAME_ACTION;
			case ITM_SWITCH_TO_DRAW_MODE:
				return SWITCH_DRAW_MODE;

			default: return EMPTY;
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		return STATUS;
	}	

}
/////////////////////////////////
	
Input::~Input()
{
}
