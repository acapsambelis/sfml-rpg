#pragma once
#include <SFML\Graphics.hpp>
#include "..\WorldItems\WorldObject.h"

class Character : public WorldObject
{
public:
	Character();
	Character(
		/*Metadata*/ std::string name, int ID, sf::Vector2f position,
		/*Texture*/ sf::IntRect rect,
		/*Character*/ float health, float speed
	);
	Character(const Character& cpy, int ID, sf::Vector2f position);
	~Character();

public:

	float health;
	float speed;

	int state;
};

