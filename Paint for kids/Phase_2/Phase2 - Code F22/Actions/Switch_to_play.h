
#pragma once
#include"../ApplicationManager.h"
#include"Action.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"

	class Switch_to_play :public Action
	{
	public:
		Switch_to_play(ApplicationManager* a);
		void ReadActionParameters();
		void Execute();
		virtual void undo();
		virtual void redo();

		virtual bool isRecordable();
	};


