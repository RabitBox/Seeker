#pragma once
#include <memory>
#include "ScenePlay.h"

class Application
{
private:
	unique_ptr<SceneBace> scene;
	//SceneBace *scene = nullptr;

public:
	Application();
	~Application();

	void AppMain();

private:
	int  Initialize();
};