#include <memory>
#include "DxLib.h"
#include "ScenePlay.h"
#include "TinyTim.h"
#include "StoneFloor.h"
using namespace std;

#define MAP_WIDTH	(20.f)
#define MAP_HEIGHT	(20.f)

#define defY (50.0f)
#define defX (50.0f)

// サンプルマップチップデータ
// 最初の4つで2次元配列的に格納するための値と一番左上の初期座標を設定する
// 順番は i,j,x,y つまり、縦, 横, 横, 縦 の順番なので注意する事
int test_map_data[] = {
	5, 6, 0, 80,
	0, 0, 0, 0, 0, 0,	// 80
	0, 0, 0, 0, 0, 0,	// 60
	0, 0, 0, 0, 0, 0,	// 40
	0, 0, 1, 0, 0, 0,	// 20
	2, 2, 2, 2, 2, 2,	// 0
};//*/

ScenePlay::ScenePlay()
{
	MapSet(test_map_data);
}

ScenePlay::~ScenePlay()
{
	objects.clear();
}

void ScenePlay::Input()
{
	//DrawString(0, 0, "Play : 入力を受け付けました", GetColor(255, 255, 255));
}

void ScenePlay::Update()
{
	//DrawString(0, 15, "Play : 更新しました", GetColor(255, 255, 255));
	SetCameraPositionAndTarget_UpVecY(VGet(defX, defY, -100.f), VGet(defX, defY, 0.f));
}

void ScenePlay::Draw()
{
	//DrawString(0, 30, "Play : 描画しました", GetColor(255, 255, 255));
	for (auto& var : objects)
	{
		var->Draw();
	}
}

// 1次元配列を受け取って2次元配列的に分解する
// データをCreateObjectに渡してオブジェクトを生成する
void ScenePlay::MapSet(int map_array[])
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
			ScenePlay::CreateObject(map[index], x, y, map_array[2], map_array[3]);
		}
	}

	delete[] map;
}

// MapSet内でだけで呼ばれる関数
// 床やプレイヤのオブジェクトを生成する
void ScenePlay::CreateObject(int obj_id, int x, int y, int f_x, int f_y)
{
	float s_x = (float)(f_x + (x * MAP_WIDTH));
	float s_y = (float)(f_y - (y * MAP_HEIGHT));
	switch (obj_id)
	{
	case (int)ScenePlay::MapId::none:
	default:
		// Noneおよび適合する値が無かった場合
		break;

	case (int)ScenePlay::MapId::tinytim:
		// TinyTimと合致した場合
		objects.push_back(unique_ptr<Acter>(new TinyTim(s_x, s_y, 0.f)));
		break;

	case (int)ScenePlay::MapId::stone_floor:
		// StoneFloorと合致した場合
		objects.push_back(unique_ptr<Acter>(new StoneFloor(s_x, s_y, 0.f)));
		break;
	}
}

