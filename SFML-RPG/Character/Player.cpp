#include "Player.h"
#include <SFML\Graphics.hpp>

#include <iostream>

Player::Player(
	/*Metadata*/ World& wr, const char* name, int ID, sf::Vector2f position,
	/*Texture*/ const char* texturePath, sf::Texture* text,
	/*Collision*/ float weight,
	/*Animation*/ float sizeScalar, bool frozen,
	sf::Vector2u imageCount, float switchTime,
	/*Character*/ float health, float speed, float strength
	) :
	Character(wr, name, ID, position,
		texturePath, text,
		weight,
		sizeScalar, frozen, imageCount, switchTime,
		health, speed, strength)
{
	this->inventory = std::vector<Entity>();
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

	if (movement.x == 0.0f)
	{
		row = 0;
	}
	else {
		row = 1;
		if (movement.x > 0.0f)
		{
			faceRight = true;
		}
		else
		{
			faceRight = false;
		}
	}

	if (!animation.frozen)
	{
		animation.Update(row, deltaTime, faceRight);
	}
	body.setTextureRect(animation.uvRect);
	Move(movement.x, movement.y);
}

bool Player::Collide(WorldObject& other, sf::View vw)
{
	bool coll = UpdateCollision(other, vw);
	if (coll && state == 2)
	{
		if (health > 0) 
		{
			this->inventory.push_back(Mine(other));
			return true;
		}
	}
	return false;
}

Entity Player::Mine(WorldObject& other)
{
	Entity temp(other.ent);
	this->health -= 10.0f;
	return temp;
}

std::ostream& operator<<(std::ostream& os, const Player& pl)
{
	os << pl.name << ',' << pl.ID << ',' << pl.body.getPosition().x << ',' <<
		pl.body.getPosition().y << '\n'
		<< pl.texturePath << '\n'
		<< pl.weight << '\n'
		<< pl.animation << '\n'
		<< pl.health << ',' << pl.speed << ',' << pl.strength << '\n';
	return os;
}
