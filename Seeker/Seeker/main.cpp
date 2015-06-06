// DXライブラリ + C++ で開発
// Gai Takakura
#include "Application.h"

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	unique_ptr<Application> app(new Application());

	app -> AppMain();

	return 0; 
}