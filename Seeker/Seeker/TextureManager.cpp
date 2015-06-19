#include "TextureManager.h"

//--------------------------------------------------
// 実態の宣言
//--------------------------------------------------
TextureManager* TextureManager::texture_manager = nullptr;

//--------------------------------------------------
// 外部使用関数
//--------------------------------------------------
// 使用開始時に呼ぶ
void TextureManager::Create()
{
	texture_manager = new TextureManager();
}

// 使用終了時に呼ぶ
void TextureManager::Destroy()
{
	delete texture_manager;
	texture_manager = nullptr;
}

// 画像を登録し、その画像のアドレスを返す
int* TextureManager::LoadTexture(char key[], int &texture)
{
	string name = key;
	//まずキーから既にロードされているかをチェックする
	if (!CheckLoaded(name))
	{
		// 無かった場合画像を登録する
		RegisterTexture(name, texture);
	}

	// 画像の格納されている場所のイテレータを探す
	map<string, int>::iterator itr_image = loaded_image.find(name);

	// 画像データの格納されたアドレスを返す
	return &itr_image->second;
}

//keyで検索し、登録された画像を削除する
void TextureManager::EraceTexture(char key[])
{
	string name = key;
	map<string, int>::iterator itr_image = loaded_image.find(name);	// keyで登録されているテクスチャのイテレータを探す
	loaded_image.erase(itr_image);									// 解放する
}

int TextureManager::GetSize()
{
	return loaded_image.size();
}

//--------------------------------------------------
// 内部限定使用関数
//--------------------------------------------------
// テクスチャデータが既に登録されているかをチェックする
bool TextureManager::CheckLoaded(string key)
{
	if (loaded_image.find(key) == loaded_image.end())
		return false;	// 登録されていなかった
	else 
		return true;	// 登録されていた
}

// テクスチャデータを登録する
void TextureManager::RegisterTexture(string key, int &texture)
{
	loaded_image.insert(map<string, int>::value_type(key, texture));
}