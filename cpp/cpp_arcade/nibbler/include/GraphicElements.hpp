//
// EPITECH PROJECT, 2018
// arcade
// File description:
// Elements with graphic purpose
//

#pragma once

#include <string>
#include "Input.hpp"

typedef struct s_Vector2i
{
	s_Vector2i(int x = 0, int y = 0);
	int x;
	int y;
}		t_Vector2i;

typedef struct s_Color
{
	s_Color(int r = 255, int g = 255, int b = 255);
	int r;
	int g;
	int b;
	int a;
}		t_Color;

class IGraphicHandler
{
public:
	~IGraphicHandler() = default;
				    
public:
	virtual void init() = 0;
	virtual void createWindow(t_Vector2i) = 0;
	virtual void cleanScreen() = 0;
	virtual void putPixel(t_Vector2i, t_Color) = 0;
	virtual KeyInput::Key getInput() = 0;
	virtual void drawRectangle(t_Vector2i, t_Vector2i, t_Color) = 0;
	virtual void writeText(t_Vector2i, std::string) = 0;
	virtual void refresh() = 0;
	virtual void exitLib() = 0;	
};
