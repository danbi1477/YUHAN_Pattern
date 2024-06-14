
#pragma comment(lib, "Opengl32.lib")
#include <GLFW/glfw3.h>
#include <iostream>

// �߷� ���ӵ� ���
const float GRAVITY = 9.81f;
// ���� �ӵ� ���
const float JUMP_VELOCITY = 5.0f;
// �̵� �ӵ� ���
const float MOVE_SPEED = 2.0f;

// ����� �ʱ� ��ġ�� �ӵ�
float personX = 0.0f;
float personY = -0.5f;
float velocityY = 0.0f;

// ����� ũ��
const float PERSON_HEIGHT = 0.3f;
const float PERSON_WIDTH = 0.2f;

// �ٴ� ��ġ
const float GROUND_Y = -0.5f;

// ����� �ٴڿ� �ִ��� Ȯ���ϴ� �÷���
bool isOnGround = true;

// Ű ���� ����
bool moveLeft = false;
bool moveRight = false;

void updatePersonPosition(float deltaTime) {
    // �߷� ���ӵ��� �ӵ��� �ݿ�
    if (!isOnGround) {
        velocityY += GRAVITY * deltaTime;
    }

    // �ӵ��� ��ġ�� �ݿ�
    personY -= velocityY * deltaTime;

    // �ٴڿ� �����ϸ� ����� ���߰� ��
    if (personY < GROUND_Y) {
        personY = GROUND_Y;
        velocityY = 0.0f;
        isOnGround = true;
    }

    // �¿� �̵� �ݿ�
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
    // ����� ���� (�簢��)
    glVertex3f(personLeft, personBottom, 0.0f);
    glVertex3f(personRight, personBottom, 0.0f);
    glVertex3f(personRight, personTop, 0.0f);
    glVertex3f(personLeft, personTop, 0.0f);
    glEnd();
}

void drawGround() {
    glBegin(GL_QUADS);
    // �� �׸��� (���η� �� �簢��)
    glVertex3f(-1.0f, GROUND_Y - 0.05f, 0.0f);
    glVertex3f(1.0f, GROUND_Y - 0.05f, 0.0f);
    glVertex3f(1.0f, GROUND_Y + 0.05f, 0.0f);
    glVertex3f(-1.0f, GROUND_Y + 0.05f, 0.0f);
    glEnd();
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_SPACE && action == GLFW_PRESS && isOnGround) {
        // ����� �ٴڿ� ���� ���� ������ �� ����
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
    // GLFW �ʱ�ȭ
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    // ������ ���� (1280x960)
    GLFWwindow* window = glfwCreateWindow(1280, 960, "Jumping Person", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    // Ű���� �Է� �ݹ� ����
    glfwSetKeyCallback(window, keyCallback);

    float lastTime = glfwGetTime();

    // ���� ����
    while (!glfwWindowShouldClose(window)) {
        float currentTime = glfwGetTime();
        float deltaTime = currentTime - lastTime;
        lastTime = currentTime;

        // ��� ��ġ ������Ʈ
        updatePersonPosition(deltaTime);

        // ȭ�� �����
        glClear(GL_COLOR_BUFFER_BIT);

        // �� �׸���
        drawGround();

        // ��� �׸���
        drawPerson();

        // ���� ��ȯ
        glfwSwapBuffers(window);

        // �̺�Ʈ ó��
        glfwPollEvents();
    }

    // GLFW ����
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}