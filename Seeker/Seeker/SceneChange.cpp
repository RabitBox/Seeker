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
	// ���̃V�[���ƃt�F�[�h�Ɏg�����V�[�����c���ă|�b�v
	SceneManager::GetInstance()->B_Leave(2);
	
	// �V���ȃV�[����O����v�b�V��
	SceneManager::GetInstance()->F_Push(SceneManager::GetInstance()->Next());
	
	// ���̃V�[�����|�b�v
	SceneManager::GetInstance()->B_Pop();
}

void SceneChange::Draw()
{

}