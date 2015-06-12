//----------------------------------------------------------------------
// TinyTim�N���X
// �{��i�̎�l��
// ���l�^�͊C�O������ "Markiplier" �̓��悩��
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
		Stand,	// ����
		Walk,	// ����
		Run,	// ����
		Jump,	// �W�����v
		Land,	// ���n
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
	//void Walk();	// ����
	//void Run();	// ����
	//void Jump();	// �W�����v
	//void Land();	// ���n
	//void Roll();	// ���[�����O

private:
	void LoadTexture() override;
	void CommandSet();
	void AnimationSet();
	void AnimStateSet();
	void Default();

private:
	// �A�j���[�V�����n
	void StandAnimSet();
	void WalkAnimSet();
	void RunAnimSet();
	void JumpAnimSet();
	void LandAnimSet();
};