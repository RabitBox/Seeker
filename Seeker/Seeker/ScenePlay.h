#pragma once
#include <vector>
#include <memory>
#include <algorithm>
#include "mleak.h"
#include "SceneBase.h"
#include "Objects.h"
#include "StageDemo.h"
using namespace std;

class ScenePlay : public SceneBace
{
protected:
	unique_ptr<StageBase> stage;

public:
	ScenePlay();
	virtual ~ScenePlay();

	virtual void Update() override;
	virtual void Draw() override;
};