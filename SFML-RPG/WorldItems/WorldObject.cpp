#include "WorldObject.h"
#include "..\Character\Player.h"

// NEW //
WorldObject::WorldObject(
	/*Metadata*/ const char* name, int ID, sf::Vector2f position,
	/*Textures*/ sf::Texture* texture, sf::Texture* entTexture,
	/*Collision*/ float weight,
	/*Animation*/ float sizeScalar, bool frozen,
		sf::Vector2u imageCount, float switchTime
	) :
		animation(texture, frozen, imageCount, switchTime),
		ent(name, entTexture)
{
	this->ID = ID;

	body.setSize(sizeScalar * sf::Vector2f(texture->getSize()));
	body.setOrigin(body.getSize() / 2.0f);
	body.setTexture(texture);
	body.setPosition(position);

	this->weight = weight;
	this->row = 0;
	this->faceRight = true;
}

// COPY //
WorldObject::WorldObject(const WorldObject& cpy, unsigned int ID, 
	sf::Vector2f position) :
		animation(cpy.animation),
		ent(cpy.ent)
{
	this->ID = ID;

	body.setSize(cpy.body.getSize());
	body.setOrigin(body.getSize() / 2.0f);
	body.setTexture(cpy.body.getTexture());
	body.setPosition(position);

	this->weight = cpy.weight;
	this->row = 0;
	this->faceRight = true;
}


WorldObject::~WorldObject()
{
}


void WorldObject::Draw(sf::RenderWindow& window, sf::View vw)
{
	sf::Vector2f size = vw.getSize();
	sf::Vector2f center = vw.getCenter();
	if (GetPosition().x + body.getSize().x > center.x - size.x / 2.0f &&
		GetPosition().x - body.getSize().x < center.x + size.x / 2.0f &&
		GetPosition().y + body.getSize().y > center.y - size.y / 2.0f &&
		GetPosition().y - body.getSize().y < center.y + size.y / 2.0f )
	{
		window.draw(body);
	}
}

bool WorldObject::UpdateCollision(WorldObject& other, sf::View vw)
{
	sf::Vector2f size = vw.getSize();
	sf::Vector2f center = vw.getCenter();
	if (GetPosition().x + body.getSize().x > center.x - size.x / 2.0f &&
		GetPosition().x - body.getSize().x < center.x + size.x / 2.0f &&
		GetPosition().y + body.getSize().y > center.y - size.y / 2.0f &&
		GetPosition().y - body.getSize().y < center.y + size.y / 2.0f)
	{
		sf::Vector3f collisionDir = this->CheckCollision(other);
		if (collisionDir != sf::Vector3f(0.0f, 0.0f, 0.0f))
		{
			Bounce(other, collisionDir);
			return true;
		}
	}
	return false;
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
	{
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
	}
	return sf::Vector3f(0.0f, 0.0f, 0.0f);
}

void WorldObject::Bounce(WorldObject& other, sf::Vector3f react, float weightOverride)
{
	if (weightOverride == -1.0f)
	{
		weightOverride = other.weight;
	}
	else
	{
		weightOverride = 1.0f;
	}

	
	other.Move(-react.z * (1.0f - weightOverride) * react.x,
		react.z * (1.0f - weightOverride) * react.y);
	Move(react.z * weightOverride * react.x,
		-react.z * weightOverride * react.y);
}

bool WorldObject::operator==(const WorldObject& w) const
{
	return (this->ID == w.ID);
}
