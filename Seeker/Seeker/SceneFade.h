#pragma once
#include <vector>
#include "SceneBase.h"
using namespace std;

class SceneFade : public SceneBace
{
private:
	enum MODE
	{
		ADD,
		CALL,
		GAIN,
	};

	MODE mode;
	vector<int*> images;
	int volume;

public:
	SceneFade();
	~SceneFade(){}

	void Update() override;
	void Draw() override;
};