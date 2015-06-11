#pragma once
#include <memory>
#include "DxLib.h"
#include "ScenePlay.h"
#include "TimeManager.h"

class Application
{
private:
	unique_ptr<SceneBace> scene;
	Fps fps;

public:
	Application();
	~Application();

	void AppMain();

private:
	int  Initialize();
};