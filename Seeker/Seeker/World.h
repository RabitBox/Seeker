// �Q�[���̕�����Ԃ̂��鐢�E
// ���̒��ɂ�����̂������d�͂̉e�����ɓ���
// �c�c�\�肾����
#pragma once
#include <list>
#include <memory>
#include "Objects.h"
using namespace std;

#define GRAVITY	0.98f

class World
{
private:
	list< unique_ptr< Acter > > objects;

public:
	World(){}
	~World(){ objects.clear(); }

public:
	void Input(){}
	void Update(){}
	void Draw(){}

	void CreateObject(){}
};