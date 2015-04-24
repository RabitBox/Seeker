#include <iostream>
#include "DxLib.h"
#include "ScenePlay.h"
#include "TinyTim.h"
using namespace std;

ScenePlay::ScenePlay()
{
	//std::cout << "Play : メモリを確保しました" << std::endl;
	active_objects.push_back(unique_ptr<Active>(new TinyTim()));
}

ScenePlay::~ScenePlay()
{

}

void ScenePlay::Input()
{
	DrawString(0, 0, "Play : 入力を受け付けました", GetColor(255, 255, 255));
}

void ScenePlay::Update()
{
	DrawString(0, 15, "Play : 更新しました", GetColor(255, 255, 255));
}

void ScenePlay::Draw()
{
	DrawString(0, 30, "Play : 描画しました", GetColor(255, 255, 255));
	for (auto& var : active_objects)
	{
		var->Draw();
	}
}