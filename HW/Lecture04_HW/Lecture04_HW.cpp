#include<iostream>

//컴파일러 지시문
//추가 종속성은 옵션에 가서 직접 지정해줘야하는데..번거로우니까 코드로 작성
#pragma comment(lib, "opengl32.lib")

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
        // GL 클리어 -> GL에 들어간 메모리?를 초기회(클리어)시켜줌
        glClear(GL_COLOR_BUFFER_BIT);

        // 스왑 버퍼?
        glfwSwapBuffers(window);
        //뭐지 클리어만 있으면 안되는데 스왑버퍼가 있으니 됌.. 테스트2
        


    }

    glfwTerminate();
    return 0;
}