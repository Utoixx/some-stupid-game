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
	gen(rd()),
	//distrX(Poo::GetWidth() * 2, Graphics::ScreenWidth - Poo::GetWidth() - 1),
	//distrY(Poo::GetHeight() * 2, Graphics::ScreenHeight - Poo::GetHeight() - 1),
	distrBool(0, 1),
	//dude(Graphics::ScreenWidth / 2, Graphics::ScreenHeight / 2),
	//object(distrX(gen), distrY(gen), Poo::GetWidth(), Poo::GetHeight()),
	//scoreBar(0, 0, Poo::GetWidth(), Poo::GetHeight())
	board(gfx, 80, 60, 10),
	snake(Location(40, 30), 3)
{
	started = false;
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
	if (wnd.kbd.KeyIsPressed(VK_UP))
		snake.MoveUp();

	if (wnd.kbd.KeyIsPressed(VK_DOWN))
		snake.MoveDown();

	if (wnd.kbd.KeyIsPressed(VK_LEFT))
		snake.MoveLeft();

	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
		snake.MoveRight();

	if (frame < totalFrame)
		++frame;
	else
	{
		snake.MoveNext();
		frame = 0;
	}
}


void Game::ComposeFrame()
{
	//Draw Boxs
	snake.Draw(board);
}
