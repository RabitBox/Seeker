// �A�j���[�V����
#pragma once
#include <vector>
#include "Generic.h"
using namespace std;

class Animation
{
public:
	struct Data
	{
		int*		texture;	// �e�N�X�`���f�[�^�ւ̃|�C���^
		int			flame_data;	// �摜��`�悷��t���[���̍ő�l
		int			t_x;		// ���S���W(X)
		int			t_y;		// ���S���W(Y)
	};

protected:
	vector<Data>	tex_data;	// �e�N�X�`���[�f�[�^���Q��(�|�C���^)
	int				flame;		// �t���[���f�[�^
	int				index;		// �`����s���f�[�^�̓Y����
	bool			is_loop;	// ���[�v����A�j���[�V�������ۂ�
	const Vector3*	owner_pos;	// ���L�҂̃|�W�V�����f�[�^

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