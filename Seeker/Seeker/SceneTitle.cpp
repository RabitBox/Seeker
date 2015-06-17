#include <algorithm>
#include "SceneTitle.h"
#include "DxLib.h"
#include "DxRaps.h"
#include "SceneManager.h"
#include "TextureManager.h"
#include "InputManager.h"
using namespace std;

#define B_SIZE 1.3f 
#define S_SIZE 0.8f

SceneTitle::SceneTitle()
{
	mode = Mode::WAIT;
	select = Select::PLAY_GAME;

	int dem_load[] = {
		LoadGraph("Texture/coollogo_seeker.png"),
		LoadGraph("Texture/coollogo_Press.png"),
		LoadGraph("Texture/coollogo_Play.png"),
		LoadGraph("Texture/coollogo_End.png")
	};

	images.push_back((TextureManager::GetInstance()->LoadTexture("TitleLogo", dem_load[0])));
	images.push_back((TextureManager::GetInstance()->LoadTexture("PRESS", dem_load[1])));
	images.push_back((TextureManager::GetInstance()->LoadTexture("PLAY", dem_load[2])));
	images.push_back((TextureManager::GetInstance()->LoadTexture("END", dem_load[3])));
}
SceneTitle::~SceneTitle()
{

}

void SceneTitle::Update()
{
	switch (mode)
	{
	case Mode::WAIT:
		Now_Wait();
		break;

	case Mode::SELECT:
		Now_Select();
		break;
	}
}
void SceneTitle::Draw()
{	
	Now_ModeDraw();

#ifdef _DEBUG
	// パラメータ確認のため
	DrawFormatString(0, 0, GetColor(255, 255, 255), "I'm Title");
	DrawFormatString(0, 15, GetColor(255, 255, 255), "%d", mode);
	DrawFormatString(0, 30, GetColor(255, 255, 255), "%d", select);
#endif
}

void SceneTitle::Now_Wait()
{
	//InputManager* input = InputManager::GetInstance();
	if (input->GetButtanInputA() == InputManager::Buttan::On)
		mode = Mode::SELECT;
}

void SceneTitle::Now_Select()
{
	//InputManager* input = InputManager::GetInstance();
	switch (select)
	{
	case Select::PLAY_GAME:
		if (input->GetButtanInputA()) return;
		if (input->GetArrowInput().down) select = Select::END_GAME;
		break;

	case Select::END_GAME:
		if (input->GetButtanInputA()) SceneManager::GetInstance()->EndCall();
		if (input->GetArrowInput().up) select = Select::PLAY_GAME;
		break;
	}
}

void SceneTitle::Now_ModeDraw()
{
	DrawGraphExtend(400, 200, 1.f, *images[0], true);

	switch (mode)
	{
	case SceneTitle::WAIT:
		DrawGraphExtend(400, 450, 0.7f, *images[1], true);
		break;

	case SceneTitle::SELECT:
		
		switch (select)
		{
		case Select::PLAY_GAME:
			DrawGraphExtend(400, 420, B_SIZE, *images[2], true);
			DrawGraphExtend(400, 480, S_SIZE, *images[3], true);
			break;

		case Select::END_GAME:
			DrawGraphExtend(400, 420, S_SIZE, *images[2], true);
			DrawGraphExtend(400, 480, B_SIZE, *images[3], true);
			break;
		}

		break;
	}
}