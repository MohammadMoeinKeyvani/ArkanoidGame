#include "Rectangle.h"

Rectangle::Rectangle(float leftInput, float topInput, float rightInput, float bottomInput)
	:
	left(leftInput),
	top(topInput),
	right(rightInput),
	bottom(bottomInput)
{
}

Rectangle::Rectangle(const Vec2 topLeft, const Vec2 bottomRight)
	:
	Rectangle(topLeft.x, topLeft.y, bottomRight.x, bottomRight.y)
{
}

Rectangle::Rectangle(const Vec2 topLeft, float width, float height)
	:
	Rectangle(topLeft, topLeft + Vec2(width, height))
{
}

bool Rectangle::IsCollidingWith(const Rectangle& rect) const
{
	return left < rect.right &&
		right > rect.left &&
		top < rect.bottom &&
		bottom > rect.top;
}
