#pragma once
#include "../Phase2 - Code F22/Actions/Action.h"

class switchtoplaymode :
    public Action
{
public:
    switchtoplaymode(ApplicationManager* pApp);
    virtual void ReadActionParameters();
    virtual void Execute();

};


