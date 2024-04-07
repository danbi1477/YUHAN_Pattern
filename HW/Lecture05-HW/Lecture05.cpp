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

//별 그리기

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
			//현재 마우스의 좌표를 lastX 와 lastZ에 저장
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
	//만약 마우스 왼쪽 키가 눌렸다면
	if (left) {
		//마우스의 이동 거리를 계산
		//이동한 거리 = 현재 마우스 위지 - 전에 있던 마우스 위치
		deltaX = xpos - lastX;
		deltaY = ypos - lastY;

		//X이동거리 / 윈도우_넓이, - Y이동거리 / 윈도우_높이 , z좌표(필요없으니 0.0f로 고정)
		//여기서 y좌표에 - 하는 이유는 마우스의 y좌표와 좌표시스템의 y좌표는 위아래가 다름.
		glTranslatef(deltaX / WINDOW_WIDTH, -deltaY / WINDOW_HEIGHT, 0.0f);

		//현재 마우스 커서의 위치를 이전 위치로 업데이트
		lastX = xpos;
		lastY = ypos;
	}
	//마우스 오른쪽 키가 눌렸을 때
	else if (right) {
		//크기는 왼쪽 오른쪽만 있으면 되니까 x좌표만 필요
		deltaX = xpos - lastX;

		//확대, 축소 비율 계산
		//기본 축소 비율(1.0f) + X이동한 거리 / 윈도우 넓이
		// zoomFactor가 오른쪽으로 이동하면서 1보다 커지면 크기가 커지고 
		// 왼쪽으로 이동하면서 1보다 작아지면 크기가 작아짐
		zoomFactor = 1.0 + deltaX / WINDOW_WIDTH;

		//x축에 대한 확대/축소 비율, y축에 대한 확대 축소 비율, z좌표 (필요없으니까 1.0f)
		glScalef(zoomFactor, zoomFactor, 1.0f);

		//현재 커서의 x좌표를 lastX에 저장
		lastX = xpos;
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

	//마우스 클릭 탐지
	glfwSetMouseButtonCallback(window, mouse_button_callback);

	//마우스 드래그 기능
	glfwSetCursorPosCallback(window, cursor_position_callback);
	
	//별 그리기
	render();

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