//----------------------------------------------------------------------
// TinyTimクラス
// 本作品の主人公
// 元ネタは海外実況者 "Markiplier" の動画から
//----------------------------------------------------------------------
#pragma once
#include "Objects.h"
#include "AnimationData.h"

class TinyTim : public Acter
{
private:
	enum State
	{
		Stand,	// 立ち
		Walk,	// 歩き
		Run,	// 走り
		Jump,	// ジャンプ
		Land,	// 着地
		Roll,	// ローリング
	};

	int						test_loaded[37];
	State					state;
	vector<int*>			images;
	vector<Animation>	anim_data;
	

public:
	TinyTim();
	TinyTim(float x, float y);
	TinyTim(float x, float y, float z);
	TinyTim(Vector3 _positon);
	virtual ~TinyTim();

	void Update() override;
	void Draw() override;

private:
	//void Walk();	// 歩く
	//void Run();	// 走る
	//void Jump();	// ジャンプ
	//void Land();	// 着地
	//void Roll();	// ローリング

private:
	void LoadTexture() override;
	void AnimationSet();
	void Default();
};