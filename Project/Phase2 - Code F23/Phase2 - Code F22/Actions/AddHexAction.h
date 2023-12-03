#ifndef ADD_HEX_ACTION
#define ADD_HEX_ACTION
#include "Action.h"
class AddHexAction:public Action
{
private:
	Point P;
	GfxInfo HexGfxInfo;
public:
	AddHexAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

#endif