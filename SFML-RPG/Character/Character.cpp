#include "Character.h"

Character::Character(
	/*Metadata*/ World& wr, const char* name, int ID, sf::Vector2f position,
	/*Texture*/ const char* texture, sf::Texture* text, 
	/*Collision*/ float weight,
	/*Animation*/ float sizeScalar, bool frozen, 
			sf::Vector2u imageCount, float switchTime,
	/*Character*/ float health, float speed, float strength
	) :
	WorldObject(name, ID, position,
		texture, texture,
		text, text,
		weight,
		sizeScalar, frozen, imageCount, switchTime),
	wr(wr)
{
	this->health = health;
	this->speed = speed;
	this->strength = strength;

	this->state = 0;
}

Character::~Character()
{
}
