#pragma once
#include "../Phase2 - Code F22/Actions/Action.h"
class PickByType :
    public Action
{

private:
    int countc;
    int countw;
    CFigure* F;
    int FI;
public:
    PickByType(ApplicationManager* pApp);
    virtual void ReadActionParameters();


    virtual void Execute();

};

