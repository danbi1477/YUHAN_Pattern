#include<iostream>
//누겟 패키지 관리자를 통해 다운받음.
#include<GLFW/glfw3.h>

int main(void)
{
    GLFWwindow* window;

    //glfw 라이브러리 초기화 
    if (!glfwInit())
        return -1;

    // 윈도우 창 생성? (1280, 768 크기, HELLO WORLD 생성)
    window = glfwCreateWindow(1280, 768, "Hello World", NULL, NULL);
    // 만약 창을 생성하지 못했을 때 초기화
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    // 중요한 함수 : MakeContextCurrent 
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        
    }

    glfwTerminate();
    return 0;
}