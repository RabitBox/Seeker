// エンドシーン
#pragma once
#include "mleak.h"
#include "SceneBase.h"

class SceneEnd : public SceneBace
{
public:
	SceneEnd(){}
	virtual ~SceneEnd(){}

	virtual void Update() override;
	virtual void Draw() override;
};