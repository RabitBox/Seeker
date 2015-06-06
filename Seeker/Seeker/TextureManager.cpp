#include "TextureManager.h"

int* TextureManager::LoadTexture(char* key, int &texture)
{
	//�܂��L�[������Ƀ��[�h����Ă��邩���`�F�b�N����
	if (!CheckLoaded(key))
	{
		// ���������ꍇ�摜��o�^����
		RegisterTexture(key, texture);
	}
	// �摜�̊i�[����Ă���ꏊ�̃C�e���[�^��T��
	map<char*, int>::iterator itr_image = loaded_image.find(key);
	// �摜�f�[�^�̊i�[���ꂽ�A�h���X��Ԃ�
	return &itr_image->second;
}

void TextureManager::EraceTexture(char* key)
{
	map<char*, int>::iterator itr_image = loaded_image.find(key);	// key�œo�^����Ă���e�N�X�`���̃C�e���[�^��T��
	loaded_image.erase(itr_image);									// �������
}

// �e�N�X�`���f�[�^�����ɓo�^����Ă��邩���`�F�b�N����
bool TextureManager::CheckLoaded(char* key)
{
	if (loaded_image.find(key) == loaded_image.end())
		return false;	// �o�^����Ă��Ȃ�����
	else 
		return true;	// �o�^����Ă���
}

// �e�N�X�`���f�[�^��o�^����
void TextureManager::RegisterTexture(char* key, int &texture)
{
	loaded_image[key] = texture;
}