#include "Entity.h"

Entity::Entity(const char* name, sf::Texture* txtr)
{
	this->name = name;
	this->txtr.setTexture(txtr);
}

Entity::Entity(const Entity& copy)
{
	this->name = copy.name;
	this->txtr = copy.txtr;
}

Entity::~Entity()
{
}
