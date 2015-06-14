#include "SceneManager.h"
using namespace std;

// シーンのヘッダ
#include "SceneDemo.h"
#include "SceneTitle.h"
#include "ScenePlay.h"
#include "ScenePouse.h"
#include "SceneEnd.h"

//--------------------------------------------------
// 実態宣言
//--------------------------------------------------
SceneManager* SceneManager::scene_manager = new SceneManager();

// 
void SceneManager::Push(SCENE _type)
{
	switch (_type)
	{
	case SceneManager::DEMO:
		scene.push_back(new SceneDemo());
		break;
	
	case SceneManager::TITLE:
		scene.push_back(new SceneTitle());
		break;
	
	case SceneManager::PLAY:
		scene.push_back(new ScenePlay());
		break;
	
	case SceneManager::POUSE:
		scene.push_back(new ScenePouse());
		break;
	
	case SceneManager::END:
		scene.push_back(new SceneEnd());
		break;
	}
}

// scene の最終要素に登録されたシーンクラスの Update を呼ぶ
void SceneManager::Update()
{
	scene[scene.size() - 1]->Update();
}

void SceneManager::Draw()
{
	for (auto &var : scene)
	{
		var->Draw();
	}
}

// scene の最終要素を解放する
void SceneManager::Pop()
{
	delete scene[scene.size() - 1];	// 最後の要素のポインタ(で確保されたメモリ)を解放して
	scene.pop_back();				// 配列内から削除する
}

// 最終要素を破棄して他の要素を入れる
void SceneManager::GoTo(SCENE _type)
{
	this->Pop();
	this->Push(_type);
}

// 要素を全て解放する
// これを最後に呼ばないとメモリリークを起こす可能性
void SceneManager::Finalize()
{
	for (auto &var : scene)
	{
		delete var;	// 確保したメモリを解放
	}
	scene.clear();	// 要素を全て破棄
}