#include "StoneFloor.h"
#include "DxRaps.h"

StoneFloor::StoneFloor()
{
	this->id = ObjID::Floor;
}

StoneFloor::StoneFloor(float x, float y, float z)
{
	this->transform.position = {x,y,z};
	this->transform.scale = { 1.f, 1.f, 0.f };
	this->transform.rotation = { 0.f, 0.f, 0.f };
	StoneFloor();
}//*/

StoneFloor::StoneFloor(Vector3 _position)
{
	this->transform.position = _position;
	this->transform.scale = { 1.f, 1.f, 0.f };
	this->transform.rotation = { 0.f, 0.f, 0.f };
	StoneFloor();
}

/*StoneFloor::StoneFloor(Vector3*_position)
{
	this->transform.position = *_position;
	this->transform.scale = { 1.f, 1.f, 0.f };
	this->transform.rotation = { 0.f, 0.f, 0.f };
	StoneFloor();
}//*/

void StoneFloor::Update()
{
	return;
}

void StoneFloor::Draw()
{
	DrawString(0, 45, "Stone : •`‰æ‚µ‚Ü‚µ‚½", GetColor(255, 255, 255));
	DrawFormatString(0, 100, GetColor(255, 255, 255), "x:%f y:%f z:%f", transform.scale.x, transform.scale.y, transform.scale.z);
	DrawQuadPolygon(this->transform.position, this->transform.rotation, this->transform.scale * 20, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, DX_NONE_GRAPH, true);

	return;
}

void StoneFloor::LoadTexture()
{
	return;
}