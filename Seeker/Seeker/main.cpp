// DX���C�u���� + C++ �ŊJ��
// Gai Takakura
#include "Application.h"

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	unique_ptr<Application> app(new Application());

	app -> AppMain();

	return 0; 
}