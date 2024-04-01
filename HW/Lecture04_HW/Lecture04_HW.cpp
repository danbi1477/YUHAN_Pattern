//과제물 프로젝트명: Lecture04_HW
//idle : 화면색 검정색으로 clear
//마우스 오른쪽 KeyDown하면 : 빨간색
//마우스 오른쪽 KeyUp하면 : 원상복구
//마우스 왼쪽 KeyDown하면 : 녹색
//마우스 왼쪽 KeyUp하면 : 원상복구
//마우스 오른쪽 KeyDown하고 드래그 중이면 : 파랑색
//마우스 왼쪽 KeyDown하고 드래그 중이면 : 마젠타색


//https://www.glfw.org/
#pragma comment(lib, "Opengl32.lib")
#include <GLFW/glfw3.h>
#include <iostream>

//드래그 중인지 확인 할 불함수 생성
bool left = false;
bool right = false;


// 오류 메세지 출력
void errorCallback(int error, const char* description)
{
	std::cerr << "GLFW Error: " << description << std::endl;
}

//ESC 누르면 윈도우를 닫음.
void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	//만약 ESC를 누르면
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		//윈도우 창을 닫음.
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
}

//마우스 클릭했을떄 색상 변경
void color(GLFWwindow* window, int button, int action, int mods) {
	//만약 오른쪽 버튼을 && key down 했을 때
	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS) {
		glClearColor(1.0f, 0.0f, 0.0f, 1.0f);	// 빨간색
		right = true;
		//만약 오른쪽 버튼을 && key up 했을 때
	}
	else if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE) {
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);	// 원상복구
		right = false;
	}
	else if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
		glClearColor(0.0f, 1.0f, 0.0f, 1.0f);	// 녹색
		left = true;
	}
	else if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE) {
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);	// 원상복구
		left = false;
	}
}

//드래그 했을 때 색상이 변경
//드래그를 클릭 후 좌표변경으로 감지.
void drag(GLFWwindow* window, double xpos, double ypos) {
	if (right) {
		glClearColor(0.0f, 0.0f, 1.0f, 1.0f);	// 파란색
	}
	else if (left) {
		glClearColor(1.0f, 0.0f, 1.0f, 1.0f);	// 마젠타색
	}
}


int main(void)
{

	//glfw라이브러리 초기화
	if (!glfwInit())
		return -1;

	//window라는 이름의 윈도우 포인터 선언
	GLFWwindow* window;
	//glfwCreateWindow함수로 윈도우 생성 (윈도우 너비, 높이, 제목)
	window = glfwCreateWindow(1280, 768, "MuSoeunEngine", NULL, NULL);

	//윈도우가 생성되지 않았을 때 종료
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	//이 함수를 호출하면서 윈도우와 관련된 OpenGL 컨텍스트 활성
	glfwMakeContextCurrent(window);
	//오류 처리콜백함수 ()안에 있는 함수를 불러옴.
	glfwSetErrorCallback(errorCallback);
	//키보드 이벤트 발생할 때 호출 이벤트 처리 수행.
	glfwSetKeyCallback(window, keyCallback);

	//색상 이벤트
	//마우스 버튼 눌렀을 때 컬러 변경
	glfwSetMouseButtonCallback(window, color);
	//버튼 누르고 드래그 했을 때 컬러 변경
	glfwSetCursorPosCallback(window, drag);

	//glfwWindowShouldClose함수가 true를 반환 할 때까지 반복
	while (!glfwWindowShouldClose(window))
	{
		//설정된 clear color를 사용하여 화면을 지움
		glClear(GL_COLOR_BUFFER_BIT);
		//더블 버퍼링 (화면에 그려진 내용을 실제 화면에 표시) 깜빡임 최소화
		glfwSwapBuffers(window);
		//이벤트 큐에서 이벤트 처리 (발생 이벤트 적절히 처리됨)
		glfwPollEvents();
	}

	//GLFW 라이브러리를 종료하는 함수.
	glfwTerminate();
	return 0;


}
