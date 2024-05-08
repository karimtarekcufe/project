#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
	int shapeIdentity = 3;
public:
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	virtual bool isInside(int x, int y) const;
	virtual int getShapeIdentity() const;
	virtual void PrintShapeInfo(Output* pOut) const;
};

#endif