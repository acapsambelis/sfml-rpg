#pragma once
#include <SFML\Graphics.hpp>
#include "Animation.h"
#include "Collider.h"

class WorldObject
{
public:
	WorldObject(sf::Texture* texture, float sizeScalar, bool frozen, sf::Vector2u imageCount, 
		float switchTime, float strength, float weight, sf::Vector2f position);
	~WorldObject();

	void Draw(sf::RenderWindow& window);

	sf::Vector2f GetPosition() { return body.getPosition(); }
	Collider GetCollider() { return Collider(body, strength, weight); }

public:
	sf::RectangleShape body;
	Animation animation;
	unsigned int row;
	bool faceRight;

	float strength;
	float weight;
};

