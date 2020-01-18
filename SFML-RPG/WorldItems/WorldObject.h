#pragma once
#include <SFML\Graphics.hpp>
#include "..\Character\Animation.h"
#include "Entity.h"

class WorldObject
{
public:
	WorldObject(
		/*Metadata*/ const char* name, int ID, sf::Vector2f position,
		/*Textures*/ sf::Texture* texture, sf::Texture* entTexture,
		/*Collision*/ float weight,
		/*Animation*/ float sizeScalar, bool frozen, 
				sf::Vector2u imageCount, float switchTime
	);
	WorldObject(const WorldObject& cpy, unsigned int ID, sf::Vector2f position);
	~WorldObject();

	// Helpers //
	sf::Vector2f GetPosition() { return body.getPosition(); }
	void Move(float dx, float dy) { body.move(dx, dy); }

	// Functions //
	void Draw(sf::RenderWindow& window, sf::View vw);

	// Collisions //
	bool UpdateCollision(WorldObject& other, sf::View vw);

	sf::Vector3f CheckCollision(WorldObject& other);
	void Bounce(WorldObject& other, sf::Vector3f react, 
		float weightOverride = -1.0f);

	sf::Vector2f GetHalfSize() { return body.getSize() / 2.0f; }

	// Overloads //
	bool operator==(const WorldObject& w) const;


public:
	int ID;

	sf::RectangleShape body;
	Animation animation;
	unsigned int row;
	bool faceRight;

	float weight;

	Entity ent;

};

class MyHashFunction
{
public:
	size_t operator()(const WorldObject& obj) const
	{
		return obj.ID;
	}
};