#pragma once

#include "MObject.h"
#include <GLFW/glfw3.h>

class Star : public MObject
{
public:
    void update()
    {

    }
    void render() override
    {
    
        float scale = 0.01f; // �� ũ�� ���� ����

        glBegin(GL_TRIANGLES);
        // �Ͼ��
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(0.2f * scale, 0.1f * scale);

        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(-0.2f * scale, 0.1f * scale);

        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(0.0f, -0.1f * scale);

        glEnd();

        glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(0.0f, 0.3f * scale);

        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(0.1f * scale, -0.1f * scale);

        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(-0.2f * scale, -0.3f * scale);
        glEnd();

        glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(0.0f, 0.3f * scale);

        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(0.2f * scale, -0.3f * scale);

        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(-0.1f * scale, -0.1f * scale);

        glEnd();
    }
    float posX; // ��: ���� X ��ġ�� ���� ����
    float color[3]; // ��: ����, �ʷ�, �Ķ� ��Ҹ� ���� �迭
    float* getColor() { return color; }
    float posY; // ��: ���� Y ��ġ�� ���� ����
};