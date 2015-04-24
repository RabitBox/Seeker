// アニメーション
#pragma once
#include <vector>
#include <map>
#include <string>
using namespace std;

class AnimationBase
{
protected:
	map<string, unsigned int> textures;

public:
	virtual ~AnimationBase() = 0;

public:
	virtual void Animation() = 0;
};

/*class AnimationBase
{
protected:
	int Flame;

public:
	virtual void Animation();
};//*/