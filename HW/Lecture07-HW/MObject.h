#pragma once

class MObject
{
public:
	//���ο��� �����ڿ� �Ҹ��ڸ� ����
	MObject();
	~MObject();

	//�Լ� update�� render ����
	virtual void update();
	virtual void render();

};
