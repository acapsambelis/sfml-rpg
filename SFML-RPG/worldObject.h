#pragma once
#include <SFML\Graphics.hpp>
#include "Animation.h"
#include <vector>
#include <unordered_set>

class WorldObject
{
public:
	WorldObject(unsigned int ID, sf::Texture* texture, float sizeScalar, bool frozen, sf::Vector2u imageCount,
		float switchTime, float weight, sf::Vector2f position);
	~WorldObject();

	void Draw(sf::RenderWindow& window);

	sf::Vector2f GetPosition() { return body.getPosition(); }
	void Move(float dx, float dy) { body.move(dx, dy); }

public:
	// Collisions //
	void UpdateCollision(WorldObject& other, std::vector<WorldObject> itemList,
		std::unordered_set<unsigned int> blacklist = {});

	sf::Vector3f CheckCollision(WorldObject& other);
	void Bounce(WorldObject& other, sf::Vector3f react, 
		float weightOverride = -1.0f);

	sf::Vector2f GetHalfSize() { return body.getSize() / 2.0f; }


public:
	unsigned int ID;

	sf::RectangleShape body;
	Animation animation;
	unsigned int row;
	bool faceRight;

	float weight;

};

