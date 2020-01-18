#include "Character.h"

Character::Character(
	/*Metadata*/ World& wr, const char* name, int ID, sf::Vector2f position,
	/*Texture*/ sf::Texture* texture, sf::Texture* entTexture,
	/*Collision*/ float weight,
	/*Animation*/ float sizeScalar, bool frozen, 
			sf::Vector2u imageCount, float switchTime,
	/*Character*/ float health, float speed, float strength
	) :
	WorldObject(name, ID, position,
		texture, entTexture,
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
