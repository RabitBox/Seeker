#include <memory>
#include "DxLib.h"
#include "ScenePlay.h"
#include "TinyTim.h"
#include "StoneFloor.h"
using namespace std;

ScenePlay::ScenePlay()
{
	stage = new StageDemo();
}

ScenePlay::~ScenePlay()
{
	delete stage;
}

void ScenePlay::Input()
{
	stage->Input();
}

void ScenePlay::Update()
{
	stage->Update();
}

void ScenePlay::Draw()
{
	stage->Draw();
}
