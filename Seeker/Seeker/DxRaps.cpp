#include "DxRaps.h"

VECTOR VGetRap(const Vector3 &vectors)
{
	return VGet(vectors.x, vectors.y, vectors.z);
}
VECTOR AVGetRap(const AVector3 &vectors)
{
	return VGet(vectors.x, vectors.y, vectors.z);
}