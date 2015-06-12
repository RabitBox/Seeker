#pragma once
#include "CollisionShapes.h"
#include <vector>
using namespace std;

class CollisionManager
{
private:
	vector<Shape*> rects;

public:
	bool CheckToId(int _target_id);

public:
	void SetData(Rect* _rect){ rects.push_back(_rect); }
};