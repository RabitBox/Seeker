// エンドシーン
#pragma once
#include "mleak.h"
#include "SceneBase.h"

class SceneEnd : public SceneBace
{
private:
	int* images;
	int time;

public:
	SceneEnd();
	virtual ~SceneEnd(){}

	virtual void Update() override;
	virtual void Draw() override;
};