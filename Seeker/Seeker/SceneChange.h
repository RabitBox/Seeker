#pragma once
#include <vector>
#include "SceneBase.h"
using namespace std;

class SceneChange : public SceneBace
{
public:
	SceneChange();
	~SceneChange(){}

	void Update() override;
	void Draw() override;

	void Change();
};