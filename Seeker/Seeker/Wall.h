// 壁クラス
// 世界の端に設置する用
#pragma once
#include "Objects.h"

class Wall : public Acter
{
public:
	Wall(float x, float y, float z);
	~Wall(){}
};