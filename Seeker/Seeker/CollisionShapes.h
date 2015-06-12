#pragma once
#include "Generic.h"

class Shape
{
public:
	enum TYPE : int
	{
//		DOT,		// �_
//		BOX,		// ��
//		SPHERE,		// ��
		RECT,		// ��`
//		CIRCLE,		// �~
		ALL_NUM,
	};

protected:
	TYPE			type;			// �`�̃^�C�v
	int				id;				// �R���W������ID
	Vector3			position;		// ���W
	const Vector3*	owner_position;	// ������̍��W
	Vector3			scale;			// �T�C�Y(���a)
	const Vector3*	owner_velocity;	// ������̍��W
	AVector3		rotation;		// ��]

public:
	Shape(){}
	virtual ~Shape(){}

public:
	TYPE		GetType(){ return type; }
	int			GetId(){ return id; }
	Vector3		GetPosition(){ return (position + *owner_position); }
	Vector3		GetScale(){ return scale; }
	Vector3		GetVelocity(){ return *owner_velocity; }
	AVector3	GetRotation(){ return rotation; }
};

class Dot : public Shape
{

};

class Box : public Shape
{

};

class Sphere : public Shape
{

};

class Rect : public Shape
{
public:
	Rect(){}
	Rect(int _id, const Vector3* _owner_pos, const Vector3& _pos, const Vector3& _scale)
	{
		type = TYPE::RECT;
		id = _id;
		owner_position = _owner_pos;
		position = _pos;
		scale = _scale;
		rotation = { 0.f, 0.f, 0.f };
	}
	~Rect(){}
};