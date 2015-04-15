#pragma once
#include "Generic.h"

enum ObjID
{
	Player,	// ƒvƒŒƒCƒ„[
	Floar,	// °
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