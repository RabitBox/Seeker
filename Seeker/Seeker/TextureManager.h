//----------------------------------------------------------------------
// TextureManagerクラス
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

// 文字列→整数：atoi(char *str)
// 整数→文字列：sprintf(char *str, "hoge_%d", int a); printfと同じ処理をした情報を *str に格納する