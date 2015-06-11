// アニメーション
#pragma once
#include <vector>
#include "Generic.h"
using namespace std;

class Animation
{
public:
	struct TextureData
	{
		int*		texture;	// テクスチャデータへのポインタ
		float		t_x;		// 中心座標(X)
		float		t_y;		// 中心座標(Y)
	};
	struct IndexData
	{
		int			index;		// 呼び出す画像のインデックス
		int			flame;		// 画像を描画するフレームの最大値
	};

protected:
	vector<TextureData>	tex_data;	// テクスチャーデータを参照
	vector<IndexData>	index_data;	// インデックス
	int					flame;		// フレームデータ
	int					index;		// 描画を行うデータの添え字
	bool				is_loop;	// ループするアニメーションか否か
	const Vector3*		owner_pos;	// 所有者のポジションデータ

public:
	Animation(){}
	//Animation(int** texture_data, int* flame_data, bool loop);
	//Animation(int** texture_data, const int flame_data[], const float x[], const float y[], const bool loop, const Vector3* pos);
	//Animation(Data* data, int array_length, const bool loop, const Vector3* pos);
	Animation(TextureData* _texture_data, int _t_length, IndexData* _index_data, int _i_length, bool _loop, const Vector3* _pos);
	~Animation(){}

public:
	void Update();
	void Draw();
	void Draw(int _turn);
};