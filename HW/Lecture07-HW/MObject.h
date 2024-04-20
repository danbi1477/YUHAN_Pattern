#pragma once

class MObject
{
public:
	//내부에서 생성자와 소멸자를 선언
	MObject();
	~MObject();

	//함수 update와 render 선언
	virtual void update();
	virtual void render();

};
