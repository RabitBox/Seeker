#include "Application.h"
#include "DxLib.h"
#include "Generic.h"
#include "InputManager.h"
#include "TextureManager.h"

Application::Application()
{
	Initialize();
	SceneManager::Create();
	TextureManager::Create();

#ifdef _DEBUG
	//SceneManager::GetInstance()->B_Push(SceneManager::SCENE::PLAY);
	SceneManager::GetInstance()->B_Push(SceneManager::SCENE::TITLE);
	//SceneManager::GetInstance()->B_Push(SceneManager::SCENE::END);
#else
	SceneManager::GetInstance()->B_Push(SceneManager::SCENE::TITLE);
#endif
}
Application::~Application()
{
	SceneManager::Destroy();
	TextureManager::Destroy();
	DxLib_End();
}

void Application::AppMain()
{
	while (!CheckHitKey(KEY_INPUT_ESCAPE)
		&& (SceneManager::GetInstance()->EndFlag())
		|| ProcessMessage() == -1)
	{
		// FPSのズレを計測
		fps.Update();

		// 入力
		InputManager::GetInstance() -> Input();

		// 更新
		//scene->Update();
		SceneManager::GetInstance()->Update();

		// 描画
		ClearDrawScreen();
		SetDrawScreen(DX_SCREEN_BACK);
		SceneManager::GetInstance()->Draw();
		ScreenFlip();
		
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