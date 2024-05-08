#ifndef SELECT_ACTION_H
#define SELECT_ACTION_H

#include "../Phase2 - Code F22/Actions/Action.h"

//Add Rectangle Action class
class SelectAction : public Action
{
private:
	Point P;

public:
	SelectAction(ApplicationManager* pApp);


	virtual void ReadActionParameters();


	virtual void Execute();

};

#endif