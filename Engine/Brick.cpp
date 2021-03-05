#include "Brick.h"

Brick::Brick(const Rect& rectInput, Color c)
	:
	rect(rectInput),
	color(c)
{
}

void Brick::Draw(Graphics& gfx)
{
	gfx.DrawRect(rect, color);
}
