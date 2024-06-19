#include "Object.h"
#include <GLFW/glfw3.h>
#include <iostream>

Object* objects[4];
float floorY = -0.0025f * 300;
float lastTime = glfwGetTime();

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    Player* player = static_cast<Player*>(objects[0]);
    if (key == GLFW_KEY_SPACE && action == GLFW_PRESS) {
        player->jump(0.0f);
    }
    else if (key == GLFW_KEY_SPACE && action == GLFW_RELEASE) {
        float jumpTime = glfwGetTime() - player->jumpStartTime;
        player->jump(jumpTime);
    }
}

void CheckCollisions() {
    Player* player = static_cast<Player*>(objects[0]);
    EnemyBlock* greenBlock1 = static_cast<EnemyBlock*>(objects[1]);
    EnemyBlock* greenBlock2 = static_cast<EnemyBlock*>(objects[2]);

    // 플레이어와 초록색 장애물 사이의 충돌을 검사
    if (player->x + player->SIZE / 2 > greenBlock1->x - greenBlock1->SIZE / 2 &&
        player->x - player->SIZE / 2 < greenBlock1->x + greenBlock1->SIZE / 2 &&
        player->y + player->SIZE / 2 > greenBlock1->y - greenBlock1->SIZE / 2 &&
        player->y - player->SIZE / 2 < greenBlock1->y + greenBlock1->SIZE / 2) {

        // 충돌 발생 시 처리
        player->OnCollisionEnter(*greenBlock1);
    }

    if (player->x + player->SIZE / 2 > greenBlock2->x - greenBlock2->SIZE / 2 &&
        player->x - player->SIZE / 2 < greenBlock2->x + greenBlock2->SIZE / 2 &&
        player->y + player->SIZE / 2 > greenBlock2->y - greenBlock2->SIZE / 2 &&
        player->y - player->SIZE / 2 < greenBlock2->y + greenBlock2->SIZE / 2) {

        // 충돌 발생 시 처리
        player->OnCollisionEnter(*greenBlock2);
    }
}

void AdjustObjectPositions() {
    // 장애물 간의 충돌을 방지하기 위해 초기 위치와 속도를 조정할 수 있습니다.
    EnemyBlock* greenBlock1 = static_cast<EnemyBlock*>(objects[1]);
    EnemyBlock* greenBlock2 = static_cast<EnemyBlock*>(objects[2]);

    // 초록색 장애물의 속도를 동일하게 설정
    float greenBlockSpeed = -0.5f;

    // 초록색 장애물의 초기 X 위치 설정
    greenBlock1->x = 0.5f;
    greenBlock2->x = 0.7f;

    // 초록색 장애물의 속도 설정
    greenBlock1->vx = greenBlockSpeed;
    greenBlock2->vx = greenBlockSpeed;
}

int main() {
    if (!glfwInit()) {
        std::cerr << "GLFW 초기화 실패" << std::endl;
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(800, 600, "Google Dino Run Copy Game", NULL, NULL);
    if (!window) {
        std::cerr << "GLFW 윈도우 생성 실패" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // V-sync 활성화

    glClearColor(0.0f, 0.1176f, 0.39215f, 1.0f);

    objects[0] = new Player(1.0f, 0.0f, 0.5f, 0.0f, 0.0f);
    objects[1] = new EnemyBlock(1.0f, true, 0.5f, 0.0f, 0.0f, 0.0f);
    objects[2] = new EnemyBlock(1.0f, false, 0.7f, 0.0f, 0.0f, 0.0f);
    objects[3] = new Floor();

    glfwSetKeyCallback(window, keyCallback);

    AdjustObjectPositions(); // 초기 위치 및 속도 조정

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        float now = glfwGetTime();
        float deltaTime = now - lastTime;
        lastTime = now;

        CheckCollisions();

        for (int i = 0; i < 4; ++i) {
            objects[i]->update(deltaTime, floorY);
            objects[i]->render();
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    for (int i = 0; i < 4; ++i) {
        delete objects[i];
    }

    glfwTerminate();
    return 0;
}