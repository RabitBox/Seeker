// ゲームの物理空間のある世界
// この中にあるものだけが重力の影響下に入る
// ……予定だった
#pragma once
#include <list>
#include <memory>
#include "Objects.h"
using namespace std;

#define GRAVITY	0.98f

class World
{
private:
	list< unique_ptr< Acter > > objects;

public:
	World(){}
	~World(){ objects.clear(); }

public:
	void Input(){}
	void Update(){}
	void Draw(){}

	void CreateObject(){}
};