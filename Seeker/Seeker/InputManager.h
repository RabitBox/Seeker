// InputManager�N���X
#pragma once

class InputManager
{
public:
	InputManager();
	virtual ~InputManager();
};

// �����̓���
enum Arrow : int
{
	NEUTRAL = 0,	// ��
	UP		= 1,	// ��
	DOWN	= 2,	// ��
	LEFT	= 4,	// ��
	RIGHT	= 8,	// �E
};

// �{�^���̓���
enum Buttan
{
	NONE	= 0,	// ��
	ON		= 1,	// �����ꂽ�u��
	STAY	= 2,	// ������Ă�����
	OUT		= 3,	// ���ꂽ�u��
};

struct InputData
{
	int Arrow;
	Buttan A;
	Buttan B;
};