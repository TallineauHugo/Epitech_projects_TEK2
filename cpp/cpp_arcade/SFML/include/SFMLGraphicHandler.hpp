//
// EPITECH PROJECT, 2018
// arcade
// File description:
// SFML Graphic Handler
//

#include "GraphicElements.hpp"
#include "Input.hpp"
#include <iostream>
#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

typedef std::map<sf::Keyboard::Key, KeyInput::Key> Map;

class SFMLGraphicHandler : virtual public IGraphicHandler
{
public:
	SFMLGraphicHandler();
	~SFMLGraphicHandler();
public:
	void init();
	void createWindow(t_Vector2i);
	void cleanScreen();
	void putPixel(t_Vector2i, t_Color);
	KeyInput::Key getInput();
	void refresh();
	void writeText(t_Vector2i, std::string);
	void drawRectangle(t_Vector2i, t_Vector2i, t_Color);
	void exitLib();
	static Map KeyMap;
private:
	sf::RenderWindow	*window;
	sf::Event		event;
	sf::Font		font;
	sf::RenderTexture	*texture;
	sf::Sprite		*sprite;
};
