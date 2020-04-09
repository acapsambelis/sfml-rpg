#include "Displayable.h"

namespace rpg {

	Displayable::Displayable()
	{
	}

	Displayable::Displayable(sf::IntRect rect, sf::Vector2f position)
	{
		this->rect = rect;
		this->spr.setTextureRect(rect);
		this->spr.setPosition(position);
	}

	Displayable::Displayable(const Displayable& cpy, sf::Vector2f position)
	{
		this->rect = cpy.rect;
		this->spr.setTextureRect(this->rect);
		this->spr.setPosition(position);
	}

	Displayable::~Displayable()
	{
	}

	void Displayable::SetSprite(sf::Texture& text)
	{
		this->spr.setTexture(text);
		this->spr.setTextureRect(this->rect);
		this->spr.setOrigin(getSprBodySize().x / 2, getSprBodySize().y / 2);
	}

	void Displayable::SetScale(float xScale, float yScale)
	{
		spr.setScale(xScale, yScale);
	}

	bool Displayable::inView(sf::View view, Displayable* obj)
	{
		sf::Vector2f size = view.getSize();
		sf::Vector2f center = view.getCenter();
		if (getPosition().x + getSprBodySize().x > center.x - size.x / 2.0f &&
			getPosition().x - getSprBodySize().x < center.x + size.x / 2.0f &&
			getPosition().y + getSprBodySize().y > center.y - size.y / 2.0f &&
			getPosition().y - getSprBodySize().y < center.y + size.y / 2.0f)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void Displayable::Move(float dx, float dy)
	{
		if (dx != 0.0 || dy != 0.0)
		{
			spr.move(dx, dy);
		}
	}

	void Displayable::Draw(sf::RenderWindow& window, sf::View vw)
	{
		if (inView(vw, this))
		{
			window.draw(spr);
		}
	}
	void Displayable::Draw(sf::RenderWindow& window, sf::View vw, bool force)
	{
		if (force)
		{
			window.draw(spr);
		}
	}

	std::string Displayable::GetWriteable()
	{
		return std::to_string(getPosition().x) + "," + std::to_string(getPosition().y) + '\n' +
			std::to_string(getRect().left) + ',' + std::to_string(getRect().top) + ',' +
			std::to_string(getRect().width) + ',' + std::to_string(getRect().height);
	}
}