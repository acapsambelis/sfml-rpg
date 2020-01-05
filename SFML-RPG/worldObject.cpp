#include "WorldObject.h"
#include <iostream>

WorldObject::WorldObject(unsigned int ID, 
	sf::Texture* texture, float sizeScalar, bool frozen, 
	sf::Vector2u imageCount, float switchTime, float weight, 
	sf::Vector2f position) :
	animation(texture, frozen, imageCount, switchTime)
{
	this->ID = ID;

	body.setSize(sizeScalar * sf::Vector2f(texture->getSize()));
	body.setOrigin(body.getSize() / 2.0f);
	body.setTexture(texture);
	body.setPosition(position);

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

void WorldObject::UpdateCollision(WorldObject& other, 
	std::vector<WorldObject> itemList, std::unordered_set<unsigned int> blacklist)
{
	sf::Vector3f collisionDir = this->CheckCollision(other);
	if (collisionDir != sf::Vector3f(0.0f, 0.0f, 0.0f))
	{
		for (unsigned int i = 0; i < itemList.size(); ++i)
		{
			if (other.ID != itemList[i].ID && other.ID != this->ID)
			{
				if (blacklist.find(itemList[i].ID) == blacklist.end())
				{
					blacklist.insert(itemList[i].ID);
					other.UpdateCollision(itemList[i], itemList, blacklist);
				}

			}
		}
		collisionDir = this->CheckCollision(other);
		Bounce(other, collisionDir);
	}
}

sf::Vector3f WorldObject::CheckCollision(WorldObject& other)
{
	sf::Vector2f otherPosition = other.GetPosition();
	sf::Vector2f otherHalfSize = other.GetHalfSize();
	sf::Vector2f thisPosition = GetPosition();
	sf::Vector2f thisHalfSize = GetHalfSize();

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;

	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

	if (intersectX < 0.0f && intersectY < 0.0f)
		if (intersectX > intersectY)
		{
			if (deltaX > 0.0f)  // player moving right
				return sf::Vector3f(1.0f, 0.0f, intersectX);
			else				// player moving left
				return sf::Vector3f(-1.0f, 0.0f, intersectX);
		}
		else
		{
			if (deltaY > 0.0f)  // player moving down
				return sf::Vector3f(0.0f, -1.0f, intersectY);
			else				// player moving up
				return sf::Vector3f(0.0f, 1.0f, intersectY);
		}

	return sf::Vector3f(0.0f, 0.0f, 0.0f);
}

void WorldObject::Bounce(WorldObject& other, sf::Vector3f react, float weightOverride)
{
	if (weightOverride == -1.0f)
		weightOverride = other.weight;
	else
		weightOverride = 1.0f;

	
	other.Move(-react.z * (1.0f - weightOverride) * react.x,
		react.z * (1.0f - weightOverride) * react.y);
	Move(react.z * weightOverride * react.x,
		-react.z * weightOverride * react.y);
}
