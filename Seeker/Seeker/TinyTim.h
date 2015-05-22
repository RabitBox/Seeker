//----------------------------------------------------------------------
// TinyTim�N���X
// �{��i�̎�l��
// ���l�^�͊C�O������ "Markiplier" �̓��悩��
//----------------------------------------------------------------------
#pragma once
#include "Objects.h"


class TinyTim : public Acter
{
private:
	enum AnimState
	{
		Stand,	// ����
		Walk,	// ����
		Run,	// ����
		Jump,	// �W�����v
		Land,	// ���n
		Roll,	// ���[�����O
	};

	AnimState state;
	//vector<int> &images;
	

public:
	TinyTim();
	TinyTim(Vector3 _positon);
	virtual ~TinyTim();

	void Update() override;
	void Draw() override;

private:
	//void Walk();	// ����
	//void Run();		// ����
	//void Jump();	// �W�����v
	//void Land();	// ���n
	//void Roll();	// ���[�����O

	void DrawPolygon();

private:
	void LoadTexture() override;
};