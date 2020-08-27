//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include "Cell.hpp"

class Head : public Cell
{
public:
	Head(t_Vector2i);
	~Head();
public:
	void display(IGraphicHandler*) const;
};
