#include "stdafx.h"
void errorCallback(int error, const char* description)
{
	std::cerr << "GLFW Error: " << description << std::endl;
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
}

// initialize, release, update, render -> ���� ������ ���� ���� �⺻��
//�����ڴ� �� ����
//�ʱ�ȭ
int initialize()
{
	Mlist<int>list;
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);

	Mlode<int>list;

	return 0;
}

//�Ҹ��ڴ� �� ����
//����
int release() 
{
	return 0;
}


int update() 
{
	return 0;
}

//ȭ�鿡 �׸���
int render() 
{
	glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	return 0;
}
/*---------------------------------------------*/
int main(void)
{
	//glfw���̺귯�� �ʱ�ȭ
	if (!glfwInit())
		return -1;

	GLFWwindow* window;
	window = glfwCreateWindow(1280, 768, "MuSoeunEngine", NULL, NULL);

	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glfwSetErrorCallback(errorCallback);
	glfwSetKeyCallback(window, keyCallback);

	initialize();
	
	while (!glfwWindowShouldClose(window))
	{
		//Ű, ���콺�� �Է��� �������ڴ�.
		glfwPollEvents();
		
		//������Ʈ ����
		update();
		render();
		glfwSwapBuffers(window);
	}

	glfwTerminate();
	return 0;

}