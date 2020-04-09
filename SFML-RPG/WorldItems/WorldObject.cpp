#include "WorldObject.h"

namespace rpg {

	WorldObject::WorldObject() :
		Displayable()
	{
		this->ID = 0;
		this->name = "";
	}

	// NEW //
	WorldObject::WorldObject(
		/*Metadata*/ std::string name, int ID, sf::Vector2f position,
		/*Textures*/ sf::IntRect rect
	) :
		Displayable(rect, position)
	{
		this->ID = ID;
		this->name = name;
	}

	// COPY //
	WorldObject::WorldObject(const WorldObject& cpy, int ID,
		sf::Vector2f position) :
		Displayable(cpy, position)
	{
		this->ID = ID;
		this->name = cpy.name;
	}

	WorldObject::~WorldObject()
	{
	}

	bool WorldObject::operator==(const WorldObject& w) const
	{
		return (this->ID == w.ID);
	}

	bool WorldObject::UpdateCollision(WorldObject& other)
	{
		sf::Vector3f collisionDir = this->CheckCollision(other);
		if (collisionDir != sf::Vector3f(0.0f, 0.0f, 0.0f))
		{
			Bounce(other, collisionDir);
			return true;
		}

		return false;
	}

	std::string WorldObject::GetWriteable()
	{
		return name + '\n' + std::to_string(ID) + '\n' + Displayable::GetWriteable();
	}

	sf::Vector3f WorldObject::CheckCollision(WorldObject other)
	{
		sf::Vector2f delta = FindDelta(other);
		sf::Vector2f intersect = FindIntersect(other, delta);

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

	sf::Vector2f WorldObject::FindIntersect(WorldObject other, sf::Vector2f delta)
	{
		sf::Vector2f otherHalfSize = (sf::Vector2f)other.getSize() / 2.0f;
		sf::Vector2f thisHalfSize = (sf::Vector2f)getSize() / 2.0f;

		return sf::Vector2f(abs(delta.x) - (otherHalfSize.x + thisHalfSize.x),
			abs(delta.y) - (otherHalfSize.y + thisHalfSize.y));
	}

	sf::Vector2f WorldObject::FindDelta(WorldObject other)
	{
		sf::Vector2f otherPosition = other.getPosition();
		sf::Vector2f thisPosition = getPosition();

		return sf::Vector2f(otherPosition.x - thisPosition.x,
			otherPosition.y - thisPosition.y);
	}

	void WorldObject::Bounce(WorldObject& other, sf::Vector3f react)
	{
		this->Move(react.z * react.x, -react.z * react.y);
	}

}