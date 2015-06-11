#include "Application.h"
#include "DxLib.h"
#include "Generic.h"

Application::Application()
{
	Initialize();
	scene.reset(new ScenePlay());
}
Application::~Application()
{
	DxLib_End();
}

void Application::AppMain()
{
	while (!CheckHitKey(KEY_INPUT_ESCAPE) || ProcessMessage() == -1)
	{
		ClearDrawScreen();
		fps.Update();		// FPS�̃Y�����v��
		scene->Input();
		scene->Update();
		scene->Draw();
		fps.Wait();			// �Y�����C��
	}
	return;
}

int Application::Initialize()
{
	SetMainWindowText("Seeker");
	SetGraphMode(800, 600, 32);
	ChangeWindowMode(TRUE);
	if (DxLib_Init() == -1)	{ return -1; }
	return 0;
}