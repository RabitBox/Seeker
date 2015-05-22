//----------------------------------------------------------------------
// TinyTimクラス
// 本作品の主人公
// 元ネタは海外実況者 "Markiplier" の動画から
//----------------------------------------------------------------------
#pragma once
#include "Objects.h"


class TinyTim : public Acter
{
private:
	enum AnimState
	{
		Stand,	// 立ち
		Walk,	// 歩き
		Run,	// 走り
		Jump,	// ジャンプ
		Land,	// 着地
		Roll,	// ローリング
	};

	AnimState state;
	//vector<int> &images;
	

public:
	TinyTim();
	TinyTim(Vector3 _positon);
	virtual ~TinyTim();

	void Update() override;
	void Draw() override;

private:
	//void Walk();	// 歩く
	//void Run();		// 走る
	//void Jump();	// ジャンプ
	//void Land();	// 着地
	//void Roll();	// ローリング

	void DrawPolygon();

private:
	void LoadTexture() override;
};