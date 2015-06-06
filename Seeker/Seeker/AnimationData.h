// アニメーション
#pragma once
#include <vector>
#include "Generic.h"
using namespace std;

class Animation
{
public:
	struct Data
	{
		int*		texture;	// テクスチャデータへのポインタ
		int			flame_data;	// 画像を描画するフレームの最大値
		int			t_x;		// 中心座標(X)
		int			t_y;		// 中心座標(Y)
	};

protected:
	vector<Data>	tex_data;	// テクスチャーデータを参照(ポインタ)
	int				flame;		// フレームデータ
	int				index;		// 描画を行うデータの添え字
	bool			is_loop;	// ループするアニメーションか否か
	const Vector3*	owner_pos;	// 所有者のポジションデータ

public:
	Animation(){}
	Animation(int** texture_data, int* flame_data, bool loop);
	Animation(int** texture_data, const int flame_data[], const float x[], const float y[], const bool loop, const Vector3* pos);
	~Animation(){}

public:
	void Update();
	void Draw();
};

//Animation::Data d;