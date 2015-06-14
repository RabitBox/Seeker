// デモプレイ用クラス
#pragma once
#include <vector>
#include "SceneBase.h"
#include "Generic.h"

class SceneDemo : public SceneBace
{
public:
	SceneDemo(){}
	virtual ~SceneDemo(){}

	virtual void Update() override;
	virtual void Draw() override;
};