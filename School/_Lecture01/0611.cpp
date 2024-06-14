
#pragma comment(lib, "Opengl32.lib")
#include <GLFW/glfw3.h>
#include <iostream>

// 중력 가속도 상수
const float GRAVITY = 9.81f;
// 점프 속도 상수
const float JUMP_VELOCITY = 5.0f;
// 이동 속도 상수
const float MOVE_SPEED = 2.0f;

// 사람의 초기 위치와 속도
float personX = 0.0f;
float personY = -0.5f;
float velocityY = 0.0f;

// 사람의 크기
const float PERSON_HEIGHT = 0.3f;
const float PERSON_WIDTH = 0.2f;

// 바닥 위치
const float GROUND_Y = -0.5f;

// 사람의 바닥에 있는지 확인하는 플래그
bool isOnGround = true;

// 키 상태 추적
bool moveLeft = false;
bool moveRight = false;

void updatePersonPosition(float deltaTime) {
    // 중력 가속도를 속도에 반영
    if (!isOnGround) {
        velocityY += GRAVITY * deltaTime;
    }

    // 속도를 위치에 반영
    personY -= velocityY * deltaTime;

    // 바닥에 도달하면 사람을 멈추게 함
    if (personY < GROUND_Y) {
        personY = GROUND_Y;
        velocityY = 0.0f;
        isOnGround = true;
    }

    // 좌우 이동 반영
    if (moveLeft) {
        personX -= MOVE_SPEED * deltaTime;
    }
    if (moveRight) {
        personX += MOVE_SPEED * deltaTime;
    }
}

void drawPerson() {
    float personBottom = personY;
    float personTop = personY + PERSON_HEIGHT;
    float personLeft = personX - PERSON_WIDTH / 2;
    float personRight = personX + PERSON_WIDTH / 2;

    glBegin(GL_QUADS);
    // 사람의 몸통 (사각형)
    glVertex3f(personLeft, personBottom, 0.0f);
    glVertex3f(personRight, personBottom, 0.0f);
    glVertex3f(personRight, personTop, 0.0f);
    glVertex3f(personLeft, personTop, 0.0f);
    glEnd();
}

void drawGround() {
    glBegin(GL_QUADS);
    // 길 그리기 (가로로 긴 사각형)
    glVertex3f(-1.0f, GROUND_Y - 0.05f, 0.0f);
    glVertex3f(1.0f, GROUND_Y - 0.05f, 0.0f);
    glVertex3f(1.0f, GROUND_Y + 0.05f, 0.0f);
    glVertex3f(-1.0f, GROUND_Y + 0.05f, 0.0f);
    glEnd();
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_SPACE && action == GLFW_PRESS && isOnGround) {
        // 사람의 바닥에 있을 때만 점프할 수 있음
        velocityY = -JUMP_VELOCITY;
        isOnGround = false;
    }
    if (key == GLFW_KEY_LEFT) {
        if (action == GLFW_PRESS) {
            moveLeft = true;
        }
        else if (action == GLFW_RELEASE) {
            moveLeft = false;
        }
    }
    if (key == GLFW_KEY_RIGHT) {
        if (action == GLFW_PRESS) {
            moveRight = true;
        }
        else if (action == GLFW_RELEASE) {
            moveRight = false;
        }
    }
}

int main() {
    // GLFW 초기화
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    // 윈도우 생성 (1280x960)
    GLFWwindow* window = glfwCreateWindow(1280, 960, "Jumping Person", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    // 키보드 입력 콜백 설정
    glfwSetKeyCallback(window, keyCallback);

    float lastTime = glfwGetTime();

    // 메인 루프
    while (!glfwWindowShouldClose(window)) {
        float currentTime = glfwGetTime();
        float deltaTime = currentTime - lastTime;
        lastTime = currentTime;

        // 사람 위치 업데이트
        updatePersonPosition(deltaTime);

        // 화면 지우기
        glClear(GL_COLOR_BUFFER_BIT);

        // 길 그리기
        drawGround();

        // 사람 그리기
        drawPerson();

        // 버퍼 교환
        glfwSwapBuffers(window);

        // 이벤트 처리
        glfwPollEvents();
    }

    // GLFW 종료
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}