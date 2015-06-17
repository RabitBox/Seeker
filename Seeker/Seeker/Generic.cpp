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
//	MatrixRotationYPR()
// [action]
//	Yaw, Pitch, Rollで回転する
// [argument]
//	Vector3	 this_position	 : {0, 0, 0} を中心と仮定した
//	Vector3	 center_position : 中心の座標
//	AVector3 rotation		 : 回転量
Vector3 MatrixRotationYPR(const Vector3 &this_position, const Vector3 &center_position, const AVector3 &rotation)
{
	Vector3 result = this_position;
	result = MatrixRotationRoll(result, { 0.f, 0.f, 0.f }, rotation);
	result = MatrixRotationPitch(result, { 0.f, 0.f, 0.f }, rotation);
	result = MatrixRotationYaw(result, { 0.f, 0.f, 0.f }, rotation);
	return (result + center_position);

	/*float Yaw = (rotation.x * DegtoRad);	// ロール ψ
	float Pitch = (rotation.y * DegtoRad);	// ピッチ θ
	float Roll = (rotation.z * DegtoRad);	// ヨー   φ

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
	//メッセージループです。
	DWORD up_time = timeGetTime();	//前回更新時間
	const int kFPS = 1000 / 60;		//希望FPS（ミリ秒に変換しています）
	do
	{
		//ここはWINイベント
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			DispatchMessage(&msg);
		}
		//FPSの時間が来ているかな？
		else if (up_time + kFPS <= timeGetTime())
		{
			//次の更新時間設定
			up_time += kFPS;
			//ここが更新ゾーンです
		}
	}
}//*/