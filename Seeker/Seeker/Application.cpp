#include "Application.h"
#include "DxLib.h"
#include "Generic.h"
#include "InputManager.h"

Application::Application()
{
	Initialize();
	scene.reset(new ScenePlay());
	stack_scene = SceneManager::GetInstance();
}
Application::~Application()
{
	stack_scene->Finalize();
	DxLib_End();
}

void Application::AppMain()
{
	while (!CheckHitKey(KEY_INPUT_ESCAPE) || ProcessMessage() == -1)
	{
		// FPSのズレを計測
		fps.Update();

		// 描画をリセット
		ClearDrawScreen();

		// 入力
		InputManager::GetInstance() -> Input();

		// 更新
		scene->Update();

		// 描画
		scene->Draw();
		
		// ズレを修正
		fps.Wait();
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