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
float square_y = 100.0f;  // �ʱ� y ��ġ (�ٴڿ� �굵�� ����)
float square_size = 50.0f;

// Derived classes
class Player : public Object {
public:
    

    int  play_render() {

        

        // ��� �׵θ� �׸���
        glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 1.0f);  // ������� ����

        // ���� �׵θ�
        glVertex2f(square_x - 3.0f, square_y - 3.0f);
        glVertex2f(square_x, square_y - 3.0f);
        glVertex2f(square_x, square_y + square_size + 3.0f);
        glVertex2f(square_x - 3.0f, square_y + square_size + 3.0f);

        // ������ �׵θ�
        glVertex2f(square_x + square_size, square_y - 3.0f);
        glVertex2f(square_x + square_size + 3.0f, square_y - 3.0f);
        glVertex2f(square_x + square_size + 3.0f, square_y + square_size + 3.0f);
        glVertex2f(square_x + square_size, square_y + square_size + 3.0f);

        // ���� �׵θ�
        glVertex2f(square_x - 3.0f, square_y + square_size);
        glVertex2f(square_x + square_size + 3.0f, square_y + square_size);
        glVertex2f(square_x + square_size + 3.0f, square_y + square_size + 3.0f);
        glVertex2f(square_x - 3.0f, square_y + square_size + 3.0f);

        // �Ʒ��� �׵θ�
        glVertex2f(square_x - 3.0f, square_y - 3.0f);
        glVertex2f(square_x + square_size + 3.0f, square_y - 3.0f);
        glVertex2f(square_x + square_size + 3.0f, square_y);
        glVertex2f(square_x - 3.0f, square_y);

        glEnd();

        glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 0.0f);  // ���������� ����
        glVertex2f(square_x, square_y);  // ���� �Ʒ�
        glVertex2f(square_x + square_size, square_y);   // ������ �Ʒ�
        glVertex2f(square_x + square_size, square_y + square_size);    // ������ ��
        glVertex2f(square_x, square_y + square_size);   // ���� ��
        glEnd();

        return 0;
        

    }

    void OnCollisionEnter(Object& other) override {
    }
};


// ���� ��ֹ��� ��ġ�� ũ��
float obstacle_x = 500.0f;  // �ʱ� x ��ġ (ȭ�� ������ ��)
float obstacle_y = floor_height;  // �ʱ� y ��ġ (�ٴڿ� �굵��)
float obstacle_width = 50.0f;
float obstacle_height = 100.0f;

// ū ��ֹ��� ��ġ�� ũ��
float big_obstacle_x = 800.0f;  // �ʱ� x ��ġ (ȭ�� ������ ��)
float big_obstacle_y = floor_height;  // �ʱ� y ��ġ (�ٴڿ� �굵��)
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
        glTranslatef(x, y, 0.0f);  // ��ֹ��� (x, y)�� �̵�
        glBegin(GL_QUADS);  // �簢�� �׸��� ����
        glColor3ub(0, 255, 0);  // ������� ����
        glVertex2f(0.0f, 0.0f);  // ���� �Ʒ�
        glVertex2f(width, 0.0f);  // ������ �Ʒ�
        glVertex2f(width, height);  // ������ ��
        glVertex2f(0.0f, height);  // ���� ��
        glEnd();
        glPopMatrix();

        return 0;
    }
    int Block2() {
        glPushMatrix();
        glTranslatef(x, y, 0.0f);  // ��ֹ��� (x, y)�� �̵�
        glBegin(GL_QUADS);  // �簢�� �׸��� ����
        glColor3ub(0, 255, 0);  // ������� ����
        glVertex2f(0.0f, 0.0f);  // ���� �Ʒ�
        glVertex2f(width, 0.0f);  // ������ �Ʒ�
        glVertex2f(width, height);  // ������ ��
        glVertex2f(0.0f, height);  // ���� ��
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

        glBegin(GL_QUADS);  // �簢�� �׸��� ����
        glColor3ub(255, 200, 15);  // Ȳ������ ����
        glVertex2f(0.0f, 0.0f);  // ���� �Ʒ�
        glVertex2f(800.0f, 0.0f);  // ������ �Ʒ�
        glVertex2f(800.0f, floor_height);  // ������ ��
        glVertex2f(0.0f, floor_height);  // ���� ��
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