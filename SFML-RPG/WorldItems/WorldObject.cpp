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

#include "WorldObject.hpp"

namespace rpg {

	////////////////////////////////////////////////////////////
	WorldObject::WorldObject() :
		Displayable()
	{
		this->id = 0;
		this->name = "";
	}

	////////////////////////////////////////////////////////////
	WorldObject::WorldObject(
		std::string name, int id, sf::Vector2f position,
		sf::IntRect rect
	) :
		Displayable(rect, position)
	{
		this->id = id;
		this->name = name;
	}

	////////////////////////////////////////////////////////////
	WorldObject::WorldObject(const WorldObject& copy, int id,
		sf::Vector2f position) :
		Displayable(copy, position)
	{
		this->id = id;
		this->name = copy.name;
	}

	////////////////////////////////////////////////////////////
	WorldObject::~WorldObject()
	{
	}

	////////////////////////////////////////////////////////////
	bool WorldObject::operator==(const WorldObject& w) const
	{
		return (this->id == w.id);
	}

	////////////////////////////////////////////////////////////
	bool WorldObject::update_collision(WorldObject& other)
	{
		sf::Vector3f collisionDir = this->check_collision(other);
		if (collisionDir != sf::Vector3f(0.0f, 0.0f, 0.0f))
		{
			bounce(collisionDir);
			return true;
		}

		return false;
	}

	////////////////////////////////////////////////////////////
	std::string WorldObject::get_writeable()
	{
		return name + '\n' + std::to_string(id) + '\n' + Displayable::GetWriteable();
	}

	////////////////////////////////////////////////////////////
	sf::Vector3f WorldObject::check_collision(WorldObject other)
	{
		sf::Vector2f delta = find_delta(other);
		sf::Vector2f intersect = find_intersect(other, delta);

		if (intersect.x < 0.0f && intersect.y < 0.0f)
		{
			if (intersect.x > intersect.y)
			{
				if (delta.x > 0.0f)  // player moving right
					return sf::Vector3f(1.0f, 0.0f, intersect.x);
				else				// player moving left
					return sf::Vector3f(-1.0f, 0.0f, intersect.x);
			}
			else
			{
				if (delta.y > 0.0f)  // player moving down
					return sf::Vector3f(0.0f, -1.0f, intersect.y);
				else				// player moving up
					return sf::Vector3f(0.0f, 1.0f, intersect.y);
			}
		}
		return sf::Vector3f(0.0f, 0.0f, 0.0f);
	}

	////////////////////////////////////////////////////////////
	sf::Vector2f WorldObject::find_intersect(WorldObject other, sf::Vector2f delta)
	{
		sf::Vector2f otherHalfSize = (sf::Vector2f)other.get_size() / 2.0f;
		sf::Vector2f thisHalfSize = (sf::Vector2f)get_size() / 2.0f;

		return sf::Vector2f(abs(delta.x) - (otherHalfSize.x + thisHalfSize.x),
			abs(delta.y) - (otherHalfSize.y + thisHalfSize.y));
	}

	////////////////////////////////////////////////////////////
	sf::Vector2f WorldObject::find_delta(WorldObject other)
	{
		sf::Vector2f otherPosition = other.get_position();
		sf::Vector2f thisPosition = get_position();

		return sf::Vector2f(otherPosition.x - thisPosition.x,
			otherPosition.y - thisPosition.y);
	}

	////////////////////////////////////////////////////////////
	void WorldObject::bounce(sf::Vector3f react)
	{
		this->move(react.z * react.x, -react.z * react.y);
	}

} // namespace rpg
