#include "Entity.h"

Entity::Entity(std::string name, std::string texturePath,
	sf::Texture* text)
{
	this->name = name;
	this->txtr.setTexture(text);
}

Entity::Entity(const Entity& copy)
{
	this->name = copy.name;
	this->txtr = copy.txtr;
}

Entity::~Entity()
{
}
