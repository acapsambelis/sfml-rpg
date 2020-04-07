#include "ObjectDisperse.h"

ObjectDisperse::ObjectDisperse(WorldObject obj, sf::Vector2f range, float num):
	objType(obj)
{
	this->range = range;
	this->popularity = num;
}

ObjectDisperse::~ObjectDisperse()
{
}

int ObjectDisperse::Disperse(int nextID,
	std::unordered_map<int, WorldObject>& map,
	std::unordered_set<int>& set)
{

	for (int i = (int)-(this->range.x / 2.0f); i < this->range.x;
		i = i + this->objType.getSprBodySize().x)
	{
		for (int j = (int)-(this->range.y / 2.0f); j < this->range.y;
			j = j + this->objType.getSprBodySize().y)
		{
			float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
			if (r < this->popularity * 0.1f)
			{
				WorldObject nw = WorldObject(this->objType, nextID, 
					sf::Vector2f(float(i), float(j)));
				map[nextID] = nw;
				set.insert(nextID);
				nextID++;
			}
		}
	}
	return nextID;
}
int ObjectDisperse::Disperse(int nextID,
	std::unordered_map<int, WorldObject>& map)
{

	for (int i = (int)-(this->range.x / 2.0f); i < this->range.x;
		i = i + this->objType.getSprBodySize().x)
	{
		for (int j = (int)-(this->range.y / 2.0f); j < this->range.y;
			j = j + this->objType.getSprBodySize().y)
		{
			float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
			if (r < this->popularity * 0.1f)
			{
				WorldObject nw = WorldObject(this->objType, nextID,
					sf::Vector2f(float(i), float(j)));
				map[nextID] = nw;
				nextID++;
			}
		}
	}
	return nextID;
}