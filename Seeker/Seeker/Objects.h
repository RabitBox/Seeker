#pragma once
#include "Generic.h"

enum ObjID
{
	Player,				// プレイヤー
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
};