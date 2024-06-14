#pragma comment(lib, "Opengl32.lib")
#include <GLFW/glfw3.h>
#include <iostream>

#pragma once
// Base class
class Object {
public:
    virtual void OnCollisionEnter(Object& other) {
    }
};

// Derived classes
class Player : public Object {
public:

    int  play_render() {

        glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 0.0f); // 빨간색

        glVertex2f(-0.8f, -0.6f);   // 왼쪽 아래
        glVertex2f(-0.65f, -0.6f);    // 오른쪽 아래
        glVertex2f(-0.65f, -0.4f);     // 오른쪽 위
        glVertex2f(-0.8f, -0.4f);    // 왼쪽 위

        glEnd();

        return 0;
        /*
        // 플레이어의 크기를 직사각형으로 정의 (cm 단위)
        float half_width = width_cm / 2.0f;   // 너비의 절반
        float half_height = height_cm / 2.0f; // 높이의 절반

        // 직사각형을 그리기 위한 좌표 계산
        float left = -half_width;
        float right = half_width;
        float bottom = -half_height;
        float top = half_height;

        // OpenGL 함수를 사용하여 직사각형 그리기
        glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 0.0f); // 빨간색

        glVertex2f(left, bottom);   // 왼쪽 아래
        glVertex2f(right, bottom);  // 오른쪽 아래
        glVertex2f(right, top);     // 오른쪽 위
        glVertex2f(left, top);      // 왼쪽 위
        */
        glEnd();

        return 0;

    }

    void OnCollisionEnter(Object& other) override {
    }
};

class EnemyBlock : public Object {
public:
    
    int Block() {
        glBegin(GL_QUADS);
        glColor3f(0.0f, 1.0f, 0.0f); // 녹색

        glVertex2f(0.8f, -0.6f);   // 왼쪽 아래
        glVertex2f(0.65f, -0.6f);    // 오른쪽 아래
        glVertex2f(0.65f, 0.1f);     // 오른쪽 위
        glVertex2f(0.8f, 0.1f);    // 왼쪽 위

        glEnd();

        return 0;
    }

    int Block2() {
        glBegin(GL_QUADS);
        glColor3f(0.0f, 1.0f, 0.0f); // 녹색

        glVertex2f(0.6f, -0.6f);   // 왼쪽 아래
        glVertex2f(0.45f, -0.6f);    // 오른쪽 아래
        glVertex2f(0.45f, -0.1f);     // 오른쪽 위
        glVertex2f(0.6f, -0.1f);    // 왼쪽 위

        glEnd();

        return 0;
    }
    void OnCollisionEnter(Object& other) override {
    }
};

class Floor : public Object {
public:

    int GamePloor() {
        glBegin(GL_QUADS);
        glColor3f(1.0f, 0.7843f, 0.0588f); // 황색

        glVertex2f(-1.0f, -1.0f);   // 왼쪽 아래
        glVertex2f(1.0f, -1.0f);    // 오른쪽 아래
        glVertex2f(1.0f, -0.6f);     // 오른쪽 위
        glVertex2f(-1.0f, -0.6f);

        glEnd();

        return 0;

    }
    void OnCollisionEnter(Object& other) override {
    }
};

class Star : public Object {
public:
    void OnCollisionEnter(Object& other) override {
    }
};


int PhysicsAABB(Object A, Object B)
{
    return 0;
}