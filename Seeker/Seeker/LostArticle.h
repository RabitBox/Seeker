#pragma once
#include "Objects.h"

#include "DxLib.h"

class LostArticle : public Acter
{
public:
	LostArticle(float x, float y, float z);
	~LostArticle()
	{
		//CollisionManager::GetInstance()->PopData(id);
		delete shape;
		shape = nullptr;
	}
};