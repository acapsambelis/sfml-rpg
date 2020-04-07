#include "Player.h"
#include <SFML\Graphics.hpp>

#include <iostream>
#include <string>
#include <vector>

Player::Player()
{
}

Player::Player(
	/*Metadata*/ std::string name, int ID, sf::Vector2f position,
	/*Texture*/ sf::IntRect rect,
	/*Character*/ float health, float speed
	) :
	Character(name, ID, position,
		rect,
		health, speed)
{
}

Player::Player(const Player& cpy, int ID, sf::Vector2f position) :
	Character(cpy, ID, position)
{
}

Player::~Player()
{
}

void Player::Update(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		state = 1;
		movement.x -= speed * deltaTime;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) 
	{
		state = 1;
		movement.x += speed * deltaTime;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) 
	{
		state = 1;
		movement.y -= speed * deltaTime;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) 
	{
		state = 1;
		movement.y += speed * deltaTime;
	}
		
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) 
	{
		state = 2;
	}


	Move(movement.x, movement.y);
}

bool Player::Collide(WorldObject& other)
{
	bool coll = UpdateCollision(other);
	if (coll && state == 2)
	{
		if (health > 0) 
		{
			Mine(other);
			return true;
		}
	}
	return false;
}

void Player::Mine(WorldObject& other)
{
	this->health -= 10.0f;
}
