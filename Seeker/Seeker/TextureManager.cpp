#include "TextureManager.h"

//--------------------------------------------------
// ���Ԃ̐錾
//--------------------------------------------------
TextureManager* TextureManager::texture_manager = new TextureManager();

//--------------------------------------------------
// �O���g�p�֐�
//--------------------------------------------------
// 
int* TextureManager::LoadTexture(char key[], int &texture)
{
	string name = key;
	//�܂��L�[������Ƀ��[�h����Ă��邩���`�F�b�N����
	if (!CheckLoaded(name))
	{
		// ���������ꍇ�摜��o�^����
		RegisterTexture(name, texture);
	}

	// �摜�̊i�[����Ă���ꏊ�̃C�e���[�^��T��
	map<string, int>::iterator itr_image = loaded_image.find(name);

	// �摜�f�[�^�̊i�[���ꂽ�A�h���X��Ԃ�
	return &itr_image->second;
}

//key�Ō������A�o�^���ꂽ�摜���폜����
void TextureManager::EraceTexture(char key[])
{
	string name = key;
	map<string, int>::iterator itr_image = loaded_image.find(name);	// key�œo�^����Ă���e�N�X�`���̃C�e���[�^��T��
	loaded_image.erase(itr_image);									// �������
}

int TextureManager::GetSize()
{
	return loaded_image.size();
}

//--------------------------------------------------
// ��������g�p�֐�
//--------------------------------------------------
// �e�N�X�`���f�[�^�����ɓo�^����Ă��邩���`�F�b�N����
bool TextureManager::CheckLoaded(string key)
{
	if (loaded_image.find(key) == loaded_image.end())
		return false;	// �o�^����Ă��Ȃ�����
	else 
		return true;	// �o�^����Ă���
}

// �e�N�X�`���f�[�^��o�^����
void TextureManager::RegisterTexture(string key, int &texture)
{
	loaded_image.insert(map<string, int>::value_type(key, texture));
}