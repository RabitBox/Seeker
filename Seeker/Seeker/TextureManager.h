//----------------------------------------------------------------------
// TextureManager�N���X
//----------------------------------------------------------------------
#pragma once
//#include <list>
#include <map>
using namespace std;

class TextureManager
{
private:
	map<char*, int> loaded_image;

public:

	virtual ~TextureManager(){}

public:
	int*	LoadTexture(char* keyward);
	bool	LoadedCheck(char* keyward);
};

// �����񁨐����Fatoi(char *str)
// ������������Fsprintf(char *str, "hoge_%d", int a); printf�Ɠ����������������� *str �Ɋi�[����