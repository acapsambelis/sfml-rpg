////////////////////////////////////////////////////////////
//
// SFML-RPG - A top-down RPG demo
// 
// Author - Alex Capsambelis
//
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include "ObjectDisperse.hpp"

namespace rpg {

	////////////////////////////////////////////////////////////
	ObjectDisperse::ObjectDisperse(WorldObject obj, sf::Vector2f range, float popularity) :
		obj_reference(obj)
	{
		this->range = range;
		this->popularity = popularity;
		srand((unsigned int)time(0));
	}

	////////////////////////////////////////////////////////////
	ObjectDisperse::~ObjectDisperse()
	{
	}

	////////////////////////////////////////////////////////////
	int ObjectDisperse::disperse(int next_id,
		std::unordered_map<int, WorldObject>& map)
	{
		std::unordered_set<int> empty;
		return disperse(next_id, map, empty);
	}

	////////////////////////////////////////////////////////////
	int ObjectDisperse::disperse(int next_id,
		std::unordered_map<int, WorldObject>& map,
		std::unordered_set<int>& set)
	{
		for (float x = -(this->range.x / 2.0f); x < this->range.x;
			x = x + this->obj_reference.get_size().x)
		{
			for (float y = -(this->range.y / 2.0f); y < this->range.y;
				y = y + this->obj_reference.get_size().y)
			{
				float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
				if (r < this->popularity * 0.1f)
				{
					WorldObject nw = WorldObject(this->obj_reference, next_id,
						sf::Vector2f(float(x), float(y)));
					map[next_id] = nw;
					set.insert(next_id);
					next_id++;
				}
			}
		}
		return next_id;
	}

} // namespace rpg
