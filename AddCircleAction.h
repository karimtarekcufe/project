#ifndef ADD_CIRC_ACTION_H
#define ADD_CIRC_ACTION_H

#include "../Phase2 - Code F22/Actions/Action.h"

//Add Rectangle Action class
class AddCircleAction : public Action
{
private:
	Point Centre, Edge; 
	GfxInfo CircGfxInfo;
public:
	AddCircleAction(ApplicationManager* pApp);

	
	virtual void ReadActionParameters();

	
	virtual void Execute();

};

#endif