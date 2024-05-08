#include "../Phase2 - Code F22/SELECT.h"
#include "Figures/CFigure.h"

#include "../Phase2 - Code F22/ApplicationManager.h"

#include "../Phase2 - Code F22/GUI/Input.h"
#include "../Phase2 - Code F22/GUI/Output.h"

SelectAction::SelectAction(ApplicationManager* pApp) :Action(pApp)
{}

void SelectAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Select a Figure");


	pIn->GetPointClicked(P.x, P.y);


	pOut->ClearStatusBar();

}

//Execute the action
void SelectAction::Execute()
{
	ActionType Action  = DRAWING_AREA;
	Output* pO = pManager->GetOutput();
	Input* pI = pManager->GetInput();
	GfxInfo* GfxArr = new GfxInfo[200];
	CFigure* FigArr[200];
	int k = 0;
	int CirCount = 0;
	int HexCount = 0;
	int RectCount = 0;
	int Squareount = 0;
	int TriCount = 0;

	ReadActionParameters();

	//Create a rectangle with the parameters read from the user
	if (pManager->GetFigure(P.x, P.y)!=NULL) {
		CFigure* F = pManager->GetFigure(P.x, P.y);
		FigArr[k] = F;

		switch (F->getShapeIdentity()) {
		case 1:
			CirCount++;
			break;
		case 2:
			HexCount++;
			break;
		case 3:
			RectCount++;
			break;
		case 4:
			Squareount++;
			break;
		case 5:
			TriCount++;
			break;
		}
		GfxArr[k]= pManager->GetFigure(P.x, P.y)->getGfx();
		k++;
		F->SetSelected(true);
		F->ChngDrawClr(MAGENTA);
		F->PrintShapeInfo(pO);
		pManager->UpdateInterface();
		Action = pManager->GetUserAction();

	}
	else {
		pO->PrintMessage("Figure NOT Found");

	}
	while (Action != DRAWING_AREA) {
		switch (Action) {
		case SELECT:
			ReadActionParameters();
			if (pManager->GetFigure(P.x, P.y) != NULL) {
				CFigure* F = pManager->GetFigure(P.x, P.y);
				if (F->IsSelected()) {
					Action = DRAWING_AREA;
				}
				else {
					FigArr[k] = F;

					switch (F->getShapeIdentity()) {
					case 1:
						CirCount++;
						break;
					case 2:
						HexCount++;
						break;
					case 3:
						RectCount++;
						break;
					case 4:
						Squareount++;
						break;
					case 5:
						TriCount++;
						break;
					}
					GfxInfo Gfx = pManager->GetFigure(P.x, P.y)->getGfx();
					GfxArr[k] = Gfx;
					k++;
					F->SetSelected(true);
					F->ChngDrawClr(MAGENTA);
					pManager->UpdateInterface();
					string r = to_string(RectCount);
					string c = to_string(CirCount);
					string s = to_string(Squareount);
					string t = to_string(TriCount);
					string h = to_string(HexCount);
					string selected = "Selected: Rectangle(" + r + ") Circle(" + c + ") Square(" + s + ") Triangle(" + t + ") Hexagon(" + h + ")";
					pO->PrintMessage(selected);
					Action = pManager->GetUserAction();
				}
			}
			else {
				pO->PrintMessage("Figure NOT Found");
			}
			break;
		case FILL_COLOR:
			if(k==1){
				CFigure* F;
				for (int i = 0; i < k; i++) {
					if (FigArr[i]->IsSelected()) {
						F = FigArr[i];
						break;
					}
				}
				F = pManager->SearchFigure(F->getID());
				pO->PrintMessage("Choose A Color To Fill The Shape With");
				Action = pManager->GetUserAction();
				pO->ClearStatusBar();
				switch (Action) {
				case BLACK_BORDER:
					F->ChngFillClr(BLACK);
					Action = DRAWING_AREA;
					pManager->UpdateInterface();
					break;
				case YELLOW_BORDER:
					F->ChngFillClr(YELLOW);
					Action = DRAWING_AREA;
					pManager->UpdateInterface();
					break;
				case BLUE_BORDER:
					F->ChngFillClr(BLUE);
					Action = DRAWING_AREA;
					pManager->UpdateInterface();
					break;
				case RED_BORDER:
					F->ChngFillClr(RED);
					Action = DRAWING_AREA;
					pManager->UpdateInterface();
					break;
				case ORANGE_BORDER:
					F->ChngFillClr(ORANGE);
					Action = DRAWING_AREA;
					pManager->UpdateInterface();
					break;
				case GREEN_BORDER:
					F->ChngFillClr(GREEN);
					Action = DRAWING_AREA;
					pManager->UpdateInterface();
					break;
				default:
					Action = DRAWING_AREA;
					pManager->UpdateInterface();
					break;
				}
			}else{
				pO->PrintMessage("Cannot Use This Function For Than One Shape!");
				Action = DRAWING_AREA;
			}
			break;
		case COLOR_BORDER:
			if (k == 1) {
				CFigure* F;
				int i = 0;
				for (i; i < k; i++) {
					if (FigArr[i]->IsSelected()) {
						F = *FigArr;
						break;
					}
				}
				F = pManager->SearchFigure(F->getID());
				pO->PrintMessage("Choose A Color To Outline The Shape With");
				Action = pManager->GetUserAction();
				pO->ClearStatusBar();
				switch (Action) {
				case BLACK_BORDER:
					F->ChngDrawClr(BLACK);
					GfxArr[i].DrawClr = BLACK;
					Action = DRAWING_AREA;
					pManager->UpdateInterface();
					break;
				case YELLOW_BORDER:
					F->ChngDrawClr(YELLOW);
					GfxArr[i].DrawClr = YELLOW;
					Action = DRAWING_AREA;
					pManager->UpdateInterface();
					break;
				case BLUE_BORDER:
					F->ChngDrawClr(BLUE);
					GfxArr[i].DrawClr = BLUE;
					Action = DRAWING_AREA;
					pManager->UpdateInterface();
					break;
				case RED_BORDER:
					F->ChngDrawClr(RED);
					GfxArr[i].DrawClr = RED;
					Action = DRAWING_AREA;
					pManager->UpdateInterface();
					break;
				case ORANGE_BORDER:
					F->ChngDrawClr(ORANGE);
					GfxArr[i].DrawClr = ORANGE;
					Action = DRAWING_AREA;
					pManager->UpdateInterface();
					break;
				case GREEN_BORDER:
					F->ChngDrawClr(GREEN);
					GfxArr[i].DrawClr = GREEN;
					Action = DRAWING_AREA;
					pManager->UpdateInterface();
					break;
				default:
					Action = DRAWING_AREA;
					pManager->UpdateInterface();
					break;
				}
			}
			else {
				pO->PrintMessage("Cannot Use This Function For Than One Shape!");
				Action = DRAWING_AREA;
			}
			break;

		default:
			Action = DRAWING_AREA;
			break;
		}
		//write the other cases

	}
	for (int i = 0; i < k;i++) {
		CFigure* FigureToReturn = pManager->SearchFigure(FigArr[i]->getID());
		FigureToReturn->returnGfx(GfxArr[i]);
		pManager->UpdateInterface();
	}
	pO->ClearStatusBar();
	delete []GfxArr;
}
