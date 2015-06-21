// �Փ˔�����s���N���X�Q
// ����͂܂��������ł���
#ifndef _COLLISION_CHECKER_
#define _COLLISION_CHECKER_

#include "CollisionShapes.h"

// �R���W�����`�F�b�J�[�N���X(�x�[�X)
class CollisionChecker{
public:
	virtual ~CollisionChecker(){}							// �f�X�g���N�^(virtual)
	virtual bool Check(Shape* s1, Shape* s2) = 0;	// ����(pure virtual)
};

// ��`�Ƌ�`�̃R���W�����`�F�b�J�[�N���X
class Rect_Rect : public CollisionChecker
{
public:
	Rect_Rect(){}
	~Rect_Rect(){}
	bool Check(Shape* _rect1, Shape* _rect2) override
	{
		float x0 = _rect1->GetPosition().x - _rect1->GetScale().x;
		float y0 = _rect1->GetPosition().x + _rect1->GetScale().x;
		float x1 = _rect1->GetPosition().y - _rect1->GetScale().y;
		float y1 = _rect1->GetPosition().y + _rect1->GetScale().y;

		float x2 = _rect2->GetPosition().x - _rect2->GetScale().x;
		float y2 = _rect2->GetPosition().x + _rect2->GetScale().x;
		float x3 = _rect2->GetPosition().y - _rect2->GetScale().y;
		float y3 = _rect2->GetPosition().y + _rect2->GetScale().y;

		if (x0 < x3 && x2 < x1 && y0 < y3 && y2 < y1)
		{
			return true;
		}
		return false;
	}
};

// ��`�Ɖ~�̃R���W�����`�F�b�J�[�N���X
class Rect_Circle : public CollisionChecker
{
public:
	Rect_Circle(){}
	~Rect_Circle(){}
	bool Check(Shape* s1, Shape* s2) override
	{
		return false;
	}
};

// �~�Ɖ~�̃R���W�����`�F�b�J�[�N���X
class Circle_Circle : public CollisionChecker
{
public:
	Circle_Circle(){}
	~Circle_Circle(){}
	bool Check(Shape* s1, Shape* s2) override
	{
		return false;
	}
};

#endif