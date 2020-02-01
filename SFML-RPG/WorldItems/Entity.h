#pragma once
#include <SFML\Graphics.hpp>

class Entity
{
public:
	Entity(const char* name, const char* texturePath, sf::Texture* text);
	Entity(const Entity& copy);
	~Entity();

public:
	const char* name;
	sf::RectangleShape txtr;
};

