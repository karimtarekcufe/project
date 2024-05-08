#pragma once
#ifndef CSQR_H
#define CSQR_H

#include "../Phase2 - Code F22/Figures/CFigure.h"

class CSquare : public CFigure
{
private:
	Point Centre;
	int shapeIdentity = 4;
public:
	CSquare(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool isInside(int x, int y) const;
	virtual int getShapeIdentity() const;
	virtual void PrintShapeInfo(Output* pOut) const;
};

#endif