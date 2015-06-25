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
	vector<Shape*> collisions;	// 各クラスのコリジョンデータを格納する
	//CollisionChecker* checker[Shape::ALL_TYPE_NUM][Shape::ALL_TYPE_NUM];	// チェッカークラス

public:
	void PushData(Shape* _shape){ collisions.push_back(_shape); }	// 
	void PopData(int _id);
	void Clear();

	bool Check(bool _trigger, int _owner_id)
	{
		// コリジョンが無ければ即抜ける
		if (collisions.empty()) return false;

		// 所有者IDと合致するコリジョンを検索するためのループを回す
		for (auto &var1 : collisions)
		{
			// ここで検索
			if ((var1)->GetID() == _owner_id)
			{
				// 次にそれ以外のコリジョンとの判定を調べる
				for (auto &var2 : collisions)
				{
					// 求めているトリガーが適応しているか否かを調べる (否ならなら以下処理を無視)
					if ((var2)->GetTrigger() != _trigger) continue;
					
					// オーナーIDが同じなら次に回す (同じなら以下処理を無視)
					if ((var1)->GetID() == (var2)->GetID()) continue;
					
					// ここから衝突検査 (一つでもかかったら即終了)
					if (Rect_Rect(var1, var2) == true ) return true;
				}
			}
		}
		
		return false;
	}

public:
	// テスト運用
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