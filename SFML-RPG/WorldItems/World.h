#pragma once

#include <unordered_map>
#include <unordered_set>

#include <SFML\Graphics.hpp>

#include "Displayable.h"
#include "WorldObject.h"

namespace rpg {
	class World : public Displayable
	{
	public:
		World();
		World(sf::Vector2f position, sf::IntRect rect,
			std::unordered_map<int, WorldObject> worldI,
			std::unordered_set<int> collID);
		~World();

		void SetObjSprite(sf::Texture& text);

		WorldObject& getWorldItem(int id) { return worldItems[id]; }

		std::unordered_map<int, WorldObject> getWorldItems() { return worldItems; }
		std::unordered_set<int> getCollID() { return collID; }

		void addWorldItem(int id, WorldObject& object) {
			worldItems[id] = object;
		}
		void addCollID(int id) {
			collID.insert(id);
		}

		void DeleteWorldItem(int id) {
			worldItems.erase(id);
			if (collID.find(id) != collID.end())
			{
				collID.erase(id);
			}
		}

		std::string GetWriteable();

		friend class Display;

	private:
		std::unordered_map<int, WorldObject> worldItems;
		std::unordered_set<int> collID;
	};
}
