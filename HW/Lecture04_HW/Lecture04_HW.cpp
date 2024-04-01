#include<iostream>

//�����Ϸ� ���ù�
//�߰� ���Ӽ��� �ɼǿ� ���� ���� ����������ϴµ�..���ŷο�ϱ� �ڵ�� �ۼ�
#pragma comment(lib, "opengl32.lib")

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
        // GL Ŭ���� -> GL�� �� �޸�?�� �ʱ�ȸ(Ŭ����)������
        glClear(GL_COLOR_BUFFER_BIT);

        // ���� ����?
        glfwSwapBuffers(window);
        //���� Ŭ��� ������ �ȵǴµ� ���ҹ��۰� ������ ��.. �׽�Ʈ2
        


    }

    glfwTerminate();
    return 0;
}