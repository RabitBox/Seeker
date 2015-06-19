#pragma once
#include "Generic.h"

class Shape
{
public:
	enum TYPE
	{
		RECT,
		CIRCLE,
		ALL_TYPE_NUM,
	};

protected:
	TYPE			type;			// 形
	bool			is_trigger;		// 物理衝突があるか否か true:なし false:あり
	Shape**			looker;			// 自身のポインタを持っているもポインタへのポインタ
	Vector3			position;		// 中心座標
	Vector3			scale;			// サイズ(直径)
	const Vector3*	owner_position;	// 持ち主の座標

public:
	Shape(){}
	virtual ~Shape(){}

public:
	TYPE	GetType(){ return type; }
	bool	GetTrigger(){ return is_trigger; }
	void	SetLookerPointer(Shape* _looker){ looker = &_looker; }
	Shape**	GetLookerPointer(){ return looker; }
	Vector3	GetPosition(){ return (position + *owner_position); }
	Vector3	GetScale(){ return scale; }
};

class Rect : public Shape
{
public:
	Rect(bool _trigger, Vector3 _pos, Vector3 _scale, const Vector3 &_owner_pos)
	{
		type = TYPE::RECT;
		is_trigger = _trigger;
		looker = nullptr;
		position = _pos;
		scale = _scale;
		owner_position = &_owner_pos;
	}
	~Rect(){}
};

class Circle : public Shape
{
public:
	Circle(bool _trigger, Vector3 _pos, Vector3 _scale, const Vector3 &_owner_pos)
	{
		type = TYPE::CIRCLE;
		is_trigger = _trigger;
		looker = nullptr;
		position = _pos;
		scale = _scale;
		owner_position = &_owner_pos;
	}
	~Circle(){}
};



/*class Shape
{
public:
	enum TYPE : int
	{
//		DOT,		// 点
//		BOX,		// 箱
//		SPHERE,		// 球
		RECT,		// 矩形
//		CIRCLE,		// 円
		ALL_NUM,
	};

protected:
	TYPE			type;			// 形のタイプ
	int				id;				// コリジョンのID
	Vector3			position;		// 座標
	const Vector3*	owner_position;	// 持ち主の座標
	Vector3			scale;			// サイズ(半径)
	const Vector3*	owner_velocity;	// 持ち主の座標
	AVector3		rotation;		// 回転

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
};//*/