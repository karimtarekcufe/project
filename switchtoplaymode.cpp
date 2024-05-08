#include "switchtoplaymode.h"
#include "../Phase2 - Code F22/ApplicationManager.h"

#include "../Phase2 - Code F22/GUI/Input.h"
#include "../Phase2 - Code F22/GUI/Output.h"

switchtoplaymode::switchtoplaymode(ApplicationManager* pApp) :Action(pApp)
{}

void switchtoplaymode::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("switch to play mode ");
}

void switchtoplaymode::Execute()
{
	//ApplicationManager* SG;
	//SG->ExecuteAction(SAVE_ITEM);
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->CreatePlayToolBar();
	pOut->PrintMessage("now to play mode ");
	pIn->GetUserAction();
}
