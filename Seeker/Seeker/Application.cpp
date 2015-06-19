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
		// FPS�̃Y�����v��
		fps.Update();

		// ����
		InputManager::GetInstance() -> Input();

		// �X�V
		//scene->Update();
		SceneManager::GetInstance()->Update();

		// �`��
		ClearDrawScreen();
		SetDrawScreen(DX_SCREEN_BACK);
		SceneManager::GetInstance()->Draw();
		ScreenFlip();
		
		// �Y�����C��
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