#pragma once
#include "Generic.h"

enum ObjID
{
	Player,				// �v���C���[
	Camera,
	Floar,				// ��
};

class Acter : public Object
{
protected:
	static int loaded_images;
	ObjID id;

public:
	Vector3 GetPosition(){ return this->transform.position; }
};