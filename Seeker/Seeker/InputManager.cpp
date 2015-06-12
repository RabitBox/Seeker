#include "DxLib.h"
#include "InputManager.h"

//--------------------------------------------------
// é¿ë‘ÇÃêÈåæ
//--------------------------------------------------
InputManager* InputManager::input_manager = new InputManager();

InputManager::InputManager()
{
	arrow.up		= false;
	arrow.down		= false;
	arrow.left		= false;
	arrow.right		= false;
	a.now_input		= Buttan::None;
	a.back_input	= Buttan::None;
	b.now_input		= Buttan::None;
	b.back_input	= Buttan::None;
}

void InputManager::Input()
{
	if (CheckHitKey(KEY_INPUT_UP) == 0){
		arrow.up = false;
	}
	else{
		arrow.up = true;
	}

	if (CheckHitKey(KEY_INPUT_DOWN) == 0){
		arrow.down = false;
	}
	else{
		arrow.down = true;
	}

	if (CheckHitKey(KEY_INPUT_LEFT) == 0){
		arrow.left = false;
	}
	else{
		arrow.left = true;
	}

	if (CheckHitKey(KEY_INPUT_RIGHT) == 0){
		arrow.right = false;
	}
	else{
		arrow.right = true;
	}

	if (CheckHitKey(KEY_INPUT_A) == 0){
		switch (a.back_input)
		{
		case Buttan::None:
		case Buttan::Out:
			a.now_input = Buttan::None;
			break;

		case Buttan::On:
		case Buttan::Stay:
			a.now_input = Buttan::Out;
			break;
		}
	}
	else{
		switch (a.back_input)
		{
		case Buttan::None:
		case Buttan::Out:
			a.now_input = Buttan::On;
			break;

		case Buttan::On:
		case Buttan::Stay:
			a.now_input = Buttan::Stay;
			break;
		}
	}
	a.back_input = a.now_input;

	if (CheckHitKey(KEY_INPUT_S) == 0){
		switch (b.back_input)
		{
		case Buttan::None:
		case Buttan::Out:
			b.now_input = Buttan::None;
			break;

		case Buttan::On:
		case Buttan::Stay:
			b.now_input = Buttan::Out;
			break;
		}
	}
	else{
		switch (b.back_input)
		{
		case Buttan::None:
		case Buttan::Out:
			b.now_input = Buttan::On;
			break;

		case Buttan::On:
		case Buttan::Stay:
			b.now_input = Buttan::Stay;
			break;
		}
	}
	b.back_input = b.now_input;
}

InputManager::X_Y InputManager::GetAxis()
{
	int x, y;
	if (arrow.left && !arrow.right){
		x = -1;
	}
	else if (!arrow.left && arrow.right){
		x = 1;
	}
	else{
		x = 0;
	}

	if (arrow.up && !arrow.down){
		y = 1;
	}
	else if (!arrow.up && arrow.down){
		y = -1;
	}
	else{
		y = 0;
	}

	return {x,y};
}