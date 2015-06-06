#include "DxLib.h"
#include "DxRaps.h"
#include "TinyTim.h"
#include "TextureManager.h"

TinyTim::TinyTim(){}

TinyTim::TinyTim(float x, float y)
{
	this->transform.position = { x, y - 10.f, 0.f };
	LoadTexture();
}

TinyTim::TinyTim(float x, float y, float z)
{
	this->transform.position = { x, y - 10.f, z };
	LoadTexture();
}

TinyTim::TinyTim(Vector3 _position)
{
	this->transform.position = _position;
	LoadTexture();
}

TinyTim::~TinyTim(){}

void TinyTim::Update(){}

void TinyTim::Draw()
{
	DrawBillboard3D(VGetRap(this->transform.position), 0.5f, 0.f, 30.f, 0.f, *images[0], FALSE, 0);
}

/*void TinyTim::Draw()
{
	switch (state)
	{
	default:
	case State::Stand:	// �����A����ё��̏�Ԃɓ��Ă͂܂�Ȃ������ꍇ

		break;
		
	case State::Walk:	// ����

		break;

	case State::Run:	// ����

		break;

	case State::Jump:	// �W�����v

		break;

	case State::Land:	// ���n

		break;

	case State::Roll:	// ���[�����O

		break;
	}
}//*/

void TinyTim::LoadTexture()
{
	// �e�X�g
	LoadDivGraph("Texture/Player.png", 37, 8, 5, 256, 256, test_loaded);
	for (int i = 0; i < 37; i++)
	{
		images.push_back(&test_loaded[i]);
	}
	return;
}

void TinyTim::AnimationSet()
{

}

void TinyTim::Default()
{
	this->id = ObjID::Player;
	state = State::Stand;
	this->transform.scale = { 20.f, 20.f, 0.1f };
	this->transform.rotation = { 0.f, 0.f, 0.f };
}