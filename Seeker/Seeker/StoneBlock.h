#pragma once
#include "Objects.h"

class StoneBlock : public Acter
{
private:
	int* image;

public:
	StoneBlock(float x, float y, float z);
	~StoneBlock(){}

public:
	void Draw() override;
};