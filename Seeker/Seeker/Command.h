// コマンドを受け付けるクラス
// 入力をするクラスは別にある
#pragma once
#define HISTRY_LENGTH	30

class Command
{
public:
	enum Direction : int
	{
		NONE	= 0,	// 初期:ニュートラル
		UP		= 2,	// 上
		DOWN	= 4,	// 下
		LEFT	= 8,	// 左
		RIGHT	= 16,	// 右
	};
	// コマンドデータ
	struct Data
	{
		int		length;				// コマンドの長さ
		int		limit;				// コマンドの受付リミット
		int*	input = nullptr;	// コマンドの内容
	};

private:
	int		index;					// 入力されたコマンドを入れる配列のインデックス
	int		histry[HISTRY_LENGTH];	// コマンド履歴 (30個まで記憶可能)
	Data*	data = nullptr;			// コマンドの種類 (配列で記憶するが、要素数は後で決める為ポインタで)

public:
	Command(){}
	Command(int _data_length);
	~Command(){}

public:
	void Set(int, int, int, int[]);
	void Input(bool, bool, bool, bool);
	int  Check();
};