#include <iostream>
#include "DxLib.h"
#include "ScenePlay.h"
#include "TinyTim.h"
#include "StoneFloor.h"
using namespace std;

ScenePlay::ScenePlay()
{
	//active_objects.push_back(unique_ptr<Acter>(new TinyTim()));
	//Vector3 *hoge = new Vector3(1.0f, 1.0f);
	active_objects.push_back(unique_ptr<Acter>(new StoneFloor({ 1.f, 1.f, 0.f })));
	//Acter *ac = new StoneFloor(1.f,1.f,0.f);
}

ScenePlay::~ScenePlay()
{
	/*for (auto& var : active_objects)
	{
		//delete var;
	}//*/
}

void ScenePlay::Input()
{
	DrawString(0, 0, "Play : “ü—Í‚ðŽó‚¯•t‚¯‚Ü‚µ‚½", GetColor(255, 255, 255));
}

void ScenePlay::Update()
{
	DrawString(0, 15, "Play : XV‚µ‚Ü‚µ‚½", GetColor(255, 255, 255));
	SetCameraPositionAndTarget_UpVecY(VGet(0.f, 0.f, -100.f), VGet(0.f, 0.f, 0.f));
}

void ScenePlay::Draw()
{
	DrawString(0, 30, "Play : •`‰æ‚µ‚Ü‚µ‚½", GetColor(255, 255, 255));
	for (auto& var : active_objects)
	{
		var->Draw();
	}
}