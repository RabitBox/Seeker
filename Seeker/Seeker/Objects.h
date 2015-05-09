#pragma once
#include "Generic.h"

enum ObjID
{
	Player,				// �v���C���[
	Camera,
	Floar,				// ��
};

class Passive : public Object
{
protected:
	ObjID id;
};

class Active : public Object
{
protected:
	ObjID id;

public:
	Vector3 GetPosition(){ return this->transform.position; }
};