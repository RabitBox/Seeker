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
		DEMO,
		TITLE,
		PLAY,
		POUSE,
		END,
	};

private:
	static SceneManager* scene_manager;
	SceneManager(){ play_flag = true; }
	~SceneManager();

public:
	static SceneManager* GetInstance(){ return scene_manager; }

private:
	vector<SceneBace*> scene;
	bool play_flag;

public:
	static void Create();
	static void Destroy();
	void Update();
	void Draw();

public:
	// �V�[���Ǘ��ɂ܂��֐�
	void B_Push(SCENE _type);
	void B_Pop();
	void B_GoTo(SCENE _type);
	void F_Push(SCENE _type);
	void F_Pop();
	void F_GoTo(SCENE _type);

	// �Q�[�����[�v�̏����ɂ܂��֐�
	void EndCall(){ play_flag = false; }
	bool EndFlag(){ return play_flag; }
};