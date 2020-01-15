#pragma once
#include <SFML\Graphics.hpp>
#include "Animation.h"
#include "Entity.h"

class WorldObject
{
public:
	WorldObject(const char* name, int ID, sf::Texture* texture, sf::Texture* entTexture,
		float sizeScalar, bool frozen, sf::Vector2u imageCount,
		float switchTime, float weight, sf::Vector2f position);
	WorldObject(const WorldObject& cpy, unsigned int ID, sf::Vector2f position);
	~WorldObject();

	void Draw(sf::RenderWindow& window);

	sf::Vector2f GetPosition() { return body.getPosition(); }
	void Move(float dx, float dy) { body.move(dx, dy); }

public:
	// Collisions //
	bool UpdateCollision(WorldObject& other);

	sf::Vector3f CheckCollision(WorldObject& other);
	void Bounce(WorldObject& other, sf::Vector3f react, 
		float weightOverride = -1.0f);

	sf::Vector2f GetHalfSize() { return body.getSize() / 2.0f; }


public:
	int ID;

	sf::RectangleShape body;
	Animation animation;
	unsigned int row;
	bool faceRight;

	float weight;

	Entity ent;

};