#include "InputManager.h"

class InputManagerDemo
{
private:
	InputData input_data;

public:
	InputManagerDemo();
	virtual ~InputManagerDemo();

public:
	InputData GetInput(){ return this->input_data; }
};