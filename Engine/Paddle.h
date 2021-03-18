#pragma once

#include "Vec2.h"
#include "Ball.h"
#include "Colors.h"
#include "Keyboard.h"

class Paddle
{
public:
	Paddle(Vec2 inputPos, float inputHalfWidt, float inputHalfHeight);
	bool DoBallCollision(Ball& ball) const;
	void DoWallCollision(const Rect wall);
	void Update(float deltaTime, Keyboard& keyboard);
	void Draw(Graphics& gfx);
	Rect GetRectangle() const;
private:
	Vec2 position;
	Color color = Colors::LightGray;
	float halfWidth;
	float halfHeight;
	float speed = 200;
};