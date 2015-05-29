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
	AVector3 total_rotation = c_rot + rot;		// 回転を合計した値
	Vector3 def_norm = {0.f, 0.f, -1.f};		// デフォルトの法線
	float h_x = scl.x / 2, h_y = scl.y / 2, h_z = scl.z / 2;

	Vector3 norm = MatrixRotation3D(def_norm, { 0.0f, 0.0f, 0.0f }, {180.f,0.f,0.f});// total_rotation);
	DrawFormatString(0, 60, GetColor(255, 255, 255), "x:%f y:%f z:%f", norm.x, norm.y, norm.z);
	//DrawFormatString(0, 60, GetColor(255, 255, 255), "x:%f y:%f z:%f", total_rotation.x, total_rotation.y, total_rotation.z);

	Vector3 set_pos = MatrixRotation3D({ -h_x, h_y, h_z }, c_pos, total_rotation);
	//DrawFormatString(0, 60, GetColor(255, 255, 255), "x:%f y:%f z:%f", set_pos.x, set_pos.y, set_pos.z);
	vertex[0].pos = VGetRap(set_pos);
	vertex[0].norm = VGetRap(norm.normalized());
	vertex[0].dif = GetColorU8(255, 255, 255, 255);
	vertex[0].spc = GetColorU8(0, 0, 0, 0);
	vertex[0].u = 0.0f;
	vertex[0].v = 0.0f;
	vertex[0].su = 0.0f;
	vertex[0].sv = 0.0f;
	//DrawFormatString(0, 60, GetColor(255, 255, 255), "x:%f y:%f z:%f", set_pos.x, set_pos.y, set_pos.z);

	set_pos = MatrixRotation3D({ h_x, h_y, h_z }, c_pos, total_rotation);
	//DrawFormatString(0, 60, GetColor(255, 255, 255), "x:%f y:%f z:%f", set_pos.x, set_pos.y, set_pos.z);
	vertex[1].pos = VGetRap(set_pos);
	vertex[1].norm = VGetRap(norm.normalized());
	vertex[1].dif = GetColorU8(255, 255, 255, 255);
	vertex[1].spc = GetColorU8(0, 0, 0, 0);
	vertex[1].u = 1.0f;
	vertex[1].v = 0.0f;
	vertex[1].su = 0.0f;
	vertex[1].sv = 0.0f;
	//DrawFormatString(0, 75, GetColor(255, 255, 255), "x:%f y:%f z:%f", set_pos.x, set_pos.y, set_pos.z);

	set_pos = MatrixRotation3D({ -h_x, -h_y, h_z }, c_pos, total_rotation);
	//DrawFormatString(0, 60, GetColor(255, 255, 255), "x:%f y:%f z:%f", set_pos.x, set_pos.y, set_pos.z);
	vertex[2].pos = VGetRap(set_pos);
	vertex[2].norm = VGetRap(norm.normalized());
	vertex[2].dif = GetColorU8(255, 255, 255, 255);
	vertex[2].spc = GetColorU8(0, 0, 0, 0);
	vertex[2].u = 0.0f;
	vertex[2].v = 1.0f;
	vertex[2].su = 0.0f;
	vertex[2].sv = 0.0f;
	//DrawFormatString(0, 90, GetColor(255, 255, 255), "x:%f y:%f z:%f", set_pos.x, set_pos.y, set_pos.z);

	set_pos = MatrixRotation3D({ h_x, -h_y, h_z }, c_pos, total_rotation);
	//DrawFormatString(0, 60, GetColor(255, 255, 255), "x:%f y:%f z:%f", set_pos.x, set_pos.y, set_pos.z);
	vertex[3].pos = VGetRap(set_pos);
	vertex[3].norm = VGetRap(norm.normalized());
	vertex[3].dif = GetColorU8(255, 255, 255, 255);
	vertex[3].spc = GetColorU8(0, 0, 0, 0);
	vertex[3].u = 1.0f;
	vertex[3].v = 1.0f;
	vertex[3].su = 0.0f;
	vertex[3].sv = 0.0f;
	//DrawFormatString(0, 105, GetColor(255, 255, 255), "x:%f y:%f z:%f", set_pos.x, set_pos.y, set_pos.z);

	DrawPolygonIndexed3D(vertex, 4, index, 2, graph_handle, trans_flag);
}

void DrawQuad(const Vector3 &c_pos,	// 基点座標
	const AVector3 &c_rot,			// 基点回転
	const Vector3 &scl,				// サイズ
	const Vector3 &pos,				// 座標
	const AVector3 &rot,			// 回転
	const int &graph_handle,		// 画像データ
	const int &trans_flag)			// 透明化のハンドル
{
	WORD index[6] = { 0, 1, 2, 3, 2, 1 };		// インデックスの準備
	VERTEX3D vertex[4];							// バーテックスの準備

	// vertex[0]


	// vertex[1]

	
	// vertex[2]


	// vertex[3]


	DrawPolygonIndexed3D(vertex, 4, index, 2, graph_handle, trans_flag);
}