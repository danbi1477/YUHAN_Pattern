#include<iostream>
//���� ��Ű�� �����ڸ� ���� �ٿ����.
#include<GLFW/glfw3.h>

int main(void)
{
    GLFWwindow* window;

    //glfw ���̺귯�� �ʱ�ȭ 
    if (!glfwInit())
        return -1;

    // ������ â ����? (1280, 768 ũ��, HELLO WORLD ����)
    window = glfwCreateWindow(1280, 768, "Hello World", NULL, NULL);
    // ���� â�� �������� ������ �� �ʱ�ȭ
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    // �߿��� �Լ� : MakeContextCurrent 
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        
    }

    glfwTerminate();
    return 0;
}