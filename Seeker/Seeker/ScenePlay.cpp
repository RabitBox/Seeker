#include <iostream>
#include "DxLib.h"
#include "ScenePlay.h"

ScenePlay::ScenePlay()
{
	//std::cout << "Play : ���������m�ۂ��܂���" << std::endl;
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
}