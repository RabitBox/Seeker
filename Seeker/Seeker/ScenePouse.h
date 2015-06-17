#pragma once
#include <vector>
#include "mleak.h"
#include "SceneBase.h"
#include "Generic.h"

class ScenePouse : public SceneBace
{
public:
	ScenePouse(){}
	virtual ~ScenePouse(){}

	virtual void Update() override;
	virtual void Draw() override;
};