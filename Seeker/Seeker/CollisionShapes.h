// �Փ˔���̌`���i��N���X�Q
#ifndef _COLLISION_SHAPE_
#define _COLLISION_SHAPE_

#include "Generic.h"

// �R���W�����̌`�̃x�[�X�N���X
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
	TYPE			type;			// �`
	bool			is_trigger;		// �����I�Փ˂����邩�ۂ� true:�Ȃ� false:����
	Vector3			position;		// ���S���W
	Vector3			scale;			// �T�C�Y
	int				owner_id;		// �������ID
	const Vector3*	owner_position;	// ������̍��W

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

// ��`�^�R���W�����N���X
class Rect : public Shape
{
public:
	Rect(bool _trigger, Vector3 _pos, Vector3 _scale, const int &_id, const Vector3 &_owner_pos)
	{
		// �ݒ�
		type = TYPE::RECT;
		is_trigger = _trigger;
		position = _pos;
		scale = _scale;
		owner_id = _id;
		owner_position = &_owner_pos;

		// �}�l�[�W���ɓo�^
		//CollisionManager::GetInstance()->PushData(this);
	}
	~Rect()
	{ 
		//CollisionManager::GetInstance()->PopData(*owner_id); 
	}
};

// �~�`�^�R���W�����N���X
class Circle : public Shape
{
public:
	Circle(bool _trigger, Vector3 _pos, Vector3 _scale, const int &_id, const Vector3 &_owner_pos)
	{
		// �ݒ�
		type = TYPE::CIRCLE;
		is_trigger = _trigger;
		position = _pos;
		scale = _scale;
		owner_id = _id;
		owner_position = &_owner_pos;

		// �ݒ�
		//CollisionManager::GetInstance()->PushData(this);
	}
	~Circle()
	{
		//CollisionManager::GetInstance()->PopData(*owner_id); 
	}
};

// ���^�R���W�����N���X
// ���^�R���W�����N���X
// �v���[���^�R���W�����N���X

#endif