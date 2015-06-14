// タイトルシーン
#pragma once
#include "SceneBase.h"

class SceneTitle : public SceneBace
{
public:
	SceneTitle(){}
	virtual ~SceneTitle(){}

	void Update() override;
	void Draw() override;
};