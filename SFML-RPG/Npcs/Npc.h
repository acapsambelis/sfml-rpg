#pragma once
#include <SFML\Graphics.hpp>
#include "..\Character\Character.h"


class Npc : public Character
{
public:
	Npc(
		/*Metadata*/ World& wr, const char* name, int ID, sf::Vector2f position,
		/*Texture*/ const char* texture, sf::Texture* text,
		/*Collision*/ float weight,
		/*Animation*/ float sizeScalar, bool frozen,
		sf::Vector2u imageCount, float switchTime,
		/*Character*/ float health, float speed, float strength
	);
	~Npc();

};

