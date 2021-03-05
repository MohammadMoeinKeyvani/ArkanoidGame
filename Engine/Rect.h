#pragma once

#include "Vec2.h"

class Rect
{
public:
	Rect() = default;
	Rect(float leftInput, float topInput, float rightInput, float bottomInput);
	Rect(const Vec2 topLeft, const Vec2 bottomRight);
	Rect(const Vec2 topLeft, float width, float height);
	bool IsCollidingWith(const Rect& rect) const;
public:
	float left;
	float top;
	float right;
	float bottom;
};