#pragma once
#include <map>
#include "Generic.h"
#include "CollisionManager.h"
using namespace std;

class Acter : public Object
{
public:
	enum ObjID { Player, Block, Floor, BackGround, Wall, LostArticle, };

protected:
	Shape* shape = nullptr;
	ObjID id;

public:
	Acter(){}
	virtual ~Acter(){}

	virtual void Input(){}

	int GetId(){ return (int)id; }


protected:
	//virtual void LoadTexture(){}
};