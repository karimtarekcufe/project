#ifndef ADD_SQR_ACTION_H
#define ADD_SQR_ACTION_H

#include "../Phase2 - Code F22/Actions/Action.h"

//Add Rectangle Action class
class AddSquareAction : public Action
{
private:
	Point Centre;
	GfxInfo SqrGfxInfo;
public:
	AddSquareAction(ApplicationManager* pApp);


	virtual void ReadActionParameters();


	virtual void Execute();

};

#endif
