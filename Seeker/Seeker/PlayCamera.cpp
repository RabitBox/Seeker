#include "DxLib.h"
#include "PlayCamera.h"

#define EDGE_GAP	(80.f)

PlayCamera::PlayCamera(float _right, float _left, Vector3 _pos)
	: edge_r(_right - EDGE_GAP), edge_l(_left + EDGE_GAP)
{
	position = _pos;
}

void PlayCamera::TargetSet(const Vector3& pos)
{
	if (edge_l > pos.x){
		position.x = edge_l;
	}
	else if (edge_r < pos.x){
		position.x = edge_r;
	}
	else {
		position.x = pos.x;
	}
	position.z = pos.z;
}

void PlayCamera::Target()
{
	SetCameraPositionAndTarget_UpVecY(
		VGet(position.x, position.y, position.z - 100.f),
		VGet(position.x, position.y, position.z));

	//DrawFormatString(0, 0, GetColor(255, 255, 255), "%f:%f:%f", position.x, position.y, position.z);
}