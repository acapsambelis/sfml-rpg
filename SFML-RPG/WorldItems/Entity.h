#pragma once
#include <SFML\Graphics.hpp>

class Entity
{
public:
	Entity(std::string name, std::string texturePath, sf::Texture* text);
	Entity(const Entity& copy);
	~Entity();

public:
	std::string name;
	sf::RectangleShape txtr;
};

