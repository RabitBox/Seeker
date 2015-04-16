#include <iostream>
#include "DxLib.h"
#include "ScenePlay.h"
#include "TinyTim.h"

ScenePlay::ScenePlay()
{
	//std::cout << "Play : ���������m�ۂ��܂���" << std::endl;
	actives.push_back(new TinyTim());
	active_objects.push_back(std::unique_ptr<Active>(new TinyTim()));
}

ScenePlay::~ScenePlay()
{
	//std::cout << "Play : �m�ۂ�����������������܂���" << std::endl;
}

void ScenePlay::Input()
{
	DrawString(0, 0, "Play : ���͂��󂯕t���܂���", GetColor(255, 255, 255));
	//std::cout << "Play : ���͂��󂯕t���܂���" << std::endl;
}

void ScenePlay::Update()
{
	DrawString(0, 15, "Play : �X�V���܂���", GetColor(255, 255, 255));
	//std::cout << "Play : �X�V���܂���" << std::endl;
}

void ScenePlay::Draw()
{
	DrawString(0, 30, "Play : �`�悵�܂���", GetColor(255, 255, 255));
	//std::cout << "Play : �`�悵�܂���" << std::endl;
	for (auto& var : active_objects)
	{
		var->Draw();
	}
}