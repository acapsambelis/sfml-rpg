#include "Player.h"
#include <SFML\Graphics.hpp>
#include "Animation.h"

#include <iostream>

Player::Player(World& wr, const char* name, int ID, sf::Texture* texture,
	float sizeScalar, bool frozen, sf::Vector2u imageCount,
	float switchTime, float strength, float weight, sf::Vector2f position, float speed) :
	WorldObject(name, ID, texture, texture, sizeScalar, frozen, imageCount, switchTime, weight, position),
	wr(wr)
{
	this->health = 100.0f;
	this->speed = speed;
	this->strength = strength;
	this->state = 0;
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
		
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		state = 2;
	}

	if (movement.x == 0.0f)
	{
		row = 0;
	}
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
	Move(movement.x, movement.y);
}

void Player::Collide(WorldObject& other, std::vector<WorldObject>& worldI)
{
	bool coll = UpdateCollision(other);
	if (coll && state == 2)
	{
		if (health > 0)
		{
			this->inventory.push_back(Mine(other));
		}
	}
}

Entity Player::Mine(WorldObject& other)
{
	Entity temp(other.ent);
	this->health -= 1.0f;
	return temp;
}
