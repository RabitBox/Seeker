#include "LostArticle.h"

LostArticle::LostArticle(float x, float y, float z)
{
	this->transform.position = { x, y, z };
	this->transform.scale = { 20.f, 20.f, 0.f };
	this->transform.rotation = { 0.f, 0.f, 0.f };
	id = ObjID::LostArticle;
	shape = new Rect(true, Vector3(0.f, 0.f), transform.scale.Harf(), id, transform.position);
	CollisionManager::GetInstance()->PushData(shape);
}