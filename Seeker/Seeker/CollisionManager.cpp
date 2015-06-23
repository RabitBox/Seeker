#include "CollisionManager.h"

// �ÓI�����o�̎��̐錾
CollisionManager* CollisionManager::collision_manager = nullptr;

void CollisionManager::PopData(int _i)
{
	if (!collisions.empty())
	{
		vector<Shape*>::iterator itr;
		for (itr = collisions.begin(); itr != collisions.end(); itr++)
		{
			if ((*itr)->GetID() == _i)
			{
				collisions.erase(itr);
			}
		}
	}
}