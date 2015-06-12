// ステージのクラス
// ステージ毎にクラスを作るのは下策かもしれないが
// 管理がしやすいので妥協する
// ステージには床などの物とプレイヤーを保存する
// またステージの端の情報などもここに保存する
#pragma once
#include <vector>
#include <algorithm>
#include "Objects.h"
#include "Camera.h"

class StageBase
{
public:
	enum MapId
	{
		none = 0,
		tinytim = 1,
		stone_floor = 2,
	};

protected:
	vector < unique_ptr<Acter> > objects;
	Camera camera;
	float right_edge, left_edge;

public:
	void Input();
	void Update();
	void Draw();

	//void	LoadMapData();
	void	EdgeSet(float _left, float _right){ left_edge = _left; right_edge = _right; }
	void	BackSet(){}
	void	MapSet(int map_array[]);
	void	CreateObject(int obj_id, int x, int y, int f_x, int f_y);
	float	GetRight(){ return right_edge; }
	float	GetLeft(){ return left_edge; }
};