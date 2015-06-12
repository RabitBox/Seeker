#pragma once
#include "DxLib.h"
#include "Generic.h"

#define EDGE_GAP	(80.f)

class Camera
{
protected:
	Vector3 position;
	float edge_r, edge_l;

public:
	Camera(){ position = Vector3(0.f, 50.f); }
	Camera(float _right, float _left) : edge_r(_right - EDGE_GAP), edge_l(_left + EDGE_GAP){ position = Vector3(0.f, 50.f); }
	~Camera(){}

public:
	void Target(const Vector3& pos)
	{
		if (edge_l > pos.x){
			position.x = edge_l;
		} else if (edge_r < pos.x){
			position.x = edge_r;
		} else {
			position.x = pos.x;
		}
		position.z = pos.z;
		SetCameraPositionAndTarget_UpVecY(VGet(position.x, position.y, position.z - 100.f), VGet(position.x, position.y, position.z));
	}
};