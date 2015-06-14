// �V�[���}�l�[�W���[�N���X
// �V���O���g���p�^�[�����g�p
// �����ɃV�[����o�^(�X�^�b�N)����
// Update() �� scene �ɓo�^���ꂽ�Ō�������X�V����Ȃ��d�l�ɂ��� (GoTo���g���₷�������)
#pragma once
#include <vector>
#include <memory>
#include "SceneBase.h"

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
	SceneManager(){}

public:
	static SceneManager* GetInstance(){ return scene_manager; }

private:
	std::vector<SceneBace*> scene;

public:
	void Update();
	void Draw();

public:
	void Push(SCENE _type);
	void Pop();
	void GoTo(SCENE _type);

	void Finalize();
};