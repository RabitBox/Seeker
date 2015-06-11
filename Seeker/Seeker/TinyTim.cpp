#include <stdio.h>
#include "DxLib.h"
#include "DxRaps.h"
#include "TinyTim.h"
#include "TextureManager.h"

TinyTim::TinyTim(){}

TinyTim::TinyTim(float x, float y)
{
	this->transform.position = { x, y - 10.f, 0.f };
	LoadTexture();
	AnimationSet();
}

TinyTim::TinyTim(float x, float y, float z)
{
	this->transform.position = { x, y - 10.f, z };
	LoadTexture();
	AnimationSet();
}

TinyTim::TinyTim(Vector3 _position)
{
	this->transform.position = _position;
	LoadTexture();
	AnimationSet();
}

TinyTim::~TinyTim(){}

void TinyTim::Update()
{
	anim.Update();
}

void TinyTim::Draw()
{
	//DrawFormatString(0, 150, GetColor(255, 255, 255), "Hey:%d", TextureManager::GetInstance()->GetSize());
	anim.Draw();
}

/*void TinyTim::Draw()
{
	switch (state)
	{
	default:
	case State::Stand:	// 立ち、および他の状態に当てはまらなかった場合

		break;
		
	case State::Walk:	// 歩き

		break;

	case State::Run:	// 走り

		break;

	case State::Jump:	// ジャンプ

		break;

	case State::Land:	// 着地

		break;

	case State::Roll:	// ローリング

		break;
	}
}//*/

void TinyTim::LoadTexture()
{
	int dem_load[TimTexNum];
	LoadDivGraph("Texture/Player.png", 37, 8, 5, 256, 256, dem_load);
	char name[20] = "";
	for (int i = 0; i < TimTexNum; i++)
	{
		sprintf_s(name, 20, "TinyTim_%d", (i + 1));
		images.push_back(TextureManager::GetInstance()->LoadTexture(name, dem_load[i]));
	}
}

void TinyTim::AnimationSet()
{
	Animation::TextureData t_dat[] = {
		{ images[0], 0.5f, 0.f },
		{ images[1], 0.5f, 0.f },
		{ images[2], 0.5f, 0.f },
		{ images[3], 0.5f, 0.f },
		{ images[4], 0.5f, 0.f },
		{ images[5], 0.5f, 0.f },
	};
	Animation::IndexData i_dat[] = {
		{ 0, 10 }, { 1, 20 }, { 2, 30 }, { 3, 40 }, { 4, 50 }, { 5, 60 },
		{ 4, 70 }, { 3, 80 }, { 2, 90 }, { 1, 100 }, { 0, 110 },
	};
	anim = Animation(t_dat, ArrayLength(t_dat), i_dat, ArrayLength(i_dat), true, &transform.position);
}

void TinyTim::AnimStateSet()
{
	anim_state[State::Stand].next_state = new State[3];
	anim_state[State::Stand].now_state = State::Stand;
	anim_state[State::Stand].next_state[0] = State::Walk;
	anim_state[State::Stand].next_state[1] = State::Run;
	anim_state[State::Stand].next_state[2] = State::Jump;

	anim_state[State::Walk].next_state = new State[3];
	anim_state[State::Walk].now_state = State::Walk;
	anim_state[State::Walk].next_state[0] = State::Stand;
	anim_state[State::Walk].next_state[1] = State::Run;
	anim_state[State::Walk].next_state[2] = State::Jump;

	anim_state[State::Run].next_state = new State[3];
	anim_state[State::Run].now_state = State::Run;
	anim_state[State::Run].next_state[0] = State::Stand;
	anim_state[State::Run].next_state[1] = State::Walk;
	anim_state[State::Run].next_state[2] = State::Jump;

	anim_state[State::Jump].next_state = new State[1];
	anim_state[State::Jump].now_state = State::Jump;
	anim_state[State::Jump].next_state[0] = State::Land;

	anim_state[State::Land].next_state = new State[3];
	anim_state[State::Land].now_state = State::Land;
	anim_state[State::Land].next_state[0] = State::Stand;
	anim_state[State::Land].next_state[1] = State::Walk;
	anim_state[State::Land].next_state[2] = State::Run;
}

void TinyTim::Default()
{
	this->id = ObjID::Player;
	state = State::Stand;
	this->transform.scale = { 20.f, 20.f, 0.1f };
	this->transform.rotation = { 0.f, 0.f, 0.f };
}