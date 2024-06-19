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

    // �÷��̾�� �ʷϻ� ��ֹ� ������ �浹�� �˻�
    if (player->x + player->SIZE / 2 > greenBlock1->x - greenBlock1->SIZE / 2 &&
        player->x - player->SIZE / 2 < greenBlock1->x + greenBlock1->SIZE / 2 &&
        player->y + player->SIZE / 2 > greenBlock1->y - greenBlock1->SIZE / 2 &&
        player->y - player->SIZE / 2 < greenBlock1->y + greenBlock1->SIZE / 2) {

        // �浹 �߻� �� ó��
        player->OnCollisionEnter(*greenBlock1);
    }

    if (player->x + player->SIZE / 2 > greenBlock2->x - greenBlock2->SIZE / 2 &&
        player->x - player->SIZE / 2 < greenBlock2->x + greenBlock2->SIZE / 2 &&
        player->y + player->SIZE / 2 > greenBlock2->y - greenBlock2->SIZE / 2 &&
        player->y - player->SIZE / 2 < greenBlock2->y + greenBlock2->SIZE / 2) {

        // �浹 �߻� �� ó��
        player->OnCollisionEnter(*greenBlock2);
    }
}

void AdjustObjectPositions() {
    // ��ֹ� ���� �浹�� �����ϱ� ���� �ʱ� ��ġ�� �ӵ��� ������ �� �ֽ��ϴ�.
    EnemyBlock* greenBlock1 = static_cast<EnemyBlock*>(objects[1]);
    EnemyBlock* greenBlock2 = static_cast<EnemyBlock*>(objects[2]);

    // �ʷϻ� ��ֹ��� �ӵ��� �����ϰ� ����
    float greenBlockSpeed = -0.5f;

    // �ʷϻ� ��ֹ��� �ʱ� X ��ġ ����
    greenBlock1->x = 0.5f;
    greenBlock2->x = 0.7f;

    // �ʷϻ� ��ֹ��� �ӵ� ����
    greenBlock1->vx = greenBlockSpeed;
    greenBlock2->vx = greenBlockSpeed;
}

int main() {
    if (!glfwInit()) {
        std::cerr << "GLFW �ʱ�ȭ ����" << std::endl;
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(800, 600, "Google Dino Run Copy Game", NULL, NULL);
    if (!window) {
        std::cerr << "GLFW ������ ���� ����" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // V-sync Ȱ��ȭ

    glClearColor(0.0f, 0.1176f, 0.39215f, 1.0f);

    objects[0] = new Player(1.0f, 0.0f, 0.5f, 0.0f, 0.0f);
    objects[1] = new EnemyBlock(1.0f, true, 0.5f, 0.0f, 0.0f, 0.0f);
    objects[2] = new EnemyBlock(1.0f, false, 0.7f, 0.0f, 0.0f, 0.0f);
    objects[3] = new Floor();

    glfwSetKeyCallback(window, keyCallback);

    AdjustObjectPositions(); // �ʱ� ��ġ �� �ӵ� ����

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