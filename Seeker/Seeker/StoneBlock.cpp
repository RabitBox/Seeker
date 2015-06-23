#include "StoneBlock.h"
#include "DxRaps.h"
#include "TextureManager.h"

StoneBlock::StoneBlock(float x, float y, float z)
{
	this->transform.position = { x, y, z };
	this->transform.scale = { 20.f, 20.f, 0.f };
	this->transform.rotation = { 0.f, 0.f, 0.f };
	id = ObjID::Wall;

	int dem_load = LoadGraph("Texture/StoneTile.png");
	image = TextureManager::GetInstance()->LoadTexture("StoneTile", dem_load);

	//shape = new Rect(false, Vector3(0.f, 0.f), transform.scale.Harf(), id, transform.position);
	//CollisionManager::GetInstance()->PushData(shape);
}

void StoneBlock::Draw()
{
	DrawQuadPolygon(this->transform.position, this->transform.rotation, this->transform.scale, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, *image, true);
}