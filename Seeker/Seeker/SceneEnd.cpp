#include "SceneEnd.h"
#include "SceneManager.h"
#include "DxLib.h"
#include "TextureManager.h"
#include "DxRaps.h"

#define END_TIME 300
#define MESSAGE_SIZE 0.7f

SceneEnd::SceneEnd()
{
	time = 0;
	int dem_load = LoadGraph("Texture/coollogo_EndMessage.png");
	images = TextureManager::GetInstance()->LoadTexture("EndMessage", dem_load);
}

void SceneEnd::Update()
{
	time++;
	if (time > END_TIME)
	{
		SceneManager::GetInstance()->NextSet(SceneManager::TITLE);
		SceneManager::GetInstance()->B_Push(SceneManager::FADE);
	}
}

void SceneEnd::Draw()
{
	DrawGraphExtend(400, 300, MESSAGE_SIZE, *images, true);
}