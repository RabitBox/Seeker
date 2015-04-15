#include <math.h>
#include "Generic.h"

Vector3 Rotation3D(const Vector3 &this_position, const Vector3 &center_position, const AVector3 &rotation)
{
	float x_1 = (float)(this_position.x * ( (cos(rotation.x) * cos(rotation.y) * cos(rotation.z)) - (sin(rotation.x) * sin(rotation.z))));
	float x_2 = (float)(this_position.y * (-(cos(rotation.x) * cos(rotation.y) * sin(rotation.z)) - (sin(rotation.x) * cos(rotation.z))));
	float x_3 = (float)(this_position.z * (  cos(rotation.x) * sin(rotation.y)));
	float y_1 = (float)(this_position.x * ( (sin(rotation.x) * cos(rotation.y) * cos(rotation.z)) + (cos(rotation.x) * sin(rotation.z))));
	float y_2 = (float)(this_position.y * (-(sin(rotation.x) * cos(rotation.y) * sin(rotation.z)) + (cos(rotation.x) * cos(rotation.z))));
	float y_3 = (float)(this_position.z * (  sin(rotation.x) * sin(rotation.y)));
	float z_1 = (float)(this_position.x * -(sin(rotation.y) * cos(rotation.z)));
	float z_2 = (float)(this_position.y *  (sin(rotation.y) * sin(rotation.z)));
	float z_3 = (float)(this_position.z *  (cos(rotation.y)));
	float x = (float)(x_1 + x_2 + x_3);
	float y = (float)(y_1 + y_2 + y_3);
	float z = (float)(z_1 + z_2 + z_3);
	Vector3 pos = {x, y, z};
	return (pos + center_position);
}

// XŽ²‰ñ“]
Vector3 RotationAxisX(const Vector3 &this_position, const Vector3 &center_position, const AVector3 &rotation)
{
	float y_1 = (float)(this_position.y *  cos(rotation.x));
	float y_2 = (float)(this_position.z * -sin(rotation.x));
	float z_1 = (float)(this_position.y *  sin(rotation.x));
	float z_2 = (float)(this_position.z *  cos(rotation.x));
	float x = (float)(this_position.x);
	float y = (float)(y_1 + y_2);
	float z = (float)(z_1 + z_2);
	Vector3 pos = { x, y, z };
	return (pos + center_position);
}

// YŽ²‰ñ“]
Vector3 RotationAxisY(const Vector3 &this_position, const Vector3 &center_position, const AVector3 &rotation)
{
	float x_1 = (float)(this_position.x *  cos(rotation.y));
	float x_2 = (float)(this_position.z *  sin(rotation.y));
	float z_1 = (float)(this_position.x * -sin(rotation.y));
	float z_2 = (float)(this_position.z *  cos(rotation.y));
	float x = (float)(x_1 + x_2);
	float y = (float)(this_position.y);
	float z = (float)(z_1 + z_2);
	Vector3 pos = { x, y, z };
	return (pos + center_position);
}

// ZŽ²‰ñ“]
Vector3 RotationAxisZ(const Vector3 &this_position, const Vector3 &center_position, const AVector3 &rotation)
{
	float x_1 = (float)(this_position.x *  cos(rotation.z));
	float x_2 = (float)(this_position.y * -sin(rotation.z));
	float y_1 = (float)(this_position.x *  sin(rotation.z));
	float y_2 = (float)(this_position.y *  cos(rotation.z));
	float x = (float)(x_1 + x_2);
	float y = (float)(y_1 + y_2);
	float z = (float)(this_position.z);
	Vector3 pos = { x, y, z };
	return (pos + center_position);
}
