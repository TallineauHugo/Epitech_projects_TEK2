//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#pragma once

#include <ncurses.h>
#include "GraphicElements.hpp"

class Window
{
public:
	Window();
	~Window();
	void createWindow(t_Vector2i);
public:
	int height;
	int lenght;
	WINDOW *window;
	
};
