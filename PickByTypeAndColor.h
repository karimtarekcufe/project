#pragma once
#include "../Phase2 - Code F22/Actions/Action.h"

class PickByTypeAndColor :
    public Action
{
private:

    CFigure* F;
    int countc;
    int countw;
public:
    PickByTypeAndColor(ApplicationManager* pApp);
    virtual void ReadActionParameters();


    virtual void Execute();
};

