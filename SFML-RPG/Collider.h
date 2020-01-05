#pragma once
#include <SFML\Graphics.hpp>
#include <vector>

class Collider
{
public:
	Collider(unsigned int id, sf::RectangleShape& body, float weight);
	~Collider();

	void Move(float dx, float dy) { body.move(dx, dy); }

	void UpdateCollision(Collider& other, std::vector<Collider> itemList);

	sf::Vector3f CheckCollision(Collider& other);
	void Bounce(Collider& other, sf::Vector3f react, float weightOverride = -1.0f);

	sf::Vector2f GetPosition() { return body.getPosition(); }
	sf::Vector2f GetHalfSize() { return body.getSize() / 2.0f; }


public:
	unsigned int ID;
	sf::RectangleShape& body;
	float weight;
};
