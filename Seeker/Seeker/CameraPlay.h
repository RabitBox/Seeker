// プレイシーンでのカメラの挙動
#pragma once
#include "Generic.h"

enum CAMERA_MODE
{
	FOLLOW,		// プレイ
	WAIT,		// 待つ
	PASSIBE,	// 動かされる
};

class CameraPlay
{
private:
	Transform transform;
	CAMERA_MODE mode;

public:
	CameraPlay();
	virtual ~CameraPlay();

	void Update();
};