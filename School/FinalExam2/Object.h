#pragma once
#include "pch.h"

class Object {
public:
    float x, y;
    float vx, vy;
    float SIZE = 50.0f * 0.0025f;

    Object(float x = 0, float y = 0, float vx = 0, float vy = 0)
        : x(x), y(y), vx(vx), vy(vy) {}

    virtual void update(float deltaTime, float floorY) {
        x += vx * deltaTime;
        y += vy * deltaTime;
    }

    virtual void render() {}

    virtual void OnCollisionEnter(Object& other) {}
};

class Player : public Object {
public:
    float mass;
    float GRAVITY = 9.8f;
    float jumpSpeed = 5.0f;
    bool isJumping = false;
    float jumpStartTime = 0.0f;

    Player(float mass, float x = 0, float y = 0, float vx = 0, float vy = 0)
        : Object(x, y, vx, vy), mass(mass) {}

    void update(float deltaTime, float floorY) override {
        if (isJumping) {
            float jumpTime = glfwGetTime() - jumpStartTime;
            float jumpStrength = calculateJumpStrength(jumpTime);
            vy = jumpStrength;
            isJumping = false;
        }
        else {
            vy -= GRAVITY * deltaTime;
        }

        x += vx * deltaTime;
        y += vy * deltaTime;

        if (y - SIZE / 2 <= floorY) {
            y = floorY + SIZE / 2;
            vy = 0;
        }

        x = std::max(-1.0f + SIZE / 2, std::min(1.0f - SIZE / 2, x));
        y = std::max(-1.0f + SIZE / 2, std::min(1.0f - SIZE / 2, y));
    }

    void render() override {
        float aspectRatio = 800.0f / 600.0f;
        float normalizedWidth = SIZE * aspectRatio;
        float normalizedHeight = SIZE;
        float borderWidth = 0.01f;

        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_QUADS);
        glVertex2f(x - normalizedHeight / 2 - borderWidth, y - normalizedWidth / 2 - borderWidth);
        glVertex2f(x + normalizedHeight / 2 + borderWidth, y - normalizedWidth / 2 - borderWidth);
        glVertex2f(x + normalizedHeight / 2 + borderWidth, y + normalizedWidth / 2 + borderWidth);
        glVertex2f(x - normalizedHeight / 2 - borderWidth, y + normalizedWidth / 2 + borderWidth);
        glEnd();

        glColor3f(1.0f, 0.0f, 0.0f);
        glBegin(GL_QUADS);
        glVertex2f(x - normalizedHeight / 2, y - normalizedWidth / 2);
        glVertex2f(x + normalizedHeight / 2, y - normalizedWidth / 2);
        glVertex2f(x + normalizedHeight / 2, y + normalizedWidth / 2);
        glVertex2f(x - normalizedHeight / 2, y + normalizedWidth / 2);
        glEnd();
    }

    void jump(float jumpTime) {
        if (!isJumping && y - SIZE / 2 <= 0.0f) {
            isJumping = true;
            jumpStartTime = glfwGetTime();
        }
    }

    float calculateJumpStrength(float jumpTime) {
        const float maxJumpTime = 0.5f;
        jumpTime = std::min(jumpTime, maxJumpTime);
        float t = jumpTime / maxJumpTime;
        return jumpSpeed * (1.0f - t) + 8.0f * t;
    }

    void OnCollisionEnter(Object& other) override {
        // 플레이어와 충돌 발생 시 게임 종료
        std::cout << "Game Over!" << std::endl;
        glfwSetWindowShouldClose(glfwGetCurrentContext(), GLFW_TRUE);
    }
};

class EnemyBlock : public Object {
public:
    float mass;
    bool isHigh;

    EnemyBlock(float mass, bool isHigh, float x = 0, float y = 0, float vx = 0, float vy = 0)
        : Object(x, y, vx, vy), mass(mass), isHigh(isHigh) {}

    void update(float deltaTime, float floorY) override {
        x += vx * deltaTime; // 우측으로 이동
        if (x < -1.0f - SIZE / 2) { // 화면을 벗어나면 다시 우측에서 나타나도록 설정
            x = 1.0f + SIZE / 2;
        }
    }

    void render() override {
        float width = 0.0025f * 50;
        float height = isHigh ? 0.0025f * 100.0f : 0.0025f * 300.0f;
        float bottomY = -1.0f + 0.25f + height / 2.0f;
        y = bottomY;

        glColor3ub(0, 255, 0);
        glBegin(GL_QUADS);
        glVertex2f(x - width / 2, y - height / 2);
        glVertex2f(x + width / 2, y - height / 2);
        glVertex2f(x + width / 2, y + height / 2);
        glVertex2f(x - width / 2, y + height / 2);
        glEnd();
    }

    void OnCollisionEnter(Object& other) override {
        // 충돌 처리
    }
};

class Floor : public Object {
public:
    void update(float deltaTime, float floorY) override {
        // 바닥은 움직이지 않음
    }

    void render() override {
        glColor3f(1.0f, 0.784f, 0.059f);
        glBegin(GL_QUADS);
        glVertex2f(-1.0f, -0.0025f * 300);
        glVertex2f(1.0f, -0.0025f * 300);
        glVertex2f(1.0f, -0.0025f * 400);
        glVertex2f(-1.0f, -0.0025f * 400);
        glEnd();
    }

    void OnCollisionEnter(Object& other) override {
        // 충돌 처리
    }
};

class Star : public Object {
public:
    void OnCollisionEnter(Object& other) override {
        // 충돌 처리
    }
};