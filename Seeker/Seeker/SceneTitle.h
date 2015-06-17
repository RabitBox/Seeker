// タイトルシーン
#pragma once
#include <vector>
#include <memory>
#include "mleak.h"
#include "SceneBase.h"
#include "InputManager.h"
using namespace std;

class SceneTitle : public SceneBace
{
private:
	enum Mode
	{
		WAIT,
		SELECT,
	};
	enum Select
	{
		PLAY_GAME,
		END_GAME,
	};

	vector<int*> images;
	Mode mode;
	Select select;

	InputManager* input = InputManager::GetInstance();

public:
	SceneTitle();
	~SceneTitle() override;

	void Update() override;
	void Draw() override;

	void Now_Wait();
	void Now_Select();

	void Now_ModeDraw();
};