//#include "../Phase2 - Code F22/ApplicationManager.h"
//#include "../Phase2 - Code F22/GUI/Input.h"
//#include "../Phase2 - Code F22/GUI/Output.h"
//#include "PickByTypeAndColor.h"
//
//PickByTypeAndColor::PickByTypeAndColor(ApplicationManager* pApp) :Action(pApp)
//{
//	countc = 0;
//	countw = 0;
//}
//
//void PickByTypeAndColor::ReadActionParameters()
//{
//	Output* pOut = pManager->GetOutput();
//	Input* pIn = pManager->GetInput();
//	F = pManager->GetRandomFig();
//	switch (type) {
//	case 1:
//		pOut->PrintMessage("choose all circels ");
//		break;
//	case 2:
//		pOut->PrintMessage("choose all hexagons ");
//		break;
//	case 3:
//		pOut->PrintMessage("choose all rectangles ");
//		break;
//	case 4:
//		pOut->PrintMessage("choose all squares ");
//		break;
//	case 5:
//		pOut->PrintMessage("choose all triangels ");
//		break;
//	}
//	color fc = F->getGfx().FillClr;
//	string s = "pick all the figuers with color " + fc;
//	pOut->PrintMessage(s);
//	//pManger->saveall();
//}
//
