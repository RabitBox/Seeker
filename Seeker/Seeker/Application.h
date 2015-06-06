#pragma once
#include <memory>
#include "DxLib.h"
#include "ScenePlay.h"

class Application
{
private:
	unique_ptr<SceneBace> scene;

public:
	Application();
	~Application();

	void AppMain();

private:
	int  Initialize();
};