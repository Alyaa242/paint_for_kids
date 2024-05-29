#ifndef ADD_HEX_ACTION
#define ADD_HEX_ACTION
#include "Action.h"


#include "..\Figures\CHexagon.h"


class AddHexAction:public Action
{
private:
	
	CHexagon* hex;
	Point P;
	GfxInfo HexGfxInfo;
public:
	AddHexAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void undo();
	virtual void redo();

	virtual bool isRecordable();
};

#endif