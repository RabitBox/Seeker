//----------------------------------------------------------------------
// TextureManager�N���X
// �V���O���g���p�^�[�����g�p
//
// �����񁨐����Fatoi(char *str)
// ������������Fsprintf(char *str, "hoge_%d", int a); printf�Ɠ����������������� *str �Ɋi�[����
//----------------------------------------------------------------------
#pragma once
#include <map>
using namespace std;

class TextureManager
{
private:
	map<char*, int> loaded_image;

public:
	~TextureManager(){}

private:
	TextureManager(){}
	static TextureManager* texture_manager;

public:
	static TextureManager* GetInstance(){ return texture_manager; }

public:
	int*	LoadTexture(char* key, int &texture);
	void	EraceTexture(char* key);

private:
	bool	CheckLoaded(char* key);
	void	RegisterTexture(char* key, int &texture);
};