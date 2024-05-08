#include "../Phase2 - Code F22/AddTriangleAction.h"
#include "../Phase2 - Code F22/CTriangle.h"

#include "../Phase2 - Code F22/ApplicationManager.h"

#include "../Phase2 - Code F22/GUI/Input.h"
#include "../Phase2 - Code F22/GUI/Output.h"

AddTriangleAction::AddTriangleAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddTriangleAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Triangle: Click first Point");


	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Triangle: Click second Point");


	pIn->GetPointClicked(P2.x, P2.y);

	pOut->PrintMessage("New Triangle: Click third Point");


	pIn->GetPointClicked(P3.x, P3.y);

	TriangleGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	TriangleGfxInfo.DrawClr = pOut->getCrntDrawColor();
	TriangleGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddTriangleAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a rectangle with the parameters read from the user
	CTriangle* R = new CTriangle(P1, P2, P3, TriangleGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(R);
}
