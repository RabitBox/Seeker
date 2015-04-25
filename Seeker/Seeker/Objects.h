#pragma once
#include "Generic.h"

enum ObjID
{
	Player,				// プレイヤー
	Camera,
	Floar,				// 床
	ParticleEmitter,	// パーティクル生成機
};

class Passive : public PassiveObject
{
protected:
	ObjID id;
};

class Active : public ActiveObject
{
protected:
	ObjID id;

public:
	Vector3 GetPosition(){ return this->transform.position; }
};