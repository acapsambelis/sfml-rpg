#include "Character.h"

Character::Character()
{
}

Character::Character(
	/*Metadata*/ std::string name, int ID, sf::Vector2f position,
	/*Texture*/ sf::IntRect rect,
	/*Character*/ float health, float speed
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
