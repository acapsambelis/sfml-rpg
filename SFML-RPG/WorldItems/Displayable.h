#pragma once

#include <SFML\Graphics.hpp>

namespace rpg {
	class Displayable
	{
	public:
		Displayable();
		Displayable(sf::IntRect rect, sf::Vector2f position);
		Displayable(const Displayable& cpy, sf::Vector2f position);
		~Displayable();

		sf::Vector2f getSprBodySize() { return sf::Vector2f(rect.width, rect.height); }
		sf::Vector2f getPosition() { return spr.getPosition(); }
		sf::Vector2f getSize() { return sf::Vector2f(rect.width, rect.height); }
		sf::IntRect getRect() { return rect; }

		void SetSprite(sf::Texture& text);
		void SetScale(float xScale, float yScale);

		bool inView(sf::View view, Displayable* obj);
		void Move(float dx, float dy);
		void Draw(sf::RenderWindow& window, sf::View vw);
		void Draw(sf::RenderWindow& window, sf::View vw, bool force);

		std::string GetWriteable();

	private:
		sf::Sprite spr;
		sf::IntRect rect;
	};
}
