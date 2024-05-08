#include "CCircle.h"

CCircle::CCircle(Point P1, Point P2,  GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Centre = P1;
	Edge = P2;
	Radius = (int)sqrt(pow(P2.x - P1.x, 2) + pow(P2.y - P1.y, 2));
}


void CCircle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawCrcl(Centre, Edge, FigGfxInfo, Selected);
}

bool CCircle::isInside(int x, int y) const{
	int X = x;
	int Y = y;
	int PointToCentre = (int)sqrt(pow(x - Centre.x, 2) + pow(y - Centre.y, 2));
	if (PointToCentre<=Radius) {
		return true;
	}
	return false;
}

int CCircle ::getShapeIdentity() const {
	return this->shapeIdentity;
}

void CCircle::PrintShapeInfo(Output* pOut) const {
	
	string sID = to_string(ID);
	string p1x = to_string(Centre.x);
	string p1y = to_string(Centre.y);
	string r = to_string(Radius);
	string total = "Hexagon: ID(" + sID + ") Center(" + p1x + "," + p1y + ") Radius("+r+") .";
	pOut->PrintMessage(total);
	return;

}