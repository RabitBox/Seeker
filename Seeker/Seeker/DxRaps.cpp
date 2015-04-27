#include "DxRaps.h"

VECTOR VGetRap(const Vector3 &vectors)
{
	return VGet(vectors.x, vectors.y, vectors.z);
}
VECTOR AVGetRap(const AVector3 &vectors)
{
	return VGet(vectors.x, vectors.y, vectors.z);
}

void DrawQuadPolygon(Vector3 scale, Vector3 position, int graph_handle, int trans_flag)
{
	//DrawPolygonIndexed3D(vertex, 4, index, 2, graph_handle, trans_flag);
	return;
}