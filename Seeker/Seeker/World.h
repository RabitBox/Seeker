// ƒQ[ƒ€‚Ì•¨—‹óŠÔ‚Ì‚ ‚é¢ŠE
// ‚±‚Ì’†‚É‚ ‚é‚à‚Ì‚¾‚¯‚ªd—Í‚Ì‰e‹¿‰º‚É“ü‚é
// cc—\’è‚¾‚Á‚½
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