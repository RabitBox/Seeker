#include "SceneManager.h"
using namespace std;

// シーンのヘッダ
#include "SceneTitle.h"
#include "ScenePlay.h"
#include "ScenePouse.h"
#include "SceneEnd.h"
#include "SceneChange.h"
#include "SceneFade.h"

// 実態宣言 (どこかで Create() を呼ばないとnullptr のまま)
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
		scene.clear();	// 要素を全て破棄
	}
}

// 使用開始時に呼ぶ (コンストラクタ)
void SceneManager::Create()
{
	scene_manager = new SceneManager();
}

// 使用終了時に呼ぶ (デストラクタ)
void SceneManager::Destroy()
{
	delete scene_manager;
	scene_manager = nullptr;
}

// scene の最終要素に登録されたシーンクラスの Update を呼ぶ
void SceneManager::Update()
{
	if (!scene.empty()){
		vector<SceneBace*>::iterator itr = --scene.end();
		(*itr)->Update();
	}	
}

// scene に登録されたシーンクラスの Draw を呼ぶ
void SceneManager::Draw()
{
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

// 最後の要素以外を破棄する
void SceneManager::B_Leave()
{
	while (scene.size()>1)
	{
		F_Pop();
	}
}

// 引数で指定した数の要素を後ろから残して破棄する
void SceneManager::B_Leave(unsigned int _num)
{
	while (scene.size()>_num)
	{
		F_Pop();
	}
}

// 前から要素を入れる
void SceneManager::F_Push(SCENE _type)
{
	// 最初の要素を指すイテレータをつくる
	vector<SceneBace*>::iterator itr = scene.begin();

	// イテレータの指す要素の前に新たな要素をねじ込む
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

// 最初の要素以外を破棄する
void SceneManager::F_Leave()
{
	while (scene.size()>1)
	{
		B_Pop();
	}
}

// 引数で指定した数の要素を前から残して破棄する
void SceneManager::F_Leave(unsigned int _num)
{
	while (scene.size()>_num)
	{
		B_Pop();
	}
}

// 全ての要素を破棄する
void SceneManager::Clear()
{
	for (vector<SceneBace*>::iterator itr = scene.begin(); itr != scene.end(); itr++)
	{
		delete (*itr);
	}
}