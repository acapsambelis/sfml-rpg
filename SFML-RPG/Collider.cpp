#include "Collider.h"
#include <iostream>

Collider::Collider(sf::RectangleShape& body, float strength, float weight) :
	body(body)
{
	this->weight = weight;
}

Collider::~Collider()
{
}

void Collider::UpdateCollision(Collider& other, Collider whitelist [], int objects)
{
	sf::Vector3f collisionDir = this->CheckCollision(other);
	if (collisionDir != sf::Vector3f(0.0f, 0.0f, 0.0f))
	{
		this->Bounce(other, collisionDir);
		for (int i = 0; i < objects; ++i)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
				std::cout << "Breakpoint" << std::endl;
			sf::Vector3f otherCollision = other.CheckCollision(whitelist[i]);
			if (otherCollision != sf::Vector3f(0.0f, 0.0f, 0.0f))
			{
				other.Bounce(whitelist[i], otherCollision);
				collisionDir = this->CheckCollision(other);
				this->Bounce(other, collisionDir, whitelist[i].weight);
			}
		}
	}
}

sf::Vector3f Collider::CheckCollision(Collider& other)
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
			if (deltaX > 0.0f) // player moving right
				return sf::Vector3f(1.0f, 0.0f, intersectX);
			else // player moving left
				return sf::Vector3f(-1.0f, 0.0f, intersectX);
		}
		else
		{
			if (deltaY > 0.0f) // player moving down
				return sf::Vector3f(0.0f, -1.0f, intersectY);
			else // player moving up
				return sf::Vector3f(0.0f, 1.0f, intersectY);
		}

	return sf::Vector3f(0.0f, 0.0f, 0.0f);
		
}

void Collider::Bounce(Collider& other, sf::Vector3f react, float weightOverride)
{
	if (weightOverride == -1.0f)
		weightOverride = other.weight;

	other.Move(-react.z * (1.0f - weightOverride) * react.x,
			    react.z * (1.0f - weightOverride) * react.y);
	Move(react.z * weightOverride * react.x,
		-react.z * weightOverride * react.y);
}
