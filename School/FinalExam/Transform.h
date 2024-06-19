#pragma once
#include "Object.h"
#include <chrono>  // 시간 측정을 위한 헤더

namespace Transform
{
	struct Vertex
	{
		float x;
		float y;
	};

	struct Vector
	{
		float x_meter;
		float y_meter;
	};
	Vertex MoveVertex(Vertex point, Vector displacement)
	{
		point.x += displacement.x_meter;
		point.y += displacement.y_meter;
		return point;
	}

	Vertex RotateVertex(Vertex point, float angle_degree)
	{
		float M_PI = 3.141592;
		float angle_rad = angle_degree * M_PI / 180.0f;  // 도를 라디안으로 변환
		float cos_angle = cos(angle_rad);
		float sin_angle = sin(angle_rad);

		float new_x = point.x * cos_angle - point.y * sin_angle;
		float new_y = point.x * sin_angle + point.y * cos_angle;

		point.x = new_x;
		point.y = new_y;

		return point;
	}

	Vertex ScaleVertex(Vertex point, Vector scale)
	{
		point.x *= scale.x_meter;
		point.y *= scale.y_meter;
		return point;
	}

};