#pragma once
#include "CollisionShapes.h"

class Collision{
public:
	virtual ~Collision(){}							// �f�X�g���N�^(virtual)
	virtual bool Check(Shape* s1, Shape* s2) = 0;	// ����(pure virtual)
};

class Rect_Rect : Collision
{
public:
	Rect_Rect(){}
	~Rect_Rect(){}
	bool Check(Shape* s1, Shape* s2) override
	{

	}
};