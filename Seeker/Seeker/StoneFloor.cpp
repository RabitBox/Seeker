#include "StoneFloor.h"
#include "DxRaps.h"
#include "TextureManager.h"

//--------------------------------------------------
StoneFloor::StoneFloor()
{
	this->transform.position = { 0.f, 0.f, 0.f };
	StoneFloor::Default();
}
StoneFloor::StoneFloor(float x, float y, float z)
{
	this->transform.position = {x,y,z};
	StoneFloor::Default();
}
/*StoneFloor::StoneFloor(Vector3 _position)
{
	this->transform.position = _position;
	Default();
}//*/
//--------------------------------------------------

void StoneFloor::Update()
{
	return;
}

void StoneFloor::Draw()
{
	DrawString(0, 45, "Stone : •`‰æ‚µ‚Ü‚µ‚½", GetColor(255, 255, 255));
	DrawQuadPolygon(this->transform.position, this->transform.rotation, this->transform.scale, { 0.0f, 10.0f, 0.0f }, { 90.0f, 0.0f, 0.0f }, DX_NONE_GRAPH, true);
	DrawQuadPolygon(this->transform.position, this->transform.rotation, this->transform.scale, { 0.0f, -10.0f, 0.0f }, { 90.0f, 0.0f, 0.0f }, DX_NONE_GRAPH, true);
	DrawQuadPolygon(this->transform.position, this->transform.rotation, this->transform.scale, { 0.0f, 0.0f, -10.0f }, { 0.0f, 0.0f, 0.0f }, DX_NONE_GRAPH, true);

	return;
}

void StoneFloor::Default()
{
	this->id = ObjID::Floor;
	this->transform.scale = { 20.f, 20.f, 0.f };
	this->transform.rotation = { 0.f, 0.f, 0.f };
}//*/

void StoneFloor::LoadTexture()
{
	return;
}