#ifndef _COLLISION_MANAGER_
#define _COLLISION_MANAGER_

#include <vector>
#include "CollisionShapes.h"
#include "CollisionCheckers.h"
using namespace std;

class CollisionManager
{
private:
	static CollisionManager* collision_manager;
	CollisionManager(){}
	~CollisionManager(){}

public:
	CollisionManager* GetInstance(){ return collision_manager; }
	static void Create(){ collision_manager = new CollisionManager(); }
	static void Destroy(){ delete collision_manager; collision_manager = nullptr; }

private:
	vector<Shape**> collisions;
	//CollisionChecker* checker[Shape::ALL_TYPE_NUM][Shape::ALL_TYPE_NUM];

public:
	bool CheckToId(int _target_id);

public:
	Shape*** SetData(Shape* _shape)
	{
		collisions.push_back(&_shape);
		vector<Shape**>::iterator itr = (--collisions.end());
		return &(*itr);
	}

public:
	bool Rect_Rect(Shape* _rect1, Shape* _rect2)
	{
		float x0 = _rect1->GetPosition().x - _rect1->GetScale().x;
		float y0 = _rect1->GetPosition().x + _rect1->GetScale().x;
		float x1 = _rect1->GetPosition().y - _rect1->GetScale().y;
		float y1 = _rect1->GetPosition().y + _rect1->GetScale().y;

		float x2 = _rect2->GetPosition().x - _rect2->GetScale().x;
		float y2 = _rect2->GetPosition().x + _rect2->GetScale().x;
		float x3 = _rect2->GetPosition().y - _rect2->GetScale().y;
		float y3 = _rect2->GetPosition().y + _rect2->GetScale().y;

		if (x0 < x3 && x2 < x1 && y0 < y3 && y2 < y1)
		{
			return true;
		}
		return false;
	}
};

CollisionManager* CollisionManager::collision_manager = nullptr;

#endif