// 衝突判定の形を司るクラス群
#ifndef _COLLISION_SHAPE_
#define _COLLISION_SHAPE_

#include "Generic.h"

// コリジョンの形のベースクラス
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
	bool			is_trigger;		// 物理的衝突があるか否か true:なし false:あり
	Vector3			position;		// 中心座標
	Vector3			scale;			// サイズ
	int				owner_id;		// 持ち主のID
	const Vector3*	owner_position;	// 持ち主の座標

public:
	Shape(){}
	virtual ~Shape(){}

public:
	TYPE		GetType(){ return type; }
	bool		GetTrigger(){ return is_trigger; }
	Vector3		GetPosition(){ return (position + *owner_position); }
	Vector3		GetScale(){ return scale; }
	int			GetID(){ return owner_id; }
};

// 矩形型コリジョンクラス
class Rect : public Shape
{
public:
	Rect(bool _trigger, Vector3 _pos, Vector3 _scale, const int &_id, const Vector3 &_owner_pos)
	{
		// 設定
		type = TYPE::RECT;
		is_trigger = _trigger;
		position = _pos;
		scale = _scale;
		owner_id = _id;
		owner_position = &_owner_pos;

		// マネージャに登録
		//CollisionManager::GetInstance()->PushData(this);
	}
	~Rect()
	{ 
		//CollisionManager::GetInstance()->PopData(*owner_id); 
	}
};

// 円形型コリジョンクラス
class Circle : public Shape
{
public:
	Circle(bool _trigger, Vector3 _pos, Vector3 _scale, const int &_id, const Vector3 &_owner_pos)
	{
		// 設定
		type = TYPE::CIRCLE;
		is_trigger = _trigger;
		position = _pos;
		scale = _scale;
		owner_id = _id;
		owner_position = &_owner_pos;

		// 設定
		//CollisionManager::GetInstance()->PushData(this);
	}
	~Circle()
	{
		//CollisionManager::GetInstance()->PopData(*owner_id); 
	}
};

// 箱型コリジョンクラス
// 球型コリジョンクラス
// プレーン型コリジョンクラス

#endif