#include "CRectangle.h"

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}
	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}

bool CRectangle::isInside(int x, int y) const {
	if ( ((x<= Corner1.x || x <= Corner2.x) && (x >= Corner1.x || x >= Corner2.x)) && ((y <= Corner1.y || y <= Corner2.y) && (y >= Corner1.y || y >= Corner2.y)) ) {
		return true;
	}
	return false;
}

int CRectangle::getShapeIdentity() const {
	return this->shapeIdentity;
}

void CRectangle::PrintShapeInfo(Output* pOut) const {
	string sID = to_string(ID);
	string p1x = to_string(Corner1.x);
	string p1y = to_string(Corner1.y);
	string p2x = to_string(Corner2.x);
	string p2y = to_string(Corner2.y);
	string l = to_string(abs(Corner1.x- Corner2.x));
	string w = to_string(abs(Corner1.y - Corner2.y));
	string total = "Square: ID(" + sID + ") Corner1(" + p1x + "," + p1y + ")  Corner2(" + p2x + "," + p2y + ") Length(" + l  + "and Width(" + w +") .";
	pOut->PrintMessage(total);
	return;
}