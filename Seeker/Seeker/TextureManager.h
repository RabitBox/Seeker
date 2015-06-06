//----------------------------------------------------------------------
// TextureManagerクラス
// シングルトンパターンを使用
//
// 文字列→整数：atoi(char *str)
// 整数→文字列：sprintf(char *str, "hoge_%d", int a); printfと同じ処理をした情報を *str に格納する
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