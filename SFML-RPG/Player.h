#pragma once
#include <SFML\Graphics.hpp>
#include "Animation.h"
#include "WorldObject.h"
#include "Entity.h"
#include "World.h"
#include <vector>
#include <unordered_set>

class Player : public WorldObject
{
public:
	Player(World& wr, const char* name, int ID, sf::Texture* texture, float sizeScalar, 
		bool frozen, sf::Vector2u imageCount, float switchTime, float strength, 
		float weight, sf::Vector2f position, float speed);
	~Player();

	void Update(float deltaTime);

	bool Collide(WorldObject& other);

	Entity Mine(WorldObject& other);

public:
	World& wr;

	float health;
	float speed;
	float strength;
	std::vector<Entity> inventory;

	int state;
	/*
	0. Stationary
	1. Moving
	2. Mining	
	*/


};
