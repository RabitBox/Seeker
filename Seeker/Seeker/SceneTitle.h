// タイトルシーン
#pragma once
#include "SceneBase.h"

class SceneTitle : public SceneBace
{
public:
	SceneTitle();
	virtual ~SceneTitle();

	virtual void Input() override;
	virtual void Update() override;
	virtual void Draw() override;
};