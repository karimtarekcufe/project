#include "../Phase2 - Code F22/AddCircleAction.h"
#include "../Phase2 - Code F22/CCircle.h"

#include "../Phase2 - Code F22/ApplicationManager.h"


#include "../Phase2 - Code F22/GUI/Input.h"
#include "../Phase2 - Code F22/GUI/Output.h"

AddCircleAction::AddCircleAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddCircleAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Circle: Click at centre");

	
	pIn->GetPointClicked(Centre.x, Centre.y);

	pOut->PrintMessage("New Circle: Click at edge");

	
	pIn->GetPointClicked(Edge.x, Edge.y);

	CircGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	CircGfxInfo.DrawClr = pOut->getCrntDrawColor();
	CircGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddCircleAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a rectangle with the parameters read from the user
	CCircle* R = new CCircle(Centre, Edge, CircGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(R);
}
