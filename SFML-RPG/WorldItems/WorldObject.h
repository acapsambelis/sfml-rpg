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

	bool operator==(const WorldObject& w) const;

	std::string getName() { return name; }
	int getID() { return ID; }

	bool UpdateCollision(WorldObject& other);

	std::string GetWriteable();

private:
	sf::Vector3f CheckCollision(WorldObject other);
	sf::Vector2f FindIntersect(WorldObject other, sf::Vector2f delta);
	sf::Vector2f FindDelta(WorldObject other);
	void Bounce(WorldObject& other, sf::Vector3f react);

private:
	int ID;
	std::string name;
};