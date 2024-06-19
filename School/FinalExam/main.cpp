#pragma comment(lib, "Opengl32.lib")
#include <iostream>
#include"Object.h"


#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#else
#define DBG_NEW new
#endif

#include <GLFW/glfw3.h>
#include <stdio.h>
#include <chrono>
#include <thread>
#include <cmath>


void errorCallback(int error, const char* description)
{
	printf("GLFW Error: %s", description);
}

bool isJumping = false;
float jumpSpeed = 10.0f;  // 점프 속도

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
	{
		if (!isJumping)
		{
			isJumping = true;
			jumpSpeed = 10.0f;  // 점프 초기 속도 설정
		}
	}
}

int Physics()
{
	return 0;
}

int Initialize()
{
	return 0;
}
float gravity = 0.5f;  // 중력 가속도
float jumpHeight = 100.0f;  // 점프 높이

int Update()
{

	Player player;
	player.play_render();

	// 장애물 스크롤 속도 설정
	float obstacle_scroll_speed = 0.5f;

	// 장애물들을 스크롤하며 이동시킴
	obstacle_x -= obstacle_scroll_speed;
	big_obstacle_x -= obstacle_scroll_speed;

	// 장애물이 왼쪽 끝을 벗어나면 오른쪽 끝으로 재사용
	if (obstacle_x + obstacle_width < 0)
		obstacle_x = 800.0f;  // 화면 오른쪽 끝에서 재시작

	if (big_obstacle_x + big_obstacle_width < 0)
		big_obstacle_x = 800.0f;  // 화면 오른쪽 끝에서 재시작



	if (isJumping)
	{
		// 캐릭터의 y 위치를 변경하여 점프를 시뮬레이트합니다.
		square_y += jumpSpeed;

		// 점프 속도를 감소시킴으로써 중력 적용
		jumpSpeed -= gravity;

		// 땅에 닿았는지 확인
		if (square_y <= floor_height)
		{
			square_y = floor_height;
			isJumping = false;  // 점프 종료
		}
	}
	return 0;
}

int Render()
{
	Player player;
	player.play_render();

	Floor floor;
	floor.GamePloor();

	// 작은 장애물 렌더링
    EnemyBlock obstacle;
    obstacle.x = obstacle_x;
    obstacle.y = obstacle_y;
    obstacle.width = obstacle_width;
    obstacle.height = obstacle_height;
    obstacle.Block();

    // 큰 장애물 렌더링
    EnemyBlock big_obstacle;
    big_obstacle.x = big_obstacle_x;
    big_obstacle.y = big_obstacle_y;
    big_obstacle.width = big_obstacle_width;
    big_obstacle.height = big_obstacle_height;
    big_obstacle.Block2();

	return 0;
}


int main(void)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	//glfw라이브러리 초기화
	if (!glfwInit())
		return -1;



	GLFWwindow* window;
	window = glfwCreateWindow(800, 600, "Google Dino Run Copy Game", NULL, NULL);

	if (!window)
	{
		glfwTerminate();
		return -1;
	}


	glfwMakeContextCurrent(window);
	glfwSetErrorCallback(errorCallback);
	glfwSetKeyCallback(window, keyCallback);

	glOrtho(0, 800, 0, 600, -1, 1);

	Initialize();

	while (!glfwWindowShouldClose(window))
	{

		glfwPollEvents();
		glClearColor(0.0f, 0.1176f, 0.3922f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		Physics();
		Update();
		Render();
		glfwSwapBuffers(window);
	}

	glfwTerminate();
	return 0;

}