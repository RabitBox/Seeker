#include "TextureManager.h"

int* TextureManager::LoadTexture(char* key, int &texture)
{
	//まずキーから既にロードされているかをチェックする
	if (!CheckLoaded(key))
	{
		// 無かった場合画像を登録する
		RegisterTexture(key, texture);
	}
	// 画像の格納されている場所のイテレータを探す
	map<char*, int>::iterator itr_image = loaded_image.find(key);
	// 画像データの格納されたアドレスを返す
	return &itr_image->second;
}

void TextureManager::EraceTexture(char* key)
{
	map<char*, int>::iterator itr_image = loaded_image.find(key);	// keyで登録されているテクスチャのイテレータを探す
	loaded_image.erase(itr_image);									// 解放する
}

// テクスチャデータが既に登録されているかをチェックする
bool TextureManager::CheckLoaded(char* key)
{
	if (loaded_image.find(key) == loaded_image.end())
		return false;	// 登録されていなかった
	else 
		return true;	// 登録されていた
}

// テクスチャデータを登録する
void TextureManager::RegisterTexture(char* key, int &texture)
{
	loaded_image[key] = texture;
}