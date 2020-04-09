#pragma once
#include <SFML\Graphics.hpp>
#include "WorldItems\WorldObject.h"

namespace rpg {
	class Character : public WorldObject
	{
	public:
		Character();
		Character(
			std::string name, int ID, sf::Vector2f position,
			sf::IntRect rect,
			float health, float speed
		);
		Character(const Character& cpy, int ID, sf::Vector2f position);
		~Character();

		float getHealth() { return health; }
		float getSpeed() { return speed; }

		void Damage(float amount) { health -= amount; }
		void Heal(float amount) { health += amount; }

		int getState() { return state; }

		void SetState(int state) { this->state = state; }

		std::string GetWriteable();

	private:
		int state;
		float health;
		float speed;
	};
}
