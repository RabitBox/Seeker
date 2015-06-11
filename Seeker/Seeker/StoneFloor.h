// Î‚Ì°ƒNƒ‰ƒX
#pragma once
#include "Objects.h"

class StoneFloor : public Acter
{
private:
	int *images = nullptr;

public:
	StoneFloor();
	StoneFloor(float x, float y, float z);
	virtual ~StoneFloor(){}

	void Update() override;
	void Draw() override;

private:
	void Default();
};