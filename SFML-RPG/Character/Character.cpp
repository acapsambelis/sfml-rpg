#include "Character.h"

Character::Character()
{
	this->health = 0.0f;
	this->speed = 0.0f;

	this->state = 0;
}

Character::Character(
	std::string name, int ID, sf::Vector2f position,
	sf::IntRect rect,
	float health, float speed
	) :
	WorldObject(name, ID, position, 
		rect)
{
	this->health = health;
	this->speed = speed;

	this->state = 0;
}

Character::Character(const Character& cpy, int ID, sf::Vector2f position) :
	WorldObject(cpy, ID, position)
{
	this->health = cpy.health;
	this->speed = cpy.speed;

	this->state = 0;
}

Character::~Character()
{
}

std::string Character::GetWriteable()
{
	return WorldObject::GetWriteable() + '\n' + std::to_string(health) + '\n' + std::to_string(speed);
}
