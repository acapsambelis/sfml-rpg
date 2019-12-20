#include "Player.h"
#include <SFML\Graphics.hpp>
#include "Animation.h"

Player::Player(sf::Texture* texture, float sizeScalar, bool frozen, sf::Vector2u imageCount,
	float switchTime, float weight, sf::Vector2f position, float speed) :
	WorldObject(texture, sizeScalar, frozen, imageCount, switchTime, weight, position)
{
	this->speed = speed;
}

Player::~Player()
{
}

void Player::Update(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		movement.x -= speed * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		movement.x += speed * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		movement.y -= speed * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		movement.y += speed * deltaTime;
		

	if (movement.x == 0.0f)
		row = 0;
	else
	{
		row = 1;

		if (movement.x > 0.0f)
			faceRight = true;
		else
			faceRight = false;
	}

	if (!animation.frozen)
		animation.Update(row, deltaTime, faceRight);

	body.setTextureRect(animation.uvRect);
	body.move(movement);

}

