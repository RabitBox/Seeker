//----------------------------------------------------------------------
// TextureManagerクラス
// シングルトンパターンを使用
//----------------------------------------------------------------------
#pragma once
#include <map>
#include <string>
using namespace std;

class TextureManager
{
private:
	map<string, int> loaded_image;

private:
	TextureManager(){}
	static TextureManager* texture_manager;

public:
	static TextureManager* GetInstance(){ return texture_manager; }

public:
	static void Create();
	static void Destroy();

	int*	LoadTexture(char key[], int &texture);
	void	EraceTexture(char key[]);
	int		GetSize();

private:
	bool	CheckLoaded(string);
	void	RegisterTexture(string, int &texture);
};