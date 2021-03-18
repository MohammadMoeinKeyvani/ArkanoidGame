/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	rect(100, 100, 150, 120),
	brick(rect, Colors::Cyan),
	ball(Vec2(300.0f, 300.0f), Vec2(300.0f, 300.0f)),
	wall(0.0f, 0.0f, float(gfx.ScreenWidth), float(gfx.ScreenHeight)),
	paddleSound(L"Sounds\\arkpad.wav"),
	brickSound(L"Sounds\\arkbrick.wav"),
	paddle(Vec2(400.0f, 500.0f), 50.0f, 15.0f)
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	const float deltaTime = ft.Mark();

	paddle.Update(deltaTime, wnd.kbd);
	paddle.DoWallCollision(wall);

	if (paddle.DoBallCollision(ball))
	{
		paddleSound.Play();
	}
	ball.Update(deltaTime);
	
	if (brick.DoBallCollision(ball))
	{
		brickSound.Play();
	}
	if (ball.IsCollidingWithWall(wall))
	{
		paddleSound.Play();
	}
}

void Game::ComposeFrame()
{
	brick.Draw(gfx);
	ball.Draw(gfx);
	paddle.Draw(gfx);
}
