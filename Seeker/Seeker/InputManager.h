// InputManagerクラス
#pragma once

class InputManager
{
public:
	InputManager();
	virtual ~InputManager();
};

// 方向の入力
enum ArrowInput
{
	NEUTRAL = 0,	// 無
	UP		= 1,	// 上
	DOWN	= 2,	// 下
	LEFT	= 4,	// 左
	RIGHT	= 8,	// 右
};

// ボタンの入力
enum ButtanInput
{
	NONE	= 0,	// 無
	DOWN	= 1,	// 押された瞬間
	STAY	= 2,	// 押されている状態
	UP		= 3,	// 離れた瞬間
};

struct InputData
{
	int Arrow;
	ButtanInput A;
	ButtanInput B;
};