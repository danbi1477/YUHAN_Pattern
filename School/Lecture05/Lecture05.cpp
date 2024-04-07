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

//�� �׸���

bool left = false;
bool right = false;
double lastX, lastY;
int WINDOW_WIDTH = 1280;
int WINDOW_HEIGHT = 768;
double deltaY;
double deltaX;
double zoomFactor;

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
	if (button == GLFW_MOUSE_BUTTON_RIGHT) {
		if (action == GLFW_PRESS) {
			right = true;
			//���� ���콺�� ��ǥ�� lastX �� lastZ�� ����
			glfwGetCursorPos(window, &lastX, &lastY);
		}
		else if (action == GLFW_RELEASE) {
			right = false;
		}
	}
	else if (button == GLFW_MOUSE_BUTTON_LEFT) {
		if (action == GLFW_PRESS) {
			left = true;
			glfwGetCursorPos(window, &lastX, &lastY);
		}
		else if (action == GLFW_RELEASE) {
			left = false;
		}
	}
}

void cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
	//���� ���콺 ���� Ű�� ���ȴٸ�
	if (left) {
		//���콺�� �̵� �Ÿ��� ���
		//�̵��� �Ÿ� = ���� ���콺 ���� - ���� �ִ� ���콺 ��ġ
		deltaX = xpos - lastX;
		deltaY = ypos - lastY;

		//X�̵��Ÿ� / ������_����, - Y�̵��Ÿ� / ������_���� , z��ǥ(�ʿ������ 0.0f�� ����)
		//���⼭ y��ǥ�� - �ϴ� ������ ���콺�� y��ǥ�� ��ǥ�ý����� y��ǥ�� ���Ʒ��� �ٸ�.
		glTranslatef(deltaX / WINDOW_WIDTH, -deltaY / WINDOW_HEIGHT, 0.0f);

		//���� ���콺 Ŀ���� ��ġ�� ���� ��ġ�� ������Ʈ
		lastX = xpos;
		lastY = ypos;
	}
	//���콺 ������ Ű�� ������ ��
	else if (right) {
		//ũ��� ���� �����ʸ� ������ �Ǵϱ� x��ǥ�� �ʿ�
		deltaX = xpos - lastX;

		//Ȯ��, ��� ���� ���
		//�⺻ ��� ����(1.0f) + X�̵��� �Ÿ� / ������ ����
		// zoomFactor�� ���������� �̵��ϸ鼭 1���� Ŀ���� ũ�Ⱑ Ŀ���� 
		// �������� �̵��ϸ鼭 1���� �۾����� ũ�Ⱑ �۾���
		zoomFactor = 1.0 + deltaX / WINDOW_WIDTH;

		//x�࿡ ���� Ȯ��/��� ����, y�࿡ ���� Ȯ�� ��� ����, z��ǥ (�ʿ�����ϱ� 1.0f)
		glScalef(zoomFactor, zoomFactor, 1.0f);

		//���� Ŀ���� x��ǥ�� lastX�� ����
		lastX = xpos;
	}
}

int render() //ȭ�鿡 ���� �׸�
{
	//�ﰢ���� �׸�
	glBegin(GL_TRIANGLES);
	//���
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

	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	glfwSetErrorCallback(errorCallback);
	glfwSetKeyCallback(window, keyCallback);

	//���콺 Ŭ�� Ž��
	glfwSetMouseButtonCallback(window, mouse_button_callback);

	//���콺 �巡�� ���
	glfwSetCursorPosCallback(window, cursor_position_callback);
	
	//�� �׸���
	render();

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//�� �׸���
		render();
		glfwSwapBuffers(window);
	}
	glfwTerminate();
	return 0;
}