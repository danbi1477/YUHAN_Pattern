#pragma comment(lib, "Opengl32.lib")
#include <GLFW/glfw3.h>
#include <iostream>

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

int render() //화면에 뭔가 그림
{
	//삼각형을 그림
	glBegin(GL_TRIANGLES);
	//흰색
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.5f, 0.3f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.5f, 0.3f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.0f, -0.2f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.0f, 0.7f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.2f, -0.1f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.4f, -0.5f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.0f, 0.7f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.4f, -0.5f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.2f, -0.1f);
	glEnd();

	return 0;
}

int main(void)
{
	//glfw라이브러리 초기화
	if (!glfwInit())
		return -1;

	GLFWwindow* window;
	window = glfwCreateWindow(1280, 768, "MuSoeunEngine", NULL, NULL);

	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	glfwSetErrorCallback(errorCallback);
	glfwSetKeyCallback(window, keyCallback);

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//별 그리기
		render();
		glfwSwapBuffers(window);
	}
	glfwTerminate();
	return 0;
}