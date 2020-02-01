#pragma once
#include <SFML\Graphics.hpp>
#include "..\WorldItems\WorldObject.h"
#include "..\WorldItems\World.h"

class Character : public WorldObject
{
public:
	Character(
		/*Metadata*/ World& wr, const char* name, int ID, sf::Vector2f position,
		/*Texture*/ const char* texture, sf::Texture* text,
		/*Collision*/ float weight,
		/*Animation*/ float sizeScalar, bool frozen, 
				sf::Vector2u imageCount, float switchTime,
		/*Character*/ float health, float speed, float strength
	);
	~Character();

public:

	World& wr;

	float health;
	float speed;
	float strength;

	int state;
};

