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
        glColor3f(1.0f, 0.0f, 0.0f); // ������

        glVertex2f(-0.8f, -0.6f);   // ���� �Ʒ�
        glVertex2f(-0.65f, -0.6f);    // ������ �Ʒ�
        glVertex2f(-0.65f, -0.4f);     // ������ ��
        glVertex2f(-0.8f, -0.4f);    // ���� ��

        glEnd();

        return 0;
        /*
        // �÷��̾��� ũ�⸦ ���簢������ ���� (cm ����)
        float half_width = width_cm / 2.0f;   // �ʺ��� ����
        float half_height = height_cm / 2.0f; // ������ ����

        // ���簢���� �׸��� ���� ��ǥ ���
        float left = -half_width;
        float right = half_width;
        float bottom = -half_height;
        float top = half_height;

        // OpenGL �Լ��� ����Ͽ� ���簢�� �׸���
        glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 0.0f); // ������

        glVertex2f(left, bottom);   // ���� �Ʒ�
        glVertex2f(right, bottom);  // ������ �Ʒ�
        glVertex2f(right, top);     // ������ ��
        glVertex2f(left, top);      // ���� ��
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
        glColor3f(0.0f, 1.0f, 0.0f); // ���

        glVertex2f(0.8f, -0.6f);   // ���� �Ʒ�
        glVertex2f(0.65f, -0.6f);    // ������ �Ʒ�
        glVertex2f(0.65f, 0.1f);     // ������ ��
        glVertex2f(0.8f, 0.1f);    // ���� ��

        glEnd();

        return 0;
    }

    int Block2() {
        glBegin(GL_QUADS);
        glColor3f(0.0f, 1.0f, 0.0f); // ���

        glVertex2f(0.6f, -0.6f);   // ���� �Ʒ�
        glVertex2f(0.45f, -0.6f);    // ������ �Ʒ�
        glVertex2f(0.45f, -0.1f);     // ������ ��
        glVertex2f(0.6f, -0.1f);    // ���� ��

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
        glColor3f(1.0f, 0.7843f, 0.0588f); // Ȳ��

        glVertex2f(-1.0f, -1.0f);   // ���� �Ʒ�
        glVertex2f(1.0f, -1.0f);    // ������ �Ʒ�
        glVertex2f(1.0f, -0.6f);     // ������ ��
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