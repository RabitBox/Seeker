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
	//��]���Ă��璆�����W��K�p���ăo�[�e�b�N�X�ɓK�p����
	float x = scale.x, y = scale.y, z = scale.z;
	WORD index[6] = { 0, 1, 2, 3, 2, 1 };
	//DrawPolygonIndexed3D(vertex, 4, index, 2, graph_handle, trans_flag);
	return;
}