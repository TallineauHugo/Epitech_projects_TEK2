//
// EPITECH PROJECT, 2018
// arcade
// File description:
// window
//

#include <stdlib.h>
#include "ArcadeError.hpp"
#include "Window.hpp"

Window::Window()
{
	window = NULL;
	height = 0;
	lenght = 0;
}

Window::~Window()
{
	delwin(window);
}

void Window::createWindow(t_Vector2i size)
{
	window = newwin(size.y, size.x, 0, 0);
	height = size.y;
	lenght = size.x;
	if (!window)
		throw ArcadeError("Invalid window size: unknown error !\n");
	keypad(window, TRUE);
	wrefresh(window);
}
