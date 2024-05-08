#pragma once
#ifndef CCIRC_H
#define CCIRC_H

#include "../Phase2 - Code F22/Figures/CFigure.h"

class CCircle : public CFigure
{
private:
	Point Centre;
	Point Edge;
	int Radius;
	int shapeIdentity = 1;
public:
	CCircle(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool isInside(int x, int y) const ;
	virtual int getShapeIdentity() const;
	virtual void PrintShapeInfo(Output* pOut) const;
};
#endif