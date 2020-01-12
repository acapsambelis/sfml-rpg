#include "ItemDisperse.h"

ItemDisperse::ItemDisperse(WorldObject obj, sf::Vector2f range, float num):
	objType(obj)
{
	this->range = range;
	this->popularity = num;
}

ItemDisperse::~ItemDisperse()
{
}

std::vector<WorldObject> ItemDisperse::Disperse(unsigned int nextID)
{
	std::vector<WorldObject> items;

	for (int i = -(this->range.x / 2.0f); i < this->range.x; 
		i = i + this->objType.body.getSize().x)
	{
		for (int j = -(this->range.y / 2.0f); j < this->range.y; 
			j = j + this->objType.body.getSize().y)
		{
			float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
			if (r < this->popularity * 0.1f)
			{
				WorldObject nw = WorldObject(this->objType, nextID, 
					sf::Vector2f(float(i), float(j)));
				items.push_back(nw);
				nextID++;
			}
		}
	}

	return items;
}
