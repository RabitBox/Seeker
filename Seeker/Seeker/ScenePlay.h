#pragma once
#include <vector>
#include "SceneBase.h"
#include "Objects.h"

class ScenePlay : public SceneBace
{
private:
	std::vector <Passive*> passive_objects;
	std::vector <Active*> active_objects;

public:
	ScenePlay();
	virtual ~ScenePlay();

	virtual void Input() override;
	virtual void Update() override;
	virtual void Draw() override;
};