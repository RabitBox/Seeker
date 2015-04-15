#include "Floar.h"

Floar::Floar()
{
	this->id = ObjID::Floar;
	this->transform = { { 0.f, 0.f, 0.f }, { 0.f, 0.f, 0.f }, { 1.f, 1.f, 1.f } };
}

Floar::Floar(Transform _transform)
{
	this->id = ObjID::Floar;
	this->transform = _transform;
}

Floar::~Floar(){}

void Floar::Update()
{

}

void Floar::Draw()
{
	//VERTEX3D vertex[14];	// 頂点
	//WORD index[36];			// インデックス
}