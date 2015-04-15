#pragma once
#include "DxLib.h"
#include "Objects.h"

class Floar : public Passive
{
public:
	Floar();
	Floar(Transform _transform);
	virtual ~Floar();

	void Update() override;
	void Draw() override;
};