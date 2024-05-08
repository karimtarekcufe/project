#ifndef ADD_TRIANGLE_ACTION_H
#define ADD_TRIANGLE_ACTION_H

#include "../Phase2 - Code F22/Actions/Action.h"

//Add Rectangle Action class
class AddTriangleAction : public Action
{
private:
	Point P1,P2,P3;
	GfxInfo TriangleGfxInfo;
public:
	AddTriangleAction(ApplicationManager* pApp);


	virtual void ReadActionParameters();


	virtual void Execute();

};

#endif