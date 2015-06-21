// �V�[���}�l�[�W���[�N���X
// �V���O���g���p�^�[�����g�p
// �����ɃV�[����o�^(�X�^�b�N)����
// Update() �� scene �ɓo�^���ꂽ�Ō�������X�V����Ȃ��d�l�ɂ��� (GoTo���g���₷�������)
#pragma once
#include <vector>
#include <memory>
#include "SceneBase.h"
using namespace std;

class SceneManager
{
public:
	enum SCENE{
		DEMO,	// ���񖢎g�p
		TITLE,
		PLAY,
		POUSE,
		END,
		CHANGE,
		FADE,
	};

private:
	static SceneManager* scene_manager;
	SceneManager();
	~SceneManager();

public:
	static SceneManager* GetInstance(){ return scene_manager; }

private:
	vector<SceneBace*> scene;
	SCENE next_scene;
	bool play_flag;

public:
	static void Create();
	static void Destroy();
	void Update();
	void Draw();

public:
	// �V�[���Ǘ��ɂ܂��֐�
	// ��납��v�f�𑀍삷��^�C�v
	void B_Push(SCENE _type);
	void B_Pop();
	void B_GoTo(SCENE _type);
	void B_Leave();
	void B_Leave(unsigned int _num);

	// �O����v�f�𑀍삷��^�C�v
	void F_Push(SCENE _type);
	void F_Pop();
	void F_GoTo(SCENE _type);
	void F_Leave();
	void F_Leave(unsigned int _num);

	// �S��
	void Clear();

	// ���̃V�[���ɂ܂��֐�
	void NextSet(SCENE _type){ next_scene = _type; }
	SCENE Next(){ return next_scene; }

	// ���[�v�̏����ɂ܂��֐�
	void EndCall(){ play_flag = false; }
	bool EndFlag(){ return play_flag; }
};