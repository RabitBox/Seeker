#ifndef _COLLISION_MANAGER_
#define _COLLISION_MANAGER_

#include <vector>
#include "CollisionShapes.h"
#include "CollisionCheckers.h"
using namespace std;

class CollisionManager
{
private:
	static CollisionManager* collision_manager;
	CollisionManager(){}
	~CollisionManager(){}

public:
	static CollisionManager* GetInstance(){ return collision_manager; }
	static void Create(){ collision_manager = new CollisionManager(); }
	static void Destroy(){ delete collision_manager; collision_manager = nullptr; }

private:
	vector<Shape*> collisions;	// �e�N���X�̃R���W�����f�[�^���i�[����
	//CollisionChecker* checker[Shape::ALL_TYPE_NUM][Shape::ALL_TYPE_NUM];	// �`�F�b�J�[�N���X

public:
	void PushData(Shape* _shape){ collisions.push_back(_shape); }	// 
	void PopData(int _id);
	void Clear();

	bool Check(bool _trigger, int _owner_id)
	{
		// �R���W������������Α�������
		if (collisions.empty()) return false;

		// ���L��ID�ƍ��v����R���W�������������邽�߂̃��[�v����
		for (auto &var1 : collisions)
		{
			// �����Ō���
			if ((var1)->GetID() == _owner_id)
			{
				// ���ɂ���ȊO�̃R���W�����Ƃ̔���𒲂ׂ�
				for (auto &var2 : collisions)
				{
					// ���߂Ă���g���K�[���K�����Ă��邩�ۂ��𒲂ׂ� (�ۂȂ�Ȃ�ȉ������𖳎�)
					if ((var2)->GetTrigger() != _trigger) continue;
					
					// �I�[�i�[ID�������Ȃ玟�ɉ� (�����Ȃ�ȉ������𖳎�)
					if ((var1)->GetID() == (var2)->GetID()) continue;
					
					// ��������Փˌ��� (��ł����������瑦�I��)
					if (Rect_Rect(var1, var2) == true ) return true;
				}
			}
		}
		
		return false;
	}

public:
	// �e�X�g�^�p
	bool Rect_Rect(Shape* _rect1, Shape* _rect2)
	{
		float Ax = _rect1->GetPosition().x - _rect1->GetScale().x;
		float Ay = _rect1->GetPosition().y - _rect1->GetScale().y;
		float AX = _rect1->GetPosition().x + _rect1->GetScale().x;
		float AY = _rect1->GetPosition().y + _rect1->GetScale().y;

		float Bx = _rect2->GetPosition().x - _rect2->GetScale().x;
		float By = _rect2->GetPosition().y - _rect2->GetScale().y;
		float BX = _rect2->GetPosition().x + _rect2->GetScale().x;
		float BY = _rect2->GetPosition().y + _rect2->GetScale().y;

		if ((AX < Bx) || (Ax > BX) || (AY < By) || (Ay > BY)) return false;
		return true;
	}
};

#endif