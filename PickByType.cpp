#include "../Phase2 - Code F22/ApplicationManager.h"
#include "../Phase2 - Code F22/GUI/Input.h"
#include "../Phase2 - Code F22/GUI/Output.h"
#include "PickByType.h"

PickByType::PickByType(ApplicationManager* pApp):Action(pApp)
{
	countc = 0;
	countw = 0;
}

void PickByType::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->ClearStatusBar();
	pOut->PrintMessage("now i am going to choose a fig to pick");
	
	F = pManager->GetRandomFig();
	 FI = F->getShapeIdentity();
	 switch (F->getShapeIdentity()) {
	 case 1:
		 pOut->ClearStatusBar();
		 pOut->PrintMessage("pick all circles");
		 break;
	 case 2:
		 pOut->ClearStatusBar();
		 pOut->PrintMessage("pick all Hexagons");
		 break;
	 case 3:
		 pOut->ClearStatusBar();
		 pOut->PrintMessage("pick all Rectngeles");
		 break;
	 case 4:
		 pOut->ClearStatusBar();
		 pOut->PrintMessage("pick all squares");
		 break;
	 case 5:
		 pOut->ClearStatusBar();
		 pOut->PrintMessage("pick all triangeles");
		 break;
	 }
	
	//pManger->saveall();
}
	


	



void PickByType::Execute() {
	Output* pO = pManager->GetOutput();
	Input* pI = pManager->GetInput();
	ReadActionParameters();
	while (pManager->CeckForFigInFLForType(F)) {
		Point P;
		pI->GetPointClicked(P.x, P.y);
		if (pManager->GetFigure(P.x, P.y) != NULL) {
			CFigure* FN = pManager->GetFigure(P.x, P.y);
			if (FN->getShapeIdentity() == F->getShapeIdentity()) {
				countc++;
				pO->ClearStatusBar();
				string s = " right pick num of correct choices = " + to_string(countc) + " and the num of wrong choice = " + to_string(countw);
				pO->PrintMessage(s);
				//delete fn
			}
			else if (FN->getShapeIdentity() != F->getShapeIdentity()) {
				countw++;
				pO->ClearStatusBar();
				string s = " wrong pick num of correct choices = " + to_string(countc) + " and the num of wrong choice = " + to_string(countw);
				pO->PrintMessage(s);
			}
		}
		else { pO->PrintMessage("thats not a figure"); }
	}
}

