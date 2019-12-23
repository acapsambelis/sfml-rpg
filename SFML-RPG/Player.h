#pragma once
#include <SFML\Graphics.hpp>
#include "Animation.h"
#include "Collider.h"

#include "WorldObject.h"

class Player : public WorldObject
{
public:
	Player(sf::Texture* texture, float sizeScalar, bool frozen, sf::Vector2u imageCount,
		float switchTime, float strength, float weight, sf::Vector2f position, float speed);
	~Player();

	void Update(float deltaTime);

private:
	float speed;

};
