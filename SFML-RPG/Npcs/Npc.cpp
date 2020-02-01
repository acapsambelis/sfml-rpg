#include "Npc.h"

Npc::Npc(
	/*Metadata*/ World& wr, const char* name, int ID, sf::Vector2f position,
	/*Texture*/ const char* texture, sf::Texture* text,
	/*Collision*/ float weight,
	/*Animation*/ float sizeScalar, bool frozen,
	sf::Vector2u imageCount, float switchTime,
	/*Character*/ float health, float speed, float strength
	) :
	Character(wr, name, ID, position,
		texture, text,
		weight,
		sizeScalar, frozen, imageCount, switchTime,
		health, speed, strength)
{
}

Npc::~Npc()
{
}
