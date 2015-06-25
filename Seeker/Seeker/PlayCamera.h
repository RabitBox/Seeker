#pragma once
#include "Generic.h"

class PlayCamera
{
protected:
	Vector3 position;
	float edge_r, edge_l;
	Vector3 target_pos;

public:
	PlayCamera(){ position = Vector3(0.f, 50.f, 0.f); }
	PlayCamera(float _right, float _left, Vector3 _pos);
	~PlayCamera(){}

public:
	void TargetSet(const Vector3& pos);
	void Target();
};