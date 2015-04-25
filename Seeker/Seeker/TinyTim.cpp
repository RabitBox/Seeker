#include "DxLib.h"
#include "TinyTim.h"

TinyTim::TinyTim()
{
	this->id = ObjID::Player;
	state = AnimState::Stand;
}

TinyTim::TinyTim(Vector3 _position)
{
	this->transform.position = _position;
	this->transform.scale = {1.f,1.f,0.1f};
	this->transform.rotation = { 0.f, 0.f, 0.f };
	TinyTim();
}

TinyTim::~TinyTim(){}

void TinyTim::Update()
{

}

void TinyTim::Draw()
{
	DrawPolygon();
}

void TinyTim::DrawPolygon()
{
	DrawString(0, 45, "TinyTim : •`‰æ‚µ‚Ü‚µ‚½", GetColor(255, 255, 255));
	float x = this->transform.position.x;
	float y = this->transform.position.y;
	float z = this->transform.position.z;
	VERTEX3D vertex[4] = { 
		{ VGet(x - 30.f, y - 30.f, z), VGet(0.f, 0.f, -1.f), GetColorU8(0.f, 255.f, 255.f, 255.f), GetColorU8(0.f, 0.f, 0.f, 0.f), 0.f, 0.f, 0.f, 0.f },
		{ VGet(x - 30.f, y + 30.f, z), VGet(0.f, 0.f, -1.f), GetColorU8(0.f, 255.f, 255.f, 0.f), GetColorU8(0.f, 0.f, 0.f, 0.f), 0.f, 0.f, 0.f, 0.f },
		{ VGet(x + 30.f, y - 30.f, z), VGet(0.f, 0.f, -1.f), GetColorU8(0.f, 255.f, 0.f, 255.f), GetColorU8(0.f, 0.f, 0.f, 0.f), 0.f, 0.f, 0.f, 0.f },
		{ VGet(x + 30.f, y + 30.f, z), VGet(0.f, 0.f, -1.f), GetColorU8(0.f, 0.f, 255.f, 255.f), GetColorU8(0.f, 0.f, 0.f, 0.f), 0.f, 0.f, 0.f, 0.f }
	};
	WORD index[6] = {0,1,2,3,2,1};
	DrawPolygonIndexed3D(vertex, 4, index, 2, DX_NONE_GRAPH, FALSE);
}