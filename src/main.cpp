#include "Core_Minimal.h"

void LoopCallback()
{
	glClearColor(0.02f, 0.21f, 0.21f, 1.0f); // default background color of window
	glClear(GL_COLOR_BUFFER_BIT);
}

int main()
{			
	Core EngineCore{};
	EngineCore.SetLoopCallbackFunc(LoopCallback);
	EngineCore.Init();
	EngineCore.Loop();

	return 0;
}