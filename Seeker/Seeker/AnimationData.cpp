#include "AnimationData.h"
#include "DxLib.h"
#include "DxRaps.h"

/*Animation::Animation(int** texture_data,
	int* flame_data,
	bool loop)
{
	for (int i = 0; i < sizeof(flame_data)/sizeof(flame_data[0]); i++)
	{
		tex_data.push_back( { texture_data[i], flame_data[i], 0.5f, 0.5f } );
	}
	flame = 0;
	index = 0;
	is_loop = loop;
}

Animation::Animation(int** texture_data,
	const int flame_data[],
	const float x[],
	const float y[],
	const bool loop,
	const Vector3* pos) : is_loop(loop), owner_pos(pos)
{
	for (int i = 0; i < sizeof(flame_data) / sizeof(flame_data[0]); i++)
	{
		tex_data.push_back({ texture_data[i], flame_data[i], x[i], y[i] });
	}
	flame = 0;
	index = 0;
	is_loop = loop;
}//*/

/*Animation::Animation(Data* data,
	int array_length,
	const bool loop,
	const Vector3* pos) : is_loop(loop), owner_pos(pos)
{
	for (int i = 0; i < array_length; i++)
	{
		tex_data.push_back(data[i]);
	}
	flame = 0;
	index = 0;
}//*/

Animation::Animation(TextureData* _texture_data,
	int _t_length,
	IndexData* _index_data,
	int _i_length,
	bool _loop,
	const Vector3* _pos,
	int _number) : is_loop(_loop), owner_pos(_pos)
{
	for (int i = 0; i < _t_length; i++)
	{
		tex_data.push_back(_texture_data[i]);
	}
	for (int i = 0; i < _i_length; i++)
	{
		index_data.push_back(_index_data[i]);
	}
	flame = 0;
	index = 0;
	number = _number;
	end_flag = false;
}

void Animation::Update()
{
	// 超過しないように制御しつつflameを加算
	// 最大フレーム量を超えていたらリセット(is_loopが有効な場合)
	if (flame < index_data[index_data.size() - 1].flame)
	{
		flame += 1;
	}
	else
	{
		if (is_loop)flame = 0;
	}
	for (int i = 0; i < index_data.size(); i++)
	{
		// その後判定→描画
		if (flame < index_data[i].flame)
		{
			index = index_data[i].index;
			break;
		}
	}
}

void Animation::Update(int _state)
{
	// 登録されている番号と不一致だった場合
	if (number != _state) { 
		flame = 0;	// フレームをリセットして
		if (!is_loop) end_flag = false;
		return;		// 処理を抜ける
	}
	// 超過しないように制御しつつflameを加算
	// 最大フレーム量を超えていたらリセット(is_loopが有効な場合)
	if (flame < index_data[index_data.size() - 1].flame)
	{
		flame += 1;
	}
	else
	{
		if (is_loop)flame = 0;
		if (!is_loop) end_flag = true;
	}
	for (int i = 0; i < index_data.size(); i++)
	{
		// その後判定→描画
		if (flame < index_data[i].flame)
		{
			index = index_data[i].index;
			break;
		}
	}
}

void Animation::Draw()
{
	//DrawFormatString(0, 15, GetColor(255, 255, 255), "Hey:%7d", flame);
	//DrawFormatString(0, 30, GetColor(255, 255, 255), "Hey:%7d", index);
	DrawBillboard3D(VGetRap(*owner_pos),
		tex_data[index].t_x,
		tex_data[index].t_y,
		30.f,
		0.f,
		*tex_data[index].texture,
		TRUE,
		0);
}

void Animation::Draw(int _turn)
{
	float s_x;
	if (_turn > 0)
	{
		_turn = 0;
		s_x = tex_data[index].t_x;
	} else
	{
		_turn = 1;
		s_x = 1.f - tex_data[index].t_x;
	}

	DrawBillboard3D(VGetRap(*owner_pos),
		s_x,
		tex_data[index].t_y,
		30.f,
		0.f,
		*tex_data[index].texture,
		TRUE,
		_turn);
}