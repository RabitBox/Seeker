#include "DxRaps.h"

VECTOR VGetRap(const Vector3 &vectors)
{
	VECTOR v = VGet(vectors.x, vectors.y, vectors.z);
	return v;
}
VECTOR AVGetRap(const AVector3 &vectors)
{
	VECTOR v = VGet(vectors.x, vectors.y, vectors.z);
	return v;
}//*/

void DrawQuadPolygon(const Vector3 &c_pos,	// 中心座標
	const Vector3 &norm,					// 法線
	const int &graph_handle,				// 画像データ
	const int &trans_flag,					// 透明化ハンドル
	const Vector3 *vertex_pos)				// 配列で渡すため、やむなくconstポインタ
{
	WORD index[6] = { 0, 1, 2, 3, 2, 1 };		// インデックスの準備
	VERTEX3D vertex[4];							// バーテックスの準備

	for (int i = 0; i < 4; i++)
	{
		vertex[i].pos = VGetRap(vertex_pos[i]);
		vertex[i].norm = VGetRap(norm);
		vertex[i].dif = GetColorU8(255, 255, 255, 255);
		vertex[i].spc = GetColorU8(0, 0, 0, 0);
		vertex[i].u = 0.0f;
		vertex[i].v = 0.0f;
		vertex[i].su = 0.0f;
		vertex[i].sv = 0.0f;
	}
	DrawPolygonIndexed3D(vertex, 4, index, 2, graph_handle, trans_flag);
}

// 面がZ軸方向を-1で見ている場合の生成
void DrawQuadPolygon(const Vector3 &c_pos,	// 基点座標
	const AVector3 &c_rot,					// 基点回転
	const Vector3 &scl,						// サイズ
	const Vector3 &pos,						// 座標
	const AVector3 &rot,					// 回転
	const int &graph_handle,				// 画像データ
	const int &trans_flag)					// 透明化のハンドル
{
	WORD index[6] = { 0, 1, 2, 3, 2, 1 };		// インデックスの準備
	VERTEX3D vertex[4];							// バーテックスの準備
	Vector3 set_pos;							// 座標をセットするVector3を設定
	AVector3 total_rotation = c_rot + rot;		// 回転を合計した値
	Vector3 def_norm = {0.f, 0.f, -1.f};		// デフォルトの法線
	float h_x = scl.x / 2, h_y = scl.y / 2, h_z = scl.z / 2;

	Vector3 norm = MatrixRotationYPR(def_norm, { 0.0f, 0.0f, 0.0f }, total_rotation);

	// vertex[0]
	set_pos = MatrixRotationYPR({ -h_x, h_y, h_z }, pos, total_rotation) + c_pos;
	vertex[0].pos = VGetRap(set_pos);
	vertex[0].norm = VGetRap(norm.normalized());
	vertex[0].dif = GetColorU8(255, 255, 255, 255);
	vertex[0].spc = GetColorU8(0, 0, 0, 0);
	vertex[0].u = 0.0f;
	vertex[0].v = 0.0f;
	vertex[0].su = 0.0f;
	vertex[0].sv = 0.0f;

	// vertex[1]
	set_pos = MatrixRotationYPR({ h_x, h_y, h_z }, pos, total_rotation) + c_pos;
	vertex[1].pos = VGetRap(set_pos);
	vertex[1].norm = VGetRap(norm.normalized());
	vertex[1].dif = GetColorU8(255, 255, 255, 255);
	vertex[1].spc = GetColorU8(0, 0, 0, 0);
	vertex[1].u = 1.0f;
	vertex[1].v = 0.0f;
	vertex[1].su = 0.0f;
	vertex[1].sv = 0.0f;

	// vertex[2]
	set_pos = MatrixRotationYPR({ -h_x, -h_y, h_z }, pos, total_rotation) + c_pos;
	vertex[2].pos = VGetRap(set_pos);
	vertex[2].norm = VGetRap(norm.normalized());
	vertex[2].dif = GetColorU8(255, 255, 255, 255);
	vertex[2].spc = GetColorU8(0, 0, 0, 0);
	vertex[2].u = 0.0f;
	vertex[2].v = 1.0f;
	vertex[2].su = 0.0f;
	vertex[2].sv = 0.0f;

	// vertex[3]
	set_pos = MatrixRotationYPR({ h_x, -h_y, h_z }, pos, total_rotation) + c_pos;
	vertex[3].pos = VGetRap(set_pos);
	vertex[3].norm = VGetRap(norm.normalized());
	vertex[3].dif = GetColorU8(255, 255, 255, 255);
	vertex[3].spc = GetColorU8(0, 0, 0, 0);
	vertex[3].u = 1.0f;
	vertex[3].v = 1.0f;
	vertex[3].su = 0.0f;
	vertex[3].sv = 0.0f;

	DrawPolygonIndexed3D(vertex, 4, index, 2, graph_handle, trans_flag);
}

/*void DrawQuad(const Vector3 &c_pos,	// 基点座標
	const AVector3 &c_rot,			// 基点回転
	const Vector3 &scl,				// サイズ
	const Vector3 &pos,				// 座標
	const AVector3 &rot,			// 回転
	const int &graph_handle,		// 画像データ
	const int &trans_flag)			// 透明化のハンドル
{
	WORD index[6] = { 0, 1, 2, 3, 2, 1 };		// インデックスの準備
	VERTEX3D vertex[4];							// バーテックスの準備

	// vertex[]


	// vertex[1]

	
	// vertex[2]


	// vertex[3]


	DrawPolygonIndexed3D(vertex, 4, index, 2, graph_handle, trans_flag);
}//*/

void DrawGraphExtend(int x, int y, float ext, const int &graph_handle, const int &trans_flag)
{
	int SizeX, SizeY;
	GetGraphSize(graph_handle, &SizeX, &SizeY);
	SizeX = (int)((SizeX/2) * ext);
	SizeY = (int)((SizeY/2) * ext);
	DrawExtendGraph((x - SizeX), (y - SizeY), (x + SizeX), (y + SizeY), graph_handle, trans_flag);
}
