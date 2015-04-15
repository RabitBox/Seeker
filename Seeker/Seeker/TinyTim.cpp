#include "TinyTim.h"

TinyTim::TinyTim()
{
	this->id = ObjID::Player;
	state = AnimState::Stand;
}

TinyTim::~TinyTim(){}