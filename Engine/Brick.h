#pragma once

#include "Rect.h"
#include "Colors.h"
#include "Graphics.h"

class Brick
{
public:
	Brick(const Rect& rectInput, Color c);
	void Draw(Graphics& gfx);
private:
	Rect rect;
	Vec2 position;
	Color color;
	bool destroyed = false;
};