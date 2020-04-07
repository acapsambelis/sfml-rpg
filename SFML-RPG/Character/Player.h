#pragma once
#include <SFML\Graphics.hpp>
#include "Character.h"
#include "..\WorldItems\WorldObject.h"

#include <vector>
#include <iostream>

class Player : public Character
{
public:
	Player();
	Player(
		/*Metadata*/ std::string name, int ID, sf::Vector2f position,
		/*Texture*/ sf::IntRect rect,
		/*Character*/ float health, float speed
	);
	Player(const Player& cpy, int ID, sf::Vector2f position);
	~Player();

	void Update(float deltaTime);

	bool Collide(WorldObject& other);

	void Mine(WorldObject& other);

	/*
	STATES
	0. Stationary
	1. Moving
	2. Mining	
	*/
};
