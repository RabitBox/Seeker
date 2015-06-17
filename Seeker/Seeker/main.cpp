// DXライブラリ + C++ で開発
// Gai Takakura
#include "Application.h"

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	_CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);

	Application* app = new Application();

	app -> AppMain();

	delete app;

	return 0; 
}