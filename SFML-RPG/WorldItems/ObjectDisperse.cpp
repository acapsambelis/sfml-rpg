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
	std::unordered_set<WorldObject, MyHashFunction>& set,
	std::unordered_set<WorldObject, MyHashFunction>& set2)
{

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
				//WorldObject nw = WorldObject(this->objType);
				set.insert(nw);
				set2.insert(nw);
				nextID++;
			}
		}
	}
	return nextID;
}
int ObjectDisperse::Disperse(int nextID,
	std::unordered_set<WorldObject, MyHashFunction>& set)
{

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
				set.insert(nw);
				nextID++;
			}
		}
	}
	return nextID;
}