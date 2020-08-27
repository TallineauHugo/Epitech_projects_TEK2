//
// EPITECH PROJECT, 2018
// arcade
// File description:
// ncurses
//

#pragma once

#include <utility>
#include <map>
#include "Window.hpp"

typedef std::map<int, KeyInput::Key> NcursesMap;

class NcursesGraphicHandler : virtual public IGraphicHandler
{
public:
	NcursesGraphicHandler();
	~NcursesGraphicHandler();
public:
	void init();
	void createWindow(t_Vector2i);
	void cleanScreen();
	void putPixel(t_Vector2i, t_Color);
	KeyInput::Key getInput();
	void drawRectangle(t_Vector2i, t_Vector2i, t_Color);
	void writeText(t_Vector2i, std::string);
	void refresh();
	void exitLib();

	static std::map<int, KeyInput::Key> _map;	
private:
	void non_block(int);
	int getNcursesColor(t_Color) const;
	t_Color convertColor(t_Color) const;

	Window *win;
	std::map<int, int> colorMap;
};
