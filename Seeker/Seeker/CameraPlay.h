// �v���C�V�[���ł̃J�����̋���
#pragma once
#include "Generic.h"

enum CAMERA_MODE
{
	FOLLOW,		// �v���C
	WAIT,		// �҂�
	PASSIBE,	// ���������
};

class CameraPlay
{
private:
	Transform transform;
	CAMERA_MODE mode;

public:
	CameraPlay();
	virtual ~CameraPlay();

	void Update();
};