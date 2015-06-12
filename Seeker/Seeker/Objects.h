#pragma once
#include <map>
#include "Generic.h"
using namespace std;

class Acter : public Object
{
public:
	enum ObjID { Player, Floor, BackGround, };

protected:
	//enum ObjID { Player, Floor, BackGround, };
	//static map<char*, int> loaded_image;
	ObjID id;

public:
	Acter(){}
	virtual ~Acter(){}

	virtual void Input(){}

	int GetId(){ return (int)id; }


protected:
	virtual void LoadTexture(){}
};