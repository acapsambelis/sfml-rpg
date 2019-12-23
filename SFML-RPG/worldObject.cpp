#include "WorldObject.h"

WorldObject::WorldObject(sf::Texture* texture, float sizeScalar, bool frozen, sf::Vector2u imageCount,
	float switchTime, float strength, float weight, sf::Vector2f position) :
	animation(texture, frozen, imageCount, switchTime)
{
	body.setSize(sizeScalar * sf::Vector2f(texture->getSize()));
	body.setOrigin(body.getSize() / 2.0f);
	body.setTexture(texture);
	body.setPosition(position);
	this->strength = strength;
	this->weight = weight;
	row = 0;
	faceRight = true;
}

WorldObject::~WorldObject()
{
}


void WorldObject::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}
