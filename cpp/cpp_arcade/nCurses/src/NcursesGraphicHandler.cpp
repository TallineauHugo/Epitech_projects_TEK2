//
// EPITECH PROJECT, 2018
// arcade
// File description:
// ncurses
//

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <term.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include "NcursesGraphicHandler.hpp"

NcursesGraphicHandler::NcursesGraphicHandler()
{
	win = new Window;
}

NcursesGraphicHandler::~NcursesGraphicHandler()
{
}

void NcursesGraphicHandler::init()
{
	win->window = initscr();
	clear();
	noecho();
	cbreak();
	curs_set(0);
	start_color();
	init_pair(1, COLOR_BLACK, COLOR_BLACK);
	init_pair(2, COLOR_BLACK, COLOR_RED);
	init_pair(3, COLOR_BLACK, COLOR_GREEN);
	init_pair(4, COLOR_BLACK, COLOR_YELLOW);
	init_pair(5, COLOR_BLACK, COLOR_BLUE);
	init_pair(6, COLOR_BLACK, COLOR_MAGENTA);
	init_pair(7, COLOR_BLACK, COLOR_CYAN);
	init_pair(8, COLOR_BLACK, COLOR_WHITE);
}

void NcursesGraphicHandler::createWindow(t_Vector2i size)
{
	size.x *= 2;
	if (size.x > COLS || size.y > LINES) {
		mvwprintw(win->window, 0, 0, "resize !");
		wrefresh(win->window);
	}
	while (size.x > COLS || size.y > LINES)
		usleep(500);
	if (size.x <= 0)
		size.x = COLS;
	if (size.y <= 0)
		size.y = LINES;
	win->createWindow(size);
}

void NcursesGraphicHandler::cleanScreen()
{
	wclear(win->window);
}

t_Color NcursesGraphicHandler::convertColor(t_Color col) const
{
	if (col.r <= 127)
		col.r = 0;
	else
		col.r = 255;
	if (col.g <= 127)
		col.g = 0;
	else
		col.g = 255;
	if (col.b <= 127)
		col.b = 0;
	else
		col.b = 255;
	return col;
}

int NcursesGraphicHandler::getNcursesColor(t_Color col) const
{
	int ret = 0;

	if (col.r == 255)
		ret += COLOR_RED;
	if (col.g == 255)
		ret += COLOR_GREEN;	
	if (col.b == 255)
		ret += COLOR_BLUE;
	return ret;
}

void NcursesGraphicHandler::putPixel(t_Vector2i pos, t_Color col)
{
	int colorPair = 0;
	
	if (pos.x > win->lenght || pos.y > win->height)
		return;
	pos.x = (pos.x < 0) ? 0 : pos.x;
	pos.y = (pos.y < 0) ? 0 : pos.y;
	colorPair = getNcursesColor(col) + 1;
	wattron(win->window, COLOR_PAIR(colorPair));
	mvwprintw(win->window, pos.y, pos.x, " ");
	wattroff(win->window, COLOR_PAIR(colorPair));
}

KeyInput::Key NcursesGraphicHandler::getInput()
{
	int c;

	wtimeout(win->window, 100);
	c = wgetch(win->window);
	flushinp();
	if (_map.find(c) != _map.end())
		return _map[c];
	return KeyInput::UNKNOWN;
}

void NcursesGraphicHandler::drawRectangle(t_Vector2i pos,
					  t_Vector2i size, t_Color col)
{
	t_Vector2i start;
	t_Vector2i goal;
	
	start.x = (pos.x * 2);
	start.y = pos.y;
	goal.x = (pos.x + size.x) * 2;
	goal.y = pos.y + size.y;

	col = convertColor(col);
	while (start.x < goal.x) {
		while (start.y < goal.y) {
			putPixel(start, col);
			start.y += 1;
		}
		start.y = pos.y;
		start.x += 1;
	}
}

void NcursesGraphicHandler::writeText(t_Vector2i pos, std::string str)
{
	if (pos.x > win->lenght || pos.y > win->height)
		return;
	pos.x = (pos.x < 0) ? 0 : pos.x;
	pos.y = (pos.y < 0) ? 0 : pos.y;

	wattron(win->window, COLOR_PAIR(2));
	mvwprintw(win->window, pos.y, (pos.x * 2), str.c_str());
	wrefresh(win->window);
	wattroff(win->window, COLOR_PAIR(2));
}

void NcursesGraphicHandler::refresh()
{
	wrefresh(win->window);
}

void NcursesGraphicHandler::exitLib()
{
	clrtoeol();
	refresh();
	endwin();
}

NcursesMap NcursesGraphicHandler::_map = {
	std::make_pair('a', KeyInput::A),
	std::make_pair('b', KeyInput::B),
	std::make_pair('c', KeyInput::C),
	std::make_pair('d', KeyInput::D),
	std::make_pair('e', KeyInput::E),
	std::make_pair('f', KeyInput::F),
	std::make_pair('g', KeyInput::G),
	std::make_pair('h', KeyInput::H),
	std::make_pair('i', KeyInput::I),
	std::make_pair('j', KeyInput::J),
	std::make_pair('k', KeyInput::K),
	std::make_pair('l', KeyInput::L),
	std::make_pair('m', KeyInput::M),
	std::make_pair('n', KeyInput::N),
	std::make_pair('o', KeyInput::O),
	std::make_pair('p', KeyInput::P),
	std::make_pair('q', KeyInput::Q),
	std::make_pair('r', KeyInput::R),
	std::make_pair('s', KeyInput::S),
	std::make_pair('t', KeyInput::T),
	std::make_pair('u', KeyInput::U),
	std::make_pair('v', KeyInput::V),
	std::make_pair('w', KeyInput::W),
	std::make_pair('x', KeyInput::X),
	std::make_pair('y', KeyInput::Y),
	std::make_pair('z', KeyInput::Z),
	std::make_pair(160, KeyInput::Num0),
	std::make_pair('&', KeyInput::Num1),
	std::make_pair(195, KeyInput::Num2),
	std::make_pair('"', KeyInput::Num3),
	std::make_pair('\'', KeyInput::Num4),
	std::make_pair('(', KeyInput::Num5),
	std::make_pair('-', KeyInput::Num6),
	std::make_pair(195, KeyInput::Num7),
	std::make_pair('_', KeyInput::Num8),
	std::make_pair(167, KeyInput::Num9),
	std::make_pair(27, KeyInput::Escape),
	std::make_pair('[', KeyInput::LBracket),
	std::make_pair(']', KeyInput::RBracket),
	std::make_pair(';', KeyInput::SemiColon),
	std::make_pair(',', KeyInput::Comma),
	std::make_pair('.', KeyInput::Period),
	std::make_pair('`', KeyInput::Quote),
	std::make_pair('/', KeyInput::Slash),
	std::make_pair('\\', KeyInput::BackSlash),
	std::make_pair('~', KeyInput::Tilde),
	std::make_pair('=', KeyInput::Equal),
	std::make_pair('-', KeyInput::Dash),
	std::make_pair(' ', KeyInput::Space),
	std::make_pair(10, KeyInput::Return),
	std::make_pair(263, KeyInput::BackSpace),
	std::make_pair('\t', KeyInput::Tab),
	std::make_pair(339, KeyInput::PageUp),
	std::make_pair(338, KeyInput::PageDown),
	std::make_pair(360, KeyInput::End),
	std::make_pair(KEY_HOME, KeyInput::Home),
	std::make_pair(331, KeyInput::Insert),
	std::make_pair(330, KeyInput::Delete),
	std::make_pair('+', KeyInput::Add),
	std::make_pair('-', KeyInput::Subtract),
	std::make_pair('*', KeyInput::Multiply),
	std::make_pair('/', KeyInput::Divide),
	std::make_pair(KEY_LEFT, KeyInput::Left),
	std::make_pair(KEY_RIGHT, KeyInput::Right),
	std::make_pair(KEY_UP, KeyInput::Up),
	std::make_pair(KEY_DOWN, KeyInput::Down),
	std::make_pair(266, KeyInput::F2),
	std::make_pair(267, KeyInput::F3),
	std::make_pair(268, KeyInput::F4),
	std::make_pair(269, KeyInput::F5),
	std::make_pair(270, KeyInput::F6),
	std::make_pair(271, KeyInput::F7),
	std::make_pair(272, KeyInput::F8),
	std::make_pair(273, KeyInput::F9),
	std::make_pair(274, KeyInput::F10),
	std::make_pair(410, KeyInput::F11),
	std::make_pair(276, KeyInput::F12),
	std::make_pair(268, KeyInput::F13),
	std::make_pair(268, KeyInput::F14),
	std::make_pair(268, KeyInput::F15)
};

extern "C"
{
	__attribute__((constructor)) void constructor(void)
	{
	}

	__attribute__((destructor)) void destructor(void)
	{
	}

	NcursesGraphicHandler* entryPoint()
	{
		NcursesGraphicHandler *ret = new NcursesGraphicHandler;
		return (ret);
	}
}
