#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "../Phase2 - Code F22/AddCircleAction.h"
#include "../Phase2 - Code F22/AddSquareAction.h"
#include "../Phase2 - Code F22/AddHexAction.h"
#include "../Phase2 - Code F22/AddTriangleAction.h"
#include "../Phase2 - Code F22/SELECT.h"
#include "../Phase2 - Code F22/switchtoplaymode.h"
#include "../Phase2 - Code F22/PickByType.h"
#include "../Phase2 - Code F22/PickByColor.h"

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	FigCount = 0;
		
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}

int ApplicationManager::GetFigCount() const {
	return FigCount;
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{

		case DRAW_RECT:
			pAct = new AddRectAction(this);
			break;

		case DRAW_CRCL:
			pAct = new AddCircleAction(this);
			break;

		case DRAW_SQR:
			pAct = new AddSquareAction(this);
			break;
		
		case DRAW_TRNGL:
			pAct = new AddTriangleAction(this);
			break;

		case DRAW_HXGN:
			pAct = new AddHexAction(this);
			break;

		case EXIT:
			///create ExitAction here

			break;

		case SELECT:
			pAct = new SelectAction(this);
			break;

		case BLACK_BORDER:
			///create ExitAction here

			break;

		case YELLOW_BORDER:
			///create ExitAction here

			break;

		case ORANGE_BORDER:
			///create ExitAction here

			break;

		case RED_BORDER:
			///create ExitAction here

			break;

		case GREEN_BORDER:
			///create ExitAction here

			break;

		case BLUE_BORDER:
			///create ExitAction here

			break;

		case BORDER:
			///create ExitAction here

			break;

		case FILL:
			///create ExitAction here

			break;

		case COLOR_BORDER:
			///create ExitAction here

			break;

		case FILL_COLOR:
			///create ExitAction here

			break;

		case CHANGE_ITEM:
			///create ExitAction here

			break;

		case CUT_ITEM:
			///create ExitAction here

			break;

		case COPY_ITEM:
			///create ExitAction here

			break;

		case PASTE_ITEM:
			///create ExitAction here

			break;

		case ERASE_ITEM:
			///create ExitAction here

			break;

		case CLEAR_ITEM:
			///create ExitAction here

			break;

		case FORWARD_ITEM:
			///create ExitAction here

			break;

		case BACKWARD_ITEM:
			///create ExitAction here

			break;

		case SAVE_ITEM:
			///create ExitAction here

			break;

		case DOWNLOAD_ITEM:
			///create ExitAction here

			break;

		case TO_PLAY:
			pAct = new switchtoplaymode(this);
			///create ExitAction here

			break;
		case PICK_BY_TYPE_ACTION:
			pAct = new PickByType (this);

			break;
		case PICK_BY_COLOR_ACTION:
			pAct = new PickByColor(this);
			break;
		case PICK_BY_TYPE_AND_COLOR_ACTION:
			break;
		case RESTART_GAME_ACTION:
			break;
		
		case STATUS:	//a click on the status bar ==> no action
			return;

	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//You may need to change this line depending to your implementation
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if (FigCount < MaxFigCount)
		FigList[FigCount] = pFig;	
		FigList[FigCount++]->setID(FigCount);
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL
	CFigure* Found = NULL;
	for (int i = 0; i < MaxFigCount; i++) {
		if (FigList[i] == NULL) {
			break;
		}
		else if (FigList[i]->isInside(x, y)) {
			Found = FigList[i];
		}
	}
	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.
	if (Found != NULL)
		return Found;
	return NULL;
}
CFigure* ApplicationManager::GetRandomFig()
{
	CFigure* F;
	int y = rand() % (FigCount);
	F = FigList[y];
	return F;
}

bool ApplicationManager::CheckForFigInFLForClr(CFigure* F)
{

	for (int i = 0; i < FigCount; i++) {
		if (FigList[i]->getGfx().FillClr == F->getGfx().FillClr)
			return true;
	}
	return false;
}

bool ApplicationManager::CheckForFigInFLForClrAndType(CFigure* F)
{
	for (int i = 0; i < FigCount; i++) {
		if (FigList[i]->getGfx().FillClr == F->getGfx().FillClr && FigList[i]->getShapeIdentity() == F->getShapeIdentity())
			return true;
	}
	return false;
}

bool ApplicationManager::CeckForFigInFLForType(CFigure* &F)
{
	for (int i = 0; i < FigCount; i++) {
		if (FigList[i]->getShapeIdentity() == F->getShapeIdentity())
			return true;
	}
	return false;
}

CFigure* ApplicationManager::SearchFigure(int id) const
{
	for (int i = 0; i < MaxFigCount; i++) {
		if (id == FigList[i]->getID())
			return FigList[i];
	}
	return NULL;
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	for(int i=0; i<FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}


////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;

	
}
