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

// 1�����z����󂯎����2�����z��I�ɕ�������
// �f�[�^��CreateObject�ɓn���ăI�u�W�F�N�g�𐶐�����
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

// MapSet���ł����ŌĂ΂��֐�
// ����v���C���̃I�u�W�F�N�g�𐶐�����
void StageBase::CreateObject(int obj_id, int x, int y, int f_x, int f_y)
{
	float s_x = (float)(f_x + (x * MAP_WIDTH));
	float s_y = (float)(f_y - (y * MAP_HEIGHT));
	switch (obj_id)
	{
	case (int)StageBase::MapId::none:
	default:
		// None����ѓK������l�����������ꍇ
		break;

	case (int)StageBase::MapId::tinytim:
		// TinyTim�ƍ��v�����ꍇ
		objects.push_back(unique_ptr<Acter>(new TinyTim(s_x, s_y + 5.f, 0.f)));
		break;

	case (int)StageBase::MapId::stone_floor:
		// StoneFloor�ƍ��v�����ꍇ
		objects.push_back(unique_ptr<Acter>(new StoneFloor(s_x, s_y, 0.f)));
		break;
	}
}