#pragma once
#include "../Phase2 - Code F22/Actions/Action.h"

class PickByColor :
    public Action
{
private:
   
    CFigure* F;
    int countc;
    int countw;
public:
    PickByColor(ApplicationManager* pApp);
    virtual void ReadActionParameters();


    virtual void Execute();
};

