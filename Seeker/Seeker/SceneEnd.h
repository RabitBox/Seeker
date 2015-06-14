// エンドシーン
#pragma once
#include "SceneBase.h"

class SceneEnd : public SceneBace
{
public:
	SceneEnd(){}
	virtual ~SceneEnd(){}

	virtual void Update() override;
	virtual void Draw() override;
};