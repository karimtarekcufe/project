#include "../Phase2 - Code F22/AddHexAction.h"
#include "../Phase2 - Code F22/CHex.h"

#include "../Phase2 - Code F22/ApplicationManager.h"

#include "../Phase2 - Code F22/GUI/Input.h"
#include "../Phase2 - Code F22/GUI/Output.h"

AddHexAction::AddHexAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddHexAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Square: Click at centre");


	pIn->GetPointClicked(Centre.x, Centre.y);


	HexGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	HexGfxInfo.DrawClr = pOut->getCrntDrawColor();
	HexGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddHexAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a rectangle with the parameters read from the user
	CHex* R = new CHex(Centre, HexGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(R);
}
