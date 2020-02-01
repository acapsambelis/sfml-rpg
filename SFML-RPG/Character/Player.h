#pragma once
#include <SFML\Graphics.hpp>
#include "Character.h"
#include "..\WorldItems\WorldObject.h"
#include "..\WorldItems\Entity.h"
#include "..\WorldItems\World.h"

#include <vector>
#include <unordered_set>
#include <iostream>

class Player : public Character
{
public:
	Player(
		/*Metadata*/ World& wr, const char* name, int ID, sf::Vector2f position,
		/*Texture*/ const char* texturePath, sf::Texture* text,
		/*Collision*/ float weight,
		/*Animation*/ float sizeScalar, bool frozen, 
				sf::Vector2u imageCount, float switchTime,
		/*Character*/ float health, float speed, float strength
	);
	~Player();
	friend std::ostream& operator<<(std::ostream& os, const Player& pl);

	void Update(float deltaTime);

	bool Collide(WorldObject& other, sf::View vw);

	Entity Mine(WorldObject& other);

public:
	std::vector<Entity> inventory;
	/*
	STATES
	0. Stationary
	1. Moving
	2. Mining	
	*/

};
