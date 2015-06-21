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
		DEMO,	// 今回未使用
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
	// シーン管理にまつわる関数
	// 後ろから要素を操作するタイプ
	void B_Push(SCENE _type);
	void B_Pop();
	void B_GoTo(SCENE _type);
	void B_Leave();
	void B_Leave(unsigned int _num);

	// 前から要素を操作するタイプ
	void F_Push(SCENE _type);
	void F_Pop();
	void F_GoTo(SCENE _type);
	void F_Leave();
	void F_Leave(unsigned int _num);

	// 全部
	void Clear();

	// 次のシーンにまつわる関数
	void NextSet(SCENE _type){ next_scene = _type; }
	SCENE Next(){ return next_scene; }

	// ループの処理にまつわる関数
	void EndCall(){ play_flag = false; }
	bool EndFlag(){ return play_flag; }
};