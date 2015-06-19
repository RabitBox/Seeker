#include "ScenePouse.h"
#include "DxLib.h"
#include "DxRaps.h"
#include "TextureManager.h"
#include "SceneManager.h"

ScenePouse::ScenePouse()
{
	int dem_load = LoadGraph("Texture/coollogo_Pouse.png");
	images.push_back((TextureManager::GetInstance()->LoadTexture("POUSE", dem_load)));
}

void ScenePouse::Update()
{
	// ポーズ終了
	if (input->GetButtanInputB()) SceneManager::GetInstance()->B_Pop() ;
}

void ScenePouse::Draw()
{
	DrawGraphExtend(400, 300, 1.0f, *images[0], true);
}