#include "DxLib.h"
#include "SceneChange.h"
#include "TextureManager.h"
#include "SceneManager.h"

#define CHANGE_VOLUME	8

SceneChange::SceneChange()
{

}

void SceneChange::Update()
{
	// このシーンとフェードに使ったシーンを残してポップ
	SceneManager::GetInstance()->B_Leave(2);
	
	// 新たなシーンを前からプッシュ
	SceneManager::GetInstance()->F_Push(SceneManager::GetInstance()->Next());
	
	// このシーンをポップ
	SceneManager::GetInstance()->B_Pop();
}

void SceneChange::Draw()
{

}