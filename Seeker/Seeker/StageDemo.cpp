#include "StageDemo.h"
#include "BackForest.h"

// �T���v���}�b�v�`�b�v�f�[�^
// �ŏ���4��2�����z��I�Ɋi�[���邽�߂̒l�ƈ�ԍ���̏������W��ݒ肷��
// ���Ԃ� i,j,x,y �܂�A�c, ��, ��, �c �̏��ԂȂ̂Œ��ӂ��鎖
int test_map_data[] = {
	5, 24, 0, 80,
	3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,	// 80
	3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,	// 60
	3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, // 40
	3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 3,	// 20
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,	// 0
};

StageDemo::StageDemo()
{
	MapSet(test_map_data);
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
	sort(objects.begin(), objects.end(), [](const unique_ptr<Acter> &left, const unique_ptr<Acter> &right){
		return left->GetId() > right->GetId();
	});
}

StageDemo::~StageDemo()
{
	objects.clear();
}