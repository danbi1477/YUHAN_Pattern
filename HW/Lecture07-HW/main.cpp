#pragma comment(lib, "Opengl32.lib")

#include <GLFW/glfw3.h>
#include <iostream>
#include "MSList.h" // <--- 수정된 부분
#include"MSList.cpp"
#include <random>
#include "Star.hpp"

float moveFactor = 0.0f;
float scaleFactor = 1.0f;

void errorCallback(int error, const char* description)
{
    std::cerr << "\033[1;31mGLFW Error: " << description << "\033[0m" << std::endl;
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
    if (key == GLFW_KEY_UP && action == GLFW_PRESS)
    {
        moveFactor += 0.01f;
    }
    if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS)
    {
        scaleFactor += 0.1f;
    }
}

MSList<MObject*> list; // <--- 수정된 부분

int initialize()
{
    std::random_device rd;  // 난수 생성기 시드 초기화
    std::mt19937 gen(rd()); // 난수 생성 엔진 초기화
    std::uniform_real_distribution<float> disX(0.0f, 1.0f); // 0.0 ~ 1.0 사이의 난수 생성 (위치)
    std::uniform_real_distribution<float> disY(0.0f, 1.0f); // 0.0 ~ 1.0 사이의 난수 생성 (위치)
    std::uniform_real_distribution<float> disR(0.0f, 1.0f); // 0.0 ~ 1.0 사이의 난수 생성 (빨강)
    std::uniform_real_distribution<float> disG(0.0f, 1.0f); // 0.0 ~ 1.0 사이의 난수 생성 (초록)
    std::uniform_real_distribution<float> disB(0.0f, 1.0f); // 0.0 ~ 1.0 사이의 난수 생성 (파랑)

    // Star 객체를 생성하여 MSList에 추가합니다.
    for (int i = 0; i < 300; ++i) {
        Star* star = new Star();
        star->posX = disX(gen);  // 랜덤 X 위치
        star->posY = disY(gen);  // 랜덤 Y 위치
        star->color[0] = disR(gen);
        star->color[1] = disG(gen);
        star->color[2] = disB(gen);
        list.push_back(star);
    }
    return 0;
}

int release()
{
    // MSList에 추가된 Star 객체들을 메모리에서 해제합니다.
    for (int i = 0; i < list.getSize(); ++i) {
        delete list.at(i);
    }
    return 0;
}

int update()
{
    return 0;
}

int render()
{
    glClearColor(0.1f, 0.2f, 0.5f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // MSList에 있는 모든 Star 객체를 렌더링합니다.
    for (int i = 0; i < list.getSize(); ++i) {
        MObject* a = list.at(i);
        a->render();
    }

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

    glfwMakeContextCurrent(window);
    glfwSetErrorCallback(errorCallback);
    glfwSetKeyCallback(window, keyCallback);

    initialize();

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        update();
        render();
        glfwSwapBuffers(window);
    }

    release();

    glfwTerminate();
    return 0;
}
