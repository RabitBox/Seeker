#include "Wall.h"

Wall::Wall(float x, float y, float z)
{
	this->transform.position = { x, y, z };
	this->transform.scale = { 20.f, 20.f, 0.f };
	this->transform.rotation = { 0.f, 0.f, 0.f };
	id = ObjID::Wall;
}