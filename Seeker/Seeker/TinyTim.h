// TinyTim�N���X
// �{��i�̎�l��
// ���l�^�͊C�O������ "Markiplier" �̓��悩��
#pragma once
#include "Objects.h"

enum AnimState
{
	Stand,	// ����
	Walk,	// ����
	Run,	// ����
	Jump,	// �W�����v
	Land,	// ���n
	Roll,	// ���[�����O
};

class TinyTim : public Active
{
private:
	AnimState state;

public:
	TinyTim();
	virtual ~TinyTim();

	void Update() override {}
	void Draw() override {}

private:
	void Walk();	// ����
	void Run();		// ����
	void Jump();	// �W�����v
	void Land();	// ���n
	void Roll();	// ���[�����O
};