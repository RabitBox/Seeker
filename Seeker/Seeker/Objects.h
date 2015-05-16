#pragma once
#include <map>
#include <string>
#include "Generic.h"
using namespace std;

enum ObjID
{
	Player,				// �v���C���[
	Camera,
	Floar,				// ��
};

class Acter : public Object
{
protected:
	static int loaded_images[];
	static map<string, int> loaded_image;
	ObjID id;

public:
	Vector3 GetPosition(){ return this->transform.position; }

protected:
	void LoadTexture();
};

// �ÓI�����o�̎��Ԑ錾
int Acter::loaded_images[10];	
map<string, int> Acter::loaded_image;