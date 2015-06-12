//----------------------------------------------------------------------
// TinyTimクラス
// 本作品の主人公
// 元ネタは海外実況者 "Markiplier" の動画から
//----------------------------------------------------------------------
#pragma once
#include "Objects.h"
#include "AnimationData.h"
#include "InputManager.h"
#include "Command.h"

#define TimTexNum 37

class TinyTim : public Acter
{
private:
	enum State : int
	{
		Stand,	// 立ち
		Walk,	// 歩き
		Run,	// 走り
		Jump,	// ジャンプ
		Land,	// 着地
		All,
	};
	enum Look : int
	{
		RIGHT	= 1,
		LEFT	= -1,

	};

	struct  AnimState
	{
		State	now_state;
		State*	next_state = nullptr;
	};

	State					state;
	State					next_state;
	vector<int*>			images;
	AnimState				anim_state[(int)State::All];
	vector<Animation>		anim_data;
	Look					look;
	Vector3					vly;
	Command					command;

public:
	TinyTim(){}
	TinyTim(float x, float y);
	TinyTim(float x, float y, float z);
	TinyTim(Vector3 _positon);
	virtual ~TinyTim(){}

	void Input() override;
	void Update() override;
	void Draw() override;

private:
	//void Walk();	// 歩く
	//void Run();	// 走る
	//void Jump();	// ジャンプ
	//void Land();	// 着地
	//void Roll();	// ローリング

private:
	void LoadTexture() override;
	void CommandSet();
	void AnimationSet();
	void AnimStateSet();
	void Default();

private:
	// アニメーション系
	void StandAnimSet();
	void WalkAnimSet();
	void RunAnimSet();
	void JumpAnimSet();
	void LandAnimSet();
};