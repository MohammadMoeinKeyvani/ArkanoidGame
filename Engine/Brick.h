#pragma once

#include "Rectangle.h"
#include "Colors.h"
#include "Graphics.h"

class Brick
{
public:
	Brick(const Rectangle& rectInput, Color c);
	void Draw(Graphics& gfx);
private:
	Rectangle rect;
	Vec2 position;
	Color color;
	bool destroyed = false;
};