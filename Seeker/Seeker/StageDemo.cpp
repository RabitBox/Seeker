#include "StageDemo.h"
#include "BackForest.h"

// サンプルマップチップデータ
// 最初の4つで2次元配列的に格納するための値と一番左上の初期座標を設定する
// 順番は i,j,x,y つまり、縦, 横, 横, 縦 の順番なので注意する事
int test_map_data[] = {
	5, 24, 0, 80,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	// 80
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	// 60
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, // 40
	0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	// 20
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,	// 0
};

StageDemo::StageDemo()
{
	for (int i = 0; i < 3; i++)
	{
		float x = (float)(left_edge + 40.f + (i * 160.f));
		if (i % 2 == 1)
		{
			objects.push_back(unique_ptr<Acter>(new BackForest(x, 60.f, -10.f, true)));
		}
		else{
			objects.push_back(unique_ptr<Acter>(new BackForest(x, 60.f, -10.f, false)));
		}
	}
	MapSet(test_map_data);
	sort(objects.begin(), objects.end(), [](const unique_ptr<Acter> &left, const unique_ptr<Acter> &right){
		return left->GetId() > right->GetId();
	});
}

StageDemo::~StageDemo()
{
	objects.clear();
}