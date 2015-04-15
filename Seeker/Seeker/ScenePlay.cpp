#include <iostream>
#include "DxLib.h"
#include "ScenePlay.h"

ScenePlay::ScenePlay()
{
	//std::cout << "Play : メモリを確保しました" << std::endl;
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
}