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
	vector<Shape**> collisions;	// 各クラスのコリジョンデータ(へのポインタ)を格納する
	//CollisionChecker* checker[Shape::ALL_TYPE_NUM][Shape::ALL_TYPE_NUM];	// チェッカークラス

public:
	void PushData(Shape* _shape){ collisions.push_back(&_shape); }	// 
	void PopData(int _id);

	bool Check(bool _trigger, int _owner_id)
	{
		// 所有者IDと合致するコリジョンを検索するためのループを回す
		for (auto &var1 : collisions)
		{
			// ここで検索
			if ((*var1)->GetID() == _owner_id)
			{
				// 次にそれ以外のコリジョンとの判定を調べる
				for (auto &var2 : collisions)
				{
					// 求めているトリガーが適応しているか否かを調べる (否ならなら以下処理を無視)
					if ((*var2)->GetTrigger != _trigger) continue;
					
					// オーナーIDが同じなら次に回す (同じなら以下処理を無視)
					if ((*var1)->GetID() == (*var2)->GetID()) continue;
					
					// ここから衝突検査 (一つでもかかったら即終了)
					if (Rect_Rect(*var1, *var2)) return true;
				}
			}
		}
		
		return false;
	}

public:
	// テスト運用
	bool Rect_Rect(Shape* _rect1, Shape* _rect2)
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

#endif