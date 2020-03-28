#include "Character.h"

Character::Character(
	/*Metadata*/ std::string name, int ID, sf::Vector2f position,
	/*Texture*/ std::string texture, sf::Texture* text,
	/*Collision*/ float weight,
	/*Animation*/ bool frozen, 
			sf::Vector2u imageCount, float switchTime,
	/*Character*/ float health, float speed, float strength
	) :
	WorldObject(name, ID, position,
		texture, texture,
		text, text,
		weight,
		frozen, imageCount, switchTime)
{
	this->health = health;
	this->speed = speed;
	this->strength = strength;

	this->state = 0;
}

Character::Character(const Character& cpy, int ID, sf::Vector2f position) :
	WorldObject(cpy, ID, position)
{
	this->health = cpy.health;
	this->speed = cpy.speed;
	this->strength = cpy.strength;

	this->state = 0;
}

Character::~Character()
{
}
