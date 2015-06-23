#include "StoneFloor.h"
#include "DxRaps.h"
#include "TextureManager.h"

//--------------------------------------------------
StoneFloor::StoneFloor()
{
	this->transform.position = { 0.f, 0.f, 0.f };
	Default();
	//LoadTexture();
}
StoneFloor::StoneFloor(float x, float y, float z)
{
	this->transform.position = {x,y,z};
	Default();
	//LoadTexture();
}
//--------------------------------------------------

void StoneFloor::Update()
{
	return;
}

void StoneFloor::Draw()
{
	DrawQuadPolygon(this->transform.position, this->transform.rotation, this->transform.scale, { 0.0f, 10.0f, 0.0f }, { 90.0f, 0.0f, 0.0f }, *images, true);
	//DrawQuadPolygon(this->transform.position, this->transform.rotation, this->transform.scale, { 0.0f, -10.0f, 0.0f }, { 90.0f, 0.0f, 0.0f }, *images, true);
	DrawQuadPolygon(this->transform.position, this->transform.rotation, this->transform.scale, { 0.0f, 0.0f, -10.0f }, { 0.0f, 0.0f, 0.0f }, *images, true);
}

void StoneFloor::Default()
{
	this->id = ObjID::Floor;
	this->transform.scale = { 20.f, 20.f, 0.f };
	this->transform.rotation = { 0.f, 0.f, 0.f };

	int dem_load = LoadGraph("Texture/StoneTile.png");
	images = TextureManager::GetInstance()->LoadTexture("StoneTile", dem_load);

	//shape = new Rect(false, Vector3(0.f, 0.f), transform.scale.Harf(), id, transform.position);
	//CollisionManager::GetInstance()->PushData(shape);
}