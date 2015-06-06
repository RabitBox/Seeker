//----------------------------------------------------------------------
// TinyTim�N���X
// �{��i�̎�l��
// ���l�^�͊C�O������ "Markiplier" �̓��悩��
//----------------------------------------------------------------------
#pragma once
#include "Objects.h"
#include "AnimationData.h"

class TinyTim : public Acter
{
private:
	enum State
	{
		Stand,	// ����
		Walk,	// ����
		Run,	// ����
		Jump,	// �W�����v
		Land,	// ���n
		Roll,	// ���[�����O
	};

	int						test_loaded[37];
	State					state;
	vector<int*>			images;
	vector<Animation>	anim_data;
	

public:
	TinyTim();
	TinyTim(float x, float y);
	TinyTim(float x, float y, float z);
	TinyTim(Vector3 _positon);
	virtual ~TinyTim();

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
	void AnimationSet();
	void Default();
};