#include"Play.h"

void main()
{
	//_CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);
	//_crtBreakAlloc = 46502;

	Play PlayManager;
	PlayManager.GamePlayMain();
}