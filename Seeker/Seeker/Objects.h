#pragma once
#include "Generic.h"

enum ObjID
{
	Player,	// �v���C���[
	Floar,	// ��
};

class Passive : public PassiveObject
{
protected:
	ObjID id;

public:
};

class Active : public ActiveObject
{
protected:
	ObjID id;
};