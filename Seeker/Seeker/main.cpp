// DX���C�u���� + C++ �ŊJ��
// Gai Takakura
#include "DxLib.h"
#include "ScenePlay.h"

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetMainWindowText("Seeker");
	SetGraphMode(800, 600, 32);
	ChangeWindowMode(TRUE);
	if (DxLib_Init() == -1)	{ return -1; }

	SceneBace *Scene = new ScenePlay;	// ���u��

	while (!CheckHitKey(KEY_INPUT_ESCAPE) || ProcessMessage() == -1)
	{
		Scene->Input();					// ���u��
		Scene->Update();				// ���u��
		Scene->Draw();					// ���u��
	}
	delete Scene;						// ���u��
	DxLib_End();
	return 0; 
}