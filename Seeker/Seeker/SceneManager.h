// シーンマネージャークラス
// シングルトンパターンを使用
// ここにシーンを登録(スタック)する
// Update() は scene に登録された最後尾しか更新されない仕様にする (GoToを使いやすくする為)
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