#pragma once
#include <SFML\Graphics.hpp>
#include "..\Character\Animation.h"
#include "Entity.h"

class WorldObject
{
public:
	WorldObject(
		/*Metadata*/ const char* name, int ID, sf::Vector2f position,
		/*Textures*/ const char* texturePath, const char* entTexturePath,
					 sf::Texture* text,		  sf::Texture* entText,
		/*Collision*/ float weight,
		/*Animation*/ float sizeScalar, bool frozen, 
				sf::Vector2u imageCount, float switchTime
	);
	WorldObject(const WorldObject& cpy, unsigned int ID, sf::Vector2f position);
	~WorldObject();

	// Overloads //
	bool operator==(const WorldObject& w) const;

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



public:
	int ID;
	const char* name;

	const char* texturePath;
	const char* entTexturePath;
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