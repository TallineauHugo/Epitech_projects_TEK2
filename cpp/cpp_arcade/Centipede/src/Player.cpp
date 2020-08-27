//
// EPITECH PROJECT, 2018
// arcade
// File description:
// Centipede Player
//

#include "Player.hpp"
#include "Centipede.hpp"

std::map<KeyInput::Key, Direction> Player::_mvmts = {std::make_pair(KeyInput::Right, RIGHT),
						     std::make_pair(KeyInput::Left, LEFT),
						     std::make_pair(KeyInput::Down, DOWN),
						     std::make_pair(KeyInput::Up, UP)
};

Player::Player(t_Vector2i pos) : Object(1, pos)
{
	_bullet = new Bullet;
}

Player::~Player()
{
}

void Player::moveBullet()
{
	_bullet->moveForward();
}

void Player::move(KeyInput::Key key, CentipedeGameHandler& game)
{
	t_Vector2i tmp = _pos;

	if (Player::_mvmts.find(key) == Player::_mvmts.end())
		return;
	switch (Player::_mvmts[key]) {
	case LEFT:
		_pos.x -= (_pos.x > 0) ? 1 : 0;
		break;
	case RIGHT:
		_pos.x += (_pos.x < game.getMapsize().x - PLAYER_SIZE_X ) ? 1 : 0;
		break;
	case UP:
		_pos.y -= (_pos.y > (game.getMapsize().y / 5) * 4 ) ? 1 : 0;
		break;
	case DOWN:
		_pos.y += (_pos.y < game.getMapsize().y) ? 1 : 0;
		break;
	}
	_pos = (!game.check_boxes(_pos, t_Vector2i(PLAYER_SIZE_X,
						   PLAYER_SIZE_Y))) ?_pos : tmp;
}

void Player::shoot()
{
	if (!_bullet->getShot())
		_bullet->setPos(t_Vector2i(_pos.x + 1,_pos.y));
	_bullet->setShot(true);
}

void Player::hitCentipede(std::list<CentipedeBody> body, CentipedeGameHandler& game)
{
	std::list<CentipedeBody>::iterator it = body.begin();
	t_Vector2i size(PLAYER_SIZE_X, PLAYER_SIZE_Y); 

	while (it != body.end()) {
		if (((_pos.x + size.x <= it->getPos().x + CENTIPEDE_SIZE_X
		      && _pos.x + size.x > it->getPos().x)
		     || (_pos.x < it->getPos().x + CENTIPEDE_SIZE_X
			 && _pos.x >= it->getPos().x))
		    && ((_pos.y + size.y <= it->getPos().y + CENTIPEDE_SIZE_Y
			 && _pos.y + size.y > it->getPos().y)
			|| (_pos.y < it->getPos().y + CENTIPEDE_SIZE_Y
			    && _pos.y >= it->getPos().y)))
			game.lost();
		it++;
	}
}

void Player::detectHit(CentipedeGameHandler& game)
{
	std::vector<Centipede> tmp = game.getCent();
	std::vector<Centipede>::iterator it = tmp.begin();

	while (it != tmp.end())	{
		hitCentipede(it->_body, game);
		it++;
	}
	_bullet->detectHit(game);
}

void Player::display(IGraphicHandler *lib)
{
	lib->drawRectangle(t_Vector2i(_pos.x, _pos.y + 1),
			   t_Vector2i(1, 2), t_Color());
	lib->drawRectangle(t_Vector2i(_pos.x + 1, _pos.y),
			   t_Vector2i(1, 2), t_Color());
	lib->drawRectangle(t_Vector2i(_pos.x + 2, _pos.y + 1),
			   t_Vector2i(1, 2), t_Color());
}

Bullet *Player::getBullet()
{
	return _bullet;
}
