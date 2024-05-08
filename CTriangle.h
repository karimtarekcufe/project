#ifndef CTRIANGLE_H
#define CTRIANGLE_H

#include "../Phase2 - Code F22/Figures/CFigure.h"

class CTriangle : public CFigure
{
private:
	Point P1;
	Point P2;
	Point P3;
	int shapeIdentity = 5;
public:
	CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool isInside(int x, int y) const;
	virtual int getShapeIdentity() const;
	virtual void PrintShapeInfo(Output* pOut) const;
};

#endif