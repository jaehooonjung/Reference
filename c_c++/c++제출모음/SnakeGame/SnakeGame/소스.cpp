#include"Game.h"

void main()
{
	Game GameManager;
	GameManager.MainMenu();
	_CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);
	//_crtBreakAlloc = 563;
}