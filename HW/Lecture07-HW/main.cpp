#pragma comment(lib, "Opengl32.lib")

#include <GLFW/glfw3.h>
#include <iostream>
#include "MSList.h" // <--- ������ �κ�
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

MSList<MObject*> list; // <--- ������ �κ�

int initialize()
{
    std::random_device rd;  // ���� ������ �õ� �ʱ�ȭ
    std::mt19937 gen(rd()); // ���� ���� ���� �ʱ�ȭ
    std::uniform_real_distribution<float> disX(0.0f, 1.0f); // 0.0 ~ 1.0 ������ ���� ���� (��ġ)
    std::uniform_real_distribution<float> disY(0.0f, 1.0f); // 0.0 ~ 1.0 ������ ���� ���� (��ġ)
    std::uniform_real_distribution<float> disR(0.0f, 1.0f); // 0.0 ~ 1.0 ������ ���� ���� (����)
    std::uniform_real_distribution<float> disG(0.0f, 1.0f); // 0.0 ~ 1.0 ������ ���� ���� (�ʷ�)
    std::uniform_real_distribution<float> disB(0.0f, 1.0f); // 0.0 ~ 1.0 ������ ���� ���� (�Ķ�)

    // Star ��ü�� �����Ͽ� MSList�� �߰��մϴ�.
    for (int i = 0; i < 300; ++i) {
        Star* star = new Star();
        star->posX = disX(gen);  // ���� X ��ġ
        star->posY = disY(gen);  // ���� Y ��ġ
        star->color[0] = disR(gen);
        star->color[1] = disG(gen);
        star->color[2] = disB(gen);
        list.push_back(star);
    }
    return 0;
}

int release()
{
    // MSList�� �߰��� Star ��ü���� �޸𸮿��� �����մϴ�.
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

    // MSList�� �ִ� ��� Star ��ü�� �������մϴ�.
    for (int i = 0; i < list.getSize(); ++i) {
        MObject* a = list.at(i);
        a->render();
    }

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
