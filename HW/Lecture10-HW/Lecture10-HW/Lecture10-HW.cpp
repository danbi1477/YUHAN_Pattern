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

GLFWwindow* window; // 전역 변수로 선언

struct CelestialBody {
    float scale;
    float r, g, b;
    float rotation; // 회전 각도
    float orbit_rotation; // 공전 각도
    float orbit_radius; // 공전 반지름
    float rotation_speed; // 회전 속도
    float orbit_speed; // 공전 속도
};

struct CelestialBody sun;
struct CelestialBody earth;
struct CelestialBody moon;

void initialize() {
    srand(time(NULL));

    // 태양 초기화
    sun.scale = 1.0f / 3.0f; // 크기를 화면의 1/3로 설정
    sun.r = 1.0f; // 빨간색
    sun.g = 1.0f; // 녹색
    sun.b = 0.0f; // 파란색
    sun.rotation_speed = 360.0f / (60.0f * 5.0f); // 10초 동안 360도 회전

    // 지구 초기화
    earth.scale = 0.1f; // 크기를 0.1로 설정하여 정사각형 표현
    earth.r = 0.36f; // 5b9bd5 색상
    earth.g = 0.61f;
    earth.b = 0.83f;
    earth.rotation_speed = 360.0f / (60.0f * 5.0f); // 10초 동안 360도 회전
    earth.orbit_radius = 0.5f; // 태양으로부터의 거리
    earth.orbit_speed = 360.0f / (300.0f * 5.0f); // 1분 동안 360도 공전

    // 달 초기화
    moon.scale = 0.03f; // 크기를 작게 설정
    moon.r = 1.0f; // 색상 (fff200)
    moon.g = 0.949f;
    moon.b = 0.0f;
    moon.rotation_speed = 360.0f / (60.0f * 5.0f); 
    moon.orbit_radius = 0.15f; // 지구로부터의 거리
    moon.orbit_speed = 360.0f / (60.0f * 5.0f); 
}

void drawSun(struct CelestialBody body) {
    glColor3f(body.r, body.g, body.b);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0f, 0.0f); // 중심점
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
    glVertex2f(-half_scale, half_scale); // 왼쪽 상단
    glVertex2f(-half_scale, -half_scale); // 왼쪽 하단
    glVertex2f(half_scale, -half_scale); // 오른쪽 하단
    glVertex2f(half_scale, half_scale); // 오른쪽 상단
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

    // 태양 그리기
    drawSun(sun);

    // 지구 그리기
    glPushMatrix();
    glRotatef(earth.orbit_rotation, 0.0f, 0.0f, 1.0f); // 공전 변환 적용
    glTranslatef(earth.orbit_radius, 0.0f, 0.0f); // 공전 반지름만큼 이동
    glRotatef(earth.rotation, 0.0f, 0.0f, 1.0f); // 회전 변환 적용
    drawEarth(earth);

    // 달 그리기
    glPushMatrix();
    glRotatef(moon.orbit_rotation, 0.0f, 0.0f, 1.0f); // 공전 변환 적용
    glTranslatef(moon.orbit_radius, 0.0f, 0.0f); // 공전 반지름만큼 이동
    glRotatef(moon.rotation, 0.0f, 0.0f, 1.0f); // 회전 변환 적용
    drawStar(0.0f, 0.0f, moon.scale);
    glPopMatrix();

    glPopMatrix();

    glfwSwapBuffers(window);
}

void updateCelestialBodies() {
    // 태양 회전 업데이트
    sun.rotation += sun.rotation_speed * 0.1f;
    if (sun.rotation > 360.0f) {
        sun.rotation -= 360.0f;
    }

    // 지구 회전 및 공전 업데이트
    earth.rotation += earth.rotation_speed * 0.1f;
    if (earth.rotation > 360.0f) {
        earth.rotation -= 360.0f;
    }

    earth.orbit_rotation += earth.orbit_speed * 0.1f;
    if (earth.orbit_rotation > 360.0f) {
        earth.orbit_rotation -= 360.0f;
    }

    // 달 회전 및 공전 업데이트
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
