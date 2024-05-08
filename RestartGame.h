#pragma once
#include "../Phase2 - Code F22/Actions/Action.h"
class RestartGame :
    public Action
{
public:

    virtual void ReadActionParameters();


    virtual void Execute();
};

