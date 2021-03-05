#pragma once

#include "Vec2.h"

class Rectangle
{
public:
	Rectangle() = default;
	Rectangle(float leftInput, float topInput, float rightInput, float bottomInput);
	Rectangle(const Vec2 topLeft, const Vec2 bottomRight);
	Rectangle(const Vec2 topLeft, float width, float height);
	bool IsCollidingWith(const Rectangle& rect) const;
public:
	float left;
	float top;
	float right;
	float bottom;
};