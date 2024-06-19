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

float floor_height = 100.0f;

float square_x = 100.0f;
float square_y = 100.0f;  // 초기 y 위치 (바닥에 닿도록 조정)
float square_size = 50.0f;

// Derived classes
class Player : public Object {
public:
    

    int  play_render() {

        

        // 흰색 테두리 그리기
        glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 1.0f);  // 흰색으로 설정

        // 왼쪽 테두리
        glVertex2f(square_x - 3.0f, square_y - 3.0f);
        glVertex2f(square_x, square_y - 3.0f);
        glVertex2f(square_x, square_y + square_size + 3.0f);
        glVertex2f(square_x - 3.0f, square_y + square_size + 3.0f);

        // 오른쪽 테두리
        glVertex2f(square_x + square_size, square_y - 3.0f);
        glVertex2f(square_x + square_size + 3.0f, square_y - 3.0f);
        glVertex2f(square_x + square_size + 3.0f, square_y + square_size + 3.0f);
        glVertex2f(square_x + square_size, square_y + square_size + 3.0f);

        // 위쪽 테두리
        glVertex2f(square_x - 3.0f, square_y + square_size);
        glVertex2f(square_x + square_size + 3.0f, square_y + square_size);
        glVertex2f(square_x + square_size + 3.0f, square_y + square_size + 3.0f);
        glVertex2f(square_x - 3.0f, square_y + square_size + 3.0f);

        // 아래쪽 테두리
        glVertex2f(square_x - 3.0f, square_y - 3.0f);
        glVertex2f(square_x + square_size + 3.0f, square_y - 3.0f);
        glVertex2f(square_x + square_size + 3.0f, square_y);
        glVertex2f(square_x - 3.0f, square_y);

        glEnd();

        glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 0.0f);  // 빨간색으로 설정
        glVertex2f(square_x, square_y);  // 왼쪽 아래
        glVertex2f(square_x + square_size, square_y);   // 오른쪽 아래
        glVertex2f(square_x + square_size, square_y + square_size);    // 오른쪽 위
        glVertex2f(square_x, square_y + square_size);   // 왼쪽 위
        glEnd();

        return 0;
        

    }

    void OnCollisionEnter(Object& other) override {
    }
};


// 작은 장애물의 위치와 크기
float obstacle_x = 500.0f;  // 초기 x 위치 (화면 오른쪽 끝)
float obstacle_y = floor_height;  // 초기 y 위치 (바닥에 닿도록)
float obstacle_width = 50.0f;
float obstacle_height = 100.0f;

// 큰 장애물의 위치와 크기
float big_obstacle_x = 800.0f;  // 초기 x 위치 (화면 오른쪽 끝)
float big_obstacle_y = floor_height;  // 초기 y 위치 (바닥에 닿도록)
float big_obstacle_width = 50.0f;
float big_obstacle_height = 300.0f;



class EnemyBlock : public Object {
public:
    float x;
    float y;
    float width;
    float height;

    EnemyBlock(float _x, float _y, float _width, float _height)
        : x(_x), y(_y), width(_width), height(_height) {}

    EnemyBlock() : x(0.0f), y(0.0f), width(0.0f), height(0.0f) {}

    int Block() {
        glPushMatrix();
        glTranslatef(x, y, 0.0f);  // 장애물을 (x, y)로 이동
        glBegin(GL_QUADS);  // 사각형 그리기 시작
        glColor3ub(0, 255, 0);  // 녹색으로 설정
        glVertex2f(0.0f, 0.0f);  // 왼쪽 아래
        glVertex2f(width, 0.0f);  // 오른쪽 아래
        glVertex2f(width, height);  // 오른쪽 위
        glVertex2f(0.0f, height);  // 왼쪽 위
        glEnd();
        glPopMatrix();

        return 0;
    }
    int Block2() {
        glPushMatrix();
        glTranslatef(x, y, 0.0f);  // 장애물을 (x, y)로 이동
        glBegin(GL_QUADS);  // 사각형 그리기 시작
        glColor3ub(0, 255, 0);  // 녹색으로 설정
        glVertex2f(0.0f, 0.0f);  // 왼쪽 아래
        glVertex2f(width, 0.0f);  // 오른쪽 아래
        glVertex2f(width, height);  // 오른쪽 위
        glVertex2f(0.0f, height);  // 왼쪽 위
        glEnd();
        glPopMatrix();

        return 0;
    }



    void OnCollisionEnter(Object& other) override {
    }
};

class Floor : public Object {
public:

    int GamePloor() {

        glBegin(GL_QUADS);  // 사각형 그리기 시작
        glColor3ub(255, 200, 15);  // 황색으로 설정
        glVertex2f(0.0f, 0.0f);  // 왼쪽 아래
        glVertex2f(800.0f, 0.0f);  // 오른쪽 아래
        glVertex2f(800.0f, floor_height);  // 오른쪽 위
        glVertex2f(0.0f, floor_height);  // 왼쪽 위
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