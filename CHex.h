#ifndef CHEX_H
#define CHEX_H

#include "../Phase2 - Code F22/Figures/CFigure.h"

class CHex : public CFigure
{
private:
	Point Centre;
	int shapeIdentity = 2;
public:
	CHex(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool isInside(int x, int y) const;
	virtual int getShapeIdentity() const;
	virtual void PrintShapeInfo(Output* pOut) const;
};


#endif