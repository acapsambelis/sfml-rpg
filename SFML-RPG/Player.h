#pragma once
#include <SFML\Graphics.hpp>
#include "Animation.h"
#include "Collider.h"

#include "WorldObject.h"

class Player : public WorldObject
{
public:
	Player(sf::Texture* texture, float sizeScalar, bool frozen, sf::Vector2u imageCount,
		float switchTime, float weight, sf::Vector2f position, float speed);
	//Player(sf::Texture* texture, bool frozen, sf::Vector2u imageCount, 
	//	float switchTime, float speed);
	~Player();

	void Update(float deltaTime);

	sf::Vector2f GetPosition() { return body.getPosition(); }
	Collider GetCollider() { return Collider(body); }

private:
	float speed;

};
