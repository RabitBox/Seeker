#include "SceneManager.h"
using namespace std;

// �V�[���̃w�b�_
#include "SceneDemo.h"
#include "SceneTitle.h"
#include "ScenePlay.h"
#include "ScenePouse.h"
#include "SceneEnd.h"

#include "DxLib.h"

//--------------------------------------------------
// ���Ԑ錾
//--------------------------------------------------
SceneManager* SceneManager::scene_manager = nullptr;//new SceneManager();

SceneManager::~SceneManager()
{
	if (!scene.empty()){
		for (auto &var : scene){ delete var; }
		scene.clear();	// �v�f��S�Ĕj��
	}
}

// �g�p�J�n���ɌĂ�
void SceneManager::Create()
{
	scene_manager = new SceneManager();
}

// �g�p�I�����ɌĂ�
void SceneManager::Destroy()
{
	delete scene_manager;
	scene_manager = nullptr;
}

// scene �̍ŏI�v�f�ɓo�^���ꂽ�V�[���N���X�� Update ���Ă�
void SceneManager::Update()
{
	DrawFormatString(0,60,GetColor(255,255,255),"�X�V���܂���");
	if (!scene.empty()){
		vector<SceneBace*>::iterator itr = --scene.end();
		(*itr)->Update();
	}	
}

void SceneManager::Draw()
{
	DrawFormatString(0, 75, GetColor(255, 255, 255), "�`�悵�܂���");
	if (!scene.empty()){
		for (auto &var : scene)
		{
			var->Draw();
		}
	}
}

// ��납��v�f������
void SceneManager::B_Push(SCENE _type)
{
	switch (_type)
	{
	case SceneManager::DEMO:
		scene.push_back((new SceneDemo()));
		break;

	case SceneManager::TITLE:
		scene.push_back((new SceneTitle()));
		break;

	case SceneManager::PLAY:
		scene.push_back((new ScenePlay()));
		break;

	case SceneManager::POUSE:
		scene.push_back((new ScenePouse()));
		break;

	case SceneManager::END:
		scene.push_back((new SceneEnd()));
		break;
	}
}

// ��납��v�f��j������
void SceneManager::B_Pop()
{
	if (!scene.empty()){

		vector<SceneBace*>::iterator itr = --scene.end();
		delete (*itr);

		// �z�������폜����
		scene.pop_back();
	}
}

// B_Pop��������B_Push����
void SceneManager::B_GoTo(SCENE _type)
{
	this->B_Pop();
	this->B_Push(_type);
}

// �O����v�f������
void SceneManager::F_Push(SCENE _type)
{
	// �ŏ��̗v�f���w���C�e���[�^������
	vector<SceneBace*>::iterator itr = scene.begin();

	// �C�e���[�^�̎w���v�f�̑O�ɐV���ȗv�f���˂�����
	switch (_type)
	{
	case SceneManager::DEMO:
		scene.insert(itr, (new SceneDemo()));
		break;

	case SceneManager::TITLE:
		scene.insert(itr, (new SceneTitle()));
		break;

	case SceneManager::PLAY:
		scene.insert(itr, (new ScenePlay()));
		break;

	case SceneManager::POUSE:
		scene.insert(itr, (new ScenePouse()));
		break;

	case SceneManager::END:
		scene.insert(itr, (new SceneEnd()));
		break;
	}
}

// �O����v�f��j������
void SceneManager::F_Pop()
{
	if (!scene.empty()){
		// �ŏ��̗v�f���w���C�e���[�^������
		vector<SceneBace*>::iterator itr = scene.begin();

		delete (*itr);

		// �ŏ��̗v�f�͔j��
		scene.erase(itr);
	}
}

// F_Pop��������F_Push����
void SceneManager::F_GoTo(SCENE _type)
{
	F_Pop();
	F_Push(_type);
}