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
    
        float scale = 0.01f; // 별 크기 조절 변수

        glBegin(GL_TRIANGLES);
        // 하얀색
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
    float posX; // 예: 별의 X 위치를 위한 변수
    float color[3]; // 예: 빨강, 초록, 파랑 요소를 위한 배열
    float* getColor() { return color; }
    float posY; // 예: 별의 Y 위치를 위한 변수
};