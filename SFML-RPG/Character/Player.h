#pragma once
#include <SFML\Graphics.hpp>
#include "Character.h"
#include "..\WorldItems\WorldObject.h"
#include "..\WorldItems\Entity.h"

#include <vector>
#include <unordered_set>
#include <iostream>

class Player : public Character
{
public:
	Player(
		/*Metadata*/ std::string name, int ID, sf::Vector2f position,
		/*Texture*/ std::string texturePath, sf::Texture* text,
		/*Collision*/ float weight,
		/*Animation*/ bool frozen, 
				sf::Vector2u imageCount, float switchTime,
		/*Character*/ float health, float speed, float strength
	);
	Player(const Player& cpy, int ID, sf::Vector2f position);
	~Player();


	void Update(float deltaTime);

	bool Collide(WorldObject& other, sf::View vw);

	Entity Mine(WorldObject& other);

private:
	std::vector<Entity> inventory;
	/*
	STATES
	0. Stationary
	1. Moving
	2. Mining	
	*/

};
