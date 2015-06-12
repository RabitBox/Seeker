#include "BackForest.h"
#include "DxLib.h"
#include"TextureManager.h"
#include "DxRaps.h"

BackForest::BackForest(float x, float y, float z, bool turn)
{
	id = ObjID::BackGround;
	transform.position = { x, y, z };
	transform.scale = { 160.f, 120.f, 0.f };
	transform.rotation = { 0.f, 0.f, 0.f };
	turn_flag = turn;
	LoadTexture();
}

void BackForest::Draw()
{
	if (turn_flag){
		DrawBillboard3D(VGetRap(transform.position),
			0.5f, 0.5f, 160.f, 0.f,
			*images, TRUE, 0);
	}
	else{
		DrawBillboard3D(VGetRap(transform.position),
			0.5f, 0.5f, 160.f, 0.f,
			*images, TRUE, 0);
	}//*/
	//DrawFormatString(0, 0, GetColor(255,255,255), "•`‰æ‚µ‚æ‚¤‚æI");
	/*DrawQuadPolygon(this->transform.position,
		this->transform.rotation,
		this->transform.scale,
		{ 0.0f, 0.0f, 0.0f },
		{ 0.0f, 0.0f, 0.0f },
		*images, turn_flag);//*/
}

void BackForest::LoadTexture()
{
	int dem_load = LoadGraph("Texture/010.jpg");
	images = TextureManager::GetInstance()->LoadTexture("Forest", dem_load);
}