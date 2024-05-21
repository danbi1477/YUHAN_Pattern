#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.14159265359

void errorCallback(int error, const char* description) {
    printf("\033[1;31mGLFW Error: %s \033[0m\n", description);
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

GLFWwindow* window; // ���� ������ ����

struct CelestialBody {
    float scale;
    float r, g, b;
    float rotation; // ȸ�� ����
    float orbit_rotation; // ���� ����
    float orbit_radius; // ���� ������
    float rotation_speed; // ȸ�� �ӵ�
    float orbit_speed; // ���� �ӵ�
};

struct CelestialBody sun;
struct CelestialBody earth;
struct CelestialBody moon;

void initialize() {
    srand(time(NULL));

    // �¾� �ʱ�ȭ
    sun.scale = 1.0f / 3.0f; // ũ�⸦ ȭ���� 1/3�� ����
    sun.r = 1.0f; // ������
    sun.g = 1.0f; // ���
    sun.b = 0.0f; // �Ķ���
    sun.rotation_speed = 360.0f / (60.0f * 5.0f); // 10�� ���� 360�� ȸ��

    // ���� �ʱ�ȭ
    earth.scale = 0.1f; // ũ�⸦ 0.1�� �����Ͽ� ���簢�� ǥ��
    earth.r = 0.36f; // 5b9bd5 ����
    earth.g = 0.61f;
    earth.b = 0.83f;
    earth.rotation_speed = 360.0f / (60.0f * 5.0f); // 10�� ���� 360�� ȸ��
    earth.orbit_radius = 0.5f; // �¾����κ����� �Ÿ�
    earth.orbit_speed = 360.0f / (300.0f * 5.0f); // 1�� ���� 360�� ����

    // �� �ʱ�ȭ
    moon.scale = 0.03f; // ũ�⸦ �۰� ����
    moon.r = 1.0f; // ���� (fff200)
    moon.g = 0.949f;
    moon.b = 0.0f;
    moon.rotation_speed = 360.0f / (60.0f * 5.0f); 
    moon.orbit_radius = 0.15f; // �����κ����� �Ÿ�
    moon.orbit_speed = 360.0f / (60.0f * 5.0f); 
}

void drawSun(struct CelestialBody body) {
    glColor3f(body.r, body.g, body.b);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0f, 0.0f); // �߽���
    for (int i = 0; i <= 100; ++i) {
        float angle = 2.0f * PI * i / 100;
        float x = body.scale * cosf(angle);
        float y = body.scale * sinf(angle);
        glVertex2f(x, y);
    }
    glEnd();
}

void drawEarth(struct CelestialBody body) {
    glColor3f(body.r, body.g, body.b);
    glBegin(GL_QUADS);
    float half_scale = body.scale / 2.0f;
    glVertex2f(-half_scale, half_scale); // ���� ���
    glVertex2f(-half_scale, -half_scale); // ���� �ϴ�
    glVertex2f(half_scale, -half_scale); // ������ �ϴ�
    glVertex2f(half_scale, half_scale); // ������ ���
    glEnd();
}

void drawStar(float x, float y, float scale) {
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(x, y + 0.5f * scale);
    glVertex2f(x - 0.1f * scale, y - 0.3f * scale);
    glVertex2f(x + 0.1f * scale, y - 0.3f * scale);
    glEnd();
}

void render() {
    glClearColor(0.1f, 0.2f, 0.5f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // �¾� �׸���
    drawSun(sun);

    // ���� �׸���
    glPushMatrix();
    glRotatef(earth.orbit_rotation, 0.0f, 0.0f, 1.0f); // ���� ��ȯ ����
    glTranslatef(earth.orbit_radius, 0.0f, 0.0f); // ���� ��������ŭ �̵�
    glRotatef(earth.rotation, 0.0f, 0.0f, 1.0f); // ȸ�� ��ȯ ����
    drawEarth(earth);

    // �� �׸���
    glPushMatrix();
    glRotatef(moon.orbit_rotation, 0.0f, 0.0f, 1.0f); // ���� ��ȯ ����
    glTranslatef(moon.orbit_radius, 0.0f, 0.0f); // ���� ��������ŭ �̵�
    glRotatef(moon.rotation, 0.0f, 0.0f, 1.0f); // ȸ�� ��ȯ ����
    drawStar(0.0f, 0.0f, moon.scale);
    glPopMatrix();

    glPopMatrix();

    glfwSwapBuffers(window);
}

void updateCelestialBodies() {
    // �¾� ȸ�� ������Ʈ
    sun.rotation += sun.rotation_speed * 0.1f;
    if (sun.rotation > 360.0f) {
        sun.rotation -= 360.0f;
    }

    // ���� ȸ�� �� ���� ������Ʈ
    earth.rotation += earth.rotation_speed * 0.1f;
    if (earth.rotation > 360.0f) {
        earth.rotation -= 360.0f;
    }

    earth.orbit_rotation += earth.orbit_speed * 0.1f;
    if (earth.orbit_rotation > 360.0f) {
        earth.orbit_rotation -= 360.0f;
    }

    // �� ȸ�� �� ���� ������Ʈ
    moon.rotation += moon.rotation_speed * 0.1f;
    if (moon.rotation > 360.0f) {
        moon.rotation -= 360.0f;
    }

    moon.orbit_rotation += moon.orbit_speed * 0.1f;
    if (moon.orbit_rotation > 360.0f) {
        moon.orbit_rotation -= 360.0f;
    }
}

int main(void) {
    if (!glfwInit())
        return -1;

    window = glfwCreateWindow(1280, 768, "SolarSystem", NULL, NULL);

    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetErrorCallback(errorCallback);
    glfwSetKeyCallback(window, keyCallback);

    initialize();

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        updateCelestialBodies();
        render();
    }

    glfwTerminate();
    return 0;
}
