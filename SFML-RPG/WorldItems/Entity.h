#pragma once
#include <SFML\Graphics.hpp>

class Entity
{
public:
	Entity(const char* name, sf::Texture* txtr);
	Entity(const Entity& copy);
	~Entity();

public:
	const char* name;
	sf::RectangleShape txtr;
};

