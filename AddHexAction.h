#ifndef ADD_HEX_ACTION_H
#define ADD_HEX_ACTION_H

#include "../Phase2 - Code F22/Actions/Action.h"

//Add Rectangle Action class
class AddHexAction : public Action
{
private:
	Point Centre;
	GfxInfo HexGfxInfo;
public:
	AddHexAction(ApplicationManager* pApp);


	virtual void ReadActionParameters();


	virtual void Execute();

};

#endif
