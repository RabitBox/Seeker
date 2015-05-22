#include "StoneFloor.h"

StoneFloor::StoneFloor()
{
	this->id = ObjID::Floor;
}

StoneFloor::StoneFloor(Vector3 _position)
{
	this->transform.position = _position;
	this->transform.scale = { 1.f, 1.f, 0.1f };
	this->transform.rotation = { 0.f, 0.f, 0.f };
}

void StoneFloor::Update()
{
	return;
}

void StoneFloor::Draw()
{
	return;
}

void StoneFloor::LoadTexture()
{
	return;
}