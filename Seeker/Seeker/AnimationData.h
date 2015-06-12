// �A�j���[�V����
#pragma once
#include <vector>
#include "Generic.h"
using namespace std;

class Animation
{
public:
	struct TextureData
	{
		int*		texture;	// �e�N�X�`���f�[�^�ւ̃|�C���^
		float		t_x;		// ���S���W(X)
		float		t_y;		// ���S���W(Y)
	};
	struct IndexData
	{
		int			index;		// �Ăяo���摜�̃C���f�b�N�X
		int			flame;		// �摜��`�悷��t���[���̍ő�l
	};

protected:
	vector<TextureData>	tex_data;	// �e�N�X�`���[�f�[�^���Q��
	vector<IndexData>	index_data;	// �C���f�b�N�X
	int					flame;		// �t���[���f�[�^
	int					index;		// �`����s���f�[�^�̓Y����
	bool				is_loop;	// ���[�v����A�j���[�V�������ۂ�
	const Vector3*		owner_pos;	// ���L�҂̃|�W�V�����f�[�^
	int					number;		// �o�^���ꂽ�ԍ�
	bool				end_flag;	// �I���������ۂ�

public:
	Animation(){}
	Animation(TextureData* _texture_data, int _t_length, IndexData* _index_data, int _i_length, bool _loop, const Vector3* _pos, int _number);
	~Animation(){}

public:
	void Update();
	void Update(int _state);
	void Draw();
	void Draw(int _turn);
	bool GetEndFlag(){ return end_flag; }
};