#pragma once
#include <SFML\Graphics.hpp>
#include "Displayable.h"

class WorldObject : public Displayable
{
public:
	WorldObject();
	WorldObject(
		/*Metadata*/ std::string name, int ID, sf::Vector2f position,
		/*Textures*/ sf::IntRect rect
	);
	WorldObject(const WorldObject& cpy, int ID, sf::Vector2f position);
	~WorldObject();

	// Overloads //
	bool operator==(const WorldObject& w) const;

	// Collisions //
	bool UpdateCollision(WorldObject& other);

private:
	sf::Vector3f CheckCollision(WorldObject other);
	sf::Vector2f FindIntersect(WorldObject other, sf::Vector2f delta);
	sf::Vector2f FindDelta(WorldObject other);
	void Bounce(WorldObject& other, sf::Vector3f react);


public:
	int ID;
private:
	std::string name;
	sf::IntRect rect;

};