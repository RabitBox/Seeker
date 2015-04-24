// DXライブラリ + C++ で開発
// Gai Takakura
#include "DxLib.h"
#include "ScenePlay.h"

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetMainWindowText("Seeker");
	SetGraphMode(800, 600, 32);
	ChangeWindowMode(TRUE);
	if (DxLib_Init() == -1)	{ return -1; }

	SceneBace *Scene = new ScenePlay;	// 仮置き

	while (!CheckHitKey(KEY_INPUT_ESCAPE) || ProcessMessage() == -1)
	{
		Scene->Input();					// 仮置き
		Scene->Update();				// 仮置き
		Scene->Draw();					// 仮置き
	}
	delete Scene;						// 仮置き
	DxLib_End();
	return 0; 
}