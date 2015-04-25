#pragma once
#include "Generic.h"

enum ObjID
{
	Player,				// �v���C���[
	Camera,
	Floar,				// ��
	ParticleEmitter,	// �p�[�e�B�N�������@
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