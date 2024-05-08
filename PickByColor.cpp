#include "../Phase2 - Code F22/ApplicationManager.h"
#include "../Phase2 - Code F22/GUI/Input.h"
#include "../Phase2 - Code F22/GUI/Output.h"
#include "PickByColor.h"

PickByColor::PickByColor(ApplicationManager* pApp):Action(pApp)
{
	countc = 0;
	countw = 0;
}

void PickByColor::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	F = pManager->GetRandomFig();
	color fc = F->getGfx().FillClr;
	if (fc == YELLOW) {
		pOut->PrintMessage("pick all Yellow Figures whohooo ");
	}
	else if (fc == BLACK){
		pOut->PrintMessage("pick all BLACK Figures whohooo ");
	}
	else if (fc == BLUE) {
		pOut->PrintMessage("pick all  BLUE Figures whohooo ");
	}
	else if (fc == GREEN) {
		pOut->PrintMessage("pick all GREEN Figures whohooo ");
	}
	else if (fc == RED) {
		pOut->PrintMessage("pick all  RED Figures whohooo ");
	}
	else if (fc == ORANGE) {
		pOut->PrintMessage("pick all ORANGE Figures whohooo ");
	}
	else {
		pOut->PrintMessage("no filled collors");
	}
}

void PickByColor::Execute()
{
	Output* pO = pManager->GetOutput();
	Input* pI = pManager->GetInput();
	ReadActionParameters();
	while (pManager->CheckForFigInFLForClr(F)) {
		Point P;
		pI->GetPointClicked(P.x, P.y);
		if (pManager->GetFigure(P.x, P.y) != NULL) {
			CFigure* FN = pManager->GetFigure(P.x, P.y);
			if (FN->getGfx().FillClr == F->getGfx().FillClr) {
				countc++;
				pO->ClearStatusBar();
				string s = " right pick num of correct choices = " + to_string(countc) + " and the num of wrong choice = " + to_string(countw);
				pO->PrintMessage(s);
				//delete fn
			}
			else if (FN->getGfx().FillClr != F->getGfx().FillClr) {
				countw++;
				pO->ClearStatusBar();
				string s = " wrong pick num of correct choices = " + to_string(countc) + " and the num of wrong choice = " + to_string(countw);
				pO->PrintMessage(s);
			}
		}
		else { pO->PrintMessage("thats not a figure"); }
	}
}
