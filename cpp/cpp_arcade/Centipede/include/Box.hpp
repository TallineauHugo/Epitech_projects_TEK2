//
// EPITECH PROJECT, 2018
// arcade
// File description:
// Centipede Box struct
//

#ifndef BOX_HPP_
#define BOX_HPP_

#include "Object.hpp"
#include "GraphicElements.hpp"

class Box : public virtual Object
{
public:
	Box(t_Vector2i pos = t_Vector2i(0, 0));
	~Box();
public:
	void display(IGraphicHandler *);
};

#endif
