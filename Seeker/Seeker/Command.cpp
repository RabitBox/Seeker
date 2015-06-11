#include "Command.h"

Command::Command(int _data_length) : index(0)
{
	for (int i = 0; i < HISTRY_LENGTH; i++){ histry[i] = Direction::NONE; }
	data = new Data[_data_length];
}

//--------------------------------------------------
// 使うコマンドを設定
void Command::Set(int _index, int _length, int _limit, int _input[])
{
	data[_index].length = _length;			// コマンドの長さを指定
	data[_index].limit = _limit;			// コマンド受付時間を指定
	data[_index].input = new int[_length];	// コマンドを入れる配列を初期化
	for (int i = 0; i < _length; i++)
	{
		data[_index].input[i] = _input[i];	// コマンドを登録
	}
}

//--------------------------------------------------
// histry[] に入力情報を入れる
void Command::Input(bool _up, bool _down, bool _left, bool _right)
{
	histry[index] = (_up ? UP : NONE) |
		(_down ? DOWN : NONE) |
		(_left ? LEFT : NONE) |
		(_right ? RIGHT : NONE);
}

//--------------------------------------------------
// コマンドをチェック
int Command::Check()
{
	// for文で使う変数をfor文を使う前に宣言する
	int c, j, i;

	// コマンドの種類だけfor文を回す
	for (c = 0; c < sizeof(data) / sizeof(data[0]); c++)
	{
		// iとjをここで初期化し、使えるようにする
		for (i = 0, j = data[c].length - 1; j >= 0; j--)
		{
			// i がリミットに達するか、コマンドが成立するまで回す
			for (; i < data[c].limit; i++)
			{
				// リミットの数まで histry[] 中を検索する
				if (histry[(index - i + HISTRY_LENGTH) % HISTRY_LENGTH] == data[c].input[j])
				{
					break;	// 検索がヒットしたら一度このfor文から抜ける
				}
			}
			// j が -1 にならず i がリミットに達した場合 (コマンド未成立)
			if (i == data[c].limit)
			{
				break;	// このfor文から抜ける
			}
		}
		// i がリミットに到達する前に j が -1 になった場合 (コマンド成立)
		if (j == -1)
		{
			// ヒストリーを初期化してから
			for (i = 0; i < HISTRY_LENGTH; i++)
			{
				histry[i] = Direction::NONE;
			}
			break;	// for文を抜ける
		}
	}

	// indexを次に進める
	index = (index + 1) % HISTRY_LENGTH;

	// コマンドが成立している場合
	// つまり c が data[] の要素数より小さい場合
	if (c < sizeof(data) / sizeof(data[0])) 
	{
		return c;	// c の値を返す
	}

	// コマンドが未成立の場合
	return -1;		// 不成立な値を返す
}