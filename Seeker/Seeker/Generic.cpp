#include <math.h>
#include "Generic.h"

//--------------------------------------------------
// [name]
//	ContinueMult()
// [action]
//	valueに入れられた配列データを連続で掛け算を行う
// [argument]
//	T*	value	: なにかしらの型の配列
template<typename T>
T ContinueMult(const T* value)
{
	T ret_val;
	for (int i = 0; i < sizeof(value) / sizeof(value[0]); i++)
	{
		if (i = 0) ret_val = value[i];
		else ret_val * value[i];
	}
	return ret_val;
}

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

//--------------------------------------------------
// [name]
//	MatrixRotationYaw()
// [action]
//	Yaw  (Y軸)回転
// [argument]
//	Vector3	 this_position	 : {0, 0, 0} を中心と仮定した座標
//	Vector3	 center_position : 中心の座標
//	AVector3 rotation		 : 回転量
Vector3 MatrixRotationYaw(const Vector3 &this_position, const Vector3 &center_position, const AVector3 &rotation)
{
	float radian_y_rotation = (rotation.y * DegtoRad);
	float x_1 = (float)((this_position.x) * ( cos(radian_y_rotation)));
	float x_2 = (float)((this_position.z) * ( sin(radian_y_rotation)));
	float z_1 = (float)((this_position.x) * (-sin(radian_y_rotation)));
	float z_2 = (float)((this_position.z) * ( cos(radian_y_rotation)));
	float x = x_1 + x_2;
	float y = this_position.y;
	float z = z_1 + z_2;
	Vector3 result_position = {x, y, z};
	return (result_position + center_position);
}

//--------------------------------------------------
// [name]
//	MatrixRotationPitch()
// [action]
//	Pitch (X軸)回転
// [argument]
//	Vector3	 this_position	 : {0, 0, 0} を中心と仮定した座標
//	Vector3	 center_position : 中心の座標
//	AVector3 rotation		 : 回転量
Vector3 MatrixRotationPitch(const Vector3 &this_position, const Vector3 &center_position, const AVector3 &rotation)
{
	float radian_x_rotation = (rotation.x * DegtoRad);
	float y_1 = (float)((this_position.y) * ( cos(radian_x_rotation)));
	float y_2 = (float)((this_position.z) * (-sin(radian_x_rotation)));
	float z_1 = (float)((this_position.y) * ( sin(radian_x_rotation)));
	float z_2 = (float)((this_position.z) * ( cos(radian_x_rotation)));
	float x = this_position.x;
	float y = y_1 + y_2;
	float z = z_1 + z_2;
	Vector3 result_position = { x, y, z };
	return (result_position + center_position);
}

//--------------------------------------------------
// [name]
//	MatrixRotationRoll()
// [action]
//	Roll (Z軸)回転
// [argument]
//	Vector3	 this_position	 : {0, 0, 0} を中心と仮定した座標
//	Vector3	 center_position : 中心の座標
//	AVector3 rotation		 : 回転量
Vector3 MatrixRotationRoll(const Vector3 &this_position, const Vector3 &center_position, const AVector3 &rotation)
{
	float radian_z_rotation = (rotation.z * DegtoRad);
	float x_1 = (float)((this_position.x) * ( cos(radian_z_rotation)));
	float x_2 = (float)((this_position.y) * (-sin(radian_z_rotation)));
	float y_1 = (float)((this_position.x) * ( sin(radian_z_rotation)));
	float y_2 = (float)((this_position.y) * ( cos(radian_z_rotation)));
	float x = x_1 + x_2;
	float y = y_1 + y_2;
	float z = this_position.z;
	Vector3 result_position = { x, y, z };
	return (result_position + center_position);
}

//--------------------------------------------------
// [name]
//	MatrixRotation3D()
// [action]
//	X,Y,Z軸の回転
// [argument]
//	Vector3	 this_position	 : {0, 0, 0} を中心と仮定した座標
//	Vector3	 center_position : 中心の座標
//	AVector3 rotation		 : 回転量
Vector3 MatrixRotation3D(const Vector3 &this_position, const Vector3 &center_position, const AVector3 &rotation)
{
	Vector3 radian = { rotation.x * DegtoRad, rotation.y * DegtoRad, rotation.z * DegtoRad };	// 角度をラジアンに変換
	
	// X'の要素
	float x_1 = (float)(this_position.x * ((cos(radian.x) * cos(radian.y) * cos(radian.z)) - (sin(radian.x) * sin(radian.z))));
	float x_2 = (float)(this_position.y * (-(cos(radian.x) * cos(radian.y) * sin(radian.z)) - (sin(radian.x) * cos(radian.z))));
	float x_3 = (float)(this_position.z * (cos(radian.x) * sin(radian.y)));
	
	// Y'の要素
	float y_1 = (float)(this_position.x * ((sin(radian.x) * cos(radian.y) * cos(radian.z)) + (cos(radian.x) * sin(radian.z))));
	float y_2 = (float)(this_position.y * (-(sin(radian.x) * cos(radian.y) * sin(radian.z)) + (cos(radian.x) * cos(radian.z))));
	float y_3 = (float)(this_position.z * (sin(radian.x) * sin(radian.y)));
	
	// Z'の要素
	float z_1 = (float)(this_position.x * -(sin(radian.y) * cos(radian.z)));
	float z_2 = (float)(this_position.y *  (sin(radian.y) * sin(radian.z)));
	float z_3 = (float)(this_position.z *  (cos(radian.y)));
	
	float x = (float)(x_1 + x_2 + x_3);	// X'
	float y = (float)(y_1 + y_2 + y_3);	// Y'
	float z = (float)(z_1 + z_2 + z_3);	// Z'
	Vector3 pos = { x, y, z };
	return (pos + center_position);
}

//--------------------------------------------------
// [name]
//	MatrixRotationYPR()
// [action]
//	Yaw, Pitch, Rollの順で回転する
// [argument]
//	Vector3	 this_position	 : {0, 0, 0} を中心と仮定した
//	Vector3	 center_position : 中心の座標
//	AVector3 rotation		 : 回転量
/*Vector3 MatrixRotationYPR(const Vector3 &this_position, const Vector3 &center_position, const AVector3 &rotation)
{
	Vector3 result_position = this_position;
	result_position = MatrixRotationYaw(result_position, { 0.f, 0.f, 0.f }, rotation);		// { 0.f, 0.f, 0.f }でcenter_positionによるズレを防止
	result_position = MatrixRotationPitch(result_position, { 0.f, 0.f, 0.f }, rotation);	// { 0.f, 0.f, 0.f }でcenter_positionによるズレを防止
	result_position = MatrixRotationRoll(result_position, center_position, rotation);		// ここで初めてcenter_positionを使用
	return result_position;
}//*/