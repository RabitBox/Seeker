#include <math.h>
#include <iostream>
#include "Generic.h"

//--------------------------------------------------
// [name]
//	ContinueMult()
// [action]
//	value�ɓ����ꂽ�z��f�[�^��A���Ŋ|���Z���s��
// [argument]
//	T*	value	: �Ȃɂ�����̌^�̔z��
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

//--------------------------------------------------
// [name]
//	MatrixRotationYaw()
// [action]
//	Yaw  (Y��)��]
// [argument]
//	Vector3	 this_position	 : {0, 0, 0} �𒆐S�Ɖ��肵�����W
//	Vector3	 center_position : ���S�̍��W
//	AVector3 rotation		 : ��]��
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
//	Pitch (X��)��]
// [argument]
//	Vector3	 this_position	 : {0, 0, 0} �𒆐S�Ɖ��肵�����W
//	Vector3	 center_position : ���S�̍��W
//	AVector3 rotation		 : ��]��
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
//	Roll (Z��)��]
// [argument]
//	Vector3	 this_position	 : {0, 0, 0} �𒆐S�Ɖ��肵�����W
//	Vector3	 center_position : ���S�̍��W
//	AVector3 rotation		 : ��]��
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
//	MatrixRotationYPR()
// [action]
//	Yaw, Pitch, Roll�ŉ�]����
// [argument]
//	Vector3	 this_position	 : {0, 0, 0} �𒆐S�Ɖ��肵��
//	Vector3	 center_position : ���S�̍��W
//	AVector3 rotation		 : ��]��
Vector3 MatrixRotationYPR(const Vector3 &this_position, const Vector3 &center_position, const AVector3 &rotation)
{
	float Yaw = (rotation.x * DegtoRad);	// ���[�� ��
	float Pitch = (rotation.y * DegtoRad);	// �s�b�` ��
	float Roll = (rotation.z * DegtoRad);	// ���[   ��

	float x_1 = (float)((cos(Roll) * cos(Pitch))) * this_position.x;
	float x_2 = (float)((cos(Roll) * sin(Pitch) * sin(Yaw)) - (sin(Roll) * cos(Yaw))) * this_position.y;
	float x_3 = (float)((cos(Roll) * sin(Pitch) * cos(Yaw)) + (sin(Roll) * sin(Yaw))) * this_position.z;

	float y_1 = (float)((sin(Roll) * cos(Pitch))) * this_position.x;
	float y_2 = (float)((sin(Roll) * sin(Pitch) * sin(Yaw)) + (cos(Roll) * cos(Yaw))) * this_position.y;
	float y_3 = (float)((sin(Roll) * sin(Pitch) * cos(Yaw)) - (cos(Roll) * sin(Yaw))) * this_position.z;

	float z_1 = (float)(-(sin(Pitch))) * this_position.x;
	float z_2 = (float)((cos(Pitch) * sin(Yaw))) * this_position.y;
	float z_3 = (float)((cos(Pitch) * sin(Yaw))) * this_position.z;

	float x = (x_1 + x_2 + x_3);
	float y = (y_1 + y_2 + y_3);
	float z = (z_1 + z_2 + z_3);

	Vector3 result = { x, y, z };

	return (result + center_position);
}

//--------------------------------------------------
// [name]
//	MatrixRotation3D()
// [action]
//	X,Y,Z���̉�]
// [argument]
//	Vector3	 this_position	 : {0, 0, 0} �𒆐S�Ɖ��肵�����W
//	Vector3	 center_position : ���S�̍��W
//	AVector3 rotation		 : ��]��
/*Vector3 MatrixRotation3D(const Vector3 &this_position, const Vector3 &center_position, const AVector3 &rotation)
{
	float alp = rotation.y * DegtoRad;	// ��(X)
	float bet = rotation.x * DegtoRad;	// ��(Y)
	float gam = rotation.z * DegtoRad;	// ��(Z)

	// X'�̗v�f
	float x_1 = (float)((this_position.x) * ( (cos(alp) * cos(bet) * cos(gam)) - (sin(alp) * sin(gam))));
	float x_2 = (float)((this_position.y) * (-(cos(alp) * cos(bet) * sin(gam)) - (sin(alp) * cos(gam))));
	float x_3 = (float)((this_position.z) * ( (cos(alp) * sin(bet))));

	// Y'�̗v�f
	float y_1 = (float)((this_position.x) * ( (sin(alp) * cos(bet) * cos(gam)) + (cos(alp) * sin(gam))));
	float y_2 = (float)((this_position.y) * (-(sin(alp) * cos(bet) * sin(gam)) + (cos(alp) * cos(gam))));
	float y_3 = (float)((this_position.z) * ( (sin(alp) * sin(bet))));

	// Z'�̗v�f
	float z_1 = (float)((this_position.x) * (-(sin(bet) * cos(gam))));
	float z_2 = (float)((this_position.y) * ( (sin(bet) * sin(gam))));
	float z_3 = (float)((this_position.z) * ( (cos(bet))));

	float x = (float)(x_1 + x_2 + x_3);	// X'
	float y = (float)(y_1 + y_2 + y_3);	// Y'
	float z = (float)(z_1 + z_2 + z_3);	// Z'
	Vector3 pos = { x, y, z };
	return (pos + center_position);
}//*/

//--------------------------------------------------
// [name]
//	MatrixRotationYPR()
// [action]
//	Yaw, Pitch, Roll�̏��ŉ�]����
// [argument]
//	Vector3	 this_position	 : {0, 0, 0} �𒆐S�Ɖ��肵��
//	Vector3	 center_position : ���S�̍��W
//	AVector3 rotation		 : ��]��
/*Vector3 MatrixRotationYPR(const Vector3 &this_position, const Vector3 &center_position, const AVector3 &rotation)
{
	Vector3 result_position = this_position;
	result_position = MatrixRotationYaw(result_position, { 0.f, 0.f, 0.f }, rotation);		// { 0.f, 0.f, 0.f }��center_position�ɂ��Y����h�~
	result_position = MatrixRotationPitch(result_position, { 0.f, 0.f, 0.f }, rotation);	// { 0.f, 0.f, 0.f }��center_position�ɂ��Y����h�~
	result_position = MatrixRotationRoll(result_position, center_position, rotation);		// �����ŏ��߂�center_position���g�p
	return result_position;
}//*/
