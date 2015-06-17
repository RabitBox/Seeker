#pragma once
#include <memory>
#include "DxLib.h"
#include "mleak.h"
#include "ScenePlay.h"
#include "TimeManager.h"
#include "SceneManager.h"

class Application
{
private:
	Fps fps;

public:
	Application();
	~Application();

	void AppMain();

private:
	int  Initialize();
};