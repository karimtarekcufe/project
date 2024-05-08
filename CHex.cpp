#include "CHex.h"

CHex::CHex(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Centre = P1;
}


void CHex::Draw(Output* pOut) const
{
	
	pOut->DrawHxgn(Centre, FigGfxInfo, Selected);
}

bool CHex::isInside(int x, int y) const{


	int P1x = Centre.x + 50;
	int P2x = Centre.x + 25;
	int P3x = Centre.x + 25;
	int P1y = Centre.y;
	int P2y = Centre.y + 43.30;
	int P3y = Centre.y - 43.30;
	int P4x = Centre.x - 50;
	int P5x = Centre.x - 25;
	int P6x = Centre.x -25;
	int P4y = Centre.y;
	int P5y = Centre.y + 43.30;
	int P6y = Centre.y - 43.30;

	bool insideSquarex = (x <= P2x && x >= P5x) ? true : false;
	bool insideSquareY = (y <= P2y && y >= P6y) ? true : false;

	float AH = 25 * 43.3;
	float A11 = abs(((x * (P1y - P2y)) + (P1x * (P2y - y)) + (P2x * (y - P1y))) / 2.0);
	float A12 = abs(((x * (P1y - P3y)) + (P1x * (P3y - y)) + (P3x * (y - P1y))) / 2.0);
	float A13 = abs(((x * (P3y - P2y)) + (P3x * (P2y - y)) + (P2x * (y - P3y))) / 2.0);
	float A21 = abs(((x * (P4y - P5y)) + (P4x * (P5y - y)) + (P5x * (y - P4y))) / 2.0);
	float A22 = abs(((x * (P5y - P6y)) + (P5x * (P6y - y)) + (P6x * (y - P5y))) / 2.0);
	float A23 = abs(((x * (P4y - P6y)) + (P4x * (P6y - y)) + (P6x * (y - P4y))) / 2.0);

	float T2 = A21 + A22 + A23;
	float T1 = A11 + A12 + A13;

	if (AH + 5 >= T2 || AH + 5 >= T1 || (insideSquarex&&insideSquareY)) {
		return true;
	}
	return false;
}

int CHex::getShapeIdentity() const {
	return this->shapeIdentity;
}

void CHex::PrintShapeInfo(Output* pOut) const {
	string sID = to_string(ID);
	string p1x = to_string(Centre.x);
	string p1y = to_string(Centre.y);
	string total = "Hexagon: ID(" + sID + ") Center(" + p1x + "," + p1y + ") Side_Length(50) .";
	pOut->PrintMessage(total);
	return;

}