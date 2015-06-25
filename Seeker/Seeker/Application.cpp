#include "Application.h"
#include "DxLib.h"
#include "Generic.h"
#include "InputManager.h"
#include "TextureManager.h"
#include "CollisionManager.h"
#include "InputManager.h"

Application::Application()
{
	Initialize();
	SceneManager::Create();
	TextureManager::Create();
	CollisionManager::Create();
	InputManager::Create();

#ifdef _DEBUG
	SceneManager::GetInstance()->B_Push(SceneManager::SCENE::PLAY);
	//SceneManager::GetInstance()->B_Push(SceneManager::SCENE::TITLE);
	//SceneManager::GetInstance()->B_Push(SceneManager::SCENE::END);
#else
	SceneManager::GetInstance()->B_Push(SceneManager::SCENE::TITLE);
#endif
}
Application::~Application()
{
	SceneManager::Destroy();
	TextureManager::Destroy();
	CollisionManager::Destroy();
	InputManager::Destroy();
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

		ClearDrawScreen();
		SetDrawScreen(DX_SCREEN_BACK);

		// 更新
		SceneManager::GetInstance()->Update();

		// 描画
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