#include "Output.h"
#include<string.h>
using namespace std;
string Output::MenuItemImages[DRAW_ITM_COUNT];

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
	UI.LineUnderTBWidth = 2;
	UI.MenuItemWidth = 44.6;
	
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
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\Menu_Rect.jpg";
	MenuItemImages[ITM_CIRCLE] = "images\\MenuItems\\D.jpeg";
	MenuItemImages[ITM_SQUARE] = "images\\MenuItems\\Drawsquare.jpg";
	MenuItemImages[ITM_TRIANGLE] = "images\\MenuItems\\Drawtriangle.jpeg";
	MenuItemImages[ITM_HEXAGON] = "images\\MenuItems\\Drawhexagon.jpeg";
	MenuItemImages[ITM_Select] = "images\\MenuItems\\DrawButton.jpeg";
	MenuItemImages[ITM_BLACK_BORDER] = "images\\MenuItems\\Drawblack.jpeg";
	MenuItemImages[ITM_YELLOW_BORDER] = "images\\MenuItems\\Drawyellow.jpeg";
	MenuItemImages[ITM_ORANGE_BORDER] = "images\\MenuItems\\Draworange.jpeg";
	MenuItemImages[ITM_RED_BORDER] = "images\\MenuItems\\Drawred.jpeg";
	MenuItemImages[ITM_GREEN_BORDER] = "images\\MenuItems\\Drawgreen.jpeg";
	MenuItemImages[ITM_BLUE_BORDER] = "images\\MenuItems\\Drawblue.jpeg";
	MenuItemImages[ITM_BORDER] = "images\\MenuItems\\border.jpg";
	MenuItemImages[ITM_FILL] = "images\\MenuItems\\fill-icon-14.jpg";
	MenuItemImages[CHANGE] = "images\\MenuItems\\A.jpeg";
	MenuItemImages[COLORBORDER] = "images\\MenuItems\\A2.jpeg";
	MenuItemImages[FILLCOLOR] = "images\\MenuItems\\A3.jpeg";
	MenuItemImages[CUT] = "images\\MenuItems\\CUT.jpg";
	MenuItemImages[COPY] = "images\\MenuItems\\COPY.jpeg";
	MenuItemImages[PASTE] = "images\\MenuItems\\PASTE.jpeg";
	MenuItemImages[ERASE] = "images\\MenuItems\\ERASE.jpeg";
	MenuItemImages[CLEAR] = "images\\MenuItems\\CLEAR.jpeg";
	MenuItemImages[FORWARD] = "images\\MenuItems\\BRING FORWARD.jpg";
	MenuItemImages[BACKWARD] = "images\\MenuItems\\BRING BACKWARD.jpg";
	MenuItemImages[SAVE] = "images\\MenuItems\\SAVE.jpg";
	MenuItemImages[DOWNLOAD] = "images\\MenuItems\\download-icn.jpg";
	MenuItemImages[PLAY] = "images\\MenuItems\\A1.jpeg";


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
	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
	UI.InterfaceMode = MODE_PLAY;
	string MenuItemImage[PLAY_ITM_COUNT];
	MenuItemImage[ITM_EXIT2] = "images\\MenuItems\\Menu_Exit.jpg";

	MenuItemImage[ITM_PICK_BY_TYPE] = "images\\MenuItems\\selecticon.jpg";
	MenuItemImage[ITM_PICK_BY_COLOR] = "images\\MenuItems\\aqwe.jpeg";
	MenuItemImage[ITM_PICK_BY_TYPE_AND_COLOR] = "images\\MenuItems\\typecolor.jpg";

	MenuItemImage[ITM_RESTART_GAME] = "images\\MenuItems\\restart.jpeg";
	MenuItemImage[ITM_SWITCH_TO_DRAW_MODE] = "images\\MenuItems\\ART.jpg";


	for (int i = 0; i < PLAY_ITM_COUNT; i++)
	{
		pWind->DrawImage(MenuItemImage[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);
	}

	pWind->SetPen(RED, UI.LineUnderTBWidth);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
	///TODO: write code to create Play mode menu
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight + UI.LineUnderTBWidth, UI.width, UI.height - UI.StatusBarHeight);
	
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

void Output::DrawSqr(Point P1, GfxInfo SqrGfxInfo, bool selected) const //Draw a square //Done 7/4/2024
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = SqrGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (SqrGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(SqrGfxInfo.FillClr);
	}
	else
		style = FRAME;
	int bottomRightX, bottomRightY, upperLeftX, upperLeftY;
	bottomRightX = P1.x + 50;
	bottomRightY = P1.y + 50;
	upperLeftX = P1.x - 50;
	upperLeftY = P1.y - 50;

	pWind->DrawRectangle(upperLeftX, upperLeftY, bottomRightX, bottomRightY, style);

}

//

void Output::DrawCrcl(Point P1, Point P2, GfxInfo CrclGfxInfo, bool selected) const //Draw a circle //Done 7/4/2024
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = CrclGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (CrclGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(CrclGfxInfo.FillClr);
	}
	else
		style = FRAME;

	int radius = (int)sqrt(pow(P2.x - P1.x, 2) + pow(P2.y - P1.y, 2));

	pWind->DrawCircle(P1.x, P1.y, radius, style);

}

//

void Output::DrawTrngl(Point P1, Point P2, Point P3, GfxInfo TrnglGfxInfo, bool selected) const //Draw a traingle //Done 8/4/2024
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = TrnglGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (TrnglGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TrnglGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);
}

void Output::DrawHxgn(Point P1, GfxInfo HxgnGfxInfo, bool selected) const //Draw a Hexagon //Done 8/4/2024
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = HxgnGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (HxgnGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(HxgnGfxInfo.FillClr);
	}
	else
		style = FRAME;

	int arrX[6] = { P1.x + 50,P1.x + 25,P1.x - 25,P1.x - 50,P1.x - 25,P1.x + 25 };
	int arrY[6] = { P1.y , P1.y + 43.30 , P1.y + 43.30 , P1.y , P1.y - 43.30 , P1.y - 43.30 };
	pWind->DrawPolygon(arrX, arrY, 6, style);

}


//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

