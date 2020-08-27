//
// EPITECH PROJECT, 2018
// arcade
// File description:
// Interface of Game Handler
//

#ifndef I_GRAPHIC_HANDLER_HPP
#define I_GRAPHIC_HANDLER_HPP

#include "GraphicElements.hpp"

class IGameHandler
{
public:
	virtual ~IGameHandler() = default;
	virtual void init() = 0;
	virtual void update(KeyInput::Key) = 0;
	virtual void display(IGraphicHandler *) = 0;
	virtual void exitLib() = 0;
};

#endif
