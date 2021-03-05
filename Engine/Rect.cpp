#include "Rect.h"

Rect::Rect(float leftInput, float topInput, float rightInput, float bottomInput)
	:
	left(leftInput),
	top(topInput),
	right(rightInput),
	bottom(bottomInput)
{
}

Rect::Rect(const Vec2 topLeft, const Vec2 bottomRight)
	:
	Rect(topLeft.x, topLeft.y, bottomRight.x, bottomRight.y)
{
}

Rect::Rect(const Vec2 topLeft, float width, float height)
	:
	Rect(topLeft, topLeft + Vec2(width, height))
{
}

bool Rect::IsCollidingWith(const Rect& rect) const
{
	return left < rect.right &&
		right > rect.left &&
		top < rect.bottom &&
		bottom > rect.top;
}
