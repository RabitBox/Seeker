#include "StageBase.h"
#include "TinyTim.h"
#include "StoneFloor.h"

#define MAP_WIDTH	(20.f)
#define MAP_HEIGHT	(20.f)

void StageBase::Update()
{
	for (auto& var : objects)
	{
		var->Update();
		if (var->GetId() == Acter::ObjID::Player)
		{
			camera.Target(var->GetPos());
		}
	}
}

void StageBase::Draw()
{
	for (auto& var : objects)
	{
		var->Draw();
	}
}

// 1次元配列を受け取って2次元配列的に分解する
// データをCreateObjectに渡してオブジェクトを生成する
void StageBase::MapSet(int map_array[])
{
	int* map = new int[map_array[0] * map_array[1]];
	for (int i = 0; i < map_array[0] * map_array[1]; i++)
	{
		map[i] = map_array[i + 4];
	}

	for (int y = 0; y < map_array[0]; y++)
	{
		for (int x = 0; x < map_array[1]; x++)
		{
			int index = x + y * map_array[1];
			CreateObject(map[index], x, y, map_array[2], map_array[3]);
		}
	}

	EdgeSet((float)(0.f), (float)((map_array[1] - 2) * MAP_WIDTH));

	camera = Camera(right_edge, left_edge);

	delete[] map;
}

// MapSet内でだけで呼ばれる関数
// 床やプレイヤのオブジェクトを生成する
void StageBase::CreateObject(int obj_id, int x, int y, int f_x, int f_y)
{
	float s_x = (float)(f_x + (x * MAP_WIDTH));
	float s_y = (float)(f_y - (y * MAP_HEIGHT));
	switch (obj_id)
	{
	case (int)StageBase::MapId::none:
	default:
		// Noneおよび適合する値が無かった場合
		break;

	case (int)StageBase::MapId::tinytim:
		// TinyTimと合致した場合
		objects.push_back(unique_ptr<Acter>(new TinyTim(s_x, s_y + 5.f, 0.f)));
		break;

	case (int)StageBase::MapId::stone_floor:
		// StoneFloorと合致した場合
		objects.push_back(unique_ptr<Acter>(new StoneFloor(s_x, s_y, 0.f)));
		break;
	}
}