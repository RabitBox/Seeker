// デモプレイ用クラス
#pragma once
#include <vector>
#include "mleak.h"
#include "SceneBase.h"
#include "Generic.h"

class SceneDemo : public SceneBace
{
public:
	SceneDemo(){}
	virtual ~SceneDemo(){}

	void Update() override;
	void Draw() override;
};