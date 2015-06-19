#include "SceneFade.h"
#include "DxLib.h"
#include "TextureManager.h"
#include "SceneManager.h"
#include "DxRaps.h"

#define ADD_VOL 10
#define TOP		800
#define UNDER	400

SceneFade::SceneFade()
{
	mode = ADD;
	volume = TOP;
	int dem_load = LoadGraph("Texture/black.bmp");
	images.push_back((TextureManager::GetInstance()->LoadTexture("Black", dem_load)));
}

void SceneFade::Update()
{
	switch (mode)
	{
	case SceneFade::ADD:
		volume -= ADD_VOL ;
		if (volume <= UNDER){
			volume = UNDER;
			mode = CALL;
		}
		break;

	case SceneFade::CALL:
		SceneManager::GetInstance()->B_Push(SceneManager::CHANGE);
		mode = GAIN;
		break;

	case SceneFade::GAIN:
		volume += ADD_VOL;
		if (volume >= TOP){
			volume = TOP;
			SceneManager::GetInstance()->B_Pop();
		}
		break;
	}
}

void SceneFade::Draw()
{
	DrawGraphExtend(400 + volume, 300, 2.f, *images[0], false);
	DrawGraphExtend(400 - volume, 300, 2.f, *images[0], false);
}