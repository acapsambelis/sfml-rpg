#pragma once
#include <SFML\Graphics.hpp>
#include "..\WorldItems\WorldObject.h"

class Character : public WorldObject
{
public:
	Character(
		/*Metadata*/ std::string name, int ID, sf::Vector2f position,
		/*Texture*/ std::string texture, sf::Texture* text,
		/*Collision*/ float weight,
		/*Animation*/ bool frozen, 
				sf::Vector2u imageCount, float switchTime,
		/*Character*/ float health, float speed, float strength
	);
	Character(const Character& cpy, int ID, sf::Vector2f position);
	~Character();

public:

	float health;
	float speed;
	float strength;

	int state;
};

