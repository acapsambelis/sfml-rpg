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

#include "Block.hpp"

namespace rpg {

	////////////////////////////////////////////////////////////
	Block::Block() :
		Displayable()
	{
		this->id = 0;
		this->name = "";
	}

	////////////////////////////////////////////////////////////
	Block::Block(
		std::string name, int id, sf::Vector2f position,
		sf::IntRect rect
	) :
		Displayable(rect, position)
	{
		this->id = id;
		this->name = name;
	}

	////////////////////////////////////////////////////////////
	Block::Block(const Block& copy, int id,
		sf::Vector2f position) :
		Displayable(copy, position)
	{
		this->id = id;
		this->name = copy.name;
	}

	////////////////////////////////////////////////////////////
	Block::~Block()
	{
	}

	////////////////////////////////////////////////////////////
	bool Block::operator==(const Block& w) const
	{
		return (this->id == w.id);
	}

	////////////////////////////////////////////////////////////
	bool Block::update_collision(Block& other)
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
	std::string Block::get_writeable()
	{
		return name + '\n' + std::to_string(id) + '\n' + Displayable::GetWriteable();
	}

	////////////////////////////////////////////////////////////
	sf::Vector3f Block::check_collision(Block other)
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
	sf::Vector2f Block::find_intersect(Block other, sf::Vector2f delta)
	{
		sf::Vector2f otherHalfSize = (sf::Vector2f)other.get_size() / 2.0f;
		sf::Vector2f thisHalfSize = (sf::Vector2f)get_size() / 2.0f;

		return sf::Vector2f(abs(delta.x) - (otherHalfSize.x + thisHalfSize.x),
			abs(delta.y) - (otherHalfSize.y + thisHalfSize.y));
	}

	////////////////////////////////////////////////////////////
	sf::Vector2f Block::find_delta(Block other)
	{
		sf::Vector2f otherPosition = other.get_position();
		sf::Vector2f thisPosition = get_position();

		return sf::Vector2f(otherPosition.x - thisPosition.x,
			otherPosition.y - thisPosition.y);
	}

	////////////////////////////////////////////////////////////
	void Block::bounce(sf::Vector3f react)
	{
		this->move(react.z * react.x, -react.z * react.y);
	}

} // namespace rpg
