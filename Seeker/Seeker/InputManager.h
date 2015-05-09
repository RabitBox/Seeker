// InputManager�N���X
#pragma once

class InputManager
{
public:
	InputManager();
	virtual ~InputManager();
};

// �����̓���
enum ArrowInput
{
	NEUTRAL = 0,	// ��
	UP		= 1,	// ��
	DOWN	= 2,	// ��
	LEFT	= 4,	// ��
	RIGHT	= 8,	// �E
};

// �{�^���̓���
enum ButtanInput
{
	NONE	= 0,	// ��
	DOWN	= 1,	// �����ꂽ�u��
	STAY	= 2,	// ������Ă�����
	UP		= 3,	// ���ꂽ�u��
};

struct InputData
{
	int Arrow;
	ButtanInput A;
	ButtanInput B;
};