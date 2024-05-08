#include "CTriangle.h"

CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	this->P1 = P1;
	this->P2 = P2;
	this->P3 = P3;
}


void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawTrngl(P1, P2, P3, FigGfxInfo, Selected);
}

bool CTriangle::isInside(int x, int y) const {
	Point P;
	P.x = x;
	P.y = y;
	float TA = abs((P1.x*(P2.y-P3.y) + P2.x*(P3.y-P1.y) + P3.x*(P1.y-P2.y)) / 2);
	float A1 = abs((P.x * (P2.y - P3.y) + P2.x * (P3.y - P.y) + P3.x * (P.y - P2.y)) / 2);
	float A2 = abs((P1.x * (P.y - P3.y) + P.x * (P3.y - P1.y) + P3.x * (P1.y - P.y)) / 2);
	float A3 = abs((P1.x * (P2.y - P.y) + P2.x * (P.y - P1.y) + P.x * (P1.y - P2.y)) / 2);

	if(TA >= A1+A2+A3) {
		return true;
	}
	return false;
}

void CTriangle::PrintShapeInfo(Output* pOut) const {
	string sID = to_string(ID);
	string p1x = to_string(P1.x);
	string p1y = to_string(P1.y);
	string p2x = to_string(P2.x);
	string p2y = to_string(P2.y);
	string p3x = to_string(P3.x);
	string p3y = to_string(P3.y);
	string total = "Triangle: ID(" + sID + ") Point1(" + p1x + "," + p1y + ") Point2(" + p2x + "," + p2y + ") Point3(" + p3x + "," + p3y + ") .";
	pOut->PrintMessage(total);
	return;
}
int CTriangle::getShapeIdentity() const {
	return this->shapeIdentity;
}