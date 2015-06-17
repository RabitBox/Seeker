#include "SceneManager.h"
using namespace std;

// シーンのヘッダ
#include "SceneDemo.h"
#include "SceneTitle.h"
#include "ScenePlay.h"
#include "ScenePouse.h"
#include "SceneEnd.h"

#include "DxLib.h"

//--------------------------------------------------
// 実態宣言
//--------------------------------------------------
SceneManager* SceneManager::scene_manager = nullptr;//new SceneManager();

SceneManager::~SceneManager()
{
	if (!scene.empty()){
		for (auto &var : scene){ delete var; }
		scene.clear();	// 要素を全て破棄
	}
}

// 使用開始時に呼ぶ
void SceneManager::Create()
{
	scene_manager = new SceneManager();
}

// 使用終了時に呼ぶ
void SceneManager::Destroy()
{
	delete scene_manager;
	scene_manager = nullptr;
}

// scene の最終要素に登録されたシーンクラスの Update を呼ぶ
void SceneManager::Update()
{
	DrawFormatString(0,60,GetColor(255,255,255),"更新しました");
	if (!scene.empty()){
		vector<SceneBace*>::iterator itr = --scene.end();
		(*itr)->Update();
	}	
}

void SceneManager::Draw()
{
	DrawFormatString(0, 75, GetColor(255, 255, 255), "描画しました");
	if (!scene.empty()){
		for (auto &var : scene)
		{
			var->Draw();
		}
	}
}

// 後ろから要素を入れる
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

// 後ろから要素を破棄する
void SceneManager::B_Pop()
{
	if (!scene.empty()){

		vector<SceneBace*>::iterator itr = --scene.end();
		delete (*itr);

		// 配列内から削除する
		scene.pop_back();
	}
}

// B_PopしたあとB_Pushする
void SceneManager::B_GoTo(SCENE _type)
{
	this->B_Pop();
	this->B_Push(_type);
}

// 前から要素を入れる
void SceneManager::F_Push(SCENE _type)
{
	// 最初の要素を指すイテレータをつくる
	vector<SceneBace*>::iterator itr = scene.begin();

	// イテレータの指す要素の前に新たな要素をねじ込む
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

// 前から要素を破棄する
void SceneManager::F_Pop()
{
	if (!scene.empty()){
		// 最初の要素を指すイテレータをつくる
		vector<SceneBace*>::iterator itr = scene.begin();

		delete (*itr);

		// 最初の要素は破棄
		scene.erase(itr);
	}
}

// F_PopしたあとF_Pushする
void SceneManager::F_GoTo(SCENE _type)
{
	F_Pop();
	F_Push(_type);
}