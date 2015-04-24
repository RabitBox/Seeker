#include "TinyTim.h"

TinyTim::TinyTim()
{
	this->id = ObjID::Player;
	state = AnimState::Stand;
}

TinyTim::TinyTim(Vector3 _position)
{
	this->transform.position = _position;
}

TinyTim::~TinyTim(){}

void TinyTim::Update()
{

}

void TinyTim::Draw()
{

}