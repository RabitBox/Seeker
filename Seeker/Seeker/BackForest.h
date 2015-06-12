#pragma once
#include "Objects.h"

class BackForest : public Acter
{
private:
	int *images = nullptr;
	bool turn_flag;

public:
	BackForest(){}
	BackForest(float x, float y, float z, bool turn);
	~BackForest(){}

public:
	//void Update() override;
	void Draw() override;

private:
	void LoadTexture() override;
};