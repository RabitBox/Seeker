#pragma once
#include <map>
#include <string>
#include "Generic.h"
using namespace std;

enum ObjID
{
	Player,
	Camera,
	Floor,
};

class Acter : public Object
{
protected:
	//static int loaded_images[50];
	static map<string, int> loaded_image;
	ObjID id;

public:
	Vector3 GetPosition(){ return this->transform.position; }

protected:
	virtual void LoadTexture() = 0;
};

//----------------------------------------------------------------------
// 静的メンバの実態宣言
//int Acter::loaded_images[10];				// テスト版
//map<string, int> Acter::loaded_image;		// 本運用版