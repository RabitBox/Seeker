#include <stdio.h>
#include "DxLib.h"
#include "DxRaps.h"
#include "TinyTim.h"
#include "TextureManager.h"

#define UNDER	0.3f
#define WALK_SPEED	0.6f
#define RUN_SPEED	1.2f
const Vector3 GRAVITY = {0.f, -0.98f, 0.f};

TinyTim::TinyTim(float x, float y)
{
	this->transform.position = { x, y - 10.f, 0.f };
	Default();
}

TinyTim::TinyTim(float x, float y, float z)
{
	this->transform.position = { x, y - 10.f, z };
	Default();
}

TinyTim::TinyTim(Vector3 _position)
{
	this->transform.position = _position;
	Default();
}

void TinyTim::Input()
{
	int i = command.Input(InputManager::GetInstance()->GetArrowInput().up,
		InputManager::GetInstance()->GetArrowInput().down,
		InputManager::GetInstance()->GetArrowInput().left,
		InputManager::GetInstance()->GetArrowInput().right);
}

void TinyTim::Update()
{
	state = next_state;
	int check = command.Check();
	if (InputManager::GetInstance()->GetArrowInput().right && !InputManager::GetInstance()->GetArrowInput().left)	{
		look = Look::RIGHT;
	} else if (!InputManager::GetInstance()->GetArrowInput().right && InputManager::GetInstance()->GetArrowInput().left){
		look = Look::LEFT;
	} else {}

	InputManager::X_Y axis = InputManager::GetInstance()->GetAxis();

	// SameUpdate
	switch (state)
	{
	default:
	case State::Stand:	// 立ち、および他の状態に当てはまらなかった場合
		vly = { 0.f, 0.f, 0.f };
		if (InputManager::GetInstance()->GetArrowInput().right && !InputManager::GetInstance()->GetArrowInput().left
			|| !InputManager::GetInstance()->GetArrowInput().right && InputManager::GetInstance()->GetArrowInput().left) next_state = State::Walk;
		if (check >= 0) next_state = State::Run;
		//if (axis.y > 0) next_state = State::Jump;
		break;

	case State::Walk:	// 歩き
		vly = { axis.x * WALK_SPEED, 0.f, 0.f };
		if (InputManager::GetInstance()->GetArrowInput().right && InputManager::GetInstance()->GetArrowInput().left ||
			!InputManager::GetInstance()->GetArrowInput().right && !InputManager::GetInstance()->GetArrowInput().left)
		{
			next_state = State::Stand;
		}
		if (check >= 0) state = State::Run;
		//if (axis.y > 0) next_state = State::Jump;
		break;

	case State::Run:	// 走り
		vly = { axis.x * RUN_SPEED, 0.f, 0.f };
		if (InputManager::GetInstance()->GetArrowInput().right && InputManager::GetInstance()->GetArrowInput().left ||
			!InputManager::GetInstance()->GetArrowInput().right && !InputManager::GetInstance()->GetArrowInput().left)
		{
			next_state = State::Stand;
		}
		//if (axis.y > 0) next_state = State::Jump;
		break;

	/*case State::Jump:	// ジャンプ
		if (state != next_state) vly += {0.f, 5.f, 0.f};
		if (!anim_data[State::Land].GetEndFlag());
		break;

	case State::Land:	// 着地
		vly = { 0.f, 0.f, 0.f };
		if (anim_data[State::Land].GetEndFlag()) state = anim_state[State::Land].next_state[0];
		break;//*/
	}
	transform.position += (vly += GRAVITY);
	if (transform.position.y < 15.f){ transform.position.y = 15.f; }

	// AnimUpdate
	for (auto& var : anim_data){ var.Update(state); }
	/*switch (state)
	{
	default:
	case State::Stand:	// 立ち、および他の状態に当てはまらなかった場合
		for (auto& var : anim_data){ var.Update(State::Stand); }
		//anim_data[State::Stand].Update();
		break;

	case State::Walk:	// 歩き
		for (auto& var : anim_data){ var.Update(State::Walk); }
		//anim_data[State::Walk].Update();
		break;

	case State::Run:	// 走り
		for (auto& var : anim_data){ var.Update(State::Run); }
		//anim_data[State::Run].Update();
		break;

	case State::Jump:	// ジャンプ
		for (auto& var : anim_data){ var.Update(State::Jump); }
		//anim_data[State::Jump].Update();
		break;

	case State::Land:	// 着地
		for (auto& var : anim_data){ var.Update(State::Land); }
		//anim_data[State::Land].Update();
		break;
	}*/
}

void TinyTim::Draw()
{
	switch (state)
	{
	default:
	case State::Stand:	// 立ち、および他の状態に当てはまらなかった場合
		anim_data[State::Stand].Draw(look);
		break;
		
	case State::Walk:	// 歩き
		anim_data[State::Walk].Draw(look);
		break;

	case State::Run:	// 走り
		anim_data[State::Run].Draw(look);
		break;

	case State::Jump:	// ジャンプ
		anim_data[State::Jump].Draw(look);
		break;

	case State::Land:	// 着地
		anim_data[State::Land].Draw(look);
		break;
	}
}

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

void TinyTim::CommandSet()
{
	command = Command(2);
	int arr1[] = { Command::Direction::NONE, Command::Direction::RIGHT, Command::Direction::NONE, Command::Direction::RIGHT };
	command.Set(0, 4, 20, arr1);
	int arr2[] = { Command::Direction::NONE, Command::Direction::LEFT, Command::Direction::NONE, Command::Direction::LEFT };
	command.Set(1, 4, 20, arr2);
}

void TinyTim::AnimationSet()
{
	StandAnimSet();
	WalkAnimSet();
	RunAnimSet();
	JumpAnimSet();
	LandAnimSet();
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
	next_state = State::Stand;
	this->transform.scale = { 20.f, 20.f, 0.1f };
	this->transform.rotation = { 0.f, 0.f, 0.f };
	look = Look::RIGHT;
	vly = { 0.f, 0.f, 0.f };
	LoadTexture();
	AnimationSet();
	AnimStateSet();
	CommandSet();
}

void TinyTim::StandAnimSet()
{
	Animation::TextureData t_dat[] = {
		{ images[0], 0.5f, UNDER },
		{ images[1], 0.5f, UNDER },
		{ images[2], 0.5f, UNDER },
		{ images[3], 0.5f, UNDER },
		{ images[4], 0.5f, UNDER },
		{ images[5], 0.5f, UNDER },
	};
	Animation::IndexData i_dat[] = {
		{ 0, 10 }, { 1, 20 }, { 2, 30 }, { 3, 40 }, { 4, 50 }, { 5, 60 },
		{ 4, 70 }, { 3, 80 }, { 2, 90 }, { 1, 100 }, { 0, 110 },
	};
	anim_data.push_back(Animation(t_dat, ArrayLength(t_dat), i_dat, ArrayLength(i_dat), true, &transform.position, State::Stand));
}
void TinyTim::WalkAnimSet()
{
	Animation::TextureData t_dat[] = {
		{ images[6], 0.5f, UNDER },
		{ images[7], 0.5f, UNDER },
		{ images[8], 0.5f, UNDER },
		{ images[9], 0.5f, UNDER },
		{ images[10], 0.5f, UNDER },
		{ images[11], 0.5f, UNDER },
		{ images[12], 0.5f, UNDER },
		{ images[13], 0.5f, UNDER },
	};
	Animation::IndexData i_dat[] = {
		{ 0, 7 }, { 1, 14 }, { 2, 21 }, { 3, 28 }, { 4, 35 }, { 5, 41 },
		{ 6, 48 }, { 7, 55 },
	};
	anim_data.push_back(Animation(t_dat, ArrayLength(t_dat), i_dat, ArrayLength(i_dat), true, &transform.position, State::Walk));
}
void TinyTim::RunAnimSet()
{
	Animation::TextureData t_dat[] = {
		{ images[14], 0.5f, UNDER },
		{ images[15], 0.5f, UNDER },
		{ images[16], 0.5f, UNDER },
		{ images[17], 0.5f, UNDER },
		{ images[18], 0.5f, UNDER },
		{ images[19], 0.5f, UNDER },
		{ images[20], 0.5f, UNDER },
		{ images[21], 0.5f, UNDER },
		{ images[22], 0.5f, UNDER },
		{ images[23], 0.5f, UNDER },
	};
	Animation::IndexData i_dat[] = {
		{ 0, 7 }, { 1, 14 }, { 2, 21 }, { 3, 28 }, { 4, 35 }, { 5, 41 },
		{ 6, 48 }, { 7, 55 }, { 8, 62 }, { 9, 69 },
	};
	anim_data.push_back(Animation(t_dat, ArrayLength(t_dat), i_dat, ArrayLength(i_dat), true, &transform.position, State::Run));
}
void TinyTim::JumpAnimSet()
{
	Animation::TextureData t_dat[] = {
		{ images[24], 0.5f, UNDER },
		{ images[25], 0.5f, UNDER },
		{ images[26], 0.5f, UNDER },
		{ images[27], 0.5f, UNDER },
		{ images[28], 0.5f, UNDER },
		{ images[29], 0.5f, UNDER },
		{ images[30], 0.5f, UNDER },
		{ images[31], 0.5f, UNDER },
		{ images[32], 0.5f, UNDER },
		{ images[33], 0.5f, UNDER },
	};
	Animation::IndexData i_dat[] = {
		{ 0, 4 }, { 1, 8 }, { 2, 12 }, { 3, 19 }, { 4, 28 }, { 5, 35 },
		{ 6, 42 }, { 7, 49 }, { 8, 56 }, { 9, 63 },
	};
	anim_data.push_back(Animation(t_dat, ArrayLength(t_dat), i_dat, ArrayLength(i_dat), false, &transform.position, State::Jump));
}
void TinyTim::LandAnimSet()
{
	Animation::TextureData t_dat[] = {
		{ images[34], 0.5f, UNDER },
		{ images[35], 0.5f, UNDER },
		{ images[36], 0.5f, UNDER },
	};
	Animation::IndexData i_dat[] = {
		{ 0, 8 }, { 1, 16 }, { 2, 24 },
	};
	anim_data.push_back(Animation(t_dat, ArrayLength(t_dat), i_dat, ArrayLength(i_dat), false, &transform.position, State::Land));
}