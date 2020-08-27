//
// EPITECH PROJECT, 2018
// arcade
// File description:
// SFML Graphic Handler cpp
//

#include <unistd.h>
#include "SFMLGraphicHandler.hpp"
#include "Input.hpp"
#include <SFML/Window/Keyboard.hpp>
#include <map>

Map SFMLGraphicHandler::KeyMap = {std::make_pair(sf::Keyboard::A, KeyInput::A),
				  std::make_pair(sf::Keyboard::B, KeyInput::B),
				  std::make_pair(sf::Keyboard::C, KeyInput::C),
				  std::make_pair(sf::Keyboard::D, KeyInput::D),
				  std::make_pair(sf::Keyboard::E, KeyInput::E),
				  std::make_pair(sf::Keyboard::F, KeyInput::F),
				  std::make_pair(sf::Keyboard::G, KeyInput::G),
				  std::make_pair(sf::Keyboard::H, KeyInput::H),
				  std::make_pair(sf::Keyboard::I, KeyInput::I),
				  std::make_pair(sf::Keyboard::J, KeyInput::J),
				  std::make_pair(sf::Keyboard::K, KeyInput::K),
				  std::make_pair(sf::Keyboard::L, KeyInput::L),
				  std::make_pair(sf::Keyboard::M, KeyInput::M),
				  std::make_pair(sf::Keyboard::N, KeyInput::N),
				  std::make_pair(sf::Keyboard::O, KeyInput::O),
				  std::make_pair(sf::Keyboard::P, KeyInput::P),
				  std::make_pair(sf::Keyboard::Q, KeyInput::Q),
				  std::make_pair(sf::Keyboard::R, KeyInput::R),
				  std::make_pair(sf::Keyboard::S, KeyInput::S),
				  std::make_pair(sf::Keyboard::T, KeyInput::T),
				  std::make_pair(sf::Keyboard::U, KeyInput::U),
				  std::make_pair(sf::Keyboard::V, KeyInput::V),
				  std::make_pair(sf::Keyboard::W, KeyInput::W),
				  std::make_pair(sf::Keyboard::X, KeyInput::X),
				  std::make_pair(sf::Keyboard::Y, KeyInput::Y),
				  std::make_pair(sf::Keyboard::Z, KeyInput::Z),
				  std::make_pair(sf::Keyboard::Num0, KeyInput::Num0),
				  std::make_pair(sf::Keyboard::Num1, KeyInput::Num1),
				  std::make_pair(sf::Keyboard::Num2, KeyInput::Num2),
				  std::make_pair(sf::Keyboard::Num3, KeyInput::Num3),
				  std::make_pair(sf::Keyboard::Num4, KeyInput::Num4),
				  std::make_pair(sf::Keyboard::Num5, KeyInput::Num5),
				  std::make_pair(sf::Keyboard::Num6, KeyInput::Num6),
				  std::make_pair(sf::Keyboard::Num7, KeyInput::Num7),
				  std::make_pair(sf::Keyboard::Num8, KeyInput::Num8),
				  std::make_pair(sf::Keyboard::Num9, KeyInput::Num9),
				  std::make_pair(sf::Keyboard::Escape, KeyInput::Escape),
				  std::make_pair(sf::Keyboard::LControl, KeyInput::LControl),
				  std::make_pair(sf::Keyboard::LShift, KeyInput::LShift),
				  std::make_pair(sf::Keyboard::LAlt, KeyInput::LAlt),
				  std::make_pair(sf::Keyboard::LSystem, KeyInput::LSystem),
				  std::make_pair(sf::Keyboard::RControl, KeyInput::RControl),
				  std::make_pair(sf::Keyboard::RShift, KeyInput::RShift),
				  std::make_pair(sf::Keyboard::RAlt, KeyInput::RAlt),
				  std::make_pair(sf::Keyboard::RSystem, KeyInput::RSystem),
				  std::make_pair(sf::Keyboard::Menu, KeyInput::Menu),
				  std::make_pair(sf::Keyboard::LBracket, KeyInput::LBracket),
				  std::make_pair(sf::Keyboard::RBracket, KeyInput::RBracket),
				  std::make_pair(sf::Keyboard::SemiColon, KeyInput::SemiColon),
				  std::make_pair(sf::Keyboard::Comma, KeyInput::Comma),
				  std::make_pair(sf::Keyboard::Period, KeyInput::Period),
				  std::make_pair(sf::Keyboard::Quote, KeyInput::Quote),
				  std::make_pair(sf::Keyboard::Slash, KeyInput::Slash),
				  std::make_pair(sf::Keyboard::BackSlash, KeyInput::BackSlash),
				  std::make_pair(sf::Keyboard::Tilde, KeyInput::Tilde),
				  std::make_pair(sf::Keyboard::Equal, KeyInput::Equal),
				  std::make_pair(sf::Keyboard::Dash, KeyInput::Dash),
				  std::make_pair(sf::Keyboard::Space, KeyInput::Space),
				  std::make_pair(sf::Keyboard::Return, KeyInput::Return),
				  std::make_pair(sf::Keyboard::BackSpace, KeyInput::BackSpace),
				  std::make_pair(sf::Keyboard::Tab, KeyInput::Tab),
				  std::make_pair(sf::Keyboard::PageUp, KeyInput::PageUp),
				  std::make_pair(sf::Keyboard::PageDown, KeyInput::PageDown),
				  std::make_pair(sf::Keyboard::End, KeyInput::End),
				  std::make_pair(sf::Keyboard::Home, KeyInput::Home),
				  std::make_pair(sf::Keyboard::Insert, KeyInput::Insert),
				  std::make_pair(sf::Keyboard::Delete, KeyInput::Delete),
				  std::make_pair(sf::Keyboard::Add, KeyInput::Add),
				  std::make_pair(sf::Keyboard::Subtract, KeyInput::Subtract),
				  std::make_pair(sf::Keyboard::Multiply, KeyInput::Multiply),
				  std::make_pair(sf::Keyboard::Divide, KeyInput::Divide),
				  std::make_pair(sf::Keyboard::Left, KeyInput::Left),
				  std::make_pair(sf::Keyboard::Right, KeyInput::Right),
				  std::make_pair(sf::Keyboard::Up, KeyInput::Up),
				  std::make_pair(sf::Keyboard::Down, KeyInput::Down),
				  std::make_pair(sf::Keyboard::Numpad0, KeyInput::Numpad0),
				  std::make_pair(sf::Keyboard::Numpad1, KeyInput::Numpad1),
				  std::make_pair(sf::Keyboard::Numpad2, KeyInput::Numpad2),
				  std::make_pair(sf::Keyboard::Numpad3, KeyInput::Numpad3),
				  std::make_pair(sf::Keyboard::Numpad4, KeyInput::Numpad4),
				  std::make_pair(sf::Keyboard::Numpad5, KeyInput::Numpad5),
				  std::make_pair(sf::Keyboard::Numpad6, KeyInput::Numpad6),
				  std::make_pair(sf::Keyboard::Numpad7, KeyInput::Numpad7),
				  std::make_pair(sf::Keyboard::Numpad8, KeyInput::Numpad8),
				  std::make_pair(sf::Keyboard::Numpad9, KeyInput::Numpad9),
				  std::make_pair(sf::Keyboard::F1, KeyInput::F1),
				  std::make_pair(sf::Keyboard::F2, KeyInput::F2),
				  std::make_pair(sf::Keyboard::F3, KeyInput::F3),
				  std::make_pair(sf::Keyboard::F4, KeyInput::F4),
				  std::make_pair(sf::Keyboard::F5, KeyInput::F5),
				  std::make_pair(sf::Keyboard::F6, KeyInput::F6),
				  std::make_pair(sf::Keyboard::F7, KeyInput::F7),
				  std::make_pair(sf::Keyboard::F8, KeyInput::F8),
				  std::make_pair(sf::Keyboard::F9, KeyInput::F9),
				  std::make_pair(sf::Keyboard::F10, KeyInput::F10),
				  std::make_pair(sf::Keyboard::F11, KeyInput::F11),
				  std::make_pair(sf::Keyboard::F12, KeyInput::F12),
				  std::make_pair(sf::Keyboard::F13, KeyInput::F13),
				  std::make_pair(sf::Keyboard::F14, KeyInput::F14),
				  std::make_pair(sf::Keyboard::F15, KeyInput::F15)
};

SFMLGraphicHandler::SFMLGraphicHandler()
{
	window = new (sf::RenderWindow);
	texture =  new(sf::RenderTexture);
	sprite = new(sf::Sprite);
}

SFMLGraphicHandler::~SFMLGraphicHandler()
{

}

void SFMLGraphicHandler::init()
{
	font.loadFromFile("./neuropol.ttf");
}

void SFMLGraphicHandler::createWindow(t_Vector2i size)
{
	window->create(sf::VideoMode(size.x * 20, size.y * 20), "Arcade");
	sf::View view = window->getDefaultView();
	view.setSize(size.x * 20, -(size.y * 20));
	window->setView(view);
	texture->create(size.x * 20, size.y * 20);
	window->clear();
}

void SFMLGraphicHandler::cleanScreen()
{
	texture->clear();
}

void SFMLGraphicHandler::putPixel(t_Vector2i pos, t_Color color)
{
	sf::RectangleShape rec(sf::Vector2f((float)(1 * 20), (float)(1.0 * 20)));
	sf::Color col(color.r, color.g, color.b, color.a);
	
	rec.setPosition((float)(pos.x * 20), (float)(pos.y * 20));
	rec.setFillColor(col);
	texture->draw(rec);
}

KeyInput::Key SFMLGraphicHandler::getInput()
{
	window->pollEvent(event);
	if (event.type == sf::Event::KeyPressed)
		return KeyMap[event.key.code];
	else
		return KeyInput::UNKNOWN;
}

void SFMLGraphicHandler::drawRectangle(t_Vector2i pos, t_Vector2i size,
				       t_Color color)
{
	sf::RectangleShape rec(sf::Vector2f((float)size.x * 20, (float)size.y * 20));
	sf::Color col(color.r, color.g, color.b, color.a);

	rec.setPosition((float)pos.x * 20, (float)pos.y * 20);
	rec.setFillColor(col);
	texture->draw(rec);
}

void SFMLGraphicHandler::writeText(t_Vector2i pos, std::string content)
{
	sf::Text text(content, font);

	text.setCharacterSize(15);
	text.setPosition(pos.x * 20, pos.y * 20);
	texture->draw(text);
}

void SFMLGraphicHandler::refresh()
{
	sprite->setTexture(texture->getTexture());
	window->draw(*sprite);
	window->display();
	usleep(1000);
}

void SFMLGraphicHandler::exitLib()
{
	texture->clear();
	refresh();
	window->close();
	delete(texture);
	delete(sprite);
}

extern "C"
{
	__attribute__((constructor)) void constructor(void)
	{
	}

	__attribute__((destructor)) void destructor(void)
	{
	}

	SFMLGraphicHandler* entryPoint()
	{
		return (new SFMLGraphicHandler);
	}
}
