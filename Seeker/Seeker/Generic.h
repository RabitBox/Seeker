//--------------------------------------------------
// �ėp�R�[�h�W
// 2015/01/30
//--------------------------------------------------
#pragma once
#include <stdint.h>
#include <vector>
#include <memory>

//======================================================================//
#define CALL_ONCE(func) do{ static bool _Initialized = false; if (!_Initialized) { func; _Initialized = true; }while(0)
#define BETWEEN(setmin, setmax, value) max(setmin, min(setmax, value))
#define ERR_CALL(str) do{std::cerr << str << std::endl;}while(0)

//======================================================================//
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
	Vector2& operator +=(const Vector2& v){ x += v.x; y += v.y; return *this; }
	Vector2& operator -=(const Vector2& v){ x -= v.x; y -= v.y; return *this; }
	Vector2& operator *=(const Vector2& v){ x *= v.x; y *= v.y; return *this; }
	Vector2& operator /=(const Vector2& v){ x /= v.x; y /= v.y; return *this; }
	Vector2& operator *=(const int n){ x *= n; y *= n; return *this; }
	Vector2& operator /=(const int n){ x /= n; y /= n; return *this; }
	Vector2& operator *=(const float f){ x *= f; y *= f; return *this; }
	Vector2& operator /=(const float f){ x /= f; y /= f; return *this; }
	Vector2& operator = (const Vector2& v){ x = v.x; y = v.y; return *this; }

	// friend function operator
	friend Vector2 operator +(const Vector2& v0, const Vector2& v1){ Vector2 V(v0.x + v1.x, v0.y + v1.y); return V; }
	friend Vector2 operator -(const Vector2& v0, const Vector2& v1){ Vector2 V(v0.x - v1.x, v0.y - v1.y); return V; }
	friend Vector2 operator *(const Vector2& v0, int n){ Vector2 V(v0.x * n, v0.y * n); return V; }
	friend Vector2 operator *(int n, const Vector2& v0){ Vector2 V(v0.x * n, v0.y * n); return V; }
	friend Vector2 operator *(const Vector2& v0, float f){ Vector2 V(v0.x * f, v0.y * f); return V; }
	friend Vector2 operator *(float f, const Vector2& v0){ Vector2 V(v0.x * f, v0.y * f); return V; }
	friend Vector2 operator /(const Vector2& v0, int n){ Vector2 V(v0.x / n, v0.y / n); return V; }
	friend Vector2 operator /(int n, const Vector2& v0){ Vector2 V(v0.x / n, v0.y / n); return V; }
	friend Vector2 operator /(const Vector2& v0, float f){ Vector2 V(v0.x / f, v0.y / f); return V; }
	friend Vector2 operator /(float f, const Vector2& v0){ Vector2 V(v0.x / f, v0.y / f); return V; }
};
class Vector3
{
public:
	// variable
	float x;
	float y;
	float z;

	// Constructor
	Vector3() : x(0.0f), y(0.0f), z(0.0f){}
	Vector3(float X, float Y) : x(X), y(Y), z(0.0f){}
	Vector3(float X, float Y, float Z) : x(X), y(Y), z(Z){}
	Vector3(const Vector3 &v) : x(v.x), y(v.y), z(v.z){}

	// Destructor
	virtual ~Vector3(){}

	// Operator
	Vector3& operator +=(const Vector3& v){ x += v.x; y += v.y; z += v.z; return *this; }
	Vector3& operator -=(const Vector3& v){ x -= v.x; y -= v.y; z -= v.z; return *this; }
	Vector3& operator *=(const Vector3& v){ x *= v.x; y *= v.y; z *= v.z; return *this; }
	Vector3& operator /=(const Vector3& v){ x /= v.x; y /= v.y; z /= v.z; return *this; }
	Vector3& operator *=(const int n){ x *= n; y *= n; z *= n; return *this; }
	Vector3& operator /=(const int n){ x /= n; y /= n; z /= n; return *this; }
	Vector3& operator *=(const float f){ x *= f; y *= f; z *= f; return *this; }
	Vector3& operator /=(const float f){ x /= f; y /= f; z /= f; return *this; }
	Vector3& operator = (const Vector3& v){ x = v.x; y = v.y; z = v.z; return *this; }

	// friend function
	friend Vector3 operator +(const Vector3& v0, const Vector3& v1){ Vector3 V(v0.x + v1.x, v0.y + v1.y, v0.z + v1.z); return V; }
	friend Vector3 operator -(const Vector3& v0, const Vector3& v1){ Vector3 V(v0.x - v1.x, v0.y - v1.y, v0.z - v1.z); return V; }
	friend Vector3 operator *(const Vector3& v0, int n){ Vector3 V(v0.x * n, v0.y * n, v0.z * n); return V; }
	friend Vector3 operator *(int n, const Vector3& v0){ Vector3 V(v0.x * n, v0.y * n, v0.z * n); return V; }
	friend Vector3 operator *(const Vector3& v0, float f){ Vector3 V(v0.x * f, v0.y * f, v0.z * f); return V; }
	friend Vector3 operator *(float f, const Vector3& v0){ Vector3 V(v0.x * f, v0.y * f, v0.z * f); return V; }
	friend Vector3 operator /(const Vector3& v0, int n){ Vector3 V(v0.x / n, v0.y / n, v0.z / n); return V; }
	friend Vector3 operator /(int n, const Vector3& v0){ Vector3 V(v0.x / n, v0.y / n, v0.z / n); return V; }
	friend Vector3 operator /(const Vector3& v0, float f){ Vector3 V(v0.x / f, v0.y / f, v0.z / f); return V; }
	friend Vector3 operator /(float f, const Vector3& v0){ Vector3 V(v0.x / f, v0.y / f, v0.z / f); return V; }
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
	AVector3& operator +=(const AVector3& v){ x = Compensate(x + v.x); y = Compensate(y + v.y); z = Compensate(z + v.z); return *this; }
	AVector3& operator -=(const AVector3& v){ x = Compensate(x - v.x); y = Compensate(y - v.y); z = Compensate(z - v.z); return *this; }
	AVector3& operator *=(const AVector3& v){ x *= v.x; y *= v.y; z *= v.z; return *this; }
	AVector3& operator /=(const AVector3& v){ x /= v.x; y /= v.y; z /= v.z; return *this; }
	AVector3& operator *=(const int n){ x = Compensate((float)x * n); y = Compensate((float)y * n); z = Compensate((float)z * n); return *this; }
	AVector3& operator /=(const int n){ x = Compensate((float)x / n); y = Compensate((float)y / n); z = Compensate((float)z / n); return *this; }
	AVector3& operator *=(const float f){ x = Compensate(x * f); y = Compensate(y * f); z = Compensate(z * f); return *this; }
	AVector3& operator /=(const float f){ x = Compensate(x / f); y = Compensate(y / f); z = Compensate(z / f); return *this; }
	AVector3& operator = (const AVector3& v){ x = Compensate(v.x); y = Compensate(v.y); z = Compensate(v.z); return *this; }

	// friend function operator
	friend AVector3 operator +(const AVector3& v0, const AVector3& v1){ AVector3 V(Compensate(v0.x + v1.x), Compensate(v0.y + v1.y), Compensate(v0.z + v1.z)); return V; }
	friend AVector3 operator -(const AVector3& v0, const AVector3& v1){ AVector3 V(Compensate(v0.x - v1.x), Compensate(v0.y - v1.y), Compensate(v0.z - v1.z)); return V; }
	friend AVector3 operator *(const AVector3& v0, int n){ AVector3 V(Compensate(v0.x * n), Compensate(v0.y * n), Compensate(v0.z * n)); return V; }
	friend AVector3 operator *(int n, const AVector3& v0){ AVector3 V(Compensate(v0.x * n), Compensate(v0.y * n), Compensate(v0.z * n)); return V; }
	friend AVector3 operator *(const AVector3& v0, float f){ AVector3 V(Compensate(v0.x * f), Compensate(v0.y * f), Compensate(v0.z * f)); return V; }
	friend AVector3 operator *(float f, const AVector3& v0){ AVector3 V(Compensate(v0.x * f), Compensate(v0.y * f), Compensate(v0.z * f)); return V; }
	friend AVector3 operator /(const AVector3& v0, int n){ AVector3 V(Compensate(v0.x / n), Compensate(v0.y / n), Compensate(v0.z / n)); return V; }
	friend AVector3 operator /(int n, const AVector3& v0){ AVector3 V(Compensate(v0.x / n), Compensate(v0.y / n), Compensate(v0.z / n)); return V; }
	friend AVector3 operator /(const AVector3& v0, float f){ AVector3 V(Compensate(v0.x / f), Compensate(v0.y / f), Compensate(v0.z / f)); return V; }
	friend AVector3 operator /(float f, const AVector3& v0){ AVector3 V(Compensate(v0.x / f), Compensate(v0.y / f), Compensate(v0.z / f)); return V; }

private:
	// Function
	static float Compensate(float value){ if (value < 0.0f || value >= 360.0f) { value += (float)((value / 360.0f) * 360.0f); } return value; }
};

struct Transform
{
	Vector3 position;
	AVector3 rotation;
	Vector3 scale;
};
class PassiveObject
{
public:
	// variable
	Transform transform;

	// Destructor
	virtual ~PassiveObject(){}

	// function
	virtual void Update() = 0;
	virtual void Draw() = 0;
};
class ActiveObject : public PassiveObject
{
public:
	// variable
	//Vector3 velocity;

	// Destructor
	virtual ~ActiveObject(){}
};

//======================================================================//
Vector3 Rotation3D(const Vector3 &this_position, const Vector3 &center_position, const AVector3 &rotation);
Vector3 RotationAxisX(const Vector3 &this_position, const Vector3 &center_position, const AVector3 &rotation);
Vector3 RotationAxisY(const Vector3 &this_position, const Vector3 &center_position, const AVector3 &rotation);
Vector3 RotationAxisZ(const Vector3 &this_position, const Vector3 &center_position, const AVector3 &rotation);

//======================================================================//
class Particle
{
public:
	Vector3 position;	// ���W
	AVector3 rotation;	// ��]
	Vector3 scale;		// �T�C�Y
	float life_time;	// ��������

	virtual void Update(){}
	virtual void Draw(){}
};
struct Emitter
{
	Vector3 start_position;		// �������W
	AVector3 start_rotation;	// ������]
	Vector3 start_scale;		// �����T�C�Y
	float start_life_time;		// ������������
	uint32_t emission_rate;		// �b�Ԑ�����
	uint32_t max_particles;		// �p�[�e�B�N���̍ő��
};
class ParticleSystem
{
public:

	// Destructor
	virtual ~ParticleSystem();

	// function
	virtual void Emit(){}				// ����
	virtual void Simulate(){}			// �V���~���[�g
	virtual void Update(){}				// �X�V

protected:
	std::vector<std::unique_ptr<Particle>> particles;	// �p�[�e�B�N��(vector)
	Emitter emitter;					// �G�~�b�^�[
	float emission_timer = 0;			// �����^�C�}�[
	float frame_duration;				// EmissionTimer��1f���̏㏸���l
};


