//--------------------------------------------------
// 汎用コード集
// 2015/01/30
//--------------------------------------------------
// 冗長インクルードガード
#ifndef _THIRD_LIBS_
#define _THIRD_LIBS_
#include <stdint.h>
#include <vector>
#include <memory>
#include <math.h>
#endif

//#pragma once//インクルードガード
#ifndef _INCLUDE_GENERIC_
#define _INCLUDE_GENERIC_
//======================================================================//
// define
#define CALL_ONCE(func)					do{ static bool _Initialized = false; if (!_Initialized) { func; _Initialized = true; }while(0)
#define BETWEEN(setmin, setmax, value)	max(setmin, min(setmax, value))
#define ERR_CALL(str)					do{std::cerr << str << std::endl;}while(0)
#define PI								(3.141592f)		// π
#define RadtoDeg						(57.29577951f)	// radianからdegreeに 180 /  π
#define DegtoRad						(0.017453293f)	// degreeからradianに  π / 180
#define DegValue(val)					(val * RadtoDegVal)
#define RadValue(val)					(val * DegtoRadVal)
#define ArrayLength(val)				(sizeof(val) / sizeof(val[0]))

//======================================================================//
// Basic Classes
class Vector2
{
public:
	// variable
	float x;
	float y;

	// Constructor
	Vector2() : x(0.0f), y(0.0f){}
	Vector2(float X, float Y) : x(X), y(Y){}
	Vector2(const Vector2 &v) : x(v.x), y(v.y){}

	// Destructor
	virtual ~Vector2(){}

	// Operator
	Vector2& operator +=(const Vector2& v)	{ x += v.x; y += v.y; return *this; }
	Vector2& operator -=(const Vector2& v)	{ x -= v.x; y -= v.y; return *this; }
	Vector2& operator *=(const Vector2& v)	{ x *= v.x; y *= v.y; return *this; }
	Vector2& operator /=(const Vector2& v)	{ x /= v.x; y /= v.y; return *this; }
	Vector2& operator *=(const int n)		{ x *= n; y *= n; return *this; }
	Vector2& operator /=(const int n)		{ x /= n; y /= n; return *this; }
	Vector2& operator *=(const float f)		{ x *= f; y *= f; return *this; }
	Vector2& operator /=(const float f)		{ x /= f; y /= f; return *this; }
	Vector2& operator = (const Vector2& v)	{ x = v.x; y = v.y; return *this; }

	// friend function operator
	friend Vector2 operator +(const Vector2& v0, const Vector2& v1)	{ Vector2 V(v0.x + v1.x, v0.y + v1.y); return V; }
	friend Vector2 operator -(const Vector2& v0, const Vector2& v1)	{ Vector2 V(v0.x - v1.x, v0.y - v1.y); return V; }
	friend Vector2 operator *(const Vector2& v0, int n)				{ Vector2 V(v0.x * n, v0.y * n); return V; }
	friend Vector2 operator *(int n, const Vector2& v0)				{ Vector2 V(v0.x * n, v0.y * n); return V; }
	friend Vector2 operator *(const Vector2& v0, float f)			{ Vector2 V(v0.x * f, v0.y * f); return V; }
	friend Vector2 operator *(float f, const Vector2& v0)			{ Vector2 V(v0.x * f, v0.y * f); return V; }
	friend Vector2 operator /(const Vector2& v0, int n)				{ Vector2 V(v0.x / n, v0.y / n); return V; }
	friend Vector2 operator /(int n, const Vector2& v0)				{ Vector2 V(v0.x / n, v0.y / n); return V; }
	friend Vector2 operator /(const Vector2& v0, float f)			{ Vector2 V(v0.x / f, v0.y / f); return V; }
	friend Vector2 operator /(float f, const Vector2& v0)			{ Vector2 V(v0.x / f, v0.y / f); return V; }
};
class Vector3
{
public:
	// variable
	float x;
	float y;
	float z;

	// Constructor
	Vector3() :	 x(0.0f), y(0.0f), z(0.0f){}
	Vector3(float X, float Y) : x(X), y(Y), z(0.0f){}
	Vector3(float X, float Y, float Z) : x(X), y(Y), z(Z){}
	Vector3(const Vector3 &v) : x(v.x), y(v.y), z(v.z){}

	// Destructor
	virtual ~Vector3(){}

	// Operator
	Vector3& operator +=(const Vector3& v)	{ x += v.x; y += v.y; z += v.z; return *this; }
	Vector3& operator -=(const Vector3& v)	{ x -= v.x; y -= v.y; z -= v.z; return *this; }
	Vector3& operator *=(const Vector3& v)	{ x *= v.x; y *= v.y; z *= v.z; return *this; }
	Vector3& operator /=(const Vector3& v)	{ x /= v.x; y /= v.y; z /= v.z; return *this; }
	Vector3& operator *=(const int n)		{ x *= n; y *= n; z *= n; return *this; }
	Vector3& operator /=(const int n)		{ x /= n; y /= n; z /= n; return *this; }
	Vector3& operator *=(const float f)		{ x *= f; y *= f; z *= f; return *this; }
	Vector3& operator /=(const float f)		{ x /= f; y /= f; z /= f; return *this; }
	Vector3& operator = (const Vector3& v)	{ x = v.x; y = v.y; z = v.z; return *this; }

	// friend function
	friend Vector3 operator +(const Vector3& v0, const Vector3& v1)	{ Vector3 V(v0.x + v1.x, v0.y + v1.y, v0.z + v1.z); return V; }
	friend Vector3 operator -(const Vector3& v0, const Vector3& v1)	{ Vector3 V(v0.x - v1.x, v0.y - v1.y, v0.z - v1.z); return V; }
	friend Vector3 operator *(const Vector3& v0, int n)				{ Vector3 V(v0.x * n, v0.y * n, v0.z * n); return V; }
	friend Vector3 operator *(int n, const Vector3& v0)				{ Vector3 V(v0.x * n, v0.y * n, v0.z * n); return V; }
	friend Vector3 operator *(const Vector3& v0, float f)			{ Vector3 V(v0.x * f, v0.y * f, v0.z * f); return V; }
	friend Vector3 operator *(float f, const Vector3& v0)			{ Vector3 V(v0.x * f, v0.y * f, v0.z * f); return V; }
	friend Vector3 operator /(const Vector3& v0, int n)				{ Vector3 V(v0.x / n, v0.y / n, v0.z / n); return V; }
	friend Vector3 operator /(int n, const Vector3& v0)				{ Vector3 V(v0.x / n, v0.y / n, v0.z / n); return V; }
	friend Vector3 operator /(const Vector3& v0, float f)			{ Vector3 V(v0.x / f, v0.y / f, v0.z / f); return V; }
	friend Vector3 operator /(float f, const Vector3& v0)			{ Vector3 V(v0.x / f, v0.y / f, v0.z / f); return V; }

	// function
	Vector3 normalized()
	{
		float mag = 1 / norm3(); float _x = x * mag, _y = y * mag, _z = z * mag; return {_x, _y, _z};
	}

private:
	float norm3(){ return (float)std::sqrt((double)( x*x + y*y + z*z)); }
};
class AVector3
{
public:
	// variable
	float x;
	float y;
	float z;

	// Constructor
	AVector3() : x(0.0f), y(0.0f), z(0.0f){}
	AVector3(float X, float Y, float Z) : x(Compensate(X)), y(Compensate(Y)), z(Compensate(Z)){}
	AVector3(const AVector3 &v) : x(Compensate(v.x)), y(Compensate(v.y)), z(Compensate(v.z)){}
	AVector3(const Vector3 &v) : x(Compensate(v.x)), y(Compensate(v.y)), z(Compensate(v.z)){}

	// Destructor
	virtual ~AVector3(){}

	// Operator
	AVector3& operator +=(const AVector3& v)	{ x = Compensate(x + v.x); y = Compensate(y + v.y); z = Compensate(z + v.z); return *this; }
	AVector3& operator -=(const AVector3& v)	{ x = Compensate(x - v.x); y = Compensate(y - v.y); z = Compensate(z - v.z); return *this; }
	AVector3& operator *=(const AVector3& v)	{ x *= v.x; y *= v.y; z *= v.z; return *this; }
	AVector3& operator /=(const AVector3& v)	{ x /= v.x; y /= v.y; z /= v.z; return *this; }
	AVector3& operator *=(const int n)			{ x = Compensate((float)x * n); y = Compensate((float)y * n); z = Compensate((float)z * n); return *this; }
	AVector3& operator /=(const int n)			{ x = Compensate((float)x / n); y = Compensate((float)y / n); z = Compensate((float)z / n); return *this; }
	AVector3& operator *=(const float f)		{ x = Compensate(x * f); y = Compensate(y * f); z = Compensate(z * f); return *this; }
	AVector3& operator /=(const float f)		{ x = Compensate(x / f); y = Compensate(y / f); z = Compensate(z / f); return *this; }
	AVector3& operator = (const AVector3& v)	{ x = Compensate(v.x); y = Compensate(v.y); z = Compensate(v.z); return *this; }

	// friend function operator
	friend AVector3 operator +(const AVector3& v0, const AVector3& v1)	{ AVector3 V(Compensate(v0.x + v1.x), Compensate(v0.y + v1.y), Compensate(v0.z + v1.z)); return V; }
	friend AVector3 operator -(const AVector3& v0, const AVector3& v1)	{ AVector3 V(Compensate(v0.x - v1.x), Compensate(v0.y - v1.y), Compensate(v0.z - v1.z)); return V; }
	friend AVector3 operator *(const AVector3& v0, int n)				{ AVector3 V(Compensate(v0.x * n), Compensate(v0.y * n), Compensate(v0.z * n)); return V; }
	friend AVector3 operator *(int n, const AVector3& v0)				{ AVector3 V(Compensate(v0.x * n), Compensate(v0.y * n), Compensate(v0.z * n)); return V; }
	friend AVector3 operator *(const AVector3& v0, float f)				{ AVector3 V(Compensate(v0.x * f), Compensate(v0.y * f), Compensate(v0.z * f)); return V; }
	friend AVector3 operator *(float f, const AVector3& v0)				{ AVector3 V(Compensate(v0.x * f), Compensate(v0.y * f), Compensate(v0.z * f)); return V; }
	friend AVector3 operator /(const AVector3& v0, int n)				{ AVector3 V(Compensate(v0.x / n), Compensate(v0.y / n), Compensate(v0.z / n)); return V; }
	friend AVector3 operator /(int n, const AVector3& v0)				{ AVector3 V(Compensate(v0.x / n), Compensate(v0.y / n), Compensate(v0.z / n)); return V; }
	friend AVector3 operator /(const AVector3& v0, float f)				{ AVector3 V(Compensate(v0.x / f), Compensate(v0.y / f), Compensate(v0.z / f)); return V; }
	friend AVector3 operator /(float f, const AVector3& v0)				{ AVector3 V(Compensate(v0.x / f), Compensate(v0.y / f), Compensate(v0.z / f)); return V; }

private:
	// Function
	static float Compensate(float value){ if (value < 0.0f || value >= 360.0f) { value += (float)((value / 360.0f) * 360.0f); } return value; }
};
/*template<class T>class Singleton
{
	//http://cflat-inc.hatenablog.com/entry/2014/03/04/214608
};//*/

//======================================================================//
// Advance Classes
struct Transform
{
	Vector3		position;
	AVector3	rotation;
	Vector3		scale;
};
class Object
{
protected:
	// variable
	Transform transform;

public:
	// Destructor
	virtual ~Object(){}

	// function
	virtual void Update(){}
	virtual void Draw(){}

	Vector3 GetPos(){ return transform.position; }
};
class Particle
{
public:
	Vector3		position;	// 座標
	AVector3	rotation;	// 回転
	Vector3		scale;		// サイズ
	float		life_time;	// 生存時間

	virtual void Update() = 0;
	virtual void Draw() = 0;
};
struct Emitter
{
	Vector3		start_position;		// 初期座標
	AVector3	start_rotation;		// 初期回転
	Vector3		start_scale;		// 初期サイズ
	float		start_life_time;	// 初期生存時間
	uint32_t	emission_rate;		// 秒間生成量
	uint32_t	max_particles;		// パーティクルの最大量
};
class ParticleSystem
{
public:
	// Constructer
	ParticleSystem(){}

	// Destructor
	virtual ~ParticleSystem(){}

	// function
	virtual void Emit() = 0;			// 生成
	virtual void Simulate(){}			// シュミレート
	virtual void Update(){}				// 更新

protected:
	std::vector<std::unique_ptr<Particle>>	particles;			// パーティクル(vector)
	Emitter									emitter;			// エミッター
	float									emission_timer = 0;	// 生成タイマー
	float									frame_duration;		// EmissionTimerの1f毎の上昇数値
};

//======================================================================//
// functions
Vector3 MatrixRotationYaw(const Vector3 &this_position, const Vector3 &center_position, const AVector3 &rotation);		// Yaw  (Y軸)回転
Vector3 MatrixRotationPitch(const Vector3 &this_position, const Vector3 &center_position, const AVector3 &rotation);	// Pitch(X軸)回転
Vector3 MatrixRotationRoll(const Vector3 &this_position, const Vector3 &center_position, const AVector3 &rotation);		// Roll (Z軸)回転
Vector3 MatrixRotationYPR(const Vector3 &this_position, const Vector3 &center_position, const AVector3 &rotation);		// X,Y,Zの回転

#endif