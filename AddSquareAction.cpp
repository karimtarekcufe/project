#include "../Phase2 - Code F22/AddSquareAction.h"
#include "../Phase2 - Code F22/CSquare.h"

#include "../Phase2 - Code F22/ApplicationManager.h"

#include "../Phase2 - Code F22/GUI/Input.h"
#include "../Phase2 - Code F22/GUI/Output.h"

AddSquareAction::AddSquareAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddSquareAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Square: Click at centre");


	pIn->GetPointClicked(Centre.x, Centre.y);


	SqrGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	SqrGfxInfo.DrawClr = pOut->getCrntDrawColor();
	SqrGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddSquareAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a rectangle with the parameters read from the user
	CSquare* R = new CSquare(Centre, SqrGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(R);
}
