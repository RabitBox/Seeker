#include "AnimationData.h"
#include "DxLib.h"
#include "DxRaps.h"

Animation::Animation(int** texture_data,
	int* flame_data,
	bool loop)
{
	for (int i = 0; i < sizeof(flame_data)/sizeof(flame_data[0]); i++)
	{
		tex_data.push_back( { texture_data[i], flame_data[i], 0.5f, 0.5f } );
	}
	flame = 0;
	is_loop = loop;
}

Animation::Animation(int** texture_data,
	const int flame_data[],
	const float x[],
	const float y[],
	const bool loop,
	const Vector3* pos) : owner_pos(pos)
{
	for (int i = 0; i < sizeof(flame_data) / sizeof(flame_data[0]); i++)
	{
		tex_data.push_back({ texture_data[i], flame_data[i], x[i], y[i] });
	}
	flame = 0;
	is_loop = loop;
}

void Animation::Update()
{
	flame++;
	for (int i = 0; i < tex_data.size(); i++)
	{
		// まず最大フレーム量を超えていたらリセット
		if (flame > tex_data[tex_data.size() - 1].flame_data && is_loop)
		{
			flame = 0;
		}
		// その後判定→描画
		if (flame < tex_data[i].flame_data)
		{
			index = i;
			break;
		}
	}
}

void Animation::Draw()
{
	DrawBillboard3D(VGetRap(*owner_pos), tex_data[index].t_x, tex_data[index].t_y, 30.f, 0.f, *tex_data[index].texture, TRUE, 0);
}