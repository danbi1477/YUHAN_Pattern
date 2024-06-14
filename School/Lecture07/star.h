#pragma once
#include"Mobject.h"
class star : public Mobject
{
	//가상함수 virtual
	virtual void update();
	virtual void render();
};

