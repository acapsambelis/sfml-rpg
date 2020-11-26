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

#include "Displayable.hpp"

namespace rpg {
	
	////////////////////////////////////////////////////////////
	Displayable::Displayable()
	{
	}

	////////////////////////////////////////////////////////////
	Displayable::Displayable(sf::IntRect texture_rect, sf::Vector2f position)
	{
		this->texture_rect = texture_rect;
		this->spr.setTextureRect(this->texture_rect);
		this->spr.setPosition(position);
	}

	////////////////////////////////////////////////////////////
	Displayable::Displayable(const Displayable& copy, sf::Vector2f position)
	{
		this->texture_rect = copy.texture_rect;
		this->spr.setTextureRect(this->texture_rect);
		this->spr.setPosition(position);
	}

	////////////////////////////////////////////////////////////
	Displayable::~Displayable()
	{
	}

	////////////////////////////////////////////////////////////
	void Displayable::set_sprite(sf::Texture& text)
	{
		this->spr.setTexture(text);
		this->spr.setTextureRect(this->texture_rect);
		this->spr.setOrigin(get_size().x / 2, get_size().y / 2);
	}

	////////////////////////////////////////////////////////////
	void Displayable::set_scale(float x_scale, float y_scale)
	{
		spr.setScale(x_scale, y_scale);
	}

	////////////////////////////////////////////////////////////
	bool Displayable::in_view(sf::View view, Displayable* obj)
	{
		sf::Vector2f size = view.getSize();
		sf::Vector2f center = view.getCenter();
		return (get_position().x + get_size().x > center.x - size.x / 2.0f &&
				get_position().x - get_size().x < center.x + size.x / 2.0f &&
				get_position().y + get_size().y > center.y - size.y / 2.0f &&
				get_position().y - get_size().y < center.y + size.y / 2.0f);
	}

	////////////////////////////////////////////////////////////
	void Displayable::move(float dx, float dy)
	{
		if (dx != 0.0 || dy != 0.0)
		{
			spr.move(dx, dy);
		}
	}

	////////////////////////////////////////////////////////////
	void Displayable::draw(sf::RenderWindow& window, sf::View vw)
	{
		draw(window, in_view(vw, this));
	}

	////////////////////////////////////////////////////////////
	void Displayable::draw(sf::RenderWindow& window, bool force)
	{
		if (force)
		{
			window.draw(spr);
		}
	}

	////////////////////////////////////////////////////////////
	std::string Displayable::GetWriteable()
	{
		return std::to_string(get_position().x) + "," + std::to_string(get_position().y) + '\n' +
			std::to_string(get_rect().left) + ',' + std::to_string(get_rect().top) + ',' +
			std::to_string(get_rect().width) + ',' + std::to_string(get_rect().height);
	}

} // namespace rpg
