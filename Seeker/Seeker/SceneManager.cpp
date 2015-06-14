#include "SceneManager.h"
using namespace std;

// �V�[���̃w�b�_
#include "SceneDemo.h"
#include "SceneTitle.h"
#include "ScenePlay.h"
#include "ScenePouse.h"
#include "SceneEnd.h"

//--------------------------------------------------
// ���Ԑ錾
//--------------------------------------------------
SceneManager* SceneManager::scene_manager = new SceneManager();

// 
void SceneManager::Push(SCENE _type)
{
	switch (_type)
	{
	case SceneManager::DEMO:
		scene.push_back(new SceneDemo());
		break;
	
	case SceneManager::TITLE:
		scene.push_back(new SceneTitle());
		break;
	
	case SceneManager::PLAY:
		scene.push_back(new ScenePlay());
		break;
	
	case SceneManager::POUSE:
		scene.push_back(new ScenePouse());
		break;
	
	case SceneManager::END:
		scene.push_back(new SceneEnd());
		break;
	}
}

// scene �̍ŏI�v�f�ɓo�^���ꂽ�V�[���N���X�� Update ���Ă�
void SceneManager::Update()
{
	scene[scene.size() - 1]->Update();
}

void SceneManager::Draw()
{
	for (auto &var : scene)
	{
		var->Draw();
	}
}

// scene �̍ŏI�v�f���������
void SceneManager::Pop()
{
	delete scene[scene.size() - 1];	// �Ō�̗v�f�̃|�C���^(�Ŋm�ۂ��ꂽ������)���������
	scene.pop_back();				// �z�������폜����
}

// �ŏI�v�f��j�����đ��̗v�f������
void SceneManager::GoTo(SCENE _type)
{
	this->Pop();
	this->Push(_type);
}

// �v�f��S�ĉ������
// ������Ō�ɌĂ΂Ȃ��ƃ��������[�N���N�����\��
void SceneManager::Finalize()
{
	for (auto &var : scene)
	{
		delete var;	// �m�ۂ��������������
	}
	scene.clear();	// �v�f��S�Ĕj��
}