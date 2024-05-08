#include "CFigure.h"

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}

void CFigure::setID(int id) {
	this->ID = id;
}

int CFigure::getID() const {
	return this->ID;
}

GfxInfo CFigure::getGfx() const {
	return this->FigGfxInfo;
}

void CFigure::returnGfx(GfxInfo Gfx) {
	SetSelected(false);
	ChngDrawClr(Gfx.DrawClr);
}