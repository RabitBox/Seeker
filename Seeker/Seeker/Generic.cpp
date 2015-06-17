#include <vector>
#include <windows.h>
#include <math.h>
#include <iostream>
#include "Generic.h"
#include "Dxlib.h"

template<typename T>
void DeleteElements(std::vector<T*>* vct)
{
	for (auto &var : *vct)
	{
		delete var;
	}
	*vct->clear();
}

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
	Vector3 result = this_position;
	result = MatrixRotationRoll(result, { 0.f, 0.f, 0.f }, rotation);
	result = MatrixRotationPitch(result, { 0.f, 0.f, 0.f }, rotation);
	result = MatrixRotationYaw(result, { 0.f, 0.f, 0.f }, rotation);
	return (result + center_position);

	/*float Yaw = (rotation.x * DegtoRad);	// ���[�� ��
	float Pitch = (rotation.y * DegtoRad);	// �s�b�` ��
	float Roll = (rotation.z * DegtoRad);	// ���[   ��

	float x_1 = (float)((cos(Roll) * cos(Pitch))) * this_position.x;
	float x_2 = (float)((cos(Roll) * sin(Pitch) * sin(Yaw)) - (sin(Roll) * cos(Yaw))) * this_position.y;
	float x_3 = (float)((cos(Roll) * sin(Pitch) * cos(Yaw)) + (sin(Roll) * sin(Yaw))) * this_position.z;
	//DrawFormatString(0, 60, GetColor(255, 255, 255), "1:%f      2:%f      3:%f", x_1, x_2, x_3);

	float y_1 = (float)((sin(Roll) * cos(Pitch))) * this_position.x;
	float y_2 = (float)((sin(Roll) * sin(Pitch) * sin(Yaw)) + (cos(Roll) * cos(Yaw))) * this_position.y;
	float y_3 = (float)((sin(Roll) * sin(Pitch) * cos(Yaw)) - (cos(Roll) * sin(Yaw))) * this_position.z;
	//DrawFormatString(0, 75, GetColor(255, 255, 255), "1:%f      2:%f      3:%f", y_1, y_2, y_3);

	float z_1 = (float)(-(sin(Pitch))) * this_position.x;
	float z_2 = (float)((cos(Pitch) * sin(Yaw))) * this_position.y;
	float z_3 = (float)((cos(Pitch) * sin(Yaw))) * this_position.z;
	//DrawFormatString(0, 90, GetColor(255, 255, 255), "1:%f      2:%f      3:%f", z_1, z_2, z_3);

	float x = (x_1 + x_2 + x_3);
	float y = (y_1 + y_2 + y_3);
	float z = (z_1 + z_2 + z_3);

	Vector3 result = { x, y, z };

	return result;//*/
}

/*void FPSSet()
{
	//���b�Z�[�W���[�v�ł��B
	DWORD up_time = timeGetTime();	//�O��X�V����
	const int kFPS = 1000 / 60;		//��]FPS�i�~���b�ɕϊ����Ă��܂��j
	do
	{
		//������WIN�C�x���g
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			DispatchMessage(&msg);
		}
		//FPS�̎��Ԃ����Ă��邩�ȁH
		else if (up_time + kFPS <= timeGetTime())
		{
			//���̍X�V���Ԑݒ�
			up_time += kFPS;
			//�������X�V�]�[���ł�
		}
	}
}//*/