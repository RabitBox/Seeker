#include "DxLib.h"
#include "ScenePlay.h"
#include "TinyTim.h"
#include "StoneFloor.h"
using namespace std;

ScenePlay::ScenePlay()
{
	stage = unique_ptr<StageBase>(new StageDemo());
}

ScenePlay::~ScenePlay(){}

void ScenePlay::Update()
{
	stage->Update();
}

void ScenePlay::Draw()
{
	stage->Draw();
}
