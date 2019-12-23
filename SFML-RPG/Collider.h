#pragma once
#include <SFML\Graphics.hpp>


class Collider
{
public:
	Collider(sf::RectangleShape& body, float strength, float weight);
	~Collider();

	void Move(float dx, float dy) { body.move(dx, dy); }

	void UpdateCollision(Collider& other, Collider whitelist[] = NULL, int objects = 0);

	sf::Vector3f CheckCollision(Collider& other);
	void Bounce(Collider& other, sf::Vector3f react, float weightOverride = -1.0f);

	sf::Vector2f GetPosition() { return body.getPosition(); }
	sf::Vector2f GetHalfSize() { return body.getSize() / 2.0f; }


private:
	sf::RectangleShape& body;
	float weight;
};
