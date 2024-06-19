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
float jumpSpeed = 10.0f;  // ���� �ӵ�

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
	{
		if (!isJumping)
		{
			isJumping = true;
			jumpSpeed = 10.0f;  // ���� �ʱ� �ӵ� ����
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
float gravity = 0.5f;  // �߷� ���ӵ�
float jumpHeight = 100.0f;  // ���� ����

int Update()
{

	Player player;
	player.play_render();

	// ��ֹ� ��ũ�� �ӵ� ����
	float obstacle_scroll_speed = 0.5f;

	// ��ֹ����� ��ũ���ϸ� �̵���Ŵ
	obstacle_x -= obstacle_scroll_speed;
	big_obstacle_x -= obstacle_scroll_speed;

	// ��ֹ��� ���� ���� ����� ������ ������ ����
	if (obstacle_x + obstacle_width < 0)
		obstacle_x = 800.0f;  // ȭ�� ������ ������ �����

	if (big_obstacle_x + big_obstacle_width < 0)
		big_obstacle_x = 800.0f;  // ȭ�� ������ ������ �����



	if (isJumping)
	{
		// ĳ������ y ��ġ�� �����Ͽ� ������ �ùķ���Ʈ�մϴ�.
		square_y += jumpSpeed;

		// ���� �ӵ��� ���ҽ�Ŵ���ν� �߷� ����
		jumpSpeed -= gravity;

		// ���� ��Ҵ��� Ȯ��
		if (square_y <= floor_height)
		{
			square_y = floor_height;
			isJumping = false;  // ���� ����
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

	// ���� ��ֹ� ������
    EnemyBlock obstacle;
    obstacle.x = obstacle_x;
    obstacle.y = obstacle_y;
    obstacle.width = obstacle_width;
    obstacle.height = obstacle_height;
    obstacle.Block();

    // ū ��ֹ� ������
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


	//glfw���̺귯�� �ʱ�ȭ
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