#pragma once
#include <map>
//#include <string>
#include "Generic.h"
using namespace std;

class Acter : public Object
{
protected:
	enum ObjID { Player, Camera, Floor, };
	static map<char*, int> loaded_image;
	ObjID id;

public:
	Acter(){}
	virtual ~Acter(){}

protected:
	virtual void LoadTexture(){}
};

