//
#pragma once
#include "Objects.h"

class StoneFloor : public Acter
{
private:
	//int* images;

public:
	StoneFloor();
	StoneFloor(Vector3 _position);
	virtual ~StoneFloor(){}

	void Update() override;
	void Draw() override;

private:
	void LoadTexture() override;
};

//*/