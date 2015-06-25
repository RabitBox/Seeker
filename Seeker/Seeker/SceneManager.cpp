#include "SceneManager.h"
using namespace std;

// �V�[���̃w�b�_
#include "SceneTitle.h"
#include "ScenePlay.h"
#include "ScenePouse.h"
#include "SceneEnd.h"
#include "SceneChange.h"
#include "SceneFade.h"

// ���Ԑ錾 (�ǂ����� Create() ���Ă΂Ȃ���nullptr �̂܂�)
SceneManager* SceneManager::scene_manager = nullptr;

SceneManager::SceneManager()
{
	next_scene = SCENE::TITLE;
	play_flag = true;
}

SceneManager::~SceneManager()
{
	if (!scene.empty()){
		for (auto &var : scene){ delete var; }
		scene.clear();	// �v�f��S�Ĕj��
	}
}

// �g�p�J�n���ɌĂ� (�R���X�g���N�^)
void SceneManager::Create()
{
	scene_manager = new SceneManager();
}

// �g�p�I�����ɌĂ� (�f�X�g���N�^)
void SceneManager::Destroy()
{
	delete scene_manager;
	scene_manager = nullptr;
}

// scene �̍ŏI�v�f�ɓo�^���ꂽ�V�[���N���X�� Update ���Ă�
void SceneManager::Update()
{
	if (!scene.empty()){
		vector<SceneBace*>::iterator itr = --scene.end();
		(*itr)->Update();
	}	
}

// scene �ɓo�^���ꂽ�V�[���N���X�� Draw ���Ă�
void SceneManager::Draw()
{
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

	case SceneManager::CHANGE:
		scene.push_back((new SceneChange()));
		break;

	case SceneManager::FADE:
		scene.push_back((new SceneFade()));
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

// �Ō�̗v�f�ȊO��j������
void SceneManager::B_Leave()
{
	while (scene.size()>1)
	{
		F_Pop();
	}
}

// �����Ŏw�肵�����̗v�f����납��c���Ĕj������
void SceneManager::B_Leave(unsigned int _num)
{
	while (scene.size()>_num)
	{
		F_Pop();
	}
}

// �O����v�f������
void SceneManager::F_Push(SCENE _type)
{
	// �ŏ��̗v�f���w���C�e���[�^������
	vector<SceneBace*>::iterator itr = scene.begin();

	// �C�e���[�^�̎w���v�f�̑O�ɐV���ȗv�f���˂�����
	switch (_type)
	{
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

	case SceneManager::CHANGE:
		scene.insert(itr, (new SceneChange()));
		break;

	case SceneManager::FADE:
		scene.insert(itr, (new SceneFade()));
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

// �ŏ��̗v�f�ȊO��j������
void SceneManager::F_Leave()
{
	while (scene.size()>1)
	{
		B_Pop();
	}
}

// �����Ŏw�肵�����̗v�f��O����c���Ĕj������
void SceneManager::F_Leave(unsigned int _num)
{
	while (scene.size()>_num)
	{
		B_Pop();
	}
}

// �S�Ă̗v�f��j������
void SceneManager::Clear()
{
	for (vector<SceneBace*>::iterator itr = scene.begin(); itr != scene.end(); itr++)
	{
		delete (*itr);
	}
}