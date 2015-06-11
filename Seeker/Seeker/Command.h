// �R�}���h���󂯕t����N���X
// ���͂�����N���X�͕ʂɂ���
#pragma once
#define HISTRY_LENGTH	30

class Command
{
public:
	enum Direction : int
	{
		NONE	= 0,	// ����:�j���[�g����
		UP		= 2,	// ��
		DOWN	= 4,	// ��
		LEFT	= 8,	// ��
		RIGHT	= 16,	// �E
	};
	// �R�}���h�f�[�^
	struct Data
	{
		int		length;				// �R�}���h�̒���
		int		limit;				// �R�}���h�̎�t���~�b�g
		int*	input = nullptr;	// �R�}���h�̓��e
	};

private:
	int		index;					// ���͂��ꂽ�R�}���h������z��̃C���f�b�N�X
	int		histry[HISTRY_LENGTH];	// �R�}���h���� (30�܂ŋL���\)
	Data*	data = nullptr;			// �R�}���h�̎�� (�z��ŋL�����邪�A�v�f���͌�Ō��߂�׃|�C���^��)

public:
	Command(){}
	Command(int _data_length);
	~Command(){}

public:
	void Set(int, int, int, int[]);
	void Input(bool, bool, bool, bool);
	int  Check();
};