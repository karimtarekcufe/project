#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	EXIT,
	DRAW_RECT,
	DRAW_CRCL,
	DRAW_SQR,
	DRAW_TRNGL,
	DRAW_HXGN,
	SELECT,
	BLACK_BORDER,
	YELLOW_BORDER,
	ORANGE_BORDER,
	RED_BORDER,
	GREEN_BORDER,
	BLUE_BORDER,
	BORDER,
	FILL,
	COLOR_BORDER,
	FILL_COLOR,
	CHANGE_ITEM,
	CUT_ITEM,
	COPY_ITEM,
	PASTE_ITEM,
	ERASE_ITEM,
	CLEAR_ITEM,
	FORWARD_ITEM,
	BACKWARD_ITEM,
	SAVE_ITEM,
	DOWNLOAD_ITEM,
	TO_PLAY,
	EMPTY,
	DRAWING_AREA,
	STATUS,
	TO_DRAW,
	CHANGE_COLOR,
	BC_ITEM,
	PICK_BY_TYPE_ACTION,
	PICK_BY_COLOR_ACTION,
	PICK_BY_TYPE_AND_COLOR_ACTION,
	RESTART_GAME_ACTION,
	SWITCH_DRAW_MODE,

	///TODO: Add the other action types of the two modes
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