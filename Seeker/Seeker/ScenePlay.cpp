#include <iostream>
#include "DxLib.h"
#include "ScenePlay.h"
#include "TinyTim.h"

ScenePlay::ScenePlay()
{
	//std::cout << "Play : メモリを確保しました" << std::endl;
	actives.push_back(new TinyTim());
	active_objects.push_back(std::unique_ptr<Active>(new TinyTim()));
}

ScenePlay::~ScenePlay()
{
	//std::cout << "Play : 確保したメモリを解放しました" << std::endl;
}

void ScenePlay::Input()
{
	DrawString(0, 0, "Play : 入力を受け付けました", GetColor(255, 255, 255));
	//std::cout << "Play : 入力を受け付けました" << std::endl;
}

void ScenePlay::Update()
{
	DrawString(0, 15, "Play : 更新しました", GetColor(255, 255, 255));
	//std::cout << "Play : 更新しました" << std::endl;
}

void ScenePlay::Draw()
{
	DrawString(0, 30, "Play : 描画しました", GetColor(255, 255, 255));
	//std::cout << "Play : 描画しました" << std::endl;
	for (auto& var : active_objects)
	{
		var->Draw();
	}
}