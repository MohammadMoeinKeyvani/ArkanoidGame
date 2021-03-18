#include "Paddle.h"

Paddle::Paddle(Vec2 inputPos, float inputHalfWidt, float inputHalfHeight)
	:
	position(inputPos),
	halfWidth(inputHalfWidt),
	halfHeight(inputHalfHeight)
{
}

bool Paddle::DoBallCollision(Ball& ball) const
{
	if (ball.GetVelocity().y > 0 && GetRectangle().IsCollidingWith(ball.GetRectangle()))
	{
		ball.ReboundY();
		return true;
	}
	return false;
}

void Paddle::DoWallCollision(const Rect wall)
{
	Rect r = GetRectangle();
	if (r.left < wall.left)
	{
		position.x += wall.left - r.left;
	}
	if (r.right > wall.right)
	{
		position.x += wall.right - r.right;
	}
}

void Paddle::Update(float deltaTime, Keyboard& keyboard)
{
	if (keyboard.KeyIsPressed(VK_LEFT))
	{
		position.x -= speed * deltaTime;
	}
	if (keyboard.KeyIsPressed(VK_RIGHT))
	{
		position.x += speed * deltaTime;
	}
}

void Paddle::Draw(Graphics& gfx)
{
	gfx.DrawRect(GetRectangle(), color);
}

Rect Paddle::GetRectangle() const
{
	return Rect::FromCenter(position, halfWidth, halfHeight);
}
