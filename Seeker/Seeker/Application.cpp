#include "Application.h"
#include "DxLib.h"
#include "Generic.h"
#include "InputManager.h"

Application::Application()
{
	Initialize();
	SceneManager::Create();
#ifdef _DEBUG
	//SceneManager::GetInstance()->B_Push(SceneManager::SCENE::PLAY);
	SceneManager::GetInstance()->B_Push(SceneManager::SCENE::TITLE);
#else
	SceneManager::GetInstance()->B_Push(SceneManager::SCENE::TITLE);
#endif
}
Application::~Application()
{
	SceneManager::Destroy();
	DxLib_End();
}

void Application::AppMain()
{
	while (!CheckHitKey(KEY_INPUT_ESCAPE)
		&& (SceneManager::GetInstance()->EndFlag())
		|| ProcessMessage() == -1)
	{
		DrawFormatString(0,105,GetColor(255,255,255),"ゲーム中");

		// FPSのズレを計測
		fps.Update();

		// 描画をリセット
		ClearDrawScreen();

		// 入力
		InputManager::GetInstance() -> Input();

		// 更新
		//scene->Update();
		SceneManager::GetInstance()->Update();

		// 描画
		//scene->Draw();
		SceneManager::GetInstance()->Draw();
		
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