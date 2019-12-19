#include "worldObject.h"

WorldObject::WorldObject(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position)
{
	body.setSize(size);
	body.setOrigin(size / 2.0f);
	body.setTexture(texture);
	body.setPosition(position);
}

WorldObject::~WorldObject()
{
}

void WorldObject::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}
