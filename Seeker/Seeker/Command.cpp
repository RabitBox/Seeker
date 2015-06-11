#include "Command.h"

Command::Command(int _data_length) : index(0)
{
	for (int i = 0; i < HISTRY_LENGTH; i++){ histry[i] = Direction::NONE; }
	data = new Data[_data_length];
}

//--------------------------------------------------
// �g���R�}���h��ݒ�
void Command::Set(int _index, int _length, int _limit, int _input[])
{
	data[_index].length = _length;			// �R�}���h�̒������w��
	data[_index].limit = _limit;			// �R�}���h��t���Ԃ��w��
	data[_index].input = new int[_length];	// �R�}���h������z���������
	for (int i = 0; i < _length; i++)
	{
		data[_index].input[i] = _input[i];	// �R�}���h��o�^
	}
}

//--------------------------------------------------
// histry[] �ɓ��͏�������
void Command::Input(bool _up, bool _down, bool _left, bool _right)
{
	histry[index] = (_up ? UP : NONE) |
		(_down ? DOWN : NONE) |
		(_left ? LEFT : NONE) |
		(_right ? RIGHT : NONE);
}

//--------------------------------------------------
// �R�}���h���`�F�b�N
int Command::Check()
{
	// for���Ŏg���ϐ���for�����g���O�ɐ錾����
	int c, j, i;

	// �R�}���h�̎�ނ���for������
	for (c = 0; c < sizeof(data) / sizeof(data[0]); c++)
	{
		// i��j�������ŏ��������A�g����悤�ɂ���
		for (i = 0, j = data[c].length - 1; j >= 0; j--)
		{
			// i �����~�b�g�ɒB���邩�A�R�}���h����������܂ŉ�
			for (; i < data[c].limit; i++)
			{
				// ���~�b�g�̐��܂� histry[] ������������
				if (histry[(index - i + HISTRY_LENGTH) % HISTRY_LENGTH] == data[c].input[j])
				{
					break;	// �������q�b�g�������x����for�����甲����
				}
			}
			// j �� -1 �ɂȂ炸 i �����~�b�g�ɒB�����ꍇ (�R�}���h������)
			if (i == data[c].limit)
			{
				break;	// ����for�����甲����
			}
		}
		// i �����~�b�g�ɓ��B����O�� j �� -1 �ɂȂ����ꍇ (�R�}���h����)
		if (j == -1)
		{
			// �q�X�g���[�����������Ă���
			for (i = 0; i < HISTRY_LENGTH; i++)
			{
				histry[i] = Direction::NONE;
			}
			break;	// for���𔲂���
		}
	}

	// index�����ɐi�߂�
	index = (index + 1) % HISTRY_LENGTH;

	// �R�}���h���������Ă���ꍇ
	// �܂� c �� data[] �̗v�f����菬�����ꍇ
	if (c < sizeof(data) / sizeof(data[0])) 
	{
		return c;	// c �̒l��Ԃ�
	}

	// �R�}���h���������̏ꍇ
	return -1;		// �s�����Ȓl��Ԃ�
}