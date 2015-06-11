#pragma once
#include "Generic.h"

class Shape
{
public:
	enum ID
	{
		dot,		// “_
		box,		// ” 
		sphere,		// ‹…
	};

protected:
	ID			id;
	Vector3		position;
	Vector3*	owner_position;
	AVector3	rotation;

public:
	Shape(){}
	virtual ~Shape(){}

public:
	ID			GetId(){ return id; }
	Vector3		GetPosition(){ return (position + *owner_position); }
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