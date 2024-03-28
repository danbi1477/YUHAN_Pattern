#include<iostream>

//�����Ϸ� ���ù�
//�߰� ���Ӽ��� �ɼǿ� ���� ���� ����������ϴµ�..���ŷο�ϱ� �ڵ�� �ۼ�
#pragma comment(lib, "opengl32.lib")

//���� ��Ű�� �����ڸ� ���� �ٿ����.
#include<GLFW/glfw3.h>


void errorCallback(int error,const char *description)
{
    std::cerr << "GLFW Error: " << description << std::endl;
}


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


    glfwSetErrorCallback(errorCallback);


    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        // GL Ŭ���� -> GL�� �� �޸�?�� �ʱ�ȸ(Ŭ����)������
        glClear(GL_COLOR_BUFFER_BIT);

        // ���� ����?
        glfwSwapBuffers(window);
        //���� Ŭ��� ������ �ȵǴµ� ���ҹ��۰� ������ ��..


        //�̺�Ʈ �ֵ��� ���α׷��� 

        

        
    }

    glfwTerminate();
    return 0;
}

//���� Lecture04_HW