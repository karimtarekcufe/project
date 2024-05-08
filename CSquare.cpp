#include "CSquare.h"

CSquare::CSquare(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Centre = P1;
}


void CSquare::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawSqr(Centre, FigGfxInfo, Selected);
}

bool CSquare::isInside(int x, int y) const {
	if ((x <= Centre.x +50 && x>= Centre.x -50) && (y <= Centre.y + 50 && y >= Centre.y - 50)) {
		return true;
	}
	return false;
}
int CSquare::getShapeIdentity() const {
	return this->shapeIdentity;
}
void CSquare::PrintShapeInfo(Output* pOut) const {
	string sID = to_string(ID);
	string p1x = to_string(Centre.x);
	string p1y = to_string(Centre.y);
	string total = "Square: ID(" + sID + ") Center(" + p1x + "," + p1y + ") Length and Width(100) .";
	pOut->PrintMessage(total);
	return;
}