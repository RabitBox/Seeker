// InputManager�N���X
#pragma once

class InputManager
{
private:
	InputManager();
	static InputManager* input_manager;

public:
	static InputManager* GetInstance(){ return input_manager; }
	static void Create();
	static void Destroy();

public:
	struct Arrow
	{
		bool up;
		bool down;
		bool left;
		bool right;
	};
	enum Buttan
	{
		None = 0,	// ��
		On = 1,		// �����ꂽ�u��
		Stay = 2,	// ������Ă�����
		Out = 4,	// ���ꂽ�u��
	};
	struct ButtanInput
	{
		Buttan	now_input;
		Buttan	back_input;
	};
	struct X_Y
	{
		int x;
		int y;
	};

private:
	Arrow		arrow;
	ButtanInput	a;
	ButtanInput	b;

public:
	void	Input();
	Arrow	GetArrowInput(){ return arrow; }
	Buttan	GetButtanInputA(){ return a.now_input; }
	Buttan	GetButtanInputB(){ return b.now_input; }
	X_Y		GetAxis();
};