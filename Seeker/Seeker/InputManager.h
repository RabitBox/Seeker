// InputManagerクラス
#pragma once

class InputManager
{
public:
	InputManager();
	virtual ~InputManager();
};

// 方向の入力
enum Arrow : int
{
	NEUTRAL = 0,	// 無
	UP		= 1,	// 上
	DOWN	= 2,	// 下
	LEFT	= 4,	// 左
	RIGHT	= 8,	// 右
};

// ボタンの入力
enum Buttan
{
	NONE	= 0,	// 無
	ON		= 1,	// 押された瞬間
	STAY	= 2,	// 押されている状態
	OUT		= 3,	// 離れた瞬間
};

struct InputData
{
	int Arrow;
	Buttan A;
	Buttan B;
};