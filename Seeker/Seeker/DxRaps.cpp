#include "DxRaps.h"

VECTOR VGetRap(const Vector3 &vectors)
{
	return VGet(vectors.x, vectors.y, vectors.z);
}
VECTOR AVGetRap(const AVector3 &vectors)
{
	return VGet(vectors.x, vectors.y, vectors.z);
}

void DrawQuadPolygon(Vector3 scale, Vector3 position, AVector3 rotation, int graph_handle, int trans_flag)
{
	//回転してから中央座標を適用してバーテックスに適用する
	float x = scale.x, y = scale.y, z = scale.z;
	WORD index[6] = { 0, 1, 2, 3, 2, 1 };
	//DrawPolygonIndexed3D(vertex, 4, index, 2, graph_handle, trans_flag);
	return;
}