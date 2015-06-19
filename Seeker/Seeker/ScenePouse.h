#pragma once
#include <vector>
#include "mleak.h"
#include "SceneBase.h"
#include "Generic.h"
#include "InputManager.h"
using namespace std;

class ScenePouse : public SceneBace
{
private:
	vector<int*> images;
	InputManager* input = InputManager::GetInstance();

public:
	ScenePouse();
	virtual ~ScenePouse(){}

	virtual void Update() override;
	virtual void Draw() override;
};