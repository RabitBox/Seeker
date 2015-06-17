// シーンマネージャークラス
// シングルトンパターンを使用
// ここにシーンを登録(スタック)する
// Update() は scene に登録された最後尾しか更新されない仕様にする (GoToを使いやすくする為)
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
	// シーン管理にまつわる関数
	void B_Push(SCENE _type);
	void B_Pop();
	void B_GoTo(SCENE _type);
	void F_Push(SCENE _type);
	void F_Pop();
	void F_GoTo(SCENE _type);

	// ゲームループの処理にまつわる関数
	void EndCall(){ play_flag = false; }
	bool EndFlag(){ return play_flag; }
};