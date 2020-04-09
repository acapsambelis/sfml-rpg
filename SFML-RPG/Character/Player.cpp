#include "Player.h"

#include <iostream>
#include <string>
#include <vector>

#include <SFML\Graphics.hpp>

namespace rpg {

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

	bool Player::Collide(WorldObject& other)
	{
		bool coll = UpdateCollision(other);
		if (coll && getState() == 2)
		{
			if (getHealth() > 0)
			{
				Mine(other);
				return true;
			}
		}
		return false;
	}

	void Player::Mine(WorldObject& other)
	{
		this->Damage(10.0f);
	}

	std::string Player::GetWriteable()
	{
		return Character::GetWriteable();
	}
}
