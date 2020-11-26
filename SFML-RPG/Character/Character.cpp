////////////////////////////////////////////////////////////
//
// SFML-RPG - A top-down RPG demo
// 
// Author - Alex Capsambelis
//
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include "Character.hpp"

namespace rpg {

	////////////////////////////////////////////////////////////
	Character::Character()
	{
		this->health = 0.0f;
		this->speed = 0.0f;
		this->state = 0;
	}

	////////////////////////////////////////////////////////////
	Character::Character(
		std::string name, int id, sf::Vector2f position,
		sf::IntRect texture_rect,
		float health, float speed
	) :
		Block(name, id, position,
			texture_rect)
	{
		this->health = health;
		this->speed = speed;
		this->state = 0;
	}

	////////////////////////////////////////////////////////////
	Character::Character(const Character& copy, int id, sf::Vector2f position) :
		Block(copy, id, position)
	{
		this->health = copy.health;
		this->speed = copy.speed;
		this->state = 0;
	}

	////////////////////////////////////////////////////////////
	Character::~Character()
	{
	}

	////////////////////////////////////////////////////////////
	std::string Character::get_writeable()
	{
		return Block::get_writeable() 
			+ '\n' + std::to_string(health) 
			+ '\n' + std::to_string(speed);
	}

} // namespace rpg
